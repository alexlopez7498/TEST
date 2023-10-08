#pragma once

#include <iostream>
#include <cstdlib>
#include <vector>
#include <iostream>     
#include <algorithm>    
#include <array>        
#include <random>       
#include <chrono> 

using namespace std;

template <class T>
class AVLNode {
public:

    AVLNode(T data) 
    {
        mpData = data;
        mpLeft = NULL;
        mpRight = NULL;
        mHeight = 1;
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
T& AVLNode<T>::getData()
{
    return mpData;
}

template<class T>
void AVLNode<T>::setData(const T& newData)
{
    mpData = newData;
}

template<class T>
AVLNode<T>* AVLNode<T>::getLeftPtr() const
{
    return mpLeft;
}

template<class T>
AVLNode<T>* AVLNode<T>::getRightPtr() const
{
    return mpRight;
}

template<class T>
void AVLNode<T>::setLeftPtr(AVLNode<T>* newLeft)
{
    mpLeft = newLeft;
}

template<class T>
void AVLNode<T>::setRightPtr(AVLNode<T>* newRight)
{
    mpRight = newRight;
}

template<class T>
int AVLNode<T>::getHeight()
{
    return mHeight;
}

template<class T>
void AVLNode<T>::setHeight(int newHeight)
{
    mHeight = newHeight;
}
