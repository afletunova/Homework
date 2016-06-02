#include "sharedpointertest.h"

int main()
{
    SharedPointerTest tester;
    QTest::qExec(&tester);

    return 0;
}
