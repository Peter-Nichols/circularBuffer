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

TEST_F(CircularBufferFixture, ComputerFactoryTests_Constructor)
{
    EXPECT_EQ(0, 0);
    //EXPECT_EQ(computer->getHDD().compare(""), 0);
    //EXPECT_EQ(computer->getRAM().compare(""), 0);
    //EXPECT_EQ(computer->isIsBluetoothEnabled(), false);
    //EXPECT_EQ(computer->isIsGraphicCardEnabled(), false);
}

TEST_F(CircularBufferFixture, ComputerFactoryTests_GetComputer)
{
    EXPECT_EQ(0, 0);
}

TEST_F(CircularBufferFixture, ComputerFactoryTests_GetComputer2)
{
    EXPECT_EQ(0, 0);
}

TEST_F(CircularBufferFixture, ComputerFactoryTests_GetComputer3)
{
    EXPECT_EQ(0, 0);

}

