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
const int NOT_POSSIBLE = -1;

template <size_t MAX_ROWS, size_t MAX_COLUMNS>
struct Matrix
{
    array<array<int, MAX_COLUMNS>, MAX_ROWS> data;
    int VALID_ROWS = MAX_ROWS;
    int VALID_COLUMNS = MAX_COLUMNS;
    Matrix()
    {
        forab(i, 0, VALID_ROWS) forab(j, 0, VALID_COLUMNS) data[i][j] = 0;
    }
    Matrix(int x)
    {
        forab(i, 0, VALID_ROWS) forab(j, 0, VALID_COLUMNS) data[i][j] = x;
    }
    Matrix(const array<array<int, MAX_COLUMNS>, MAX_ROWS> _data)
    {
        data = _data;
    }
    int &operator()(const size_t i, const size_t j)
    {
        return data.at(i).at(j);
    }
    int operator()(const size_t i, const size_t j) const
    {
        return data.at(i).at(j);
    }
    void set_dim(const int &NEW_VALID_ROWS, const int &NEW_VALID_COLUMNS)
    {
        VALID_ROWS = NEW_VALID_ROWS;
        VALID_COLUMNS = NEW_VALID_COLUMNS;
    }
};

template <size_t MAX_ROWS, size_t MID_DIM, size_t MAX_COLUMNS>
Matrix<MAX_ROWS, MAX_COLUMNS> multiply_matrix(const Matrix<MAX_ROWS, MID_DIM> &a, const Matrix<MID_DIM, MAX_COLUMNS> &b)
{
    const int &VALID_ROWS = a.VALID_ROWS;
    const int &VALID_COLUMNS = b.VALID_COLUMNS;
    const int &valid_mid_mid = a.VALID_COLUMNS;
    Matrix<MAX_ROWS, MAX_COLUMNS> result(NOT_POSSIBLE);
    result.set_dim(VALID_ROWS, VALID_COLUMNS);
    forab(i, 0, VALID_ROWS)
    {
        forab(j, 0, VALID_COLUMNS)
        {
            forab(k, 0, MID_DIM) //move from i->j through k
            {
                if (a(i, k) == NOT_POSSIBLE || b(k, j) == NOT_POSSIBLE)
                    continue;
                if (result(i, j) == NOT_POSSIBLE)
                    result(i, j) = a(i, k) + b(k, j);
                else
                    result(i, j) = min(result(i, j), a(i, k) + b(k, j));
            }
        }
    }
    return result;
}

template <size_t MAX_ROWS>
Matrix<MAX_ROWS, MAX_ROWS> get_identity_matrix(const int &VALID_ROWS = MAX_ROWS)
{
    Matrix identity = Matrix<MAX_ROWS, MAX_ROWS>();
    identity.set_dim(VALID_ROWS, VALID_ROWS);
    forab(i, 0, VALID_ROWS)
    {
        identity(i, i) = 1;
    }
    return identity;
}

template <size_t MAX_ROWS>
Matrix<MAX_ROWS, MAX_ROWS> matrix_to_pow(const Matrix<MAX_ROWS, MAX_ROWS> &mat, int b)
{
    if (b == 0)
        return get_identity_matrix<MAX_ROWS>(mat.VALID_ROWS);
    else if (b == 1)
        return mat;
    else if (b % 2)
        return multiply_matrix(matrix_to_pow(multiply_matrix(mat, mat), b / 2), mat);
    else
        return matrix_to_pow(multiply_matrix(mat, mat), b / 2);
}

template <size_t MAX_ROWS, size_t MAX_COLUMNS>
void show_matrix(const Matrix<MAX_ROWS, MAX_COLUMNS> &mat)
{
    const int &VALID_ROWS = mat.VALID_ROWS;
    const int &VALID_COLUMNS = mat.VALID_COLUMNS;
    forab(i, 0, VALID_ROWS)
    {
        forab(j, 0, VALID_COLUMNS)
        {
            cout << mat(i, j) << ' ';
        }
        PL;
    }
    PL;
}
void solve()
{
    int x, y, w, M, K, N;
    cin >> N >> M >> K;
    Matrix<101, 101> mat(NOT_POSSIBLE);
    mat.set_dim(N + 1, N + 1);
    forab(i, 0, M)
    {
        cin >> x >> y >> w;
        if (mat(x, y) == NOT_POSSIBLE)
            mat(x, y) = w;
        else
            mat(x, y) = min(mat(x, y), w);
    }
    const auto &result = matrix_to_pow(mat, K);
    cout << result(1, N) << endl;
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