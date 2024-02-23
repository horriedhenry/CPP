#include <iostream>
#include <string>
#include <vector>

#define rows 4
#define cols 4
#define wall 0
#define end -1

std::string path = "";

bool walk(int maze[rows][cols], bool visited[rows][cols], int r, int c) {
    // out of bounds
    // std::cout << "r : " << r << ", c : " << c << "\n";
    if (r < 0 || r >= rows || c < 0 || c >= cols) {
        return false;
    }

    // wall
    if (maze[r][c] == wall) {
        return false;
    }

    // visited
    if (visited[r][c] == true) {
        return false;
    }

    // end
    if (maze[r][c] == end) {
        visited[r][c] = true;
        return true;
    }

    visited[r][c] = true;
    if (walk(maze, visited, r + 1, c)) {
        return true;
    } else if (walk(maze, visited, r, c - 1)) {
        return true;
    } else if (walk(maze, visited, r, c + 1)) {
        return true;
    } else if (walk(maze, visited, r - 1, c)) {
        return true;
    }
    visited[r][c] = false;
    return false;
}

void solve(int maze[rows][cols], bool visited[rows][cols], int r, int c) {
    if (walk(maze, visited, r, c)) {
        std::cout << "There is a path" << std::endl;
        std::cout << path << std::endl;
    } else {
        std::cout << "There is no path" << std::endl;
    }
}

int main (int argc, char *argv[]) 
{
    int maze[rows][cols] = {
        {1, 0, 0, 0},
        {1, 0, 0, 0},
        {1, 1, 1, 0},
        {0, 0, 1, -1},
    };

    bool visited[rows][cols] = {false};
    std::vector<int> ans;
    solve(maze, visited, 0, 0);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            std::cout << visited[i][j] << " ";
        }
        std::cout << std::endl;
    }
    // Output is perfect and this is the only way out
    // There is a path
    //
    // 1 0 0 0
    // 1 0 0 0
    // 1 1 1 0
    // 0 0 1 1
    return 0;
}
