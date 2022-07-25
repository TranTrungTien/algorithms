// ref https://www.hackerrank.com/challenges/cavity-map/problem?isFullScreen=true

#include "iostream"
#include "string"
#include "vector"

bool isDeeper(const char target, const char above, const char bottom, const char left, const char right)
{
    const unsigned targetI = target - '0';
    const unsigned aboveI = above - '0';
    const unsigned bottomI = bottom - '0';
    const unsigned rightI = right - '0';
    const unsigned leftI = left - '0';

    return targetI > aboveI && targetI > bottomI && targetI > rightI && targetI > leftI;
}

std::vector<std::string> cavityMap(const std::vector<std::string> &grid)
{
    std::vector<std::string> result = grid;
    const unsigned xLength = result.size() - 1;
    const unsigned yLength = result[0].size() - 1;

    for (unsigned i = 1; i < xLength; ++i)
    {

        for (unsigned j = 1; j < yLength; ++j)
        {
            const bool isElementDeeper = isDeeper(grid[i][j], grid[i][j - 1], grid[i][j + 1], grid[i - 1][j], grid[i + 1][j]);
            if (isElementDeeper)
            {
                result[i][j] = 'X';
            }
        }
    }

    return result;
}

int main(int argc, char *argv[])
{
    std::vector<std::string> grid = {"179443854", "961621369", "164139922", "968633951", "812882578", "257829163", "812438597", "176656233", "485773814"};
    for (auto &&value : cavityMap(grid))
    {
        std::cout << "value : " << value << std::endl;
    }

    return 0;
}