#include "sharedpointer.h"

#include <QtTest/QTest>
#include <QtCore/QObject>

class SharedPointerTest : public QObject
{
    Q_OBJECT

private slots:
    void copyConstructorTest()
    {
        SharedPointer<int> pointer(new int(42));
        SharedPointer<int> newPointer(pointer);
        QCOMPARE(*pointer, *newPointer);
    }

    void dereferenceTest()
    {
        SharedPointer<int> pointer(new int(42));
        QCOMPARE(*pointer, 42);
    }

    void copeOperatorTest()
    {
        SharedPointer<int> pointer(new int(42));
        SharedPointer<int> newPointer = pointer;
        QCOMPARE(*pointer, *newPointer);
    }

    void getTest()
    {
        SharedPointer<int> pointer(new int(42));
        SharedPointer<int> newPointer(new int(41));
        newPointer = pointer;
        QCOMPARE(pointer.get(), newPointer.get());
    }

    void useCountTest()
    {
        SharedPointer<int> pointer(new int(42));
        SharedPointer<int> newPointer(pointer);
        QCOMPARE(newPointer.useCount(), 2);
    }
};
