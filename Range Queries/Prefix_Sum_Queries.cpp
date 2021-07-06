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
const int NMAX = 2e5 + 5;
array<int, NMAX> arr;
struct SegmentTree
{
    int sum_of_range;
    int max_prefix_in_range;
    int index_l;
    int index_r;
    shared_ptr<SegmentTree> lower;
    shared_ptr<SegmentTree> upper;
    bool is_leaf = false;

    SegmentTree(const int _index_l,
                const int _index_r)
    {
        index_l = _index_l;
        index_r = _index_r;
        is_leaf = (index_l == index_r);
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
    static void update_segment_tree(shared_ptr<SegmentTree> &root, const int &update_node_index, const int &update_node_new_val)
    {
        if (!root)
            return;
        root->update_node(update_node_index, update_node_new_val);
        return;
    }
    static tuple<bool, int, int> query_segment_tree(shared_ptr<SegmentTree> &root, const int &target_l, const int &target_r)
    {
        return root->query_tree(target_l, target_r);
    }
    bool update_node(const int &update_node_index, const int &update_node_new_val)
    {
        if (!index_lies_in_node(update_node_index))
            return false;
        if (is_leaf)
        {
            sum_of_range = update_node_new_val;
            max_prefix_in_range = sum_of_range;
            max_prefix_in_range = max(max_prefix_in_range, 0LL);
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

    const int INVALID_ANS = 0; //return in place of invalid ans
    template <typename type_t>
    static shared_ptr<SegmentTree> build_segment_tree(const type_t &arr,
                                                      const int &curr_index_l,
                                                      const int &curr_index_r)
    {
        shared_ptr<SegmentTree> node = make_shared<SegmentTree>(curr_index_l, curr_index_r);
        if (node->is_leaf)
        {
            node->sum_of_range = arr[curr_index_l];
            node->max_prefix_in_range = node->sum_of_range;
            node->max_prefix_in_range = max(node->max_prefix_in_range, 0LL);
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
        this->sum_of_range = lower->sum_of_range + upper->sum_of_range;
        this->max_prefix_in_range = max(lower->max_prefix_in_range, lower->sum_of_range + upper->max_prefix_in_range);
        this->max_prefix_in_range = max(max_prefix_in_range, 0LL);
    }

    tuple<bool, int, int> query_tree(const int &target_l, const int &target_r) const
    {
        if (enclosed_in(target_l, target_r))
        {
            return {true, sum_of_range, max_prefix_in_range};
        }

        else if (overlap(target_l, target_r) && !is_leaf)
        {
            const auto &[validity_lower, sum_in_lower, max_prefix_in_lower] = lower->query_tree(target_l, target_r);
            const auto &[validity_upper, sum_in_upper, max_prefix_in_upper] = upper->query_tree(target_l, target_r);

            if (!validity_lower) //no overlap with lower
                return {validity_upper, sum_in_upper, max_prefix_in_upper};
            if (!validity_upper) //no overlap with upper
                return {validity_lower, sum_in_lower, max_prefix_in_lower};

            // merge answers for lower and upper
            return {true, sum_in_lower + sum_in_upper, max(max_prefix_in_lower, sum_in_lower + max_prefix_in_upper)};
        }

        return {false, INVALID_ANS, INVALID_ANS};
    }
};

void solve()
{
    int N, Q;
    cin >> N >> Q;
    forab(i, 1, N + 1) cin >> arr[i];
    {
        int tp, k, u, a, b;
        shared_ptr<SegmentTree> root = SegmentTree::build_segment_tree(arr, 1, N);
        forab(i, 0, Q)
        {
            cin >> tp;
            if (tp == 1)
            {
                cin >> k >> u;
                SegmentTree::update_segment_tree(root, k, u);
            }
            else if (tp == 2)
            {
                cin >> a >> b;
                const auto &[validity, sum, max_pref] = SegmentTree::query_segment_tree(root, a, b);
                cout << max_pref << endl;
            }
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
    cout.flush();
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