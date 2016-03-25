#pragma once

#include "priorityqueue.h"

#include <QtCore/QObject>
#include <QtTest/QtTest>

/**
 * @brief The QueueTest class test with PriorityQueue<int> class
 */

class QueueTest : public QObject
{
    Q_OBJECT

private:
    PriorityQueue<int> *queue = nullptr;

private slots:
    void testEmptyQueue()
    {
        queue = new PriorityQueue<int>;
        QVERIFY(queue->dequeue() == 923);
    }

    void testQueueWithOneElement()
    {
        queue = new PriorityQueue<int>;
        queue->enqueue(7, 9);
        QCOMPARE(queue->dequeue(), 7);
    }

    void testQueueWithTwoElement()
    {
        queue = new PriorityQueue<int>;
        queue->enqueue(8, 3);
        queue->enqueue(3, 9);
        QCOMPARE(queue->dequeue(), 3);
    }
};
