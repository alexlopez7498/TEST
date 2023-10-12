#pragma once

#include <iostream>
#include <cstdlib>
#include <vector>
#include <iostream>     
#include <algorithm>    
#include <array>        
#include <random>       
#include <chrono> 

template <class T>
class AVLNode 
{
public:

    AVLNode(T newData) 
    {
        mpData = newData;
        mpLeft = nullptr;
        mpRight = nullptr;
        mHeight = 0;
    }

    ~AVLNode() 
    {
        delete mpLeft;
        delete mpRight;
    }

    T& getData();

    void setData(const T& newData);

    AVLNode<T>* getLeftPtr() const;

    AVLNode<T>* getRightPtr() const;

    void setLeftPtr(AVLNode<T>* newLeft);

    void setRightPtr(AVLNode<T>* newRight);

    int getHeight();

    void setHeight(int newHeight);


private:

    T mpData;
    AVLNode<T>* mpLeft;
    AVLNode<T>* mpRight;
    int mHeight;
};

template<class T>
// the function gets the data of the node
T& AVLNode<T>::getData()
{
    return mpData;
}

template<class T>
// the function sets the data of the node
void AVLNode<T>::setData(const T& newData)
{
    mpData = newData;
}

template<class T>
// the function gets the left ptr of the node
AVLNode<T>* AVLNode<T>::getLeftPtr() const
{
    return mpLeft;
}

template<class T>
// the function gets the right ptr of the node
AVLNode<T>* AVLNode<T>::getRightPtr() const
{
    return mpRight;
}

template<class T>
// the function sets the left ptr of the node
void AVLNode<T>::setLeftPtr(AVLNode<T>* newLeft)
{
    mpLeft = newLeft;
}

template<class T>
// the function sets the right ptr of the node
void AVLNode<T>::setRightPtr(AVLNode<T>* newRight)
{
    mpRight = newRight;
}

template<class T>
// the function gets the height
int AVLNode<T>::getHeight()
{
    return mHeight;
}

template<class T>
// the function sets the height
void AVLNode<T>::setHeight(int newHeight)
{
    mHeight = newHeight;
}
