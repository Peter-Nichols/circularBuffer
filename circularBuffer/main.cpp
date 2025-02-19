#include <iostream>
#include <vector>
#include <stdexcept>

class CircularBuffer {
private:
    std::vector<int> buffer; // Underlying storage
    size_t capacity;         // Maximum capacity of the buffer
    size_t head = 0;         // Index of the first element
    size_t tail = 0;         // Index where the next element will be inserted
    size_t size = 0;         // Current number of elements in the buffer

public:
    // Constructor to initialize the buffer with a given capacity
    CircularBuffer(size_t capacity) : capacity(capacity) {
        buffer.resize(capacity);
    }

    // Check if the buffer is empty
    bool isEmpty() const {
        return size == 0;
    }

    // Check if the buffer is full
    bool isFull() const {
        return size == capacity;
    }

    // Add an element to the buffer
    void enqueue(int value) {
        if (isFull()) {
            throw std::overflow_error("Buffer is full");
        }
        buffer[tail] = value;
        tail = (tail + 1) % capacity; // Wrap around if necessary
        size++;
    }

    // Remove and return the oldest element from the buffer
    int dequeue() {
        if (isEmpty()) {
            throw std::underflow_error("Buffer is empty");
        }
        int value = buffer[head];
        head = (head + 1) % capacity; // Wrap around if necessary
        size--;
        return value;
    }

    // Peek at the oldest element without removing it
    int peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Buffer is empty");
        }
        return buffer[head];
    }

    // Display the contents of the buffer
    void display() const {
        std::cout << "Buffer contents: ";
        for (size_t i = 0; i < size; i++) {
            std::cout << buffer[(head + i) % capacity] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    // Create a circular buffer with a capacity of 5
    CircularBuffer cb(5);

    // Enqueue elements
    cb.enqueue(10);
    cb.enqueue(20);
    cb.enqueue(30);
    cb.display(); // Output: Buffer contents: 10 20 30

    // Dequeue an element
    std::cout << "Dequeued: " << cb.dequeue() << std::endl; // Output: Dequeued: 10
    cb.display(); // Output: Buffer contents: 20 30

    // Enqueue more elements
    cb.enqueue(40);
    cb.enqueue(50);
    cb.enqueue(60);
    cb.display(); // Output: Buffer contents: 20 30 40 50 60

    // Try to enqueue when the buffer is full
    try {
        cb.enqueue(70);
    } catch (const std::overflow_error& e) {
        std::cout << "Error: " << e.what() << std::endl; // Output: Error: Buffer is full
    }

    // Dequeue all elements
    while (!cb.isEmpty()) {
        std::cout << "Dequeued: " << cb.dequeue() << std::endl;
    }

    // Try to dequeue when the buffer is empty
    try {
        cb.dequeue();
    } catch (const std::underflow_error& e) {
        std::cout << "Error: " << e.what() << std::endl; // Output: Error: Buffer is empty
    }

    return 0;
}