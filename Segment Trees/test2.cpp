/*
 Problem Statement
You are given a sequence A[1], A[2], ..., A[N] ( 0 ≤ A[i] ≤ 10^8 , 2 ≤ N ≤ 10^5 ). There are two types of operations and they are defined as follows:
Update:
This will be indicated in the input by a 'U' followed by space and then two integers i and x.
U i x, 1 ≤ i ≤ N, and x, 0 ≤ x ≤ 10^8.
This operation sets the value of A[i] to x.

Query:
This will be indicated in the input by a 'Q' followed by a single space and then two integers i and j.
Q x y, 1 ≤ x < y ≤ N.
You must find i and j such that x ≤ i, j ≤ y and i != j, such that the sum A[i]+A[j] is maximized. Print the sum A[i]+A[j].

Input
The first line of input consists of an integer N representing the length of the sequence. Next line consists of N space separated integers A[i]. Next line contains an integer Q, Q ≤ 10^5, representing the number of operations. Next Q lines contain the operations.

Output
Output the maximum sum mentioned above, in a separate line, for each Query.

TEST CASES
Input:
5
1 2 3 4 5
6
Q 2 4
Q 2 5
U 1 6
Q 1 5
U 1 7
Q 1 5

Output:
7
9
11
12

*/

#include <bits/stdc++.h>
#include "segment_tree.h"
#define ll long long
using namespace std;

struct node
{
    node(int x, int y) : m1(x), m2(y) {}
    node() {}
    int m1, m2;
};

node combine(node x, node y)
{
    node temp;
    vector<int> s = {x.m1, x.m2, y.m1, y.m2};
    sort(s.begin(), s.end(), greater<int>());
    temp.m1 = s[0];
    temp.m2 = s[1];
    return temp;
}

int main()
{

    int n, i, j, q;
    cin >> n;
    vector<node> ar(n);

    for (int i = 0; i < n; i++)
    {
        cin >> ar[i].m1;
        ar[i].m2 = INT_MIN;
    }
    node smallest(INT_MIN, INT_MIN);

    SegmentTree<node> sg(ar, smallest, combine);

    cin >> q;
    while (q--)
    {
        char ch;
        int x, y;
        cin >> ch >> x >> y;
        if (ch == 'Q')
        {
            node ans = sg.query(x - 1, y - 1);
            cout << ans.m1 + ans.m2 << '\n';
        }
        else
        {
            node upd(y, INT_MIN);
            sg.update(x - 1, upd);
        }
    }
    return 0;
}