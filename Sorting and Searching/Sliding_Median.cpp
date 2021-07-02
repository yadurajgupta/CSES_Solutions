#include <bits/stdc++.h>
#include <iostream>

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define endl "\n"
#define int long long
#define all(a) a.begin(), a.end()

using namespace std;
int N, i, T, K;
void balance(multiset<int> &lower, multiset<int> &upper, int K)
{
    while (lower.size() > upper.size() + K % 2)
    {
        upper.insert(*lower.rbegin());
        lower.erase(prev(lower.end()), lower.end());
    }
    while (lower.size() < upper.size())
    {
        lower.insert(*upper.begin());
        upper.erase(upper.begin(), next(upper.begin()));
    }
}
void show(multiset<int> &st)
{
    for (int i : st)
        cout << i << " ";
    cout << endl;
}
void del(multiset<int> &lower, multiset<int> &upper, int val, int K)
{
    auto it = lower.find(val);
    if (it != lower.end())
        lower.erase(it);
    else
        upper.erase(upper.find(val));
    balance(lower, upper, K);
}
void insert(multiset<int> &lower, multiset<int> &upper, int val, int K)
{
    if (val <= (*lower.rbegin()))
        lower.insert(val);
    else
        upper.insert(val);
    balance(lower, upper, K);
}
void solve()
{
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    if (K == 1)
    {
        for (int i : A)
            cout << i << " ";
        cout << endl;
        return;
    }
    multiset<int> lower, upper;
    i = 0;
    for (; i < K; i++)
    {
        lower.insert(A[i]);
    }

    balance(lower, upper, K);
    // show(lower);
    // show(upper);
    cout << (*lower.rbegin()) << " ";
    for (; i < N; i++)
    {
        del(lower, upper, A[i - K], K);
        insert(lower, upper, A[i], K);
        // show(lower);
        // show(upper);
        cout << (*lower.rbegin()) << " ";
    }
    cout << endl;
}
int32_t main()
{
    IOS
    // cin>>T;
    // while(T--)
    solve();
    return 0;
}