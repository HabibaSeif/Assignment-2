#ifndef QUEUE_H
#define QUEUE_H

#define SIZE 5
#include <iostream>
#include <stdio.h>
using namespace std;

template <class T>
class Queue
{
public:
    T A[SIZE];
    int F;
    int back;

    Queue()
    {
        F = back = -1;
    }
    Queue(const Queue & rhs) 
    {
        for (int i = 0; i < this->back; i++)
        {
            this->A[i] = rhs.A[i];
        }

        this->F = rhs.F;
        this->back = rhs.back;
    }
    bool empty()
    {
        return (F == -1 && back == -1);
    }

    bool full()
    {
        return (back == SIZE - 1);
    }

    void push(T x)
    {
        if (full())
        {
            cout << "It's full" << endl;
        }
        else
        {
            back++;
            A[back] = x;
        }
    }
   /* void pop()
    {
        if (empty() == true)
            cout << "its empty, error \n";
        else
        {
            for (int i=0;i<size-1;i++)
        }
    }*/
    void pop()
    {
        if (empty()==true)
        {
            cout << "It's empty" << endl;
        }
        else
        {
            for (int i = 0; i < (SIZE - 1); i++)
            {
                A[i] = A[i + 1];
            }

            back--;
        }
    }

    T front()
    {
        //cout << "front \n";
        if (empty())
        {
            cout << "its empty" << endl;
        }
        return A[0]; 
    }

    T front2(T temp)
    {
        A[0] = temp;
        return A[0];
    }
};
#endif