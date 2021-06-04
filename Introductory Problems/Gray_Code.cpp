#include <iostream>
#include <bits/stdc++.h>

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#undef INT_MAX
#define INT_MAX LLONG_MAX
#define endl "\n"
#define int long long
#define forab(ii, aa, bb) for (int ii = aa; ii < bb; ii++)
#define forabd(ii, aa, bb) for (int ii = aa; ii >= bb; ii--)
#define forabi(ii, aa, bb, inc) for (int ii = aa; ii < bb; ii += inc)
#define all(aa) aa.begin(), aa.end()
#define rall(aa) aa.rbegin(), aa.rend()
#define twodi(type, name, NN, MM, II) vector<vector<type>> name(NN, vector<type>(MM, II));
#define twod(type, name, NN, MM) vector<vector<type>> name(NN, vector<type>(MM));
#define threedi(type, name, NN, MM, LL, II) vector<vector<vector<type>>> name(NN, vector<vector<type>>(MM, vector<type>(LL, II)));
#define threed(type, name, NN, MM, LL) vector<vector<vector<type>>> name(NN, vector<vector<type>>(MM, vector<type>(LL)));
#define PL cout << endl
#define print(vv)          \
    for (auto &ii : vv)    \
        cout << ii << ' '; \
    cout << endl;
#define printn(vv, NN)         \
    forab(ii, 0, NN)           \
    {                          \
        cout << vv[ii] << ' '; \
    }                          \
    cout << endl;
#define invec(type, vv, NN) \
    vector<type> vv(NN);    \
    for (auto &ii : vv)     \
        cin >> ii;

using namespace std;
int N;
void set_bits(int num, vector<bool> &bits)
{
    int index = 0;
    while (num)
    {
        bits[index++] = num % 2;
        num /= 2;
    }
}
void to_gray(vector<bool> &bits, vector<bool> &gray)
{
    gray.back() = bits.back();
    forabd(i, N - 2, 0)
    {
        gray[i] = bits[i + 1] ^ bits[i];
    }
}
void print_bin(vector<bool> &gray)
{
    for (bool b : gray)
        cout << (b ? '1' : '0');
    cout << endl;
}
void solve()
{
    cin >> N;
    int mx = pow(2, N);
    vector<bool> bits(N, false);
    vector<bool> gray(N, false);
    forab(i, 0, mx)
    {
        set_bits(i, bits);
        to_gray(bits, gray);
        print_bin(gray);
    }
}
int32_t main()
{
    IOS;
    // int T;
    // cin >> T;
    // while (T--)
    solve();
    return 0;
}