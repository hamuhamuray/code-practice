#include <iostream>
#include <queue>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
using namespace std;

// Global variables
const int BUFFER_SIZE = 3;
const int PRODUCER_COUNT = 2;
const int CONSUMER_COUNT = 2;
int total_produced_tasks = 0, total_consumed_tasks = 0;
mutex cout_stats_mtx;

struct Task {
    int producer_id;
    int item_id;
    Task(){};
    Task(int pid, int iid): producer_id(pid), item_id(iid){};
};

class TaskQueue{
    private:
    queue<Task> buffer;
    int buffer_size;
    int active_producers;

    mutex mtx;
    condition_variable not_empty, not_full;

    public:
    TaskQueue(int size, int producer_count): buffer_size(size), active_producers(producer_count){
    }

    void push(Task task){
        {
            //Lock the buffer before using
            unique_lock<mutex> lock(mtx);
            not_full.wait(lock, [this]{
                return buffer.size() < buffer_size;
            });
            buffer.push(task);
        }
        not_empty.notify_one();
    }

    bool pop(Task& task){
        {
            //Lock the buffer before using
            unique_lock<mutex> lock(mtx);
            not_empty.wait(lock, [this]{
                return !buffer.empty() || active_producers == 0;
            });
            if(buffer.empty() && active_producers == 0) return false; /*There aren't any tasks left in the buffer, therefore Consumer is finished*/
            task = buffer.front();
            buffer.pop();
        }
        // Notify one producer that there's a space
        not_full.notify_one();
        // Successfully get the task
        return true;
    }

    void producerFinished(){
        {
            lock_guard<mutex> lock(mtx);
            active_producers--;
        }
        not_empty.notify_all();
    }
};

TaskQueue task_queue(BUFFER_SIZE, PRODUCER_COUNT);

void Producer(int producer_id){
    int produced_tasks = 0;
    for(int i = 1 ; i <= 5 ; i++){
        Task new_task{producer_id, i};
        task_queue.push(new_task);
        {
            lock_guard<mutex> lock_cout(cout_stats_mtx);
            cout << "Producer " << producer_id << " produced: " << i << "\n";
            produced_tasks++;
            total_produced_tasks++;
        }
        this_thread::sleep_for(chrono::milliseconds(500));        
    }
    task_queue.producerFinished();
    {
        lock_guard<mutex> lock_cout(cout_stats_mtx);
        cout << "Producer " << producer_id << " produced " << produced_tasks << " task(s)" << "\n";
    }
}

void Consumer(int consumer_id){
    int consumed_tasks = 0;
    Task popped_task;
    while(true){
        if(!task_queue.pop(popped_task)) break;
        {
            lock_guard<mutex> lock_cout(cout_stats_mtx);
            cout << "Consumer " << consumer_id << " consumed: " << popped_task.item_id << " from Producer " << popped_task.producer_id << "\n";
            consumed_tasks++;
            total_consumed_tasks++;
        }
        this_thread::sleep_for(chrono::milliseconds(300));
    }
    {
        lock_guard<mutex> lock_cout(cout_stats_mtx);
        cout << "Consumer " << consumer_id << " consumed " << consumed_tasks << " task(s)" << "\n";
    }
}

int main(){
    thread p1(Producer, 1);
    thread p2(Producer, 2);
    thread c1(Consumer, 1);
    thread c2(Consumer, 2);
    p1.join();
    p2.join();
    c1.join();
    c2.join();
    cout << "Total produced: " << total_produced_tasks << "\n";
    cout << "Total consumed: " << total_consumed_tasks << "\n";
    return 0;
}

