// ref https://www.hackerrank.com/challenges/the-time-in-words/problem?isFullScreen=true

#include "iostream"
#include "string"
#include "vector"

enum TimeToWords
{
    Zero,
    One,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Eleven,
    Twelve,
    Thirteen,
    Fourteen,
    Fifteen,
    Sixteen,
    Seventeen,
    Eighteen,
    Nineteen,
    Twenty
};

std::string convertEnumToString(const int value)
{
    switch (value)
    {
    case TimeToWords::One:
        return "one";
        break;
    case TimeToWords::Two:
        return "two";
        break;

    case TimeToWords::Three:
        return "three";
        break;

    case TimeToWords::Four:
        return "four";
        break;

    case TimeToWords::Five:
        return "five";
        break;
    case TimeToWords::Six:
        return "six";
        break;

    case TimeToWords::Seven:
        return "seven";
        break;

    case TimeToWords::Eight:
        return "eight";
        break;

    case TimeToWords::Nine:
        return "nine";
        break;

    case TimeToWords::Ten:
        return "ten";
        break;
    case TimeToWords::Eleven:
        return "eleven";
        break;
    case TimeToWords::Twelve:
        return "twelve";
        break;
    case TimeToWords::Thirteen:
        return "thirteen";
        break;
    case TimeToWords::Fourteen:
        return "fourteen";
        break;
    case TimeToWords::Fifteen:
        return "fifteen";
        break;
    case TimeToWords::Sixteen:
        return "sixteen";
        break;
    case TimeToWords::Seventeen:
        return "seventeen";
        break;
    case TimeToWords::Eighteen:
        return "eighteen";
        break;
    case TimeToWords::Nineteen:
        return "nineteen";
        break;
    case TimeToWords::Twenty:
        return "twenty";
        break;
    default:
        return "zero";
        break;
    }
}

const std::vector<int>
splitTime(const int &n)
{
    std::vector<int> result;
    const int secondsNumber = n % 10;
    const int firstNumber = n - secondsNumber;
    result.push_back(firstNumber);
    result.push_back(secondsNumber);
    return result;
}

std::string convertHoursToString(const int &h)
{
    std::string hoursWords = "";

    if (h <= 20)
    {
        return convertEnumToString(h);
    }
    else if (h <= 23 && h >= 21)
    {
        const std::vector<int> result = splitTime(h);
        for (auto x : result)
        {
            hoursWords += convertEnumToString(x);
            hoursWords += " ";
        }
    }
    return hoursWords;
}

std::string convertMinutesToWords(const int &m, const std::string &hoursWords, const std::string &tobe)
{
    if (m == 0)
    {
        return hoursWords + " o' clock";
    }
    else if (m == 1)
    {
        return convertEnumToString(m) + " minute " + tobe + hoursWords;
    }
    if (m == 30)
        return "half " + tobe + hoursWords;
    else if (m == 15)
        return "quarter " + tobe + hoursWords;
    else if (m == 1)
        return "one minute " + tobe + hoursWords;
    else if (m <= 29)
    {
        if (m > 21)
        {
            std::string minuteWords = "";
            const std::vector<int> result = splitTime(m);
            for (auto x : result)
            {
                minuteWords += convertEnumToString(x);
                minuteWords += " ";
            }
            return minuteWords + "minutes " + tobe + hoursWords;
        }
        else
        {
            return convertEnumToString(m) += " minutes " + tobe + hoursWords;
        }
    }
    else
    {
        return "";
    }
}

std::string timeInWords(int h, int m)
{
    std::cout << "m :" << m << std::endl;

    if (m >= 0 && m <= 30)
    {
        const std::string hoursWords = convertHoursToString(h);
        return convertMinutesToWords(m, hoursWords, "past ");
    }
    else if (m >= 31 && m <= 59)
    {

        const std::string hoursWords = convertHoursToString(h + 1);

        return convertMinutesToWords(60 - m, hoursWords, "to ");
    }
    else
    {
        return "";
    }
}

int main(int argc, char *argv[])
{
    std::cout << timeInWords(10, 57) << std::endl;
    return 0;
}