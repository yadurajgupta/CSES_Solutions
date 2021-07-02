#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
using namespace std;

// #define _DEBUG_CODE 1
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
    #define debugab(x1, s, e) cout << #x1 << '[' << min(s, e) << ':' << max(s, e) << ']' << ' '; _debug_p_vector_typeab(x1, min(s, e), max(s, e) + 1); cout<<endl;
#endif
#ifdef ONLINE_JUDGE
    #define PNAV(x)
    #define debug(x1)
    #define debug2(x1, x2)
    #define debug3(x1, x2, x3)
    #define debug4(x1, x2, x3, x4)
    #define debug5(x1, x2, x3, x4, x5)
    #define debug6(x1, x2, x3, x4, x5, x6)
    #define debugab(x1,s,e)
    #define endl '\n'
#endif
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
// clang-format on
/* TEMPLATE END */
#pragma endregion
int N, x, y, Q, tp;
const int NMAX = 2e5 + 5;
array<int, NMAX> arr;
const int EMPTY_ANS = LLONG_MIN;
struct SegmentTree
{
    int max_pref, sum;
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
SegmentTree *build_segment_tree(array<int, NMAX> &arr, int st, int ed, SegmentTree *par = NULL)
{
    if (st > ed)
        return NULL;
    SegmentTree *node = new SegmentTree();
    node->parent = par;
    node->l = st;
    node->r = ed;
    if (st == ed)
    {
        node->sum = node->max_pref = arr[st];
        node->max_pref = max(node->max_pref, 0LL);
        leafs[st] = node;
    }
    else
    {
        int m = st + (ed - st) / 2;
        node->lower = build_segment_tree(arr, st, m, node);
        node->upper = build_segment_tree(arr, m + 1, ed, node);
        node->sum = node->lower->sum + node->upper->sum;
        node->max_pref = max(node->lower->max_pref, node->lower->sum + node->upper->max_pref);
        node->max_pref = max(node->max_pref, 0LL);
    }
    return node;
}
int query_tree_sum(SegmentTree *node, int l, int r)
{
    if (node == NULL || l > r)
        return 0;
    else if (node->enclosed_in(l, r))
        return node->sum;
    else if (node->overlap(l, r))
        return query_tree_sum(node->lower, l, r) + query_tree_sum(node->upper, l, r);
    else
        return 0;
}
int query_tree_max_pref(SegmentTree *node, SegmentTree *root, int l, int r)
{
    if (node == NULL || l > r)
        return EMPTY_ANS;
    else if (node->enclosed_in(l, r))
        return query_tree_sum(root, l, node->l - 1) + node->max_pref;
    else if (node->overlap(l, r))
        return max(query_tree_max_pref(node->lower, root, l, r), query_tree_max_pref(node->upper, root, l, r));
    else
        return EMPTY_ANS;
}
void update_node(SegmentTree *node)
{
    if (node == NULL)
        return;
    node->sum = node->lower->sum + node->upper->sum;
    node->max_pref = max(node->lower->max_pref, node->lower->sum + node->upper->max_pref);
    node->max_pref = max(node->max_pref, 0LL);
    update_node(node->parent);
}
void update_node(int node, int new_val)
{
    leafs[node]->sum = leafs[node]->max_pref = new_val;
    leafs[node]->max_pref = max(leafs[node]->max_pref, 0LL);
    update_node(leafs[node]->parent);
}
void solve()
{
    cin >> N >> Q;
    forab(i, 1, N + 1) { cin >> arr[i]; }
    SegmentTree *root = build_segment_tree(arr, 1, N);
    forab(i, 0, Q)
    {
        cin >> tp >> x >> y;
        if (tp == 1)
        {
            update_node(x, y);
        }
        else if (tp == 2)
        {
            cout << query_tree_max_pref(root, root, x, y) << endl;
        }
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
    freopen("/home/yaduraj/CC/IN.txt", "r", stdin);
    freopen("/home/yaduraj/CC/OUT.txt", "w", stdout);
#endif
    // int T;
    // cin >> T;
    // while (T--)
    solve();
    return 0;
}
#pragma region
// clang-format off
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
        _debug_p(t[i]);
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
#pragma endregion