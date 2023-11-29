#include "BST Header.h"
#include <iostream>

using namespace std;

//Private Functions
void BinarySearchTree::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
    if(nodePtr == nullptr)
    {
        nodePtr = newNode;
    }
    
    else if(newNode->value < nodePtr->value)
    {
        insert(nodePtr->leftNode, newNode);
    }
    
    else
    {
        insert(nodePtr->rightNode, newNode);
    }
}

void BinarySearchTree::destroySubTree(TreeNode *nodePtr)
{
    if(nodePtr)
    {
        if(nodePtr->leftNode)
        {
            destroySubTree(nodePtr->leftNode);
        }
        
        if(nodePtr->rightNode)
        {
            destroySubTree(nodePtr->rightNode);
        }
        
        delete nodePtr;
    }
}

void BinarySearchTree::deleteNode(int num, TreeNode *&nodePtr)
{
    if (num < nodePtr->value)
    {
        deleteNode(num,nodePtr->leftNode);
    }
    
    else if(num > nodePtr->value)
    {
        deleteNode(num, nodePtr->rightNode);
    }
    
    else
    {
        makeDeletion(nodePtr);
    }
}

void BinarySearchTree::makeDeletion(TreeNode *&nodePtr)
{
    TreeNode *tempPtr = nullptr;
    
    if(nodePtr == nullptr)
    {
        cout<< "Cant delete an empty node."<< endl;
    }
    
    else if(nodePtr->rightNode == nullptr)
    {
        tempPtr = nodePtr;
        nodePtr = nodePtr->leftNode;
        delete tempPtr;
    }
    
    else if(nodePtr->leftNode == nullptr)
    {
        tempPtr = nodePtr;
        nodePtr = nodePtr->rightNode;
        delete tempPtr;
    }
    
    else
    {
        tempPtr = nodePtr->rightNode;
        
        while(tempPtr->leftNode)
        {
            tempPtr = tempPtr->leftNode;
        }
        
        tempPtr->leftNode = nodePtr->leftNode;
        tempPtr = nodePtr;
        nodePtr = nodePtr->rightNode;
        delete tempPtr;
    }
}

void BinarySearchTree::In_Order(TreeNode *nodePtr)const
{
    if(nodePtr)
    {
        In_Order(nodePtr->leftNode);
        cout<< nodePtr->value;
        cout<< endl;
        In_Order(nodePtr->rightNode);
    }
}

void BinarySearchTree::Pre_Order(TreeNode *nodePtr)const
{
    if(nodePtr)
    {
        cout<< nodePtr->value << endl;
        Pre_Order(nodePtr->leftNode);
        Pre_Order(nodePtr->rightNode);
    }
}

void BinarySearchTree::Post_Order(TreeNode *nodePtr)const
{
    if(nodePtr)
    {
        Post_Order(nodePtr->leftNode);
        Post_Order(nodePtr->rightNode);
        cout<< nodePtr->value << endl;
    }
}

bool BinarySearchTree::checkAVL(TreeNode *nodePtr) const
{
    if(nodePtr == nullptr)
    {
        return true;
    }
    
    int balance = getBalance(nodePtr);
    
    if(!(balance < 0 || balance > 1))
    {
        return false;
    }
    
    return checkAVL(nodePtr->leftNode) && checkAVL(nodePtr->rightNode);
}

int BinarySearchTree::getBalance(TreeNode *nodePtr) const
{
    return getHeight(nodePtr->leftNode) - getHeight(nodePtr->rightNode);
}

int BinarySearchTree::getHeight(TreeNode *nodePtr) const
{
    if (nodePtr == nullptr)
    {
        return false;
    }

    int leftHeight = getHeight(nodePtr->leftNode);
    int rightHeight = getHeight(nodePtr->rightNode);

    int max = leftHeight;//Setting max to equal leftHeight by default
    if (rightHeight > leftHeight)
    {
        max = rightHeight;
    }

    // Return the maximum height + 1 for the current node
    return max + 1;
}



//Public Functions
BinarySearchTree::BinarySearchTree()
{
    root = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
    destroySubTree(root);
}

void BinarySearchTree::insertNode(int num)
{
    TreeNode *newNode = nullptr;
    
    newNode = new TreeNode;
    newNode->value = num;
    newNode->leftNode = newNode->rightNode = nullptr;
    
    insert(root, newNode);
}

void BinarySearchTree::remove(int num)
{
    deleteNode(num, root);
}

void BinarySearchTree::displayInOrder() const
{
    In_Order(root);
}

void BinarySearchTree::displayPreOrder() const
{
    Pre_Order(root);
}

void BinarySearchTree::displayPostOrder() const
{
    Post_Order(root);
}

bool BinarySearchTree::isAVLTree() const
{
    return checkAVL(root);
}
