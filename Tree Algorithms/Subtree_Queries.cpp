#include <iostream>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define printp(vv) cout << '{' << vv.firt << ' ' << vv.second << '}' << ' '
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
    cout << var1 << ' ';
    debug(var2...);
}
/* TEMPLATE END */
class SegmentTree
{
public:
    int data = -1;
    int l = -1, r = -1;
    SegmentTree *lower = NULL, *upper = NULL, *parent = NULL;
};
int N, M, x, y, Q;
const int NMAX = 2 * (1e5) + 10;
array<int, NMAX> value;
array<vector<int>, NMAX> adj;
array<int, NMAX> euler_array;
array<int, NMAX> subtree_elems;
array<int, NMAX> start;
array<SegmentTree *, NMAX> leafs;
int timer = 0;
int dfs1(int node, int par)
{
    start[node] = timer;
    euler_array[timer++] = value[node];
    int subtree = 1;
    for (int next : adj[node])
    {
        if (next == par)
            continue;
        subtree += dfs1(next, node);
    }
    return subtree_elems[node] = subtree;
}
SegmentTree *make_segment_tree(array<int, NMAX> &euler_array, SegmentTree *par, int st, int en)
{

    SegmentTree *root = new SegmentTree();
    root->parent = par;
    root->l = st;
    root->r = en;
    if (st == en)
    {
        root->data = euler_array[st];
        leafs[st] = root;
    }
    else
    {
        int md = (st + en) / 2;
        root->lower = make_segment_tree(euler_array, root, st, md);
        root->upper = make_segment_tree(euler_array, root, md + 1, en);
        root->data = root->lower->data + root->upper->data;
    }
    return root;
}

SegmentTree *make_segment_tree(array<int, NMAX> &euler_array)
{
    return make_segment_tree(euler_array, NULL, 0, euler_array.size() - 1);
}

void updateTree(SegmentTree *nd, int new_val, int old_val)
{
    if (nd == NULL)
        return;
    nd->data -= old_val;
    nd->data += new_val;
    updateTree(nd->parent, new_val, old_val);
}

void updateTree(int node, int new_val)
{
    SegmentTree *n = leafs[node];
    updateTree(n, new_val, n->data);
}

int query_tree(SegmentTree *node, int l, int r)
{
    if (node == NULL)
        return 0;
    else if (l <= node->l && node->r <= r)
        return node->data;
    else if (max(r, node->r) - min(l, node->l) <= (r - l + node->r - node->l))
        return query_tree(node->lower, l, r) + query_tree(node->upper, l, r);
    else
        return 0;
}

int query_tree(SegmentTree *node, int node_val)
{
    return query_tree(node, start[node_val], start[node_val] + subtree_elems[node_val] - 1);
}
bool in_range(int st, int en, int val)
{
    return st <= val && val <= en;
}

void solve()
{
    cin >> N >> Q;
    forab(i, 1, N + 1)
    {
        cin >> value[i];
    }
    forab(i, 0, N - 1)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs1(1, -1);
    SegmentTree *root = make_segment_tree(euler_array);
    {
        int tp, s, x;

        forab(i, 0, Q)
        {
            cin >> tp;
            if (tp == 1)
            {
                cin >> s >> x;
                int euler_index = start[s];
                updateTree(euler_index, x);
            }
            else
            {
                cin >> x;
                cout << query_tree(root, x) << endl;
            }
        }
    }
}
int32_t main()
{
    IOS;
    // freopen("C:\Users\yadur\Desktop\CC\IN.txt", "r", stdin);
    // freopen("C:\Users\yadur\Desktop\CC\OUT.txt", "w", stdout);
    // int T;
    // cin >> T;
    // while (T--)
        solve();
    return 0;
}