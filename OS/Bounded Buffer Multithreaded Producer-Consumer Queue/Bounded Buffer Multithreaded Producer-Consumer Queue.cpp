#include <iostream>
#include <queue>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
using namespace std;

struct Task {
    int producer_id;
    int item_id;
};


// queue<int> buffer;
queue<Task> buffer;
const int BUFFER_SIZE = 3;

mutex mtx;
condition_variable not_empty, not_full;

bool producer_done = false;
const int PRODUCER_COUNT = 2;
const int CONSUMER_COUNT = 2;
int finished_producers = 0;
int total_produced_tasks = 0, total_consumed_tasks = 0;



void Producer(int producer_id){
    int produced_tasks = 0;
    for(int i = 1 ; i <= 5 ; i++){
        {
            //Lock the buffer before using
            // lock_guard<mutex> lock(mtx);
            unique_lock<mutex> lock(mtx);
            not_full.wait(lock, []{
                return buffer.size() < BUFFER_SIZE;
            });
            Task new_task{producer_id, i};
            buffer.push(new_task);
            cout << "Producer " << producer_id << " produced: " << i << "\n";
            produced_tasks++;
            total_produced_tasks++;
        }
        // Notify one consumer that a data is added in the buffer
        not_empty.notify_one();
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    {
        lock_guard<mutex> lock(mtx);
        // producer_done = true;
        finished_producers++;
        cout << "Producer " << producer_id << " produced " << produced_tasks << " task(s)" << "\n";
    }
    // Notify all the waiting threads that the Producer is done
    not_empty.notify_all();
}

void Consumer(int consumer_id){
    int consumed_tasks = 0;
    while(true){
        {
            //Lock the buffer before using
            unique_lock<mutex> lock(mtx);
            // not_empty.wait(lock, []{
            //     return !buffer.empty() || producer_done;
            // });
            // if(buffer.empty() && producer_done){
            //     break;
            // }
            not_empty.wait(lock, []{
                return !buffer.empty() || finished_producers == PRODUCER_COUNT;
            });
            if(buffer.empty() && finished_producers == PRODUCER_COUNT) break;
            Task x = buffer.front();
            buffer.pop();
            cout << "Consumer " << consumer_id << " consumed: " << x.item_id << " from Producer " << x.producer_id << "\n";
            consumed_tasks++;
            total_consumed_tasks++;
        }
        // Notify one producer that there's a space
        not_full.notify_one();
        // Simulate the consumer needs time to finish the task
        this_thread::sleep_for(chrono::milliseconds(300));
    }
    {
        lock_guard<mutex> lock(mtx);
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