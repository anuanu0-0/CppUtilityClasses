#include <iostream>
#include "MinStack.h"
#include "MinQueue.h"
using namespace std;

int main()
{

    /** STACK**/
    MinStack<int> s;
    s.push(3);
    s.push(2);
    s.push(1);
    s.push(6);
    s.push(5);
    s.push(4);

    s.pop();

    cout << " Element at top of Stack: " << s.top() << endl;
    cout << "Min elemenet in stack : " << s.getMin() << endl;
    cout << "Is Stack Empty? : " << s.empty() << endl;

    while (!s.empty())
    {
        cout << " " << s.top();
        s.pop();
    }

    /*  Queue */
    MinQueue<int> q;
    q.push(3);
    q.push(2);
    q.push(1);
    q.push(6);
    q.push(5);
    q.push(4);

    q.pop();

    cout << " Element at top : " << q.top() << endl;
    cout << "Min elemenet in queue : " << q.getMin() << endl;
    cout << "Is Queue Empty? : " << q.empty() << endl;
    while (!q.empty())
    {
        cout << " " << q.top();
        q.pop();
    }

    return 0;
}