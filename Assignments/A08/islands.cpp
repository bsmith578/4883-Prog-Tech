class Solution {
public:
    //Recursive Depth First Search
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0')
            return;
        //Mark current cell with 0 to show it has been visited
        grid[i][j] = '0';

        //Perform a recursive DFS on the current cell's
        //vertical and horizontal neightbors
        dfs(grid, i + 1, j);  //down
        dfs(grid, i - 1, j);  //up
        dfs(grid, i, j + 1);  //right
        dfs(grid, i, j - 1);  //left
    }

    int numIslands(vector<vector<char>>& grid) {
        //keep track of number of islands
        int count = 0;

        //If no values in grid return 0
        //as there are no islands
        if(grid.empty())
            return 0;

        //Iterate through each row and column performing
        //a DFS to count the number of islands
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        //return total num of islands
        return count;
    }
};