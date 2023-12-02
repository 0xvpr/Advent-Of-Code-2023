#include <string.h>
#include <stdint.h>
#include <stdio.h>

int calibration_value(const char* restrict str, size_t length)
{
    int left = 0;
    int right = length-1;

    for (size_t i = 0; i < length; ++i)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            left = i;
            break;
        }
    }

    for (size_t i = length-1; i+1 > 0; --i)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            right = i;
            break;
        }
    }

    return (int)((10 * (str[left] - '0')) + (str[right] - '0'));
}

int main(int argc, char** argv)
{
    uint64_t result = 0;

    if (argc < 2)
    {
        return 1;
    }

    for (int i = 1; i < argc; ++i)
    {
        char* str = argv[i];
        size_t size = strlen(str);

        result += calibration_value(str, size);
    }

    fprintf(stdout, "%lu\n", result);

    return 0;
}
