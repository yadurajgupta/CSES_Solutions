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
int N, M, Q;
const int NMAX = 2e5 + 10;
array<int, NMAX> arr;
const int EMPTY_ANS = -1;
int fn(int a, int b)
{
    return max(a, b);
}
struct SegmentTree
{
    int val;
    int l, r;
    SegmentTree *lower = NULL;
    SegmentTree *upper = NULL;
    SegmentTree *parent = NULL;
    bool overlap(int _l, int _r)
    {
        return max(r, _r) - min(l, _l) <= (r - l) + (_r - _l);
    }
    bool enclosed_in(int _l, int _r)
    {
        return _l <= l && r <= _r;
    }
};
array<SegmentTree *, NMAX> leafs;
SegmentTree *build_segment_tree(array<int, NMAX> &arr, int st, int ed, SegmentTree *par)
{
    if (st > ed)
        return NULL;
    SegmentTree *node = new SegmentTree();
    node->parent = par;
    node->l = st;
    node->r = ed;
    if (st == ed)
    {
        node->val = arr[st];
        leafs[st] = node;
    }
    else
    {
        int m = st + (ed - st) / 2;
        node->lower = build_segment_tree(arr, st, m, node);
        node->upper = build_segment_tree(arr, m + 1, ed, node);
        node->val = fn(node->lower->val, node->upper->val);
    }
    return node;
}
int query_tree(SegmentTree *node, int l, int r)
{
    if (node == NULL)
        return EMPTY_ANS;

    if (node->enclosed_in(l, r))
        return node->val;
    else if (node->overlap(l, r))
        return fn(query_tree(node->lower, l, r), query_tree(node->upper, l, r));
    else
        return EMPTY_ANS;
}
void update_node(SegmentTree *node)
{
    if (node == NULL)
        return;
    node->val = fn(node->lower->val, node->upper->val);
    update_node(node->parent);
}
void update_node(int node, int new_val)
{
    leafs[node]->val = new_val;
    update_node(leafs[node]->parent);
}
int binser(SegmentTree *node, int mn_val)
{
    int st = 1;
    int ed = N;
    if (query_tree(node, st, ed) < mn_val)
        return 0;
    int m;
    int ans = 0;
    while (st <= ed)
    {
        if (m == (st + ed) / 2)
            break;
        m = (st + ed) / 2;
        if (query_tree(node, 1, m) < mn_val)
        {
            st = m;
        }
        else
        {
            ed = ans = m;
        }
    }
    return ans;
}
int find_val(SegmentTree *node, int mn_val)
{
    if (node == NULL || node->val < mn_val)
        return LLONG_MAX;
    else if (node->r == node->l)
        return node->l;
    else if (node->lower && node->lower->val >= mn_val)
        return find_val(node->lower, mn_val);
    else if (node->upper && node->upper->val >= mn_val)
        return find_val(node->upper, mn_val);
    else
        return LLONG_MAX;
}
void solve()
{
    cin >> N >> M;
    forab(i, 1, N + 1)
    {
        cin >> arr[i];
    }
    SegmentTree *root = build_segment_tree(arr, 1, N, NULL);
    forab(i, 0, M)
    {
        cin >> Q;
        int index = find_val(root, Q);
        if (index == LLONG_MAX)
        {
            cout << 0 << " ";
            continue;
        }
        cout << index << " ";
        arr[index] -= Q;
        update_node(index, arr[index]);
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