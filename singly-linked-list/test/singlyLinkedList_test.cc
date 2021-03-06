#include "../src/singlyLinkedList.cc"
#include "gtest/gtest.h"

namespace singlylinkedlist{

namespace{

class SinglyLinedListTest : public ::testing::Test 
{
    protected:
    void SetUp() override 
    {
        SinglyLinkedList sll;
    }

    SinglyLinkedList sll;
};

TEST_F(SinglyLinedListTest, emptyList)
{
    ASSERT_EQ(sll.getListSize(), 0);
}

TEST_F(SinglyLinedListTest, insertingAtBeginning)
{
    sll.insertAtBeginning(1);
    ASSERT_EQ(sll.getListSize(), 1);
    ASSERT_EQ(sll.getValueAtIndex(0), 1);
}

TEST_F(SinglyLinedListTest, insertingAtEnd)
{
    sll.insertAtEnd(1);
    sll.insertAtEnd(2);
    ASSERT_EQ(sll.getListSize(), 2);
    ASSERT_EQ(sll.getValueAtIndex(1), 2);
}

TEST_F(SinglyLinedListTest, insertingAtIndex)
{
    sll.insertAtBeginning(1);
    sll.insertAtBeginning(2);
    sll.insertAtBeginning(3);

    sll.insertAtIndex(1, 10);
    ASSERT_EQ(sll.getListSize(), 4);
    ASSERT_EQ(sll.getValueAtIndex(1), 10);
}

TEST_F(SinglyLinedListTest, insertingAtIndexException)
{
    sll.insertAtBeginning(1);
    sll.insertAtBeginning(2);
    sll.insertAtBeginning(3);

    ASSERT_THROW(sll.insertAtIndex(5, 10), std::string);
    ASSERT_EQ(sll.getListSize(), 3);
}

TEST_F(SinglyLinedListTest, insertingAtIndexNegativeException)
{
    sll.insertAtBeginning(1);
    sll.insertAtBeginning(2);
    sll.insertAtBeginning(3);

    ASSERT_THROW(sll.insertAtIndex(-5, 10), std::string);
    ASSERT_EQ(sll.getListSize(), 3);
}

TEST_F(SinglyLinedListTest, deleteAtIndex)
{
    sll.insertAtBeginning(1);
    sll.insertAtBeginning(2);
    sll.insertAtBeginning(3);

    sll.deleteAtIndex(1);
    ASSERT_EQ(sll.getListSize(), 2);    
    ASSERT_EQ(sll.getValueAtIndex(1), 1);
}

TEST_F(SinglyLinedListTest, deleteAtIndexException)
{
    sll.insertAtBeginning(1);
    sll.insertAtBeginning(2);
    sll.insertAtBeginning(3);

    ASSERT_THROW(sll.deleteAtIndex(10), std::string);
    ASSERT_EQ(sll.getListSize(), 3);    
}

TEST_F(SinglyLinedListTest, deleteAtIndexNegativeException)
{
    sll.insertAtBeginning(1);
    sll.insertAtBeginning(2);
    sll.insertAtBeginning(3);

    ASSERT_THROW(sll.deleteAtIndex(-5), std::string);
    ASSERT_EQ(sll.getListSize(), 3);  
}

TEST_F(SinglyLinedListTest, searchValue)
{
    sll.insertAtBeginning(1);
    sll.insertAtBeginning(2);
    sll.insertAtBeginning(3);
    auto node = sll.searchValue(2);
    ASSERT_EQ(node->value, 2);  
    node = sll.searchValue(10);
    ASSERT_EQ(node, nullptr);
}

TEST_F(SinglyLinedListTest, listSize)
{
    ASSERT_EQ(sll.getListSize(), 0);  
    sll.insertAtBeginning(1);
    ASSERT_EQ(sll.getListSize(), 1); 
}

TEST_F(SinglyLinedListTest, removeDuplicates)
{
    sll.insertAtBeginning(1);
    sll.insertAtBeginning(2);
    sll.insertAtBeginning(3);
    sll.insertAtBeginning(3);
    sll.insertAtBeginning(1);
    ASSERT_EQ(sll.getListSize(), 5); 
    sll.removeDuplicates();
    ASSERT_EQ(sll.getListSize(), 3);    
}

TEST_F(SinglyLinedListTest, reverseList)
{
    sll.insertAtBeginning(4);
    sll.insertAtBeginning(3);
    sll.insertAtBeginning(2);
    sll.insertAtBeginning(1);
    ASSERT_EQ(sll.getListSize(), 4); 
    sll.reverseList();
    ASSERT_EQ(sll.getValueAtIndex(0), 4); 
    ASSERT_EQ(sll.getValueAtIndex(1), 3);    
    ASSERT_EQ(sll.getValueAtIndex(2), 2);    
    ASSERT_EQ(sll.getValueAtIndex(3), 1);    
}

} //namespace
} //singlyLinkedList