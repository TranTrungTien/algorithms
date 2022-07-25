// ref https://www.hackerrank.com/challenges/append-and-delete/problem?isFullScreen=true

#include "iostream"
#include "string"

int sameCharactersLength(const std::string s, const std::string t)
{
    int sameCounter = 0;
    for (int i = 0, j = 0; i < s.length() && j < t.length(); ++i, ++j)
    {
        if (s[i] == t[j])
            ++sameCounter;
        else
        {
            break;
        }
    }
    return sameCounter;
}
bool isSameOddOrEven(int i, int j)
{
    return (i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0);
}
std::string appendAndDelete(std::string s, std::string t, int k)
{

    int sLength = s.length();
    int tLength = t.length();
    int sameCharacterLength = sameCharactersLength(s, t);
    std::cout << "s length: " << sLength << " t length: " << tLength << sameCharacterLength << std::endl;
    if (sLength + tLength < k)
        return "Yes";

    else if (((sLength - sameCharacterLength) + (tLength - sameCharacterLength)) == k)
    {
        return "Yes";
    }

    else if (sLength == tLength)
    {
        if ((sLength + tLength) - k + 1 == 0)
            return "Yes";
        else if (sLength - sameCharacterLength == k / 2)
            return "Yes";
        else if (k % 2 == 0 && sLength == sameCharacterLength)
            return "Yes";
        else
            return "No";
    }
    else if (isSameOddOrEven(((sLength - sameCharacterLength) + (tLength - sameCharacterLength)), k))
    {
        return "Yes";
    }
    else
    {
        return "No";
    }
}

int main(int argc, char **argv)
{
    std::cout << appendAndDelete("asdfqwertyuighjkzxcvasdfqwertyuighjkzxcvasdfqwertyuighjkzxcvasdfqwertyuighjkzxcvasdfqwertyuighjkzxcv", "asdfqwertyuighjkzxcvasdfqwertyuighjkzxcvasdfqwertyuighjkzxcvasdfqwertyuighjkzxcvasdfqwertyuighjkzxcv", 20);
    return 0;
}