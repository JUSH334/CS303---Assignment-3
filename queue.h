#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <queue>

using namespace std;

template <typename T>
class Queue {
private:
    queue<T> elements;

public:
    void enqueue(const T& value);
    T dequeue();
    T front() const;
    bool isEmpty() const;
    int size() const;
};


#endif
