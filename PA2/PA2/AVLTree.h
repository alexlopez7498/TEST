#pragma once
#include "AVLNode.h"

using namespace std;

template <class T>
class AVLTree
{
public:

    AVLTree()
    {
        mpRoot = nullptr;
    }

    ~AVLTree()
    {
        delete mpRoot;
    }

    void insert(T data);

    int height();

    bool contains(T data);

    int validate();

private: 
    AVLNode<T>* mpRoot;
};

template<class T>
void AVLTree<T>::insert(T data)
{
    mpRoot = Insert(mpRoot, data);
}

template<class T>
int AVLTree<T>::height()
{
    return nodeHeight(mpRoot);
}

template<class T>
bool AVLTree<T>::contains(T data)
{
    return search(mpRoot, data);
}

template<class T>
int AVLTree<T>::validate()
{
    return checkBalance(mpRoot);
}

template <class T>
// function gets the nodes height
int nodeHeight(AVLNode<T>* root)
{
    int height = 0;
    if (root != nullptr)
    {
        height = root->getHeight();
    }
    return height;
}

template <class T>
// function gets the tree balance of the level
int treeBalance(AVLNode<T>* root)
{
    int balance = 0;
    int LHeight = 0;
    int RHeight = 0;
    LHeight = nodeHeight(root->getLeftPtr());
    RHeight = nodeHeight(root->getRightPtr());
    if (root != nullptr)
    {
        balance = LHeight - RHeight;
    }

    return balance;
}

template <class T>
// checks the balance of the whole tree
int checkBalance(AVLNode<T>* root)
{
    int balance = 0;
    int LHeight = 0;
    int RHeight = 0;
    if (root == nullptr)
    {
        return 1;
    }

    LHeight = nodeHeight(root->getLeftPtr());
    RHeight = nodeHeight(root->getRightPtr());
    balance = LHeight - RHeight;

    if (balance >= -1 && balance <= 1 && checkBalance(root->getLeftPtr()) && checkBalance(root->getRightPtr()))
    {
        return 1;
    }

    return 0;
}

template <class T>
// function does a right rotation 
AVLNode<T>* rightRotation(AVLNode<T>* root)
{
    int LLHeight = 0;
    int LRHeight = 0;
    int newLHeight = 0;
    int newRHeight = 0;
    AVLNode<T>* nextRoot = root->getLeftPtr();
    AVLNode<T>* mpTemp = nextRoot->getRightPtr();

    nextRoot->setRightPtr(root);
    root->setLeftPtr(mpTemp);

    if (root == nullptr)
    {
        return root;
    }


    if (root->getLeftPtr() != nullptr)
    {
        LLHeight = root->getLeftPtr()->getHeight();
    }
    else
    {
        LLHeight = -1;
    }

    if (root->getRightPtr() != nullptr)
    {
        LRHeight = root->getRightPtr()->getHeight();
    }
    else
    {
        LRHeight = -1;
    }

    if (LLHeight > LRHeight)
    {
        root->setHeight(1 + LLHeight);
    }
    else
    {
        root->setHeight(1 + LRHeight);
    }



    if (nextRoot->getLeftPtr() != nullptr)
    {
        newLHeight = nextRoot->getLeftPtr()->getHeight();
    }
    else
    {
        newLHeight = -1;
    }

    if (nextRoot->getRightPtr() != nullptr)
    {
        newRHeight = nextRoot->getRightPtr()->getHeight();
    }
    else
    {
        newRHeight = -1;
    }

    if (newLHeight > newRHeight)
    {
        nextRoot->setHeight(1 + newLHeight);
    }
    else
    {
        nextRoot->setHeight(1 + newRHeight);
    }

    return nextRoot;
}

template <class T>
// left rotation of tree
AVLNode<T>* leftRotation(AVLNode<T>* root)
{
    int RLHeight = 0;
    int RRHeight = 0;
    int newLHeight = 0;
    int newRHeight = 0;
    AVLNode<T>* nextRoot = root->getRightPtr();
    AVLNode<T>* mpTemp = nextRoot->getLeftPtr();

    nextRoot->setLeftPtr(root);
    root->setRightPtr(mpTemp);

    if (root == nullptr)
    {
        return root;
    }

    if (root->getLeftPtr() != nullptr)
    {
        RLHeight = root->getLeftPtr()->getHeight();
    }
    else
    {
        RLHeight = -1;
    }

    if (root->getRightPtr() != nullptr)
    {
        RRHeight = root->getRightPtr()->getHeight();
    }
    else
    {
        RRHeight = -1;
    }

    if (RLHeight > RRHeight)
    {
        root->setHeight(1 + RLHeight);
    }
    else
    {
        root->setHeight(1 + RRHeight);
    }

    if (nextRoot->getLeftPtr() != nullptr)
    {
        newLHeight = nextRoot->getLeftPtr()->getHeight();
    }
    else
    {
        newLHeight = -1;
    }

    if (nextRoot->getRightPtr() != nullptr)
    {
        newRHeight = nextRoot->getRightPtr()->getHeight();
    }
    else
    {
        newRHeight = -1;
    }

    if (newLHeight > newRHeight)
    {
        nextRoot->setHeight(1 + newLHeight);
    }
    else
    {
        nextRoot->setHeight(1 + newRHeight);
    }

    return nextRoot;
}


template <class T>
AVLNode<T>* Insert(AVLNode<T>* root, T data)
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
        root->setLeftPtr(Insert(root->getLeftPtr(), data));
    }
    else if (data > root->getData())
    {
        root->setRightPtr(Insert(root->getRightPtr(), data));
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

    balance = treeBalance(root);

    // Left Left Case 
    if (balance > 1)
    {
        if (data < root->getLeftPtr()->getData())
        {
            return rightRotation(root);
        }
        else
        {
            root->setLeftPtr(leftRotation(root->getLeftPtr()));
            return rightRotation(root);
        }
    }

    // Right Right Case
    if (balance < -1)
    {
        if (data > root->getRightPtr()->getData())
        {
            return leftRotation(root);
        }
        else
        {
            root->setRightPtr(rightRotation(root->getRightPtr()));
            return leftRotation(root);
        }
    }

    return root;
}

template <class T>
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
    if (root->getData() > data)
    {
        return search(root->getLeftPtr(), data);
    }
    if (root->getData() < data)
    {
        return search(root->getRightPtr(), data);
    }
}
