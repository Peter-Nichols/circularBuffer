#ifndef CIRCULARBUFFER_HPP
#define CIRCULARBUFFER_HPP

#include <vector>
#include <stddef.h>

#define MIN_BUFFER_SIZE 5
#define MAX_BUFFER_SIZE 25

class CircularBuffer
{
public:
    CircularBuffer();
    CircularBuffer(size_t capacity);
    ~CircularBuffer();

    bool isEmpty() const;
    bool isFull() const;
    void enqueue(int value);
    void push(int value);
    int dequeue();
    int pop();
    int peek() const;
    size_t getSize() const;
    void display() const;

private:
    std::vector<int> buffer; // Underlying storage
    size_t capacity;         // Maximum capacity of the buffer
    size_t head;             // Index of the first element
    size_t tail;             // Index where the next element will be inserted
    size_t size;             // Current number of elements in the buffer
};

#endif // CIRCULARBUFFER_HPP
