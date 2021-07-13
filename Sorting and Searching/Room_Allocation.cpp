#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#undef INT_MAX
#define INT_MAX LLONG_MAX
#define endl '\n'
#define int long long
template <class type>
using oset = __gnu_pbds::tree<type, __gnu_pbds::null_type, less<type>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
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
#define PS(aa) cout << #aa << ' ' << aa << ' ';
#define PSL(aa)               \
    cout << #aa << ' ' << aa; \
    PL;
#define print(vv)          \
    for (auto &ii : vv)    \
        cout << ii << ' '; \
    PL;
#define printn(vv, NN)                      \
    forab(ii, 0, NN) cout << vv[ii] << ' '; \
    PL;
#define invec(type, vv, NN) \
    vector<type> vv(NN);    \
    for (auto &ii : vv)     \
        cin >> ii;

using namespace std;
int N, x, y;
void solve()
{
    cin >> N;
    vector<tuple<int, int, int>> A(2 * N);
    forab(i, 0, N)
    {
        cin >> x >> y;
        A[2 * i] = {x, -1, i};
        A[2 * i + 1] = {y, 1, i};
    }
    sort(all(A));
    int max_rooms = 0;
    int curr_rooms = 0;
    for (auto &[time, type, index] : A)
    {
        // cout << time<<" " << type << ", ";
        curr_rooms -= type;
        max_rooms = max(max_rooms, curr_rooms);
    }
    PL;
    cout << max_rooms << endl;
    set<int> st;
    forab(i, 1, max_rooms + 1)
        st.insert(i);
    map<int, int> index_to_room;
    for (auto &[time, type, index] : A)
    {
        if (type == -1)
        {
            index_to_room[index] = *st.begin();
            st.erase(st.begin());
        }
        else
        {
            st.insert(index_to_room[index]);
        }
    }
    for (auto &[index, room] : index_to_room)
        cout << room << " ";
    PL;
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