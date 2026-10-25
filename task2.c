#include <stdio.h>
#include <limits.h>
#include <float.h>

void main()
{
    printf("char: %zu byte, CHAR_MIN=%d, CHAR_MAX=%d\n",
           sizeof(char), CHAR_MIN, CHAR_MAX);

    printf("short: %zu bytes, SHRT_MIN=%d, SHRT_MAX=%d\n",
           sizeof(short), SHRT_MIN, SHRT_MAX);

    printf("unsigned short: %zu bytes, max=%u\n",
           sizeof(unsigned short), (unsigned)USHRT_MAX);

    printf("int: %zu bytes, INT_MIN=%d, INT_MAX=%d\n",
           sizeof(int), INT_MIN, INT_MAX);

    printf("unsigned int: %zu bytes, max=%u\n",
           sizeof(unsigned int), UINT_MAX);

    printf("long: %zu bytes\n", sizeof(long));
    printf("long long: %zu bytes\n", sizeof(long long));

    printf("float: %zu bytes, max=%e\n",
           sizeof(float), FLT_MAX);

    printf("double: %zu bytes, max=%e\n",
           sizeof(double), DBL_MAX);
}