#include <bits/stdc++.h>
#include <iostream>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#undef INT_MAX
#define INT_MAX LLONG_MAX
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
int N, K;
void balance(multiset<int> &lower, multiset<int> &upper, int &lower_sum, int &upper_sum)
{
    int to_move;
    while (lower.size() > upper.size())
    {
        to_move = *lower.rbegin();
        upper.insert(to_move);
        lower.erase(lower.find(to_move));
        lower_sum -= to_move;
        upper_sum += to_move;
    }
    while (lower.size() < upper.size())
    {
        to_move = *upper.begin();
        lower.insert(to_move);
        upper.erase(upper.find(to_move));
        lower_sum += to_move;
        upper_sum -= to_move;
    }
}
int give_min_cost(int lower_sum, int upper_sum, multiset<int> &lower, multiset<int> &upper)
{
    int lower_size = lower.size();
    int upper_size = upper.size();
    vector<int> ans{*lower.rbegin()};

    if (K % 2 == 0)
        ans.push_back(*upper.begin());

    int min_cost = ULLONG_MAX;
    // PSL(min_cost);
    for (int poss_ans : ans)
    {
        min_cost = min(min_cost, poss_ans * lower_size - lower_sum + upper_sum - poss_ans * upper_size);
    }
    return min_cost;
}
void solve()
{
    cin >> N >> K;
    invec(int, A, N);
    if (K == 1)
    {
        forab(i, 0, N)
        {
            cout << 0 << " ";
        }
        PL;
        return;
    }
    multiset<int> lower(A.begin(), A.begin() + K);
    multiset<int> upper;
    int lower_sum = accumulate(all(lower), 0ULL);
    int upper_sum = 0;
    balance(lower, upper, lower_sum, upper_sum);

    cout << give_min_cost(lower_sum, upper_sum, lower, upper) << " ";
    forab(i, K, N)
    {
        int to_remove = A[i - K];
        if (lower.count(to_remove))
        {
            lower_sum -= to_remove;
            lower.erase(lower.find(to_remove));
        }
        else
        {
            upper_sum -= to_remove;
            upper.erase(upper.find(to_remove));
        }
        int to_add = A[i];
        if (!upper.empty() && to_add >= *upper.begin())
        {
            upper_sum += to_add;
            upper.insert(to_add);
        }
        else
        {
            lower_sum += to_add;
            lower.insert(to_add);
        }
        balance(lower, upper, lower_sum, upper_sum);
        cout << give_min_cost(lower_sum, upper_sum, lower, upper) << " ";
    }
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