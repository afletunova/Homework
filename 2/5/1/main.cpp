#include <iostream>
#include <fstream>
#include "tree.h"
#include "treetest.h"

using namespace std;

const int size = 20;
const int length = 512;

int main()
{
    char fileName[size];
    cout << "Enter name of file." << endl;
    cin >> fileName;
    ifstream file(fileName);

    if (file)
    {
        string expression;
        getline(file, expression);

        Tree *tree = new Tree(QString::fromStdString(expression));

        tree->print();
        cout << " " << tree->compute();

        delete tree;
    }

    TreeTest tester;
    QTest::qExec(&tester);

    return 0;
}
