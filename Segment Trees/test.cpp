/*
Probelem Statement
You are given a sequence A[1], A[2], ..., A[N] . ( |A[i]| ≤ 15007 , 1 ≤ N ≤ 50000 ). A query is defined as follows:
Query(x,y) = Max { a[i]+a[i+1]+...+a[j] ; x ≤ i ≤ j ≤ y }.
Given M queries, your program must output the results of these queries.

Input
The first line of the input file contains the integer N.
In the second line, N numbers follow.
The third line contains the integer M.
M lines follow, where line i contains 2 numbers xi and yi.
Output
Your program should output the results of the M queries, one query per line.


Test cases: 
Input:
3 
-1 2 3
1
1 2

Output:
2
*/

#include <bits/stdc++.h>
#include "segment_tree.h"
#define ll long long
using namespace std;

struct node
{
    int ans;
    int tot;
    int pref;
    int suf;
    node() {}
    node(int val) { tot = ans = pref = suf = val; }
};
node combine(node x, node y)
{
    node *ptr = new node();
    ptr->ans = max(x.ans, y.ans);
    ptr->ans = max(ptr->ans, y.pref + x.suf);
    ptr->pref = max(x.tot + y.pref, x.pref);
    ptr->suf = max(y.tot + x.suf, y.suf);
    ptr->tot = x.tot + y.tot;
    return *ptr;
}
int main()
{
    int t, i, j, n, ans;
    cin >> n;
    vector<node> v(n);
    for (i = 0; i < n; i++)
    {
        cin >> j;
        v[i] = node(j);
    }
    SegmentTree<node> sg(v, node(-20000), combine);
    cin >> n;
    while (n--)
    {
        cin >> i >> j;
        node as = sg.query(i - 1, j - 1);
        cout << (as.ans) << endl;
    }
    return 0;
}
