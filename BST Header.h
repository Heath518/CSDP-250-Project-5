#ifndef BST_Header_h
#define BST_Header_h
#include <iostream>

using namespace std;

class BinarySearchTree
{
private:
    struct TreeNode
    {
        int value;
        TreeNode *leftNode;
        TreeNode *rightNode;
    };
    
    TreeNode *root;
    
    void insert(TreeNode *&, TreeNode *&);
    void destroySubTree(TreeNode *);
    void deleteNode(int, TreeNode *&);
    void makeDeletion(TreeNode *&);
    void In_Order(TreeNode *)const;
    void Pre_Order(TreeNode *)const;
    void Post_Order(TreeNode *)const;
    bool checkAVL(TreeNode *node) const;
    int getBalance(TreeNode *node) const;
    int getHeight(TreeNode *node) const;
    
public:
    BinarySearchTree();
    ~BinarySearchTree();
    void insertNode(int);
    void remove(int);
    void displayInOrder() const;
    void displayPreOrder() const;
    void displayPostOrder() const;
    bool isAVLTree() const;
};

#endif /* BST_Header_h */
