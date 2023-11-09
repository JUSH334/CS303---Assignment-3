#include <iostream>
#include "queue.h"

using namespace std;

//Inserts a new element at the rear of the queue.
template <typename T>
void Queue<T>::enqueue(const T& value) {
    elements.push(value);
    cout << "Element " << value << " enqueued." << endl;
}

//Removes the front element of the queue and returns it.
template <typename T>
T Queue<T>::dequeue() {
    if (isEmpty()) {
        cerr << "Error: Queue is empty. Cannot dequeue." << endl;
        return T(); // Return a default value or handle the error accordingly
    }

    T frontElement = elements.front();
    elements.pop();
    cout << "Element " << frontElement << " dequeued." << endl;
    return frontElement;
}

//Returns the front element present in the queue without removing it
template <typename T>
T Queue<T>::front() const {
    if (isEmpty()) {
        cerr << "Error: Queue is empty. Cannot get front element." << endl;
        return T(); // Return a default value or handle the error accordingly
    }

    return elements.front();
}

//Checks if the queue is empty
template <typename T>
bool Queue<T>::isEmpty() const {
    return elements.empty();
}

//Returns the total number of elements present in the queue
template <typename T>
int Queue<T>::size() const {
    return elements.size();
}

// Explicit instantiation of the class for different data types
template class  Queue<int>;
template class  Queue<double>;
template class  Queue<string>;
template class  Queue<char>;