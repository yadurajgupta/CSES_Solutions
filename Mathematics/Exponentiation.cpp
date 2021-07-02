#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
using namespace std;

// #define _DEBUG_CODE 1
#ifdef _DEBUG_CODE
#define FILEIO                                                      \
    freopen("C:\\Users\\yadur\\Desktop\\CC\\IN.txt", "r", stdin);   \
    freopen("C:\\Users\\yadur\\Desktop\\CC\\OUT.txt", "w", stdout); \
    cout << "DEBUGGING" << endl;
#define APPLY_NOT_IN_GDB cout << "!tup";
#endif

#ifndef _DEBUG_CODE
#define FILEIO ;
#define APPLY_NOT_IN_GDB                        \
    cout << '(';                                \
    bool first = true;                          \
    std::apply([&first](auto &&...args)         \
               {                                \
                   auto print = [&](auto &&val) \
                   {                            \
                       if (!first)              \
                           cout << ',' << ' ';  \
                       _debug_p(val);           \
                       first = false;           \
                   };                           \
                   (print(args), ...);          \
               },                               \
               t);                              \
    cout << ' ' << ')';
#endif

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
#define printn(vv, NN)                              \
    forab(ii, 0, NN) _debug_p(vv[ii]), cout << ' '; \
    PL;
#ifndef ONLINE_JUDGE
#define PNAV(x)        \
    cout << #x << ' '; \
    _debug_p(x);       \
    cout << ' ';
#define debug(x1) \
    PNAV(x1)      \
    cout << endl;
#define debug2(x1, x2) \
    PNAV(x1);          \
    debug(x2);
#define debug3(x1, x2, x3) \
    PNAV(x1);              \
    debug2(x2, x3);
#define debug4(x1, x2, x3, x4) \
    PNAV(x1);                  \
    debug3(x2, x3, x4);
#define debug5(x1, x2, x3, x4, x5) \
    PNAV(x1);                      \
    debug4(x2, x3, x4, x5);
#define debug6(x1, x2, x3, x4, x5, x6) \
    PNAV(x1);                          \
    debug5(x2, x3, x4, x5, x6);
#define IOS ;
#endif

#ifdef ONLINE_JUDGE
#define debug(x1) ;
#define debug2(x1, x2) ;
#define debug3(x1, x2, x3) ;
#define debug4(x1, x2, x3, x4) ;
#define debug5(x1, x2, x3, x4, x5) ;
#define debug6(x1, x2, x3, x4, x5, x6) ;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
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
template <typename T>
void _debug_p(vector<T> vec);
template <typename T>
void _debug_p(set<T> vec);
template <typename T>
void _debug_p(unordered_set<T> vec);
template <typename T>
void _debug_p(multiset<T> vec);
template <typename T>
void _debug_p(unordered_multiset<T> vec);
template <typename t1, typename t2>
void _debug_p(pair<t1, t2> p);
template <class... Args>
void _debug_p(tuple<Args...> t);
template <typename t1, typename t2>
void _debug_p(map<t1, t2> mp);
template <typename t1, typename t2>
void _debug_p(unordered_map<t1, t2> mp);
template <typename t1, typename t2>
void _debug_p(multimap<t1, t2> mp);
template <typename t1, typename t2>
void _debug_p(unordered_multimap<t1, t2> mp);
/* TEMPLATE END */
int N, x, y, a, b;
const int NMAX = 1e5 + 5;
int MOD = 1e9 + 7;
int modAdd(int a, int b) { return (a % MOD + b % MOD) % MOD; }
int modMult(int a, int b) { return ((a % MOD) * (b % MOD)) % MOD; }
int modPow(int a, int b) //a^b
{
    if (a == 0 && b == 0)
        return 1;
    if (a == 0 || a == 1)
        return a;
    else if (b == 0)
        return 1;
    else if (b == 1)
        return a;
    else if (b % 2)
        return modMult(a, modPow(modMult(a, a), (b - 1) / 2));
    else
        return modPow(modMult(a, a), b / 2);
}
void solve()
{
    cin >> a >> b;
    cout << modPow(a, b) << endl;
}
int32_t main()
{
    IOS;
    FILEIO;
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}

void _debug_p(int T)
{
    cout << T;
}
void _debug_p(int32_t T)
{
    cout << T;
}
void _debug_p(unsigned int T)
{
    cout << T;
}
void _debug_p(unsigned T)
{
    cout << T;
}
void _debug_p(double T)
{
    cout << T << 'd';
}
void _debug_p(string T)
{
    cout << '"' << T << '"';
}
void _debug_p(const char T[])
{
    cout << '"' << T << '"';
}
void _debug_p(char T)
{
    cout << '\'' << T << '\'';
}
void _debug_p(bool T)
{
    cout << (T ? '1' : '0') << 'b';
}
template <typename T>
void _debug_p(vector<T> vec)
{
    cout << '[';
    bool first = true;
    for (auto it : vec)
    {
        if (!first)
            cout << ',' << ' ';
        _debug_p(it);
        first = false;
    }
    cout << ']';
}
template <typename T>
void _debug_p(set<T> vec)
{
    cout << '[';
    bool first = true;
    for (auto it : vec)
    {
        if (!first)
            cout << ',' << ' ';
        _debug_p(it);
        first = false;
    }
    cout << ']';
}
template <typename T>
void _debug_p(unordered_set<T> vec)
{
    cout << '[';
    bool first = true;
    for (auto it : vec)
    {
        if (!first)
            cout << ',' << ' ';
        _debug_p(it);
        first = false;
    }
    cout << ']';
}
template <typename T>
void _debug_p(multiset<T> vec)
{
    cout << '[';
    bool first = true;
    for (auto it : vec)
    {
        if (!first)
            cout << ',' << ' ';
        _debug_p(it);
        first = false;
    }
    cout << ']';
}
template <typename T>
void _debug_p(unordered_multiset<T> vec)
{
    cout << '[';
    bool first = true;
    for (auto it : vec)
    {
        if (!first)
            cout << ',' << ' ';
        _debug_p(it);
        first = false;
    }
    cout << ']';
}
template <typename t1, typename t2>
void _debug_p(pair<t1, t2> p)
{
    cout << '(';
    _debug_p(p.first);
    cout << ',' << ' ';
    _debug_p(p.second);
    cout << ')';
}
template <class... Args>
void _debug_p(tuple<Args...> t)
{
    APPLY_NOT_IN_GDB;
}
template <typename t1, typename t2>
void _debug_p(map<t1, t2> mp)
{
    cout << '[';
    bool first = true;
    for (auto [it, it2] : mp)
    {
        if (!first)
            cout << ',' << ' ';
        cout << '{';
        _debug_p(it);
        cout << ':';
        _debug_p(it2);
        cout << '}';
        first = false;
    }
    cout << ']';
}
template <typename t1, typename t2>
void _debug_p(unordered_map<t1, t2> mp)
{
    cout << '[';
    bool first = true;
    for (auto [it, it2] : mp)
    {
        if (!first)
            cout << ',' << ' ';
        cout << '{';
        _debug_p(it);
        cout << ':';
        _debug_p(it2);
        cout << '}';
        first = false;
    }
    cout << ']';
}
template <typename t1, typename t2>
void _debug_p(multimap<t1, t2> mp)
{
    cout << '[';
    bool first = true;
    for (auto [it, it2] : mp)
    {
        if (!first)
            cout << ',' << ' ';
        cout << '{';
        _debug_p(it);
        cout << ':';
        _debug_p(it2);
        cout << '}';
        first = false;
    }
    cout << ']';
}
template <typename t1, typename t2>
void _debug_p(unordered_multimap<t1, t2> mp)
{
    cout << '[';
    bool first = true;
    for (auto [it, it2] : mp)
    {
        if (!first)
            cout << ',' << ' ';
        cout << '{';
        _debug_p(it);
        cout << ':';
        _debug_p(it2);
        cout << '}';
        first = false;
    }
    cout << ']';
}