#include <iostream>
#include <string>

#define rows 4
#define cols 4
#define wall 0
#define end -1

std::string path = "";

bool walk(int maze[rows][cols], bool visited[rows][cols], int r, int c, std::string curr_direction) 
{
    // TODO : Document this process
    // Base Cases
    // Check if the the curr pos is out of maze
    if (r < 0 || r > rows - 1 || c < 0 || c > cols - 1) {
        // return false because we cannot move there(or here) it is out of the maze
        path.append(curr_direction);
        return false;
    }

    // check if there is a wall in curr position
    if (maze[r][c] == wall) {
        path.append(curr_direction);
        // this path.append() made it easy
        // now if we look at path we can check the entire path rat took to reach end (if any).
        // cannot move here there is a wall in here.. go back to your previous position
        return false;
    }

    // check if rat already visited this pos
    if (visited[r][c] == true) {
        path.append(curr_direction);
        // cannot move here, this is already visited.. go back
        return false;
    }

    // if the curr pos is the end of the maze (i.e the rat reached the end of maze)
    if (maze[r][c] == end) {
        // mark it as visited and return true
        path.append(curr_direction); // either D or L or R or U (down, left, right, up)
        visited[r][c] = true;
        return true;
    }

    // pre recursion : before checking in all other Directions from position, mark this pos visited
    // and then add what direction we took to path
    visited[r][c] = true;
    path.append(curr_direction); // either D or L or R or U (down, left, right, up)
    // recursion : check, where can the rat move from curr position, we have 4 possible directions -> down, left, right, up
    // if we can move in any direction, walk to that position and again recursivly check all other directions form that position
    // check if we can walk in downward direction from curr pos
    if (walk(maze, visited, r + 1, c, "D")) {
        // if we can go downward then walk in that direction
        // return true to indicate that we can walk down
        return true;
    }
    // if we could not walk downward, then check if we can walk in left direction
    else if (walk(maze, visited, r, c - 1, "L")) {
        // if we can go left then walk in that direction
        // return true to indicate that we can walk left
        return true;
    }
    // if we could not walk downward, or left then check if we can take a right
    else if (walk(maze, visited, r, c + 1, "R")) {
        // if we can go right, then walk in right direction
        // return true to indicate that we can walk right
        return true;
    }
    // if we could not walk downward, or left or right then check if we can go in upward direction
    else if (walk(maze, visited, r - 1, c, "U")) {
        // if we can go up, then walk in upward direction
        // return true to indicate that we can walk up
        return true;
    }

    // post recursion : if the rat cannot move in any direction from the curr position then go back, where you came from 
    // and then check all directions from there.
    // To indicate that rat cannot make a move or walk from this position in the maze return false
    // and mark this pos as not visited
    // marking the position we already visited (false) will also help us to view the path rat took to reach end in visited 2d array. it looks someting like this
    // maze : 
    // int maze[rows][cols] = {
    //     {1, 0, 0, 0},
    //     {1, 0, 0, 0},
    //     {1, 1, 1, 0},
    //     {0, 0, 1, -1},
    // };
    // path rat took to reach end
    // (start)1 0 0 0
           // 1 0 0 0
           // 1 1 1 0
           // 0 0 1 1(end)
    // Directions from (0, 0)
    // DDRRDR
    // visited[r][c] = false;
    // if we don't make visited = false this is what we get
    // maze : 
    // int maze[rows][cols] = {
    //     {1, 0, 0, 0},
    //     {1, 1, 1, 0},
    //     {1, 0, 1, 0},
    //     {0, 0, 1, -1},
    // };
    // path rat took to reach end
    // Reached Destination
    // 1 0 0 0
    // 1 1 1 0
    // 1 0 1 0
    // 0 0 1 1
    // Directions from (0, 0)
    // may be this is good... we should not make it false, this will help us determine the entire path the rat travelled to 
    // reach it's destination (if any).
    return false;
}

void solve(int maze[rows][cols], bool visited[rows][cols], int r, int c, std::string curr_direction) 
{
    if (walk(maze, visited, r, c, "")) {
        std::cout << "Reached Destination" << std::endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < rows; j++) {
                std::cout << visited[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "Directions from (0, 0)" << std::endl;
        std::cout << path << std::endl;
    } else {
        std::cout << "There is not path to Destination" << std::endl;
    }
}

int main (int argc, char *argv[]) 
{
    int maze[rows][cols] = {
        {1, 0, 0, 0},
        {1, 1, 1, 0},
        {1, 0, 1, 0},
        {0, 0, 1, -1},
    };

    bool visited[rows][cols] = {false};
    solve(maze, visited, 0, 0, "");
    // Output is perfect and this is the only way out
    // There is a path
    //
    // 1 0 0 0
    // 1 0 0 0
    // 1 1 1 0
    // 0 0 1 1
    return 0;
}
