#include <iostream>
#include "dsu.h"
using namespace std;

int main()
{
    DSU dsuTest(5);
    dsuTest.Union(0, 1);
    dsuTest.Union(4, 2);
    dsuTest.Union(3, 1);

    // Not Valid ID return -1
    cout << "ID : " << dsuTest.Find(8) << endl;
    // Valid ID
    cout << "ID : " << dsuTest.Find(4) << endl;

    // Check if 2 elements are in same group
    if (dsuTest.Find(2) == dsuTest.Find(1))
        cout << "Yes, 2 & 1 belong to same group" << endl;
    else
        cout << "No, 2 & 1 donot belong to same group" << endl;
        
    cout << "Count of Groups: " << dsuTest.getCountOfGroups() << endl;
    cout << "Group Size : " << dsuTest.groupSize(1) << endl;
    cout << "Valid ID ? :" << dsuTest.isValidId(3) << endl;

    return 0;
}