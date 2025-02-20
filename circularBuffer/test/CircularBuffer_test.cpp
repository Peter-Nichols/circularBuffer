/*
 * CircularBuffer_test.cpp
 */

#include "CircularBuffer.h"


#include <gtest/gtest.h>

#include <string>
#include <typeinfo>


class CircularBufferFixture : public ::testing::Test
{
protected:
    CircularBuffer* cb;


    void SetUp() override
    {
        cb = new CircularBuffer();
    }

    void TearDown() override
    {
        delete(cb);
        cb = nullptr;
    }
};

// Unit Tests
TEST(CircularBufferFixture, IsEmptyOnCreation) {
    CircularBuffer cb(10);
    EXPECT_TRUE(cb.isEmpty());
    EXPECT_FALSE(cb.isFull());
    EXPECT_EQ(cb.getSize(), 0);
}

TEST(CircularBufferFixture, IsEmptyOnCreationDefault) {
    CircularBuffer cb;
    EXPECT_TRUE(cb.isEmpty());
    EXPECT_FALSE(cb.isFull());
    EXPECT_EQ(cb.getSize(), 0);
}

TEST(CircularBufferFixture, EnqueueAndDequeue) {
    CircularBuffer cb(5);
    cb.enqueue(10);
    EXPECT_FALSE(cb.isEmpty());
    EXPECT_EQ(cb.getSize(), 1);
    EXPECT_EQ(cb.dequeue(), 10);
    EXPECT_TRUE(cb.isEmpty());
}

TEST(CircularBufferFixture, PushAndPop) {
    CircularBuffer cb(5);
    cb.push(10);
    EXPECT_FALSE(cb.isEmpty());
    EXPECT_EQ(cb.getSize(), 1);
    EXPECT_EQ(cb.pop(), 10);
    EXPECT_TRUE(cb.isEmpty());
}

TEST(CircularBufferFixture, FillBufferEnqueue) {
    CircularBuffer cb(6);
    cb.enqueue(100);
    cb.enqueue(200);
    cb.enqueue(300);
    cb.enqueue(400);
    cb.enqueue(500);
    cb.enqueue(600);
    EXPECT_TRUE(cb.isFull());
    EXPECT_EQ(cb.getSize(), 6);

    EXPECT_THROW(cb.push(700), std::runtime_error); // Buffer is full
}

TEST(CircularBufferFixture, FillBuffer) {
    CircularBuffer cb(5);
    cb.push(1);
    cb.push(2);
    cb.push(3);
    cb.push(4);
    cb.push(5);
    EXPECT_TRUE(cb.isFull());
    EXPECT_EQ(cb.getSize(), 5);

    EXPECT_THROW(cb.push(4), std::runtime_error); // Buffer is full
}

TEST(CircularBufferFixture, PopFromEmptyBufferDequeue) {
    CircularBuffer cb(10);
    EXPECT_THROW(cb.pop(), std::runtime_error); // Buffer is empty
}

TEST(CircularBufferFixture, PopFromEmptyBuffer) {
    CircularBuffer cb(10);
    EXPECT_THROW(cb.pop(), std::runtime_error); // Buffer is empty
}

TEST(CircularBufferFixture, WrapAround) {
    CircularBuffer cb(3);
    cb.push(1);
    cb.push(2);
    cb.push(3);
    EXPECT_EQ(cb.pop(), 1);
    cb.push(4); // Wrap around
    EXPECT_EQ(cb.getSize(), 3);
    EXPECT_EQ(cb.pop(), 2);
    EXPECT_EQ(cb.pop(), 3);
    EXPECT_EQ(cb.pop(), 4);
    EXPECT_TRUE(cb.isEmpty());
}

TEST(CircularBufferFixture, MixedOperations) {
    CircularBuffer cb(5);
    cb.push(1);
    cb.push(2);
    cb.push(3);
    EXPECT_EQ(cb.pop(), 1);
    cb.push(4);
    EXPECT_EQ(cb.getSize(), 3);
    EXPECT_EQ(cb.pop(), 2);
    EXPECT_EQ(cb.pop(), 3);
    EXPECT_EQ(cb.pop(), 4);
    EXPECT_TRUE(cb.isEmpty());
}
