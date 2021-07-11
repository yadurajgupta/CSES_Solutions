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
array<int, NMAX> value;
array<int, NMAX> euler_array;
array<int, NMAX> node_index_to_euler_index;
array<bool, NMAX> vis;
array<int, NMAX> subtree_elems;
array<vector<int>, NMAX> adj;
struct SegmentTree
{
    int val;
    int index_l;
    int index_r;
    SegmentTree *lower = NULL;
    SegmentTree *upper = NULL;
    bool is_leaf = false;
    static const int INVALID_ANSWER;

    SegmentTree(const int _index_l,
                const int _index_r)
    {
        index_l = _index_l;
        index_r = _index_r;
        is_leaf = (index_l == index_r);
    }
    ~SegmentTree()
    {
        if (lower)
            delete lower;
        if (upper)
            delete upper;
    }
    bool overlap(const int &other_index_l, const int &other_index_r) const
    {
        return (index_l <= other_index_r) &&
               (index_r >= other_index_l);
    }
    bool enclosed_in(const int &other_index_l, const int &other_index_r) const
    {
        return (other_index_l <= index_l) &&
               (index_r <= other_index_r);
    }
    bool index_lies_in_node(const int &index) const
    {
        return (index_l <= index) &&
               (index <= index_r);
    }
    static void update_segment_tree(SegmentTree *&root, const int &update_node_index, const int &update_node_new_val)
    {
        if (!root)
            return;
        root->update_node(update_node_index, update_node_new_val);
        return;
    }
    static pair<bool, int> query_segment_tree(SegmentTree *&root, const int &target_l, const int &target_r)
    {
        return root->query_tree(target_l, target_r);
    }
    bool update_node(const int &update_node_index, const int &update_node_new_val)
    {
        if (!index_lies_in_node(update_node_index))
            return false;
        if (is_leaf)
        {
            val = update_node_new_val;
            return true;
        }
        if (lower->update_node(update_node_index, update_node_new_val) ||
            upper->update_node(update_node_index, update_node_new_val))
        {
            this->update_node_based_on_children();
            return true;
        }
        return false;
    }

    template <typename type_t>
    static SegmentTree *build_segment_tree(const type_t &arr,
                                           const int &curr_index_l,
                                           const int &curr_index_r)
    {
        SegmentTree *node = new SegmentTree(curr_index_l, curr_index_r);
        if (node->is_leaf)
        {
            node->val = arr[curr_index_l];
        }
        else
        {
            int curr_index_m = curr_index_l + (curr_index_r - curr_index_l) / 2;
            node->lower = build_segment_tree(arr, curr_index_l, curr_index_m);
            node->upper = build_segment_tree(arr, curr_index_m + 1, curr_index_r);
            node->update_node_based_on_children();
        }
        return node;
    }
    void update_node_based_on_children()
    {
        if (is_leaf)
            return;
        this->val = lower->val + upper->val;
    }
    pair<bool, int> query_tree(const int &target_l, const int &target_r) const
    {
        if (enclosed_in(target_l, target_r))
            return {true, val};
        else if (overlap(target_l, target_r) && !is_leaf)
        {
            const auto &[lower_valid, lower_ans] = lower->query_tree(target_l, target_r);
            const auto &[upper_valid, upper_ans] = upper->query_tree(target_l, target_r);
            if (!lower_valid)
                return {upper_valid, upper_ans};
            if (!upper_valid)
                return {lower_valid, lower_ans};
            //Merge the answers together
            return {true, lower_ans + upper_ans};
        }
        return {false, INVALID_ANSWER};
    }
};
const int SegmentTree::INVALID_ANSWER = 0;

int dfs(int node, int par, int &timer)
{
    node_index_to_euler_index[node] = timer;
    euler_array[timer] = value[node];
    timer++;
    int curr_subtree_elems = 1;
    for (const int &next : adj[node])
    {
        if (next == par)
            continue;
        curr_subtree_elems += dfs(next, node, timer);
    }
    return subtree_elems[node] = curr_subtree_elems;
}
void solve()
{
    cin >> N >> Q;
    forab(i, 1, N + 1) cin >> value[i];
    forab(i, 0, N - 1)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int timer = 1;
    dfs(1, 0, timer);

    SegmentTree *root = SegmentTree::build_segment_tree(euler_array, 1, N);
    int tp, index, new_value;
    forab(i, 0, Q)
    {
        cin >> tp;
        if (tp == 1)
        {
            cin >> index >> new_value;
            const auto &euler_index = node_index_to_euler_index[index];
            SegmentTree::update_segment_tree(root, euler_index, new_value);
        }
        else if (tp == 2)
        {
            cin >> index;
            const auto &euler_index_start = node_index_to_euler_index[index];
            const auto &euler_index_end = euler_index_start + subtree_elems[index] - 1;
            cout << SegmentTree::query_segment_tree(root, euler_index_start, euler_index_end).second << endl;
        }
    }
    delete root;
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
    // freopen("C:/Users/yadur/Downloads/Stuff/CC/IN.txt", "r", stdin);
    // freopen("C:/Users/yadur/Downloads/Stuff/CC/OUT.txt", "w", stdout);
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
#endif
#pragma endregion