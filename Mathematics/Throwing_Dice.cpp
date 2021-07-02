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
#define forab(ii, aa, bb) for (unsigned int ii = aa; ii < bb; ii++)
#define forabd(ii, aa, bb) for (unsigned int ii = aa; ii >= bb; ii--)
#define forabi(ii, aa, bb, inc) for (unsigned int ii = aa; ii < bb; ii += inc)
#define forabdi(ii, aa, bb, inc) for (unsigned int ii = aa; ii >= bb; ii -= inc)
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
const int MOD = 1e9 + 7;
const int MOD_INV_2 = 5e8 + 4;
int modAdd(int a, int b) { return ((a % MOD + b % MOD) % MOD + MOD) % MOD; }
int modMult(int a, int b) { return (((a % MOD) * (b % MOD)) % MOD + MOD) % MOD; }
template <size_t _N_dim, size_t _M_dim>
struct Matrix
{
    array<array<int, _N_dim>, _M_dim> data = {};
    Matrix()
    {
        forab(i, 0, _N_dim) forab(j, 0, _M_dim) data[i][j] = 0;
    }
    Matrix(int x)
    {
        forab(i, 0, _N_dim) forab(j, 0, _M_dim) data[i][j] = x;
    }
    Matrix(const array<array<int, _N_dim>, _M_dim> _data)
    {
        data = _data;
    }
};
template <size_t _N_dim, size_t _mid_dim, size_t _M_dim>
Matrix<_N_dim, _M_dim> mult_mat(const Matrix<_N_dim, _mid_dim> &a, const Matrix<_mid_dim, _M_dim> &b)
{
    Matrix<_N_dim, _M_dim> result;
    auto &result_data = result.data;
    const auto &a_data = a.data;
    const auto &b_data = b.data;
    forab(i, 0, _M_dim)
    {
        forab(j, 0, _N_dim)
        {
            forab(k, 0, _mid_dim)
            {
                result_data[i][j] = modAdd(result_data[i][j], modMult(a_data[i][k], b_data[k][j]));
            }
        }
    }
    return result;
}
template <size_t _N_dim>
Matrix<_N_dim, _N_dim> get_identity_matrix()
{
    Matrix identity = Matrix<_N_dim, _N_dim>();
    forab(i, 0, _N_dim)
    {
        identity.data[i][i] = 1;
    }
    return identity;
}

template <size_t _N_dim>
Matrix<_N_dim, _N_dim> mat_to_pow(const Matrix<_N_dim, _N_dim> &mat, int b)
{
    if (b == 0)
        return get_identity_matrix<_N_dim>();
    else if (b == 1)
        return mat;
    else if (b % 2)
        return mult_mat(mat_to_pow(mult_mat(mat, mat), b / 2), mat);
    else
        return mat_to_pow(mult_mat(mat, mat), b / 2);
}

template <size_t _N_dim, size_t _M_dim>
void show_matrix(const Matrix<_N_dim, _M_dim> &mat)
{
    forab(i, 0, _M_dim)
    {
        forab(j, 0, _N_dim)
        {
            cout << mat.data[j][i] << ' ';
        }
        PL;
    }
    PL;
}

void solve()
{
    cin >> N;
    if (N <= 6)
    {
        cout << pow(2, N - 1) << endl;
        return;
    }
    // O(1) space dp
    // int dp1 = 1;
    // int dp2 = 2;
    // int dp3 = 4;
    // int dp4 = 8;
    // int dp5 = 16;
    // int dp6 = 32;
    // forab(i, 7, N + 1)
    // {
    //     int new_dp1 = dp2;
    //     int new_dp2 = dp3;
    //     int new_dp3 = dp4;
    //     int new_dp4 = dp5;
    //     int new_dp5 = dp6;
    //     int new_dp6 = dp1;
    //     int new_dp6 = dp1 + dp2 + dp3 + dp4 + dp5 + dp6;
    //     dp1 = new_dp1;
    //     dp2 = new_dp2;
    //     dp3 = new_dp3;
    //     dp4 = new_dp4;
    //     dp5 = new_dp5;
    //     dp6 = new_dp6;
    // }
    // cout << dp6 << endl;

    // Matrix Exponention
    array<array<int, 6>, 6> arr{{
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1},
    }};
    Matrix base(arr);
    const auto &pow_N = mat_to_pow(base, N);
    cout << pow_N.data[5][5] << endl;
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