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
map<tuple<int, int, int>, pair<pair<int, int>, tuple<int, int, int>>> mp;
int give_hash_row(vector<bool> &row)
{
    int hash = 0;
    int index = 0;
    for (bool b : row)
    {
        if (b)
            hash = hash | 1 << index;
        index++;
    }
    return hash;
}
void set_row_from_hash(int hash, vector<bool> &row)
{
    forab(i, 0, N)
    {
        row[i] = (hash & 1 << i);
    }
}
tuple<int, int, int> give_hash_board(vector<vector<bool>> &board)
{
    vector<int> x(3);
    forab(i, 0, 3)
    {
        x[i] = give_hash_row(board[i]);
    }
    return {x[0], x[1], x[2]};
}
void set_board_from_hash(tuple<int, int, int> &hash, vector<vector<bool>> &board)
{
    set_row_from_hash(get<0>(hash), board[0]);
    set_row_from_hash(get<1>(hash), board[1]);
    set_row_from_hash(get<2>(hash), board[2]);
}

vector<int> get_tops(vector<vector<bool>> &board)
{
    vector<int> tops;
    forab(i, 0, 3)
    {
        bool is_set = false;
        forabd(j, N - 1, 0)
        {
            if (board[i][j])
            {
                is_set = true;
                tops.push_back(j);
                break;
            }
        }
        if (!is_set)
            tops.push_back(-1);
    }
    return tops;
}
vector<pair<pair<int, int>, int>> get_poss_moves(vector<vector<bool>> &board)
{
    vector<pair<pair<int, int>, int>> moves;
    vector<int> tops = get_tops(board);
    forab(i, 0, 3)
    {
        forab(j, 0, 3)
        {
            if (i == j || tops[i] == -1)
                continue;
            if (tops[j] == -1 || tops[i] > tops[j])
                moves.push_back({{i, j}, tops[i]});
        }
    }
    return moves;
}
void print_board(vector<vector<bool>> &board)
{
    forab(i, 0, 3)
    {
        cout << i << ": ";
        forab(j, 0, N)
        {
            if (board[i][j])
                cout << j + 1 << " ";
        }
        cout << endl;
    }
}
void move_disk(int source, int destination, int through, int disks)
{
    if (disks == 1)
    {
        cout << source << " " << destination << endl;
    }
    else
    {
        move_disk(source, through, destination, disks - 1);
        move_disk(source, destination, through, 1);
        move_disk(through, destination, source, disks - 1);
    }
}
void solve()
{

    cin >> N;
    cout << (1 << N) - 1 << endl;
    // Recursive
    {
        move_disk(1, 3, 2, N);
    }
    // BFS TLE
    {
        // vector<vector<bool>> board(3, vector<bool>(N, false));
        // vector<vector<bool>> curr_board(3, vector<bool>(N, false));
        // vector<vector<bool>> next_board(3, vector<bool>(N, false));
        // board[0] = vector<bool>(N, true);
        // auto hash = give_hash_board(board);
        // mp.clear();
        // mp[hash] = {{-1, -1}, {-1, -1, -1}};
        // queue<pair<tuple<int, int, int>, int>> que;
        // que.push({hash, 0});
        // auto final_hash = hash;
        // while (!que.empty())
        // {
        //     auto curr = que.front();
        //     que.pop();
        //     auto curr_hash = curr.first;
        //     int d = curr.second;
        //     set_board_from_hash(curr_hash, curr_board);
        //     bool is_ans = true;
        //     forab(i, 0, N)
        //     {
        //         if (!curr_board[2][i])
        //         {
        //             is_ans = false;
        //             break;
        //         }
        //     }
        //     if (is_ans)
        //     {
        //         cout << d << endl;
        //         final_hash = curr_hash;
        //         break;
        //     }
        //     auto moves = get_poss_moves(curr_board);
        //     for (auto &move : moves)
        //     {
        //         set_board_from_hash(curr_hash, next_board);
        //         int source = move.first.first;
        //         int destination = move.first.second;
        //         int num = move.second;
        //         next_board[source][num] = false;
        //         next_board[destination][num] = true;
        //         auto next_hash = give_hash_board(next_board);
        //         if (mp.count(next_hash))
        //             continue;
        //         mp[next_hash] = {{source + 1, destination + 1}, curr_hash};
        //         que.push({next_hash, d + 1});
        //     }
        // }
        // vector<pair<int, int>> moves;
        // while (true)
        // {
        //     auto prev = mp[final_hash];
        //     if (prev.second == make_tuple(-1, -1, -1))
        //         break;

        //     moves.push_back(prev.first);
        //     final_hash = prev.second;
        // }
        // reverse(all(moves));
        // for (auto move : moves)
        // {
        //     cout << move.first << " " << move.second << endl;
        // }
    }
}
int32_t main()
{
    IOS;
    solve();
    return 0;
}