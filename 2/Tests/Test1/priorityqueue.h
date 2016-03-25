#pragma once
#include <iostream>

using namespace std;

template <typename T>
/**
 * @brief The PriorityQueue class priority queue
 */
class PriorityQueue
{
public:
    PriorityQueue();
    void enqueue(T value, int key); ///< Get value and its priority
    T dequeue(); ///< Returns value with top priority
    ~PriorityQueue();
private:
    class ElementOfQueue
    {
    public:
        ElementOfQueue()
        {}
        ElementOfQueue(T value, int key)
            :value(value), key(key), next(nullptr)
        {}
        T value;
        int key;
        ElementOfQueue *next;
        ~ElementOfQueue()
        {}
    };
    ElementOfQueue *top;
};

template <typename T>
PriorityQueue<T>::PriorityQueue()
    :top(nullptr)
{}

template <typename T>
void PriorityQueue<T>::enqueue(T value, int key)
{
    if (!top)
    {
        top = new ElementOfQueue(value, key);
    }
    else if (top->key < key)
    {
        ElementOfQueue *auxiliary = new ElementOfQueue(value, key);
        auxiliary->next = top;
        top = auxiliary;
    }
    else
    {
        ElementOfQueue *element = top;
        if (element->next->key)
        {
            while (element->next->key > key)
            {
                element = element->next;
            }
        }
        ElementOfQueue *auxiliary = new ElementOfQueue(value, key);
        auxiliary->next = element->next;
        element->next = auxiliary;
    }
}

template <typename T>
T PriorityQueue<T>::dequeue()
{
    try
    {
        if (!top) throw 923;
    }
    catch(int error)
    {
        cout << "Error " << error << ": queue is empty." << endl;
        return error;
    }

    T output = top->value;
    if (top->next)
    {
        ElementOfQueue *auxiliary = top->next;
        delete top;
        top = auxiliary;
    }
    else
    {
        delete top;
    }
    return output;
}
