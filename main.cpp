
#include <iostream>

#include "CircularBuffer.h"

int main(int rgc, char* argv[])
{
    // Create a circular buffer with a capacity of 5
    CircularBuffer cb(5);

    // Enqueue elements
    cb.enqueue(100);
    cb.enqueue(200);
    cb.enqueue(300);
    cb.display(); // Output: Buffer contents: 100 200 300

    // Dequeue an element
    std::cout << "Dequeued: " << cb.dequeue() << '\n'; // Output: Dequeued: 100
    cb.display(); // Output: Buffer contents: 200 300

    // Enqueue more elements
    cb.enqueue(400);
    cb.enqueue(500);
    cb.enqueue(600);
    cb.display(); // Output: Buffer contents: 200 300 400 500 600

    // Try to enqueue when the buffer is full
    try {
        cb.enqueue(700);
    } catch (const std::overflow_error& e) {
        std::cout << "Error: " << e.what() << '\n'; // Output: Error: Buffer is full
    }

    // Dequeue all elements
    while (!cb.isEmpty()) {
        std::cout << "Dequeued: " << cb.dequeue() << '\n';
    }

    // Try to dequeue when the buffer is empty
    try {
        cb.dequeue();
    } catch (const std::underflow_error& e) {
        std::cout << "Error: " << e.what() << '\n'; // Output: Error: Buffer is empty
    }
}
