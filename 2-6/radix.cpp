#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
#include <optional>

using namespace std;

#include "radix.h"

struct inputParamsType {
    int value;
    int destinationRadix;
    int sourceRadix;
};

int CharToInt(const char c, bool& wasError)
{
    if (c >= '0' && c <= '9')
    {
        return c - '0';
    }
    else if (c >= 'A' && c <= 'Z')
    {
        return c - 'A' + 10;
    }
    else
    {
        wasError = true;
    }
    return 0;
}

char IntToChar(const int digit)
{
    if (digit < 10)
    {
        return digit + '0';
    }
    else
    {
        return digit + 'A' - 10;
    }
}

int StringToInt(const std::string& str, int radix, bool& wasError)
{
    wasError = false;
    int result = 0;
    int sign = 1;
    for (char c : str)
    {
        if (c == '-')
        {
            sign = -1;
            continue;
        }
        int digit = CharToInt(c, wasError);
        if (digit >= radix)
        {
            wasError = true;
            break;
        }
        if (result > (numeric_limits<int>::max() - digit) / radix)
        {
            wasError = true;
            break;
        }
        result = result * radix + digit;
    }
    if (wasError)
    {
        return 0;
    }
    return result * sign;
}

string IntToString(int n, int radix, bool& wasError)
{
    if (n == 0)
    {
        return "0";
    }
    string result;
    bool isNegative = n < 0;
    if (n == std::numeric_limits<int>::min())
    {
        wasError = true;
    }
    n = abs(n);                                               //done корректно обрабатывать значение intmin
    while (n > 0)
    {
        int digit = n % radix;                                   //done IntToChar
        result += IntToChar(digit);
        n /= radix;
    }                                                            //done вставка в конец с инверсией
    if (isNegative)
    {
        result += '-';
    }
    std::reverse(result.begin(), result.end());
    return result;
}

                                                                    //done structure, radix is number
std::optional<inputParamsType> ParseArgs(char* argv[], const int& argc)
{
    bool wasError = false;
    inputParamsType inputParams;
    if (argc != 4)
    {
        cout << "Error: invalid number of arguments." << endl;
        return std::nullopt;
    }

    inputParams.sourceRadix = StringToInt(argv[1], 10, wasError);
    if (wasError || inputParams.sourceRadix < 2 || inputParams.sourceRadix > 36)
    {
        cout << "Error: invalid source radix." << endl;
        return std::nullopt;
    }

    inputParams.destinationRadix  = StringToInt(argv[2], 10, wasError);
    if (wasError || inputParams.destinationRadix < 2 || inputParams.destinationRadix > 36)
    {
        cout << "Error: invalid destination radix." << endl;
        return std::nullopt;
    }
    inputParams.value = StringToInt(argv[3], inputParams.sourceRadix, wasError);
    if (wasError)
    {
        cout << "Error: invalid input value." << endl;
        return std::nullopt;
    }
    return inputParams;
}
                                                                //done парсинг параметров входной строки отдельной функцией
                                                                //done main сложна
int main(int argc, char* argv[])
{
    bool wasError = false;
    optional<inputParamsType> inputParameters = ParseArgs(argv, argc);

    if (!inputParameters)
    {
        return 1;
    }

    cout << IntToString((*inputParameters).value, (*inputParameters).destinationRadix, wasError) << endl;
    return wasError;
}
