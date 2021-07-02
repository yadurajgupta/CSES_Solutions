#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#undef INT_MAX
#define INT_MAX LLONG_MAX
#define endl '\n'
#define int long long
#define ordered_set(type) __gnu_pbds::tree<type, __gnu_pbds::null_type, less<type>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>
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
int N, M;
vector<int> find_ans(vector<pair<int, int>> &v1, vector<pair<int, int>> &v2)
{
    for (auto &[i1, i2] : v1)
    {
        for (auto &[i3, i4] : v2)
        {
            if (i1 == i3 || i1 == i4 || i2 == i3 || i2 == i4)
                continue;
            else
            {
                vector<int> v{i1, i2, i3, i4};
                sort(all(v));
                return v;
            }
        }
    }
    return {};
}
void solve()
{
    cin >> N >> M;
    if (N <= 3)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    invec(int, A, N);
    map<int, vector<pair<int, int>>> sum2;
    forab(i, 0, N)
    {
        forab(j, i + 1, N)
        {
            sum2[A[i] + A[j]].push_back({i + 1, j + 1});
        }
    }
    for (auto &[sum, vec1] : sum2)
    {
        int comp = M - sum;
        if (sum2.count(comp))
        {
            auto &vec2 = sum2[comp];
            auto ans = find_ans(vec1, vec2);
            if (!ans.empty())
            {
                print(ans);
                return;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
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