#include "CircularBuffer.h"

#include <cstddef>
#include <iostream>
#include <stdexcept>

CircularBuffer::~CircularBuffer()
{

}

// Constructor to initialize the buffer with default minimum capacity
CircularBuffer::CircularBuffer() : capacity(MIN_BUFFER_SIZE), head(0), tail(0), size(0) {
    buffer.resize(capacity);
}

// Constructor to initialize the buffer with a given capacity
CircularBuffer::CircularBuffer(size_t capacity) : capacity(capacity), head(0), tail(0), size(0) {
    //Check the capacity for minimum and maximum size
    if (capacity < MIN_BUFFER_SIZE)
        capacity = MIN_BUFFER_SIZE;
    else if (capacity > MAX_BUFFER_SIZE)
        capacity = MAX_BUFFER_SIZE;
    buffer.resize(capacity);
}

// Check if the buffer is empty
bool CircularBuffer::isEmpty() const {
    return size == 0;
}

// Check if the buffer is full
bool CircularBuffer::isFull() const {
    return size == capacity;
}

// Add an element to the buffer
void CircularBuffer::enqueue(int value) {
    if (isFull()) {
        throw std::overflow_error("Buffer is full");
    }
    buffer[tail] = value;
    tail = (tail + 1) % capacity; // Wrap around if necessary
    size++;
}

// Add an element to the buffer using push
void CircularBuffer::push(int value) {
    enqueue(value);
}

// Remove and return the oldest element from the buffer
int CircularBuffer::dequeue() {
    if (isEmpty()) {
        throw std::underflow_error("Buffer is empty");
    }
    int value = buffer[head];
    head = (head + 1) % capacity; // Wrap around if necessary
    size--;
    return value;
}

//Remove and return the oldest element from the buffer using pop
int CircularBuffer::pop() {
    return dequeue();
}

// Peek at the oldest element without removing it
int CircularBuffer::peek() const {
    if (isEmpty()) {
        throw std::underflow_error("Buffer is empty");
    }
    return buffer[head];
}

// Get the size of the buffer
size_t CircularBuffer::getSize() const {
    return size;
}

// Display the contents of the buffer
void CircularBuffer::display() const {
    std::cout << "Buffer contents: ";
    for (size_t i = 0; i < size; i++) {
        std::cout << buffer[(head + i) % capacity] << " ";
    }
    std::cout << std::endl;
}
