#include "circular-queue.h"
#include <iostream>

using namespace std;

const CircularQueue::QueueItem CircularQueue::EMPTY_QUEUE = -999;

CircularQueue::CircularQueue() {
    items_ = new QueueItem[16];
    head_ = 0;
    tail_ = 0;
    capacity_ = 16;
    size_ = 0;
}

CircularQueue::CircularQueue(unsigned int capacity) {
    items_ = new QueueItem[capacity];
    head_ = 0;
    tail_ = 0;
    capacity_ = capacity;
    size_ = 0;
}

CircularQueue::~CircularQueue() {
    delete [] items_;
    items_ = nullptr;
}

unsigned int CircularQueue::size() const {
    return size_;
}

bool CircularQueue::empty() const {
    return size_ == 0;
}

bool CircularQueue::full() const {
    return size_ == capacity_;
}

CircularQueue::QueueItem CircularQueue::peek() const {
    if(empty())
        return EMPTY_QUEUE;
    return items_[head_];
}

bool CircularQueue::enqueue(QueueItem value) {
    if(full())
        return false;

    items_[tail_] = value;
    tail_ = (tail_ + 1) % capacity_;
    size_++;

    return true;
}

CircularQueue::QueueItem CircularQueue::dequeue() {
    if(empty())
        return EMPTY_QUEUE;

    QueueItem returnVal = items_[head_];
    head_ = (head_ + 1) % capacity_;
    size_--;

    return returnVal;
}

void CircularQueue::print() const {
    for(int i = 0; i < size_; i++) {
        cout << "index " << i << ": " << items_[(head_ + i) % capacity_] << endl;
    }
}
