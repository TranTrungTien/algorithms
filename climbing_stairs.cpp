// ref https://leetcode.com/problems/climbing-stairs/

#include "iostream"

int climbStairs(int n)
{
    unsigned int pre = 0;
    unsigned int current = 1;
    unsigned int counter = 0;
    for (unsigned int i = 1; i <= (unsigned)n; i++)
    {
        counter = pre + current;
        pre = current;
        current = counter;
    }
    return counter;
}
// 1/1/1/2
// 1/1/2/1
// 1/2/1/1
// 2/1/1/1
// 1/2/2
// 2/1/2
// 2/2/1

int main(int argc, char **argv)
{
    std::cout << "total ways : " << climbStairs(6) << std::endl;
    return 0;
}

// 1 => 1;
// 2 => 2;
// 3 => 3;
// 4 => 5;
// 5 => 8;
// 6 => 13;
// 7 => 21;