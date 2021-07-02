#include <bits/stdc++.h>
#include <iostream>

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define endl "\n"
#define int long long
#define all(a) a.begin(), a.end()
#define forn(i, N) for (int i = 0; i < N; i++)
#define print(x)          \
    for (auto i : x)      \
        cout << i << ' '; \
    cout << endl;

using namespace std;
int N, i, T, x, y, K;

void solve()
{
    cin >> N >> K;
    vector<pair<int, int>> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        A[i] = {y, x};
    }
    sort(all(A));
    multiset<int> st;
    forn(i, K) st.insert(0);
    int cnt = 0;
    forn(i, N)
    {
        auto it = st.upper_bound(A[i].second);
        if (it == st.begin())
            continue;
        cnt++;
        st.erase(prev(it));
        st.insert(A[i].first);
    }
    cout << cnt << endl;
}
int32_t main()
{
    IOS
    // cin>>T;
    // while(T--)
    solve();
    return 0;
}