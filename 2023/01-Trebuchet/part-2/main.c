#include <stdio.h>
#include <stdint.h>
#include <string.h>

const char* const repr[9] = {
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine"
};

int calculate_value(const char* const restrict str, size_t size)
{
    int result = 0;
    
    for (size_t i = 0; i < size; ++i)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            result = (int)(10 * (str[i] - '0'));
            break;
        }

        int numeric = 0;
        for (int j = 0; j < 9; ++j)
        {
            if (strlen(str+i) >= strlen(repr[j]) && strncmp(str+i, repr[j], strlen(repr[j])) == 0)
            {
                result += 10 * (j+1);
                numeric = 1;
                break;
            }
        }

        if (numeric)
        {
            break;
        }
    }

    for (size_t i = size-1; i+1 > 0; --i)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            result += (int)(str[i] - '0');
            break;
        }

        for (int j = 0; j < 9; ++j)
        {
            if (strlen(str+i) >= strlen(repr[j]) && strncmp(str+i, repr[j], strlen(repr[j])) == 0)
            {
                result += j+1;
                return result;
            }
        }
    }

    return result;
}

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        return 1;
    }

    uint64_t result = 0;
    for (int i = 1; i < argc; ++i)
    {
        result += calculate_value(argv[i], strlen(argv[i]));
    }

    fprintf(stdout, "%lu\n", result);

    return 0;
}
