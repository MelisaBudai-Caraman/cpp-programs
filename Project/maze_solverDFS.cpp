#include <iostream>
#include <vector>
using namespace std;


int dx[] = {1, 0, -1, 0};   // directions for right, down, left, up
int dy[] = {0, 1, 0, -1};

// check if a move is possible
bool isValid(int x, int y, vector<vector<int>> &maze, vector<vector<bool>> &visited) {
    int n = maze.size();
    int m = maze[0].size();


    return (x >= 0 && x < n && y >= 0 && y < m && maze[x][y] == 0 && !visited[x][y]);
}

// solving the maze DFS
bool solveMazeDFS(int x, int y, vector<vector<int>> &maze, vector<vector<bool>> &visited) {
    int n = maze.size();
    int m = maze[0].size();


    if (x == n - 1 && y == m - 1) {
        return true;
    }


    visited[x][y] = true;

    // moving in all 4 directions
    for (int dir = 0; dir < 4; dir++) {
        int newX = x + dx[dir];  // new row
        int newY = y + dy[dir];  // New column

        if (isValid(newX, newY, maze, visited)) {
            // if we can find the path by moving in this direction, return true
            if (solveMazeDFS(newX, newY, maze, visited)) {
                return true;
            }
        }
    }

    // if none of the moves worked, backtrack by unmarking the cell
    visited[x][y] = false;
    return false;
}

int main() {
    int n, m;

    cout << "Welcome to the maze!" << endl;
    cout << "enter the dimensions of the maze (rows and columns): ";
    cin >> n >> m;

    vector<vector<int>> maze(n, vector<int>(m));
    cout << "Now, enter the maze layout (0 for open path, 1 for wall):" << endl;

    //the maze layout from the user
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }


    vector<vector<bool>> visited(n, vector<bool>(m, false));

    // if start or goal is blocked, return
    if (maze[0][0] == 1 || maze[n - 1][m - 1] == 1) {
        cout << "Sorry, no path could be found through the maze." << endl;
        return 0;
    }

    if (solveMazeDFS(0, 0, maze, visited)) {
        cout << "Bravoo! A path was found from start to end!" << endl;
    } else {
        cout << "Sorry, no path could be found through the maze." << endl;
    }

    return 0;
}
