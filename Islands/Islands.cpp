#include <vector>
#include <assert.h>

/*
 * To analyze satellite images, a geospatial company studies maps of remote ocean regions.
 * Each map is represented as a grid where land and water are identified.
 *
 * Your task is to determine how many separate islands are present on a given map.
 * The map is represented as a 2D grid of characters :
 *    - '1' represents land
 *    - '0' represents water
 *
 * An island is defined as a group of connected land cells.
 * Cells are considered connected if they are adjacent horizontally or vertically(not diagonally).
 * The grid is surrounded by water.
 * 
 * Implement the function count_islands which returns the total number of islands present in the map.
 */

int count_islands(std::vector<std::vector<char>>& grid)
{
    int islands = 0;

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == '1')
            {
                islands++;
                grid[i][j] = '0';

                std::vector<std::pair<int, int>> stack;
                stack.push_back({i, j});

                while (!stack.empty())
                {
                    std::pair<int, int> current = stack.back();
                    int x = current.first;
                    int y = current.second;
                    stack.pop_back();

                    if (x > 0 && grid[x - 1][y] == '1')
                    {
                        stack.push_back({x - 1, y});
                        grid[x - 1][y] = '0';
                    }
                    if (x < grid.size() - 1 && grid[x + 1][y] == '1')
                    {
                        stack.push_back({x + 1, y});
                        grid[x + 1][y] = '0';
                    }
                    if (y > 0 && grid[x][y - 1] == '1')
                    {
                        stack.push_back({x, y - 1});
                        grid[x][y - 1] = '0';
                    }
                    if (y < grid[x].size() - 1 && grid[x][y + 1] == '1')
                    {
                        stack.push_back({x, y + 1});
                        grid[x][y + 1] = '0';
                    }
                }
            }
        }
    }
    return islands;
}

int main()
{
    {
        std::vector<std::vector<char>> grid = {
            {'1','1','0','0'},
            {'1','1','0','0'},
            {'0','0','1','0'},
            {'0','0','0','1'}
        };
        assert(count_islands(grid) == 3);
    }

    {
        std::vector<std::vector<char>> grid = {
            {'1','1','1'},
            {'0','1','0'},
            {'1','1','1'}
        };
        assert(count_islands(grid) == 1);
    }

    return 0;
}