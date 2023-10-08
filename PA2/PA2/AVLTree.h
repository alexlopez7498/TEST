#pragma once
#include "AVLNode.h"

using namespace std;

template <class T>
class AVLTree
{
public:

    // constructor
    AVLTree()
    {
        mpRoot = NULL;
    }

    void insert(T data) 
    {
        mpRoot = insert(mpRoot, data);
    }

    int height()
    {
        return getHeightofNode(mpRoot);
    }

    bool contains(T data) 
    {
        return search(mpRoot, data);
    }

    int validate()
    {
        return checkBalance(mpRoot);
    }

    // destructor
    ~AVLTree() 
    {
        delete mpRoot;
    }

private: 
    AVLNode<T>* mpRoot;
    // return height of node
    int getHeightofNode(AVLNode<T>* root)
    {
        int height = 0;
        if (root != nullptr)
        {
           height = root->getHeight();
        }
        return height;
    }

    // return balace of a node
    int getBalanceOfNode(AVLNode<T>* root) 
    {
        int balance = 0;
        int LHeight = 0;
        int RHeight = 0;
        LHeight = getHeightofNode(root->getLeftPtr());
        RHeight = getHeightofNode(root->getRightPtr());
        if (root != nullptr)
        {
            balance = LHeight - RHeight;
        }

        return balance;
    }

    // right rotation of tree
    AVLNode<T>* rightRotate(AVLNode<T>* root)
    {
        int leftLeftHeight = 0;
        int leftRightHeight = 0;
        int newRootLeftHeight = 0;
        int newRootRightHeight = 0;
        if (root == nullptr) 
        {
            return nullptr; // Rotation is not possible with a null node
        }

        AVLNode<T>* newRoot = root->getLeftPtr();
        AVLNode<T>* temp = newRoot->getRightPtr();

        // Perform rotation
        newRoot->setRightPtr(root);
        root->setLeftPtr(temp);
        /////////////////////////////////////////////////////////////////////////
        if (root->getLeftPtr() != nullptr)
        {
            leftLeftHeight = root->getLeftPtr()->getHeight();
        }
        else
        {
            leftLeftHeight = -1; // 
        }
        /////////////////////////////////////////////////////////////////////////
        if (root->getRightPtr() != nullptr)
        {
            leftRightHeight = root->getRightPtr()->getHeight();
        }
        else
        {
            leftRightHeight = -1;
        }
        /////////////////////////////////////////////////////////////////////////
        if (leftLeftHeight > leftRightHeight)
        {
            root->setHeight(1 + leftLeftHeight);
        }
        else
        {
            root->setHeight(1 + leftRightHeight);
        }
        /////////////////////////////////////////////////////////////////////////
        if (newRoot->getLeftPtr() != nullptr)
        {
            newRootLeftHeight = newRoot->getLeftPtr()->getHeight();
        }
        else
        {
            newRootLeftHeight = -1;
        }
        /////////////////////////////////////////////////////////////////////////
        if (newRoot->getRightPtr() != nullptr)
        {
            newRootRightHeight = newRoot->getRightPtr()->getHeight();
        }
        else
        {
            newRootRightHeight = -1;
        }
        /////////////////////////////////////////////////////////////////////////
        if (newRootLeftHeight > newRootRightHeight)
        {
            newRoot->setHeight(1 + newRootLeftHeight);
        }
        else
        {
            newRoot->setHeight(1 + newRootRightHeight);
        }

        return newRoot;
    }


    // left rotation of tree
    AVLNode<T>* leftRotate(AVLNode<T>* root)
    {
        int rightLeftHeight = 0;
        int rightRightHeight = 0;
        int newRootLeftHeight = 0;
        int newRootRightHeight = 0;

        if (root == nullptr) {
            return nullptr; // Rotation is not possible with a null node
        }

        AVLNode<T>* newRoot = root->getRightPtr();
        AVLNode<T>* temp = newRoot->getLeftPtr();

        // Perform rotation
        newRoot->setLeftPtr(root);
        root->setRightPtr(temp);

        // Calculate heights
        /////////////////////////////////////////////////////////////////////////
        if (root->getLeftPtr() != nullptr)
        {
            rightLeftHeight = root->getLeftPtr()->getHeight();
        }
        else {
            rightLeftHeight = -1;
        }
        /////////////////////////////////////////////////////////////////////////
        if (root->getRightPtr() != nullptr) 
        {
            rightRightHeight = root->getRightPtr()->getHeight();
        }
        else 
        {
            rightRightHeight = -1;
        }
        /////////////////////////////////////////////////////////////////////////
        if (rightLeftHeight > rightRightHeight) 
        {
            root->setHeight(1 + rightLeftHeight);
        }
        else 
        {
            root->setHeight(1 + rightRightHeight);
        }
        /////////////////////////////////////////////////////////////////////////
        if (newRoot->getLeftPtr() != nullptr) 
        {
            newRootLeftHeight = newRoot->getLeftPtr()->getHeight();
        }
        else 
        {
            newRootLeftHeight = -1;
        }
        /////////////////////////////////////////////////////////////////////////
        if (newRoot->getRightPtr() != nullptr) 
        {
            newRootRightHeight = newRoot->getRightPtr()->getHeight();
        }
        else 
        {
            newRootRightHeight = -1;
        }
        /////////////////////////////////////////////////////////////////////////
        if (newRootLeftHeight > newRootRightHeight) 
        {
            newRoot->setHeight(1 + newRootLeftHeight);
        }
        else 
        {
            newRoot->setHeight(1 + newRootRightHeight);
        }

        return newRoot;
    }


    AVLNode<T>* insert(AVLNode<T>* root, T data)
    {

        int balance = 0;
        int LHeight = 0;
        int RHeight = 0;
        if (root == nullptr)
        {
            return new AVLNode<T>(data);
        }
        if (data < root->getData())
        {
            root->setLeftPtr(insert(root->getLeftPtr(), data));
        }
        else if (data > root->getData())
        {
            root->setRightPtr(insert(root->getRightPtr(), data));
        }
        else
        {
            return root;
        }

        if (root->getLeftPtr() != nullptr)
        {
            LHeight = root->getLeftPtr()->getHeight();
        }
        else
        {
            LHeight = -1;
        }

        if (root->getRightPtr() != nullptr)
        {
            RHeight = root->getRightPtr()->getHeight();
        }
        else
        {
            RHeight = -1;
        }

        if (LHeight > RHeight)
        {
            root->setHeight(1 + LHeight);
        }
        else
        {
            root->setHeight(1 + RHeight);
        }

        balance = getBalanceOfNode(root);

        // Left Left Case 
        if (balance > 1) 
        {
            if (data < root->getLeftPtr()->getData())
            {
                return rightRotate(root);
            }
            else
            {
                root->setLeftPtr(leftRotate(root->getLeftPtr()));
                return rightRotate(root);
            }
        }

        // Right Right Case 
        if (balance < -1) 
        {
            if (data > root->getRightPtr()->getData())
            {
                return leftRotate(root);
            }
            else
            {
                root->setRightPtr(rightRotate(root->getRightPtr()));
                return leftRotate(root);
            }
        }

        return root;
    }

    int search(AVLNode<T>* root, T data) 
    {
        if (root == nullptr)
        {
            return 0;
        }
        if (root->getData() == data)
        {
            return 1;
        }
        if(root->getData() > data)
        {
            return search(root->getLeftPtr(), data);
        }
        if (root->getData() < data)
        {
            return search(root->getRightPtr(), data);
        }
    }

    int checkBalance(AVLNode<T>* root) 
    {
        int balance = 0;
        int LHeight = 0;
        int RHeight = 0;
        if (root == nullptr) 
        {
            return 1; // An empty tree is balanced
        }

        // Get the heights of the left and right subtrees
        LHeight = getHeightofNode(root->getLeftPtr());
        RHeight = getHeightofNode(root->getRightPtr());
        balance = LHeight - RHeight;

        // Check if the current node is balanced and its subtrees are balanced
        if (balance >= -1 && balance <= 1 && checkBalance(root->getLeftPtr()) && checkBalance(root->getRightPtr()))
        {
            return 1;
        }

        // If any of the conditions fail, the tree is not balanced
        return 0;
    }


};