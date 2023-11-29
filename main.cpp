//Heath Wright
//0001305281
//Project 5
//This project purpose is to generate 35 random numbers which needs to be saved in an array, constructed into a binary search tree, then displayed
//in InOrder DFS. After then which the program prompts the user which number from the BST they want to delete and display the updated tree in
//PostOrder DFS and test to see if the tree is a AVL tree.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "BST Header.h"
using namespace std;

int main()
{
    const int size = 35;
    int count = 0;
    int randomNumbers[size];
    int num;
    
    BinarySearchTree tree;
    
    srand(static_cast<unsigned int>(time(nullptr)));
    
    for (int i = 0; i < size; i++)
    {
        randomNumbers[i] = rand() % 100;
        tree.insertNode(randomNumbers[i]);
        count++;
    }
    
    cout << "Random " << count << " Generated Numbers..." << endl;
    for (int i = 0; i < size; i++)
    {
        cout << randomNumbers[i] << endl;
    }
    cout<< "InOrder traversal:" << endl;
    tree.displayInOrder();
    cout<< endl;

    do
    {
        cout << "Out of all 35 numbers, which number would you like to delete." << endl;
        cin >> num;
        cout << endl;
        
        if(num < 0)
        {
            cout << "There are no negative numbers generated, please try again." << endl;
            cout << endl;
        }
        
    }while(num < 0);
    
    tree.remove(num);
    
    cout << "Deleting " << num << endl;
    cout << "PostOrder traversal:" << endl;
    tree.displayPostOrder();
    
    if(tree.isAVLTree() == true)
    {
        cout << "This is a balanced AVL Tree." << endl;
    }
    
    else
    {
        cout << "This is not a balanced AVL Tree." << endl;
    }
    
    return 0;
}
