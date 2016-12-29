#include <iostream>
#include "priorityqueue.h"

using namespace std;

int main()
{
    int answer = 0;
    bool correctAnswer = false;
    bool toExit = false;
    PriorityQueue<int> *queue = new PriorityQueue<int>;
    while (!toExit)
    {
        cout << "Enter 1 to add new element in queue, or 2 to get a top priority element. Enter 0 to exit:" << endl;
        cin >> answer;
        if (answer == 0)
        {
            toExit = true;
        }
        else if (answer == 1)
        {
            int value = 0;
            int priority = 0;
            cout << "Enter a value ang priority" << endl;
            cin >> value >> priority;
            queue->enqueue(value, priority);
            correctAnswer = true;
        }
        else if (answer == 2)
        {
            cout << "Element with a top priority: " << queue->dequeue() << endl;
            correctAnswer = true;
        }
        if (!correctAnswer)
        {
            cout << "Incorrect answer. Try again.\n Enter 1 to add new element in queue, or 2 to get a top priority element:" << endl;
            cin >> answer;
        }
    }

    return 0;
}
