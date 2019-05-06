//
//  main.cpp
//  circular queue
//  from leetcode
//
//  Impleted by js on 2019/5/6.
//  Copyright © 2019 js. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class MyCircularQueue {
private:
    int _capacity;  //  max capacity, used for constructor
    //  current size, when call enQueue(), ++_size;
    //  otherwise, when call deQueue(), --_size.
    //
    //  There is another way to avoid using variable _size,
    //  But I prefer using _size;
    //
    int _size;
    int* _list;     //  an array used for save data
    int _front;     //  front pointer of the queue
    int _rear;      //  rear  pointer of the queue
public:
    /** Initialize your data structure here.
     *  Set the size of the queue to be k.
     */
    MyCircularQueue(int k) {
        _capacity = k+1;             // IMPORTANT!!!, waste one space.
        _size = 0;
        _list = new int[_capacity]();
        _front = _rear = 0;          // waste first place
    }
    
    /** Insert an element into the circular queue.
     *  Return true if the operation is successful.
     */
    bool enQueue(int value) {
        if (isFull()) {     //  if is full, return false
            return false;
        } else {            //  if is not full
            _rear = (_rear + 1) % _capacity;  //  move rear pointer
            _list[_rear] = value;             //  save data
            _size = _size + 1;                //  add current size
            return true;                      //  finally return true
        }
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) {     //  if is empty, underflow, return false
            return false;
        } else {             //  if is not empty
            _front = (_front + 1) % _capacity;  //  move front pointer
            _size = _size - 1;                  //  minus size
            return true;                        //  finally return true
        }
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) {
            return -1;
        } else {
            return _list[(_front+1) % _capacity];
        }
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) {
            return -1;
        } else {
            return _list[_rear];
        }
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return _size == 0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return _size == _capacity - 1;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */


int main(int argc, const char * argv[]) {
    MyCircularQueue circularQueue(3);
    cout << circularQueue.enQueue(1) << endl;  // return true
    cout << circularQueue.enQueue(2) << endl;   // return true
    cout << circularQueue.enQueue(3) << endl;  // return true
    cout << circularQueue.enQueue(4) << endl;  // return false, the queue is full
    cout << circularQueue.Rear() << endl; // return 3
    cout << circularQueue.isFull() << endl;  // return true
    cout << circularQueue.deQueue() << endl;  // return true
    cout << circularQueue.enQueue(4) << endl;  // return true
    cout << circularQueue.Rear() << endl;  // return 4
    
}
