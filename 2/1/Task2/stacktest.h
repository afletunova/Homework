#pragma once

#include "stack.h"
#include "pointerstack.h"
#include "arraystack.h"

#include <QtCore/QObject>
#include <QtTest/QtTest>

class StackTest : public QObject
{
    Q_OBJECT

private:
    Stack<int> *stack = nullptr;

private slots:
    void testEmptyArrayStack()
    {
        stack = new ArrayStack;
        QVERIFY(stack->getSize() == 0);
    }

    void testEmptyPointerStack()
    {
        stack = new PointerStack<int>;
        QVERIFY(stack->getSize() == 0);
    }

    void testPushSingleElementToArrayStack()
    {
        stack = new ArrayStack;
        stack->push(5);
        QVERIFY(stack->getSize() == 1);
    }

    void testPushSingleElementToPointerStack()
    {
        stack = new PointerStack<int>;
        stack->push(5);
        QVERIFY(stack->getSize() == 1);
    }

    void testPushMoreThanOneElementToArrayStack()
    {
        stack = new ArrayStack;
        int n = 5;
        for (int i = 0; i < n; ++i)
        {
            stack->push(i);
        }
        QVERIFY(stack->getSize() == n);
    }

    void testPushMoreThanOneElementToPointerStack()
    {
        stack = new PointerStack<int>;
        int n = 5;
        for (int i = 0; i < n; ++i)
        {
            stack->push(i);
        }
        QVERIFY(stack->getSize() == n);
    }

    void testPopSingleElementFromArrayStack()
    {
        stack = new ArrayStack;
        stack->push(5);
        stack->pop();
        QVERIFY(stack->getSize() == 0);
    }

    void testPopSingleElementFromPointerStack()
    {
        stack = new PointerStack<int>;
        stack->push(5);
        stack->pop();
        QVERIFY(stack->getSize() == 0);
    }

    void testPopMoreThanOneElementFromArrayStack()
    {
        stack = new ArrayStack;
        int n = 5;
        for (int i = 0; i < n; ++i)
        {
            stack->push(i);
        }
        int m = 3;
        for (int i = 0; i < m; ++i)
        {
            stack->pop();
        }
        QVERIFY(stack->getSize() == n - m);
    }

    void testPopMoreThanOneElementFromPointerStack()
    {
        stack = new PointerStack<int>;
        int n = 5;
        for (int i = 0; i < n; ++i)
        {
            stack->push(i);
        }
        int m = 3;
        for (int i = 0; i < m; ++i)
        {
            stack->pop();
        }
        QVERIFY(stack->getSize() == n - m);
    }
};

QTEST_MAIN(StackTest);
