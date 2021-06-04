#include <iostream>
#include <bits/stdc++.h>

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#undef INT_MAX
#define INT_MAX LLONG_MAX
#define endl '\n'
#define int long long
#define forab(ii, aa, bb) for (int ii = aa; ii < bb; ii++)
#define forabd(ii, aa, bb) for (int ii = aa; ii >= bb; ii--)
#define forabi(ii, aa, bb, inc) for (int ii = aa; ii < bb; ii += inc)
#define all(aa) aa.begin(), aa.end()
#define rall(aa) aa.rbegin(), aa.rend()
#define twodi(type, name, NN, MM, II) vector<vector<type>> name(NN, vector<type>(MM, II));
#define twod(type, name, NN, MM) vector<vector<type>> name(NN, vector<type>(MM));
#define threedi(type, name, NN, MM, LL, II) vector<vector<vector<type>>> name(NN, vector<vector<type>>(MM, vector<type>(LL, II)));
#define threed(type, name, NN, MM, LL) vector<vector<vector<type>>> name(NN, vector<vector<type>>(MM, vector<type>(LL)));
#define PL cout << endl
#define PS(aa) cout << #aa << ' ' << aa << ' ';
#define PSL(aa)               \
    cout << #aa << ' ' << aa; \
    PL;
#define print(vv)          \
    for (auto &ii : vv)    \
        cout << ii << ' '; \
    PL;
#define printn(vv, NN)                      \
    forab(ii, 0, NN) cout << vv[ii] << ' '; \
    PL;
#define invec(type, vv, NN) \
    vector<type> vv(NN);    \
    for (auto &ii : vv)     \
        cin >> ii;

using namespace std;
int N, K;
struct CircularQueue
{
    int data;
    CircularQueue *next, *prev;
};
CircularQueue *giveNode(int num)
{
    CircularQueue *node = new CircularQueue();
    node->data = num;
    node->next = NULL;
    node->prev = NULL;
    return node;
}
void solve()
{
    cin >> N >> K;
    // K++;
    if (N == 1)
    {
        cout << 1 << endl;
        return;
    }
    vector<CircularQueue *> vec;
    forab(i, 1, N + 1)
    {
        vec.push_back(giveNode(i));
    }
    forab(i, 0, N)
    {
        vec[i]->next = vec[(i + 1 + N) % N];
        vec[i]->prev = vec[(i - 1 + N) % N];
    }
    int sz = N;
    int k = (K) % N;
    CircularQueue *node = vec[k];
    CircularQueue *prev;
    CircularQueue *next;
    while (N--)
    {
        cout << node->data << " ";
        prev = node->prev;
        next = node->next;
        prev->next = next;
        next->prev = prev;
        node = next;
        while (k--)
            node = node->next;
        if (N)
            k = (K) % N;
    }
}
int32_t main()
{
    IOS;
    // int T;
    // cin >> T;
    // while (T--)
    solve();
    return 0;
}