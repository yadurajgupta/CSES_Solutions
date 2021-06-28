// replace slashes then double qutotes then stringify

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
using namespace std;

// #define _DEBUG_CODE 1
// #define ONLINE_JUDGE 1
#pragma region
// clang-format off
#define int long long
#define ordered_set(type) __gnu_pbds::tree<type, __gnu_pbds::null_type, less<type>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>
#define forab(ii, aa, bb) for (int ii = aa; ii < bb; ii++)
#define forabd(ii, aa, bb) for (int ii = aa; ii >= bb; ii--)
#define forabi(ii, aa, bb, inc) for (int ii = aa; ii < bb; ii += inc)
#define forabdi(ii, aa, bb, inc) for (int ii = aa; ii >= bb; ii -= inc)
#define all(aa) aa.begin(), aa.end()
#define rall(aa) aa.rbegin(), aa.rend()
#define PL cout << endl
#define mkt make_tuple
#define mkp make_pair
#define mka(type, SZ) array<type, SZ>
#define printn(vv, NN) forab(ii, 0, NN) _debug_p(vv[ii]), cout << ' '; PL;

#ifndef ONLINE_JUDGE
    #define PNAV(x) cout << #x << ' '; _debug_p(x); cout << ' ';
    #define debug(x1) PNAV(x1) cout << endl;
    #define debug2(x1, x2) PNAV(x1); debug(x2);
    #define debug3(x1, x2, x3) PNAV(x1); debug2(x2, x3);
    #define debug4(x1, x2, x3, x4) PNAV(x1); debug3(x2, x3, x4);
    #define debug5(x1, x2, x3, x4, x5) PNAV(x1); debug4(x2, x3, x4, x5);
    #define debug6(x1, x2, x3, x4, x5, x6) PNAV(x1); debug5(x2, x3, x4, x5, x6);
    #define debug7(x1, x2, x3, x4, x5, x6, x7) PNAV(x1); debug6(x2, x3, x4, x5, x6, x7);
    #define debug8(x1, x2, x3, x4, x5, x6, x7, x8) PNAV(x1); debug7(x2, x3, x4, x5, x6, x7, x8);
    #define debug9(x1, x2, x3, x4, x5, x6, x7, x8, x9) PNAV(x1); debug8(x2, x3, x4, x5, x6, x7, x8, x9);
    #define debug10(x1, x2, x3, x4, x5, x6, x7, x8, x9, x10) PNAV(x1); debug9(x2, x3, x4, x5, x6, x7, x8, x9, x10);
    #define debugab(x1, s, e) cout << #x1 << '[' << min((int)s, (int)e) << ':' << max((int)s, (int)e) << ']' << ' '; _debug_p_vector_typeab(x1, min((int)s, (int)e), max((int)s, (int)e) + 1); cout<<endl;
    void _debug_p(int T);
    void _debug_p(int32_t T);
    void _debug_p(unsigned int T);
    void _debug_p(unsigned T);
    void _debug_p(double T);
    void _debug_p(string T);
    void _debug_p(const char T[]);
    void _debug_p(char T);
    void _debug_p(bool T);
    template <typename T> void _debug_p(const vector<T> &vec);
    template <typename T> void _debug_p(const list<T> &vec);
    template <typename T,size_t sz> void _debug_p(const array<T,sz> &vec);
    template <typename T> void _debug_p(const set<T> &vec);
    template <typename T> void _debug_p(const unordered_set<T> &vec);
    template <typename T> void _debug_p(const multiset<T> &vec);
    template <typename T> void _debug_p(const unordered_multiset<T> &vec);
    template <typename t1, typename t2> void _debug_p(const map<t1, t2> &mp);
    template <typename t1, typename t2> void _debug_p(const unordered_map<t1, t2> &mp);
    template <typename t1, typename t2> void _debug_p(const multimap<t1, t2> &mp);
    template <typename t1, typename t2> void _debug_p(const unordered_multimap<t1, t2> &mp);
    template <class... T> void _debug_p(const tuple<T...> &_tup);
    template <class TupType, size_t... I> void _debug_p_tup(const TupType &_tup, index_sequence<I...>);
    template <typename T> void _debug_p_vector_type(const T &t);
    template <typename T> void _debug_p_vector_typeab(const T &t,int s,int e);
    template <typename T> void _debug_p_map_type(const T &t);
    template <typename t1, typename t2> void _debug_p(const pair<t1, t2> &p);
#endif

#ifdef ONLINE_JUDGE
    #define PNAV(x)
    #define debug(x1)
    #define debug2(x1, x2)
    #define debug3(x1, x2, x3)
    #define debug4(x1, x2, x3, x4)
    #define debug5(x1, x2, x3, x4, x5)
    #define debug6(x1, x2, x3, x4, x5, x6)
    #define debug7(x1, x2, x3, x4, x5, x6, x7)
    #define debug8(x1, x2, x3, x4, x5, x6, x7, x8)
    #define debug9(x1, x2, x3, x4, x5, x6, x7, x8, x9)
    #define debug10(x1, x2, x3, x4, x5, x6, x7, x8, x9, x10)
    #define debugab(x1,s,e)
    #define endl '\n'
#endif
// clang-format on
/* TEMPLATE END */
#pragma endregion
int N, x, y, Q;
const int NMAX = 2e5 + 5;
const int LGMAX = 20;
array<array<int, LGMAX>, NMAX> rev_dp;
array<int, NMAX> rev_depth;
array<vector<int>, NMAX> rev_adj;
array<int, NMAX> arr;
array<int, NMAX> cycles_ids;
array<int, NMAX> cycles_ids_pos;
array<int, NMAX> cycles_ids_size;
array<int, NMAX> trees_ids;
array<int, NMAX> trees_ids_to_cycle_ids;
array<int, NMAX> trees_ids_to_cycle_node;
array<int, NMAX> tree_to_root_node;
array<bool, NMAX> curr_vis;
array<bool, NMAX> vis;
vector<int> tree_roots;
array<int, NMAX> node_to_index;

int total_number_of_cycles = 0;
int total_number_of_trees = 0;

void find_cycle(int node, int par, vector<int> &path)
{
    int next = arr[node];
    if (curr_vis[next]) // found a cycle
    {
        int prev_index_of_next = node_to_index[next];
        int pos = 0;
        int sz = path.size() - prev_index_of_next;
        forab(i, prev_index_of_next, path.size())
        {
            cycles_ids[path[i]] = total_number_of_cycles;
            cycles_ids_pos[path[i]] = pos++;
            cycles_ids_size[path[i]] = sz;
        }
        total_number_of_cycles++;
    }
    else if (vis[next]) // no need to continue;
    {
        return;
    }
    else //continue dfs
    {
        node_to_index[next] = path.size();
        path.push_back(next);
        vis[next] = true;
        curr_vis[next] = true;

        find_cycle(next, next, path);

        node_to_index[next] = -1;
        path.pop_back();
        curr_vis[next] = false;
    }
}
void find_tree(int node, int par, vector<int> &path)
{
    int next = arr[node];
    if (cycles_ids[next] != -1) // found its way to a cycle
    {
        for (int n : path)
        {
            trees_ids[n] = total_number_of_trees;
            trees_ids_to_cycle_ids[n] = cycles_ids[next];
            tree_to_root_node[n] = node;
            trees_ids_to_cycle_node[n] = next;
        }
        tree_roots.push_back(node);
        total_number_of_trees++;
    }
    else if (trees_ids[next] != -1) // merge this tree into another
    {
        for (int n : path)
        {
            trees_ids[n] = trees_ids[next];
            trees_ids_to_cycle_ids[n] = trees_ids_to_cycle_ids[next];
            tree_to_root_node[n] = tree_to_root_node[next];
            trees_ids_to_cycle_node[n] = trees_ids_to_cycle_node[next];
        }
    }
    else //continue dfs
    {
        path.push_back(next);
        find_tree(next, node, path);
        path.pop_back();
    }
}
void set_tree_depths(int node, int par, int depth = 0)
{
    rev_depth[node] = depth;
    rev_dp[node][0] = par;
    for (int next : rev_adj[node])
    {
        if (trees_ids[next] != -1 && next != par)
        {
            set_tree_depths(next, node, depth + 1);
        }
    }
}
int get_cycle_dist(int x, int y)
{
    const int &cycle_sz = cycles_ids_size[x];
    if (cycles_ids_pos[x] <= cycles_ids_pos[y])
        return cycles_ids_pos[y] - cycles_ids_pos[x];
    else
        return cycle_sz - cycles_ids_pos[x] + cycles_ids_pos[y];
}
int jump_to_par(int node, int jumps)
{
    debug3(node, rev_depth[node], jumps);
    if (jumps > rev_depth[node])
        return -1;
    forabd(j, LGMAX - 1, 0)
    {
        if (jumps & (1 << j))
        {
            debug3(node, j, rev_dp[node][j]);
            node = rev_dp[node][j];
        }
    }
    return node;
}
int get_tree_dist(int x, int y)
{
    int to_jump = rev_depth[y] - rev_depth[x];
    debug3(x, y, to_jump);
    if (to_jump < 0)
        return -1;
    else if (to_jump == 0)
        return (x == y) ? 0 : -1;
    else if (jump_to_par(y, to_jump) == x)
        return to_jump;
    return -1;
}
void solve()
{
    cin >> N >> Q;
    forab(i, 1, N + 1)
    {
        cin >> arr[i];
        rev_adj[arr[i]].push_back(i);
    }

    forab(i, 1, N + 1)
    {
        if (!vis[i])
        {
            vector<int> path;
            node_to_index[i] = path.size();
            path.push_back(i);
            vis[i] = true;
            curr_vis[i] = true;

            find_cycle(i, -1, path);

            node_to_index[i] = -1;
            path.pop_back();
            curr_vis[i] = false;
        }
    }

    forab(i, 1, N + 1)
    {
        if (trees_ids[i] == -1 && cycles_ids[i] == -1)
        {
            vector<int> path;
            path.push_back(i);
            find_tree(i, -1, path);
            path.pop_back();
        }
    }

    for (const int &node : tree_roots)
    {
        set_tree_depths(node, -1);
    }

    forab(jump, 1, LGMAX)
    {
        forab(node, 1, N + 1)
        {
            if (rev_dp[node][jump - 1] != -1)
            {
                rev_dp[node][jump] = rev_dp[rev_dp[node][jump - 1]][jump - 1];
            }
        }
    }

    forab(i, 0, Q)
    {
        cin >> x >> y;
        const bool &x_is_cycle = (cycles_ids[x] != -1);
        const bool &y_is_cycle = (cycles_ids[y] != -1);

        if (x_is_cycle && y_is_cycle && cycles_ids[x] == cycles_ids[y])
        {
            cout << get_cycle_dist(x, y) << endl;
            continue;
        }

        if (x_is_cycle == false && y_is_cycle && cycles_ids[y] == trees_ids_to_cycle_ids[x])
        {
            int root_node_of_tree = tree_to_root_node[x];
            int first_cycle_node = trees_ids_to_cycle_node[x];
            int tree_dist = get_tree_dist(root_node_of_tree, x);
            if (tree_dist == -1)
                cout << -1 << endl;
            else
                cout << tree_dist + 1 + get_cycle_dist(first_cycle_node, y) << endl; // tree_distance + 1 to move tree to cycle
            continue;
        }

        if (x_is_cycle == false && y_is_cycle == false && trees_ids[x] == trees_ids[y])
        {
            cout << get_tree_dist(y, x) << endl;
            continue;
        }

        cout << -1 << endl;
    }
}
int32_t main()
{

#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
#ifdef _DEBUG_CODE
    cout << "DEBUGGING ON" << endl;
    cout.flush();
    freopen("C:\\Users\\yadur\\Desktop\\CC\\IN.txt", "r", stdin);
    freopen("C:\\Users\\yadur\\Desktop\\CC\\OUT.txt", "w", stdout);
#endif
    // int T;
    // cin >> T;
    // while (T--)
    for (auto &row : rev_dp)
        row.fill(-1);

    rev_depth.fill(-1);
    cycles_ids.fill(-1);
    cycles_ids_pos.fill(-1);
    cycles_ids_size.fill(-1);
    trees_ids.fill(-1);
    trees_ids_to_cycle_ids.fill(-1);
    trees_ids_to_cycle_node.fill(-1);
    tree_to_root_node.fill(-1);
    solve();
    return 0;
}
#pragma region
// clang-format off
#ifndef ONLINE_JUDGE
void _debug_p(int T) { cout << T; }
void _debug_p(int32_t T) { cout << T; }
void _debug_p(unsigned int T) { cout << T; }
void _debug_p(unsigned T) { cout << T; }
void _debug_p(double T) { cout << T << 'd'; }
void _debug_p(string T) { cout << '"' << T << '"'; }
void _debug_p(const char T[]) { cout << '"' << T << '"'; }
void _debug_p(char T) { cout << '\'' << T << '\''; }
void _debug_p(bool T) { cout << (T ? '1' : '0') << 'b'; }
template <typename T> void _debug_p(const vector<T> &vec) { _debug_p_vector_type(vec); }
template <typename T> void _debug_p(const list<T> &vec) { _debug_p_vector_type(vec); }
template <typename T,size_t sz> void _debug_p(const array<T,sz> &vec) { _debug_p_vector_type(vec); }
template <typename T> void _debug_p(const set<T> &vec) { _debug_p_vector_type(vec); }
template <typename T> void _debug_p(const unordered_set<T> &vec) { _debug_p_vector_type(vec); }
template <typename T> void _debug_p(const multiset<T> &vec) { _debug_p_vector_type(vec); }
template <typename T> void _debug_p(const unordered_multiset<T> &vec) { _debug_p_vector_type(vec); }
template <typename t1, typename t2> void _debug_p(const map<t1, t2> &mp) { _debug_p_map_type(mp); }
template <typename t1, typename t2> void _debug_p(const unordered_map<t1, t2> &mp) { _debug_p_map_type(mp); }
template <typename t1, typename t2> void _debug_p(const multimap<t1, t2> &mp) { _debug_p_map_type(mp); }
template <typename t1, typename t2> void _debug_p(const unordered_multimap<t1, t2> &mp) { _debug_p_map_type(mp); }
template <class... T> void _debug_p(const tuple<T...> &_tup) { _debug_p_tup(_tup, make_index_sequence<sizeof...(T)>()); }
template <class TupType, size_t... I> void _debug_p_tup(const TupType &_tup, index_sequence<I...>) { 
    cout << '(';
    (..., (cout << (I == 0 ? "" : ", "), _debug_p(get<I>(_tup))));
    cout << ')';
}
template <typename T> void _debug_p_vector_type(const T &t) { 
    cout << '[';
    bool first = true;
    for (auto it : t)
    {
        if (!first)
            cout << ',' << ' ';
        _debug_p(it);
        first = false;
    }
    cout << ']';
}
template <typename T> void _debug_p_vector_typeab(const T &t,int s,int e) { 
    cout << '[';
    bool first = true;
    forab (i,s,e)
    {
        if (!first)
            cout << ',' << ' ';
        cout<<'{'<<i<<':';_debug_p(t[i]);cout<<'}';
        first = false;
    }
    cout << ']';
}
template <typename T> void _debug_p_map_type(const T &t) { 
    cout << '[';
    bool first = true;
    for (const auto &[key, val] : t)
    {
        if (!first)
            cout << ',' << ' ';
        cout << '{';
        _debug_p(key);
        cout << ':';
        _debug_p(val);
        cout << '}';
        first = false;
    }
    cout << ']';
}
template <typename t1, typename t2> void _debug_p(const pair<t1, t2> &p) { 
    cout << '(';
    _debug_p(p.first);
    cout << ',' << ' ';
    _debug_p(p.second);
    cout << ')';
}
#endif
#pragma endregion