#include <bits/stdc++.h>
#include <iostream>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define endl '\n'
#define int unsigned long long
//#define ordered_set(type) __gnu_pbds::tree<type, __gnu_pbds::null_type, less<type>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>
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
int N, M;
bool give_max_elements_given_time(int time, map<int, int> &mp)
{
    int items = 0;
    for (auto &[time_period, fre] : mp)
    {
        if (time_period > time)
        {
            break;
        }
        items += fre * (time / time_period);
        if (items >= M)
            break;
    }
    return items >= M;
}
int bin_ser(map<int, int> &mp)
{
    int s = 0;
    int e = LLONG_MAX;
    int mid = -1;
    int ans = LLONG_MAX;
    while (s <= e)
    {
        if (mid == (s + e) / 2)
            break;
        mid = (s + e) / 2;
        if (give_max_elements_given_time(mid, mp))
        {
            ans = min(ans, mid);
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}
void solve()
{
    cin >> N >> M;
    invec(int, A, N);
    map<int, int> mp;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> st;
    forab(i, 0, N)
    {
        mp[A[i]]++;
    }
    for (auto [time_period, fre] : mp)
    {
        st.push({0 + time_period, time_period, fre});
    }
    cout << bin_ser(mp) << endl;
    // int num = 0;
    // int max_end_time = 0;
    // int end_time, time_period, fre, next_end_time, next_time_period, next_fre;
    // while (num < M)
    // {
    //     tie(end_time, time_period, fre) = st.top();
    //     st.pop();
    //     int times = 1;
    //     if (!st.empty())
    //     {
    //         tie(next_end_time, next_time_period, next_fre) = st.top();
    //         int time_left = next_end_time - end_time;
    //         int times = time_left / time_period;
    //         if (num + times * fre > M)
    //         {
    //             times = (M - num) / fre;
    //         }
    //     }
    //     st.push({end_time + times * time_period, time_period, fre});
    //     num += times * fre;
    //     max_end_time = end_time + (times - 1) * time_period;
    // }
    // cout << max_end_time << endl;
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