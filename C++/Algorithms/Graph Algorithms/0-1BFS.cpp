// #include <bits/stdc++.h>
// #define ll long long
// #define ld long double
// #define pb push_back
// #define ff first
// #define ss second
// #define vll vector<ll>
// #define F(i,a,n) for(ll i=a;i<n;i++)
// #define all(x) x.begin(),x.end()
// #define rall(x) x.rbegin(),x.rend()

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>


// // order_of_key (k) : Number of items strictly smaller than k .
// // find_by_order(k) : K-th element in a set (counting from zero).

// using namespace std;

// // Problem Statement :

// /*



// */



// int n, m;
// char a[1001][1001];
// int dis[1001][1001];
// int dx[4] = {0, 0, 1, -1};
// int dy[4] = {1, -1, 0, 0};

// bool valid(int x, int y) {

//     if (x < 0 || y < 0 || x >= n || y >= m || a[x][y] == '#')return false;
//     return true;

// }

// pair<int, int>dp[1001][1001][4];

// pair<int, int>rec(int x, int y, int dir)
// {
//     if (dp[x][y][dir] != make_pair(-1, -1)) {
//         return dp[x][y][dir];
//     }
//     int nx = x + dx[dir];
//     int ny = y + dy[dir];
//     if (!valid(nx, ny)) {
//         return dp[x][y][dir] = {x, y};
//     }
//     else {
//         return dp[x][y][dir] = rec(nx, ny, dir);
//     }


// }

// void bfs(int x, int y) {

//     queue<pair<int, int>>q;
//     q.push({x, y});
//     dis[x][y] = 0;
//     while (!q.empty()) {

//         int sx = q.front().ff;
//         int sy = q.front().ss;
//         int curd = dis[sx][sy];
//         q.pop();
//         for (int i = 0; i < 4; i++) {

//             pair<int, int>c = rec(sx, sy, i);
//             int cx = c.ff;
//             int cy = c.ss;
//             if (!valid(cx, cy)) {
//                 continue;
//             }
//             if (dis[cx][cy] > 1 + curd) {
//                 dis[cx][cy] = 1 + curd;
//                 q.push({cx, cy});
//             }
//         }

//     }


// }


// int main() {

//     int tc;
//     tc = 1;
//     // factorial();
//     // cin >> tc; // take test cases
//     while (tc--) {

//         cin >> n >> m;
//         int sx, sy, ex, ey;
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 cin >> a[i][j];
//                 // robot's position
//                 if (a[i][j] == 'S') {
//                     sx = i;
//                     sy = j;
//                 }
//                 else if (a[i][j] == 'E') {
//                     ex = i;
//                     ey = j;
//                 }
//                 dis[i][j] = 1e9;
//                 for (int k = 0; k < 4; k++)
//                 {
//                     dp[i][j][k] = { -1, -1};

//                 }
//             }
//         }
//         bfs(sx, sy);
//         // cout << sx << " " << sy << '\n';
//         // cout << ex << " " << ey << '\n';
//         cout << dis[ex][ey] << '\n';

//     }


//     return 0;

// }


#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define vll vector<ll>
#define F(i,a,n) for(ll i=a;i<n;i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>


// order_of_key (k) : Number of items strictly smaller than k .
// find_by_order(k) : K-th element in a set (counting from zero).

using namespace std;

// Problem Statement :

/*

    There is a nxm grid given. With certain blocked cells or walls.There is a robot
    standing at (sx,sy) in the grid.If a robot is given a push in either of the directions
    (up ,down,left and right) , it moves continuously until it strikes an obstacle(be it wall
    or boundary of grid).We need to find the minimum amount of pushes given to the robot
    in order to reach its destination cell.

    Consider the sample below , S is the robot's starting position and E is the destination cell
    # is a blocked wall and . is a free cell.

*/


/*
    Testcase :

    6 6
    .#....
    ...#.#
    .S....
    ......
    ....E.
    #.#...

*/


int n, m;
char a[1001][1001];
int dis[1001][1001][4];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool valid(int x, int y) {

    if (x < 0 || y < 0 || x >= n || y >= m || a[x][y] == '#')return false;
    return true;

}


void bfs(int x, int y) {

    deque<pair<pair<int, int>, int>>q;
    for (int i = 0; i < 4; i++) {
        q.push_front({{x, y}, i});
        dis[x][y][i] = 1;
        // why distance one?
        // Becausing we are pushing it in some direction

    }
    while (!q.empty()) {

        int sx = q.front().ff.ff;
        int sy = q.front().ff.ss;
        int dir = q.front().ss;
        int curd = dis[sx][sy][dir];
        q.pop_front();

        // same direction

        int cx = sx + dx[dir];
        int cy = sy + dy[dir];
        if (valid(cx, cy) ) {

            if (dis[cx][cy][dir] > curd) {

                dis[cx][cy][dir] = curd;
                q.push_front({{cx, cy}, dir});
            }
        }
        else {

            for (int i = 0; i < 4; i++) {

                if (dis[sx][sy][i] > 1 + curd) {
                    dis[sx][sy][i] = 1 + curd;
                    q.push_back({{sx, sy}, i});
                }
            }

        }




    }


}



int main() {

    int tc;
    tc = 1;
    // factorial();
    // cin >> tc; // take test cases
    while (tc--) {

        cin >> n >> m;
        int sx, sy, ex, ey;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
                // robot's position
                if (a[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }
                else if (a[i][j] == 'E') {
                    ex = i;
                    ey = j;
                }
                for (int k = 0; k < 4; k++)
                {
                    dis[i][j][k] = 1e9;

                }
            }
        }
        bfs(sx, sy);
        cout << min({dis[ex][ey][0], dis[ex][ey][1], dis[ex][ey][2], dis[ex][ey][3]}) << '\n';

    }


    return 0;

}
