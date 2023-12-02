#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const int red_max   = 12;
static const int green_max = 13;
static const int blue_max  = 14;

// Sample input
// Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
unsigned parse_input(const char* restrict game)
{
    int red   = 0;
    int green = 0;
    int blue  = 0;

    unsigned game_id = 0;
    if (sscanf(game, "Game %u:", &game_id) == 1)
    {
        char* next_position = NULL;
        if ((next_position = strchr(game, ':')))
        {
            game = next_position+2;
        }
    }

    while (strchr(game, ',') || strchr(game, ';'))
    {
        int value = 0;
        char c = 0;
        if (sscanf(game, "%d %c", &value, &c))
        {
            red   += value * (c == 'r');
            green += value * (c == 'g');
            blue  += value * (c == 'b');

            if (red > red_max || blue > blue_max || green > green_max ) 
            {
                return 0;
            }
        }

        // advance to next position
        char* next_comma = strchr(game, ',');
        char* next_semi_colon = strchr(game, ';');

        if (next_comma && next_comma < next_semi_colon)
        {
            game = next_comma+2;
        }
        else if (next_semi_colon && next_semi_colon < next_comma)
        {
            red   = 0;
            green = 0;
            blue  = 0;

            game = next_semi_colon+2;
        }
        else
        {
            red   = 0;
            green = 0;
            blue  = 0;

            game = ((char *)((size_t)next_semi_colon + (size_t)next_comma)) + 2;
        }
    }

    int value = 0;
    char c = 0;
    if (sscanf(game, "%d %c", &value, &c))
    {
        red   += value * (c == 'r');
        green += value * (c == 'g');
        blue  += value * (c == 'b');

        if (red > red_max || blue > blue_max || green > green_max ) 
        {
            return 0;
        }
    }

    return ( red <= red_max && green <= green_max && blue <= blue_max ) * game_id;
}

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        return 1;
    }

    unsigned sum = 0;
    for (int i = 1; i < argc; ++i)
    {
        sum += parse_input(argv[i]);
    }
    fprintf(stdout, "%u\n", sum);

    return 0;
}
