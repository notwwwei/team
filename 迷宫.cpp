#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int x;
    int y;
    int steps;
};

int shortestPath(vector<vector<int> >& maze, pair<int, int> start, pair<int, int> destination) {
    int m = maze.size();
    int n = maze[0].size();
    vector<vector<bool> > visited(m, vector<bool>(n, false));
    queue<Node> q;
    q.push({start.first, start.second, 0});
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        Node curr = q.front();
        q.pop();

        if (curr.x == destination.first && curr.y == destination.second) {
            return curr.steps;
        }

        // 向上移动
        if (curr.x > 0 && maze[curr.x - 1][curr.y] == 0 && !visited[curr.x - 1][curr.y]) {
            q.push({curr.x - 1, curr.y, curr.steps + 1});
            visited[curr.x - 1][curr.y] = true;
        }

        // 向下移动
        if (curr.x < m - 1 && maze[curr.x + 1][curr.y] == 0 && !visited[curr.x + 1][curr.y]) {
            q.push({curr.x + 1, curr.y, curr.steps + 1});
            visited[curr.x + 1][curr.y] = true;
        }

        // 向左移动
        if (curr.y > 0 && maze[curr.x][curr.y - 1] == 0 && !visited[curr.x][curr.y - 1]) {
            q.push({curr.x, curr.y - 1, curr.steps + 1});
            visited[curr.x][curr.y - 1] = true;
        }

        // 向右移动
        if (curr.y < n - 1 && maze[curr.x][curr.y + 1] == 0 && !visited[curr.x][curr.y + 1]) {
            q.push({curr.x, curr.y + 1, curr.steps + 1});
            visited[curr.x][curr.y + 1] = true;
        }
    }

    return -1;  // 无法到达终点
}

int main() {
    vector<vector<int> > maze = {
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };
    pair<int, int> start = make_pair(0, 0);
    pair<int, int> destination = make_pair(4, 4);

    int result = shortestPath(maze, start, destination);
    cout << "Shortest path length: " << result << endl;

    return 0;
}