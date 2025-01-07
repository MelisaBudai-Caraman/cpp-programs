#include <iostream>
#include <queue>
#include <vector>

using namespace std;


int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

//checking if th next cell is valid for movement
bool isValid(int x, int y, vector<vector<int>> &maze, vector<vector<bool>> &visited) {
    int n = maze.size();
    int m = maze[0].size();


    if (x >= 0 && x < n && y >= 0 && y < m && maze[x][y] == 0 && !visited[x][y]) {
        return true;
    }
    return false;
}

// BFS
bool solveMaze(vector<vector<int>> &maze) {
    int n = maze.size();
    int m = maze[0].size();


    vector<vector<bool>> visited(n, vector<bool>(m, false));

    // queue to store the current cell coordinates
    queue<pair<int, int>> q;

    // BFS start
    q.push({0, 0});
    visited[0][0] = true;

    // Run until there are cells to explore
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();


        if (x == n - 1 && y == m - 1) {
            return true;
        }

        // Try moving in all 4 directions
        for (int dir = 0; dir < 4; dir++) {
            int newX = x + dx[dir];
            int newY = y + dy[dir];

            if (isValid(newX, newY, maze, visited)) {
                q.push({newX, newY});
                visited[newX][newY] = true;  // Mark the cell as visited
            }
        }
    }


    return false;
}

int main() {
    int n, m;

    cout << "This is the Maze Solver!" << endl;
    cout << "enter the dimensions of the maze (rows and columns): ";
    cin >> n >> m;

    vector<vector<int>> maze(n, vector<int>(m));
    cout << "now, enter the maze layout (0 for open path, 1 for wall):" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }

    // Solve the maze and display the result
    if (solveMaze(maze)) {
        cout << "Bravoo! A path was found from start to end!" << endl;
    } else {
        cout << "Sorry, no path found" << endl;
    }

    return 0;
}
