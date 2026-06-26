#include <iostream>
#include <queue>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
using namespace std;


queue<int> buffer;

mutex mtx;
condition_variable cv;

bool producer_done = false;


// Producer: create 1~5 and put into the buffer
void Producer(){
    for (int i = 1; i <= 5; i++) {
        {
            // Lock before using the queue
            lock_guard<mutex> lock(mtx);
            // TODO: put i into the buffer
            buffer.push(i);
            // TODO: print "Produced: i"
            cout << "Produced: " << i << "\n";
        }
        // Notify a consumer which is waiting
        cv.notify_one();
        // Wait 0.5 seconds
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    {
        lock_guard<mutex> lock(mtx);
        producer_done = true;
    }
    // Notify all consumers which are waiting
    cv.notify_all();
}

void Consumer(){
    // int consumer_count = 0;
    // Consumer: Take the data out of the buffer if there is any
    while (true) {
        // {
            // Lock before using the queue
            // lock_guard<mutex> lock(mtx);
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [] {
            return !buffer.empty() || producer_done;
            });
            if (buffer.empty() && producer_done) {
                break;
            }
            // if(!buffer.empty()/* TODO: buffer is not empty */){
            //     // TODO: get the data at the front
            //     int x = buffer.front();
            //     // TODO: remove the data at the front
            //     buffer.pop();
            //     // TODO: print "Consumed: item"
            //     cout << "Consumed: " << x << "\n";
            //     consumer_count++;
            // }
            // TODO: get the data at the front
            int x = buffer.front();
            // TODO: remove the data at the front
            buffer.pop();
            // TODO: print "Consumed: item"
            cout << "Consumed: " << x << "\n";
            // consumer_count++;
        // }
        // Wait 0.1 seconds after each checking
        // this_thread::sleep_for(chrono::milliseconds(100)); 
    }
}


int main() {
    thread p(Producer);
    thread c(Consumer);
    
    p.join();
    c.join(); 
    return 0;
}