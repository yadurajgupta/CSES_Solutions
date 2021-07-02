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
#define int unsigned long long int
#define ordered_set(type) __gnu_pbds::tree<type, __gnu_pbds::null_type, less<type>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>
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
int N, max_cuts;
bool number_of_cuts(vector<int> &arr, int max_sum, int max_cuts)
{
    int cuts = 1;
    int sum = 0;
    forab(i, 0, N)
    {
        if (sum + arr[i] > max_sum)
        {
            sum = 0;
            cuts++;
        }
        sum += arr[i];
    }
    return cuts <= max_cuts;
}
int binary_search_on_answer(vector<int> &arr, int max_cuts)
{
    int min_sum = *max_element(all(arr));
    int max_sum = accumulate(all(arr), 0LL);

    if (max_cuts == 1)
        return max_sum;
    if (max_cuts == N)
        return min_sum;

    int mid = -1;
    if (number_of_cuts(arr, min_sum, max_cuts))
        return min_sum;

    int ans = ULLONG_MAX;
    while (min_sum <= max_sum)
    {
        if (mid == (min_sum + max_sum) / 2)
            break;
        mid = (min_sum + max_sum) / 2;
        if (number_of_cuts(arr, mid, max_cuts))
        {
            ans = min(ans, mid);
            max_sum = mid;
        }
        else
        {
            min_sum = mid;
        }
    }
    return ans;
}
void solve()
{
    cin >> N >> max_cuts;
    invec(int, A, N);
    cout << binary_search_on_answer(A, max_cuts) << endl;
}
int32_t main()
{
    IOS;
    solve();
    return 0;
}