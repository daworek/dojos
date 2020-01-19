#include <gtest/gtest.h>

int equi(int inputArr[], int arrayLen)
{
    // Find equilibrium index of inputArr

    long leftSum = 0;
    long rightSum = 0;

    // Sum of right side of the input array
    for (int i = 1; i < arrayLen; i++)
    {
        rightSum += inputArr[i];
    }

    // Look for Equilibrium index
    for (int i = 0; i < arrayLen - 1; i++)
    {
        if (leftSum == rightSum)
        {
            return i;
        }

        leftSum += inputArr[i];
        rightSum -= inputArr[i+1];
    }
    if (leftSum == rightSum)
    {
        return arrayLen - 1;
    }

    return -1;
}

TEST(EquiTest, EmptyArrayReturnsZero)
{
    const int arrayLen = 0;
    int inputArr[arrayLen] = {};
    int equiIndex = equi(inputArr, arrayLen);
    int expectedEquiIndex = -1;
    ASSERT_EQ(expectedEquiIndex, equiIndex);
}

TEST(EquiTest, Equi3)
{
    const int arrayLen = 5;
    int inputArr[arrayLen] = {1, -3, 4, -2, 2};
    int equiIndex = equi(inputArr, arrayLen);
    int expectedEquiIndex = 3;
    ASSERT_EQ(expectedEquiIndex, equiIndex);
}

TEST(EquiTest, EquiNotExist)
{
    const int arrayLen = 6;
    int inputArr[arrayLen] = {1, -3, 4, -2, 2, 2};
    int equiIndex = equi(inputArr, arrayLen);
    int expectedEquiIndex = -1;
    ASSERT_EQ(expectedEquiIndex, equiIndex);
}
