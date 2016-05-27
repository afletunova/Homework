#include "settest.h"

int main()
{
    SetTest tester;
    QTest::qExec(&tester);

    return 0;
}

