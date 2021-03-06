#include <bits/stdc++.h>
#include <iostream>

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
int fre[26];
void solve()
{
    string S;
    cin >> S;
    // cin >> N;
    int N = S.size();
    for (char &c : S)
    {
        fre[c - 'A']++;
    }
    int odd = 0;
    int odd_index = -1;
    int s = 0;
    int e = S.size() - 1;
    forab(i, 0, 26)
    {
        if (fre[i] % 2)
        {
            odd++;
            odd_index = i;
        }
        else
        {
            while (fre[i])
            {
                S[s++] = S[e--] = i + 'A';
                fre[i] -= 2;
            }
        }
    }
    if (odd > 1)
    {
        cout << "NO SOLUTION" << endl;
        return;
    }
    if (odd_index != -1)
    {
        forab(i, s, e + 1)
        {
            S[i] = odd_index + 'A';
        }
    }
    forab(i, 0, N)
            cout
        << S[i];
    cout << endl;
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