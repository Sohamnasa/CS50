#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int c = 0;
    float n = get_float("Money given: ");
    int j = n * 100;

    {
        while (j >= 25)
        {
            c = c + 1;
            j = j - 25;
        }
 
        while (j >= 10)
        {
            c = c + 1;
            j = j - 10;
        }

        while (j >= 5)
        {
            c = c + 1;
            j = j - 5;
        }

        while (j >= 1)
        {
            c = c + 1;
            j = j - 1;
        }
        printf("%d\n coins", c);
        return 0;
    }
}
