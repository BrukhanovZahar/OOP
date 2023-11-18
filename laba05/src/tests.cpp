#include <gtest/gtest.h>
#include "../include/DynamicArray.h"
#include "../include/DequeAllocator.h"


TEST(AllocatorTestSet, allocateTest) {
    DequeAllocator<int, 2> allocator;

    int* pint = allocator.allocate(1);

    EXPECT_NE(pint, nullptr);
    ASSERT_NO_THROW(allocator.allocate(10000000));

    allocator.deallocate(pint);
}

TEST(AllocatorTestSet, InnerTypesIsConvertible) {
    bool p2constP = std::is_convertible_v<DequeAllocator<int>::pointer, DequeAllocator<int>::const_pointer>;
    bool p2voidP = std::is_convertible_v<DequeAllocator<int>::pointer, DequeAllocator<int>::void_pointer>;
    bool p2constVoidP = std::is_convertible_v<DequeAllocator<int>::pointer, DequeAllocator<int>::const_void_pointer>;
    bool constP2constVoidP = std::is_convertible_v<DequeAllocator<int>::const_pointer, DequeAllocator<int>::const_void_pointer>;
    bool voidP2constVoidP = std::is_convertible_v<DequeAllocator<int>::void_pointer, DequeAllocator<int>::const_void_pointer>;

    EXPECT_TRUE(p2constP);
    EXPECT_TRUE(p2voidP);
    EXPECT_TRUE(p2constVoidP);
    EXPECT_TRUE(constP2constVoidP);
    EXPECT_TRUE(voidP2constVoidP);

}

TEST(DynamicArrayTest, pushTest) {
    DynamicArray<int, DequeAllocator<int>> dynamicArray;
    const int src = 1;
    int expectedInt = 1;
    int returnedInt;

    returnedInt = dynamicArray.push_back(src);

    ASSERT_EQ(expectedInt, returnedInt);
}

TEST(DynamicArrayTest, atTest) {
    DynamicArray<int, DequeAllocator<int>> dynamicArray;
    const int srcFirst = 1;
    const int srcSecond = 1;
    int returnedIntFirst, returnedIntSecond;

    dynamicArray.push_back(srcFirst);
    dynamicArray.push_back(srcSecond);
    returnedIntFirst = dynamicArray.at(0);
    returnedIntSecond = dynamicArray.at(1);

    EXPECT_EQ(srcFirst, returnedIntFirst);
    EXPECT_EQ(srcSecond, returnedIntSecond);
}

TEST(DynamicArrayTest, getSizeTest) {
    DynamicArray<int, DequeAllocator<int>> dynamicArray;
    const int srcFirst = 1;
    const int srcSecond = 3;
    const int srcThird = 6;
    const int expectedInt = 3;
    std::size_t returnedSize;

    dynamicArray.push_back(srcFirst);
    dynamicArray.push_back(srcSecond);
    dynamicArray.push_back(srcThird);
    returnedSize = dynamicArray.getSize();

    EXPECT_EQ(expectedInt, returnedSize);
}

TEST(DynamicArrayTest, emptyTest) {
    DynamicArray<int, DequeAllocator<int>> dynamicArray;
    const int srcFirst = 1;
    const int srcSecond = 3;
    const int srcThird = 6;
    const bool expectedFirst = true;
    const bool expectedSecond = false;
    bool emptyFirst, emptySecond;

    emptyFirst = dynamicArray.empty();
    dynamicArray.push_back(srcFirst);
    dynamicArray.push_back(srcSecond);
    dynamicArray.push_back(srcThird);
    emptySecond = dynamicArray.empty();

    EXPECT_EQ(expectedFirst, emptyFirst);
    EXPECT_EQ(expectedSecond, emptySecond);
}

TEST(DynamicArrayTest, pop_backTest) {
    DynamicArray<int, DequeAllocator<int>> dynamicArray;
    const int srcFirst = 1;
    const int srcSecond = 3;
    const int srcThird = 6;
    const int expectedFirst = 3;
    const int expectedSecond = 1;
    std::size_t sizeFirst, sizeSecond;

    dynamicArray.push_back(srcFirst);
    dynamicArray.push_back(srcSecond);
    dynamicArray.push_back(srcThird);
    sizeFirst = dynamicArray.getSize();
    dynamicArray.pop_back();
    dynamicArray.pop_back();
    sizeSecond = dynamicArray.getSize();

    EXPECT_EQ(expectedFirst, sizeFirst);
    EXPECT_EQ(expectedSecond, sizeSecond);
}

TEST(DynamicArrayTest, iteratorTest) {
    DynamicArray<int, DequeAllocator<int>> dynamicArray;
    const int src[]{1, 3, 6};
    int i = 0;

    dynamicArray.push_back(src[0]);
    dynamicArray.push_back(src[1]);
    dynamicArray.push_back(src[2]);

    for (int elem: dynamicArray) {
        EXPECT_EQ(elem, src[i]);
        ++i;
    }
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}