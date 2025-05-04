#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAX_N = 10005;
string grid[MAX_N];
vector<vector<vector<int>>> dist;
int n, m;

enum Direction { LEFT = 0, RIGHT = 1, UP = 2, DOWN = 3, NONE = 4 };

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

void dijkstra(int startX, int startY) {
    dist[NONE][startX][startY] = 0;
    priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<>> pq;
    pq.push({0, NONE, startX, startY});

    while (!pq.empty()) {
        auto [cost, dir, x, y] = pq.top(); pq.pop();

        for (int d = 0; d < 4; ++d) {
            if (d == dir) continue;

            for (int step = 1; step <= 3; ++step) {
                int nx = x + dx[d] * step;
                int ny = y + dy[d] * step;

                if (nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] == '#')
                    break;

                if (dist[d][nx][ny] > cost + step) {
                    dist[d][nx][ny] = cost + step;
                    pq.push({dist[d][nx][ny], d, nx, ny});
                }
            }
        }
    }
}


int main() {
    cin >> n >> m;
    pair<int, int> start, target;

    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'S') start = {i, j};
            if (grid[i][j] == 'T') target = {i, j};
        }
    }

    dist.assign(5, vector<vector<int>>(n, vector<int>(m, INF)));
    dijkstra(start.first, start.second);

    int result = INF;
    for (int d = 0; d < 4; ++d)
        result = min(result, dist[d][target.first][target.second]);

    cout << (result == INF ? -1 : result) << "\n";
}
