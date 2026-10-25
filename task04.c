#include <stdio.h>

#define RUPEES_TO_PAISE(r) ((r) * 100)
#define SQUARE(x) ((x) * (x))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int main(void)
{
    int a = 4;
    int b = 7;

    printf("Rupees to paise: %d\n", RUPEES_TO_PAISE(50));
    printf("Square of a + 1: %d\n", SQUARE(a + 1));
    printf("Maximum value: %d\n", MAX(a, b));

    return 0;
}


