#include "vectortest.h"

int main()
{
    VectorTest tester;
    QTest::qExec(&tester);

    return 0;
}
