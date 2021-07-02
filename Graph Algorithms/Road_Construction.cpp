#include <bits/stdc++.h>
#include <iostream>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define endl '\n'
#define int long long
//#define ordered_set(type) __gnu_pbds::tree<type, __gnu_pbds::null_type, less<type>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>
#define forab(ii, aa, bb) for (int ii = aa; ii < bb; ii++)
#define forabd(ii, aa, bb) for (int ii = aa; ii >= bb; ii--)
#define forabi(ii, aa, bb, inc) for (int ii = aa; ii < bb; ii += inc)
#define forabdi(ii, aa, bb, inc) for (int ii = aa; ii >= bb; ii -= inc)
#define all(aa) aa.begin(), aa.end()
#define rall(aa) aa.rbegin(), aa.rend()
#define twodi(type, name, NN, MM, II) vector<vector<type>> name(NN, vector<type>(MM, II))
#define twod(type, name, NN, MM) vector<vector<type>> name(NN, vector<type>(MM))
#define threedi(type, name, NN, MM, LL, II) vector<vector<vector<type>>> name(NN, vector<vector<type>>(MM, vector<type>(LL, II)))
#define threed(type, name, NN, MM, LL) vector<vector<vector<type>>> name(NN, vector<vector<type>>(MM, vector<type>(LL)))
#define PL cout << endl
#define PS(aa) cout << #aa << ' ' << aa << ' '
#define PSL(aa)               \
    cout << #aa << ' ' << aa; \
    PL;
#define print(vv)          \
    for (auto &ii : vv)    \
        cout << ii << ' '; \
    PL;
#define print2d(vv)            \
    for (auto &row : vv)       \
    {                          \
        for (auto &ii : row)   \
            cout << ii << ' '; \
        cout << endl;          \
    }
#define printp(vv) cout << "{" << vv.firt << "," << vv.second << "} "
#define printn(vv, NN)                      \
    forab(ii, 0, NN) cout << vv[ii] << ' '; \
    PL;
#define invec(type, vv, NN) \
    vector<type> vv(NN);    \
    for (auto &ii : vv)     \
        cin >> ii;
void debug()
{
    PL;
}
template <typename T, typename... Types>
void debug(T var1, Types... var2)
{
    cout << var1 << " ";
    debug(var2...);
}
/* TEMPLATE END */
int N, M, a, b;
const int NMAX = 1e5 + 10;
array<vector<int>, NMAX> adj;
array<bool, NMAX> vis;
array<int, NMAX> parent;
int dfs(int node, int curr_parent)
{
    vis[node] = true;
    int ans = 1;
    parent[node] = curr_parent;
    for (int next : adj[node])
    {
        if (!vis[next])
            ans += dfs(next, curr_parent);
    }
    return ans;
}
list<list<int>> components;
array<list<list<int>>::iterator, NMAX> mp;
void solve()
{
    cin >> N >> M;
    int number_of_components = N;
    int max_size_of_component = 1;
    forab(i, 1, N + 1)
    {
        components.push_front({i});
        mp[i] = components.begin();
    }
    // cout << "YES" << endl;
    forab(i, 1, M + 1)
    {
        cin >> a >> b;
        if (mp[a] != mp[b]) //components merge
        {
            number_of_components--;

            if ((*mp[a]).size() > (*mp[b]).size())
                swap(a, b);

            auto list_a_it = mp[a];
            auto list_b_it = mp[b];
            auto &list_a = (*mp[a]);
            auto &list_b = (*mp[b]);

            list_b.insert(list_b.end(), all(list_a));

            for (int &i : list_a)
                mp[i] = list_b_it;

            components.erase(list_a_it);

            max_size_of_component = max(max_size_of_component, (int)list_b.size());
        }
        cout << number_of_components << " " << max_size_of_component << endl;
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