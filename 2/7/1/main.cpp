#include "bagtest.h"

int main()
{
    BagTest tester;
    QTest::qExec(&tester);

    return 0;
}
