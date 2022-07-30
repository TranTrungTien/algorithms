// ref https://leetcode.com/problems/multiply-strings/

// Memory limit exceeded ........
#include "iostream"
#include "vector"
#include "string"

unsigned product(char x, char y)
{
    return (x - '0') * (y - '0');
}
unsigned add(unsigned x, unsigned y)
{
    return (x) + (y);
}

std::string multiply(std::string num1, std::string num2)
{
    const int num1Length = num1.length();
    const int num2Length = num2.length();
    std::vector<std::string> container;
    for (int i = num2Length - 1; i >= 0; i--)
    {
        unsigned remainder = 0;
        std::string temp = "";
        for (int j = num1Length - 1; j >= 0; j--)
        {
            const unsigned data = product(num2[i], num1[j]) + remainder;
            unsigned result = data;
            if (j == 0)
            {
                remainder = 0;
            }
            else
            {
                result = data % 10;
                remainder = data / 10;
            }
            temp = std::to_string(result) + temp;
        }
        container.push_back(temp);
    }
    unsigned maxLoop = 0;
    const auto maxContainer = (int)container.size();

    for (auto i = 0; i < maxContainer - 1; i++)
    {
        maxLoop = std::max(container[i].length(), container[i + 1].length());
    }
    maxLoop += maxContainer - 1;
    for (auto c : container)
    {
        std::cout << "c :" << c << std::endl;
    }
    for (auto i = 0; i < maxContainer; i++)
    {
        const std::string back(i, '0');
        container[i] += back;
        const unsigned int currentLength = container[i].length();
        const std::string front(maxLoop - currentLength, '0');
        container[i] = front + container[i];
    }
    std::string final = "";
    int remainder = 0;
    for (int i = maxLoop - 1; i >= 0; i--)
    {
        unsigned int sum = 0;
        for (auto j = 0; j < maxContainer; j++)
        {
            sum += container[j][i] - '0';
        }
        sum += remainder;
        if (sum >= 10 && i != 0)
        {
            remainder = sum / 10;
            sum %= 10;
        }
        else
        {
            remainder = 0;
        }
        final = std::to_string(sum) + final;
    }
    return final;
}

int main(int argc, char **argv)
{
    std::string num1 = "123456789", num2 = "987654321";
    std::cout << "result: \n"
              << multiply(num1, num2) << std::endl;
    return 0;
}