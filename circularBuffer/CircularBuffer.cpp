#include "CircularBuffer.h"

#include <iostream>
#include <stdexcept>

CircularBuffer::~CircularBuffer()
{

}

// Constructor to initialize the buffer with default minimum capacity
CircularBuffer::CircularBuffer() : capacity(MIN_BUFFER_SIZE) {
    buffer.resize(capacity);
}

// Constructor to initialize the buffer with a given capacity
CircularBuffer::CircularBuffer(size_t capacity) : capacity(capacity) {
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

// Peek at the oldest element without removing it
int CircularBuffer::peek() const {
    if (isEmpty()) {
        throw std::underflow_error("Buffer is empty");
    }
    return buffer[head];
}

// Display the contents of the buffer
void CircularBuffer::display() const {
    std::cout << "Buffer contents: ";
    for (size_t i = 0; i < size; i++) {
        std::cout << buffer[(head + i) % capacity] << " ";
    }
    std::cout << std::endl;
}