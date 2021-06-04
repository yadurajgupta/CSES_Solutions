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
int N, M, x, y;
void get_ans(int index_small, int index_large, int index_old_small, int index_old_large, map<pair<int, int>, int> &ans)
{
    if ((index_small > index_large) == (index_old_small > index_old_large))
        return;
    else if (index_old_small < index_old_large)
        ans[{index_old_small, index_old_large}] = 1;
    else
        ans[{index_old_small, index_old_large}] = -1;
}
int get_new_index(int num, int n1, int n2, vector<int> &mp)
{
    if (num == n1)
        return mp[n2];
    if (num == n2)
        return mp[n1];
    return mp[num];
}
void solve()
{
    cin >> N >> M;
    invec(int, A, N);
    vector<int> mp(N + 1);
    forab(i, 0, N)
        mp[A[i]] = i;
    int round = 1;
    forab(i, 2, N + 1)
    {
        if (mp[i] < mp[i - 1])
            round++;
    }
    forab(i, 0, M)
    {
        // print(A);
        map<pair<int, int>, int> ans;
        cin >> x >> y;
        --x;
        --y;
        if (x == y)
        {
            cout << round << endl;
            continue;
        }
        int n1 = A[x];
        int n2 = A[y];
        if (n1 - 1 >= 1)
            get_ans(get_new_index(n1 - 1, n1, n2, mp), get_new_index(n1, n1, n2, mp), mp[n1 - 1], mp[n1], ans);
        if (n1 + 1 <= N)
            get_ans(get_new_index(n1, n1, n2, mp), get_new_index(n1 + 1, n1, n2, mp), mp[n1], mp[n1 + 1], ans);
        if (n2 - 1 >= 1)
            get_ans(get_new_index(n2 - 1, n1, n2, mp), get_new_index(n2, n1, n2, mp), mp[n2 - 1], mp[n2], ans);
        if (n2 + 1 <= N)
            get_ans(get_new_index(n2, n1, n2, mp), get_new_index(n2 + 1, n1, n2, mp), mp[n2], mp[n2 + 1], ans);

        for (auto p : ans)
        {
            round += p.second;
        }
        swap(A[x], A[y]);
        swap(mp[n2], mp[n1]);
        cout << round << endl;
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