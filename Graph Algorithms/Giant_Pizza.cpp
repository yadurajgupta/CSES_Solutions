#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define endl '\n'
#define int long long
#define ordered_set(type) __gnu_pbds::tree<type, __gnu_pbds::null_type, less<type>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>
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
int N, M, x;
char c;
const int NMAX = 1e5 + 10;

struct two_sat
{
    vector<vector<int>> adj;
    vector<vector<int>> rev_adj;
    vector<bool> vis;
    vector<int> scc_ids;
    int nodes;
    vector<int> topo;
    bool scc_done = false;
    bool topo_done = false;
    //first prob of 2SAT ( (a1 or a2) & (a3 or a4)& () ...)
    // if you want to make a true a -> a||a -> !a->a add this edge (same can be done for !a (!a || !a))
    // make a graph using the impls

    two_sat(int _nodes)
    {
        nodes = _nodes;
        adj = vector<vector<int>>(2 * nodes + 10);
        rev_adj = vector<vector<int>>(2 * nodes + 10);
        scc_ids = vector<int>(2 * nodes + 10);
        vis = vector<bool>(2 * nodes + 10);
    }
    pair<bool, int> get_node(int index)
    {
        return {index % 2 == 0, index / 2};
    }
    int get_index(const pair<bool, int> &a)
    {
        return 2 * a.second + !a.first;
    }
    void add_edges(const pair<bool, int> &a, const pair<bool, int> &b)
    {
        adj[get_index(a)].push_back(get_index(b));
        rev_adj[get_index(b)].push_back(get_index(a));
        topo_done = false;
        scc_done = false;
    }
    void add_or(const pair<bool, int> &a, const pair<bool, int> &b)
    {
        //a || b -> !a means b and !b means a
        add_edges({!a.first, a.second}, b);
        add_edges({!b.first, b.second}, a);
    }
    void add_xor(const pair<bool, int> &a, const pair<bool, int> &b)
    {
        //a xor b -> (a or b) and (!a or !b)
        add_or(a, b);
        add_or({!a.first, a.second}, {!b.first, b.second});
    }
    void add_together(const pair<bool, int> &a, const pair<bool, int> &b)
    {
        //if you want a->b ->!(a xor b)->(a impl b) and (!a impl !b)
        add_edges(a, b);
        add_edges({!a.first, a.second}, {!b.first, b.second});
    }
    void toposort(int node, vector<int> &stk, vector<vector<int>> &adj)
    {
        vis[node] = true;
        for (int &next : adj[node])
        {
            if (!vis[next])
                toposort(next, stk, adj);
        }
        stk.push_back(node);
    }
    void set_topo()
    {
        if (topo_done)
            return;
        topo.clear();
        fill(all(vis), false);
        forab(i, 1, nodes + 1)
        {
            if (!vis[2 * i])
                toposort(2 * i, topo, adj);
            if (!vis[2 * i + 1])
                toposort(2 * i + 1, topo, adj);
        }
        reverse(all(topo));
        fill(all(vis), false);
        topo_done = true;
    }
    void dfs_scc(int node, int scc_id)
    {
        if (vis[node])
            return;
        vis[node] = true;
        scc_ids[node] = scc_id;
        for (int next : rev_adj[node])
            dfs_scc(next, scc_id);
    }
    void set_sccs()
    {
        if (scc_done)
            return;
        fill(all(scc_ids), -1);
        set_topo();
        fill(all(vis), false);
        int scc_id = 0;
        for (int &node : topo)
        {
            if (!vis[node])
                dfs_scc(node, scc_id++);
        }
        fill(all(vis), false);
        scc_done = true;
    }
    bool is_satisfiable()
    {
        set_sccs();
        forab(i, 1, nodes + 1)
        {
            if (scc_ids[2 * i] == scc_ids[2 * i + 1])
                return false;
        }
        return true;
    }
    vector<bool> get_soln()
    {
        set_sccs();
        vector<bool> vec(nodes + 1);
        forab(i, 1, nodes + 1)
        {
            vec[i] = (scc_ids[2 * i] > scc_ids[2 * i + 1]);
        }
        return vec;
    }
};
void solve()
{
    cin >> M >> N;
    pair<bool, int> a, b;
    two_sat ts(N);
    forab(i, 0, M)
    {
        cin >> c >> x;
        a = {c == '+', x};
        cin >> c >> x;
        b = {c == '+', x};
        ts.add_or(a, b);
    }
    // debug("123");
    if (!ts.is_satisfiable())
        cout << "IMPOSSIBLE" << endl;
    else
    {
        vector<bool> sol = ts.get_soln();
        forab(i, 1, N + 1)
        {
            cout << (sol[i] ? '+' : '-') << " ";
        }
    }
}
int32_t main()
{
    IOS;
    // int T;
    // cin >> T;
    // while (T--)
    solve();
    // debug("END");
    return 0;
}