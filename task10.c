#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    int bill_counts[] = {4000, 60000, 800000};
    int i;

    const int bill_paise = 12345;
    const float bill_float = 123.45f;
    const double bill_double = 123.45;

    printf("TASK 10: EXPECTATIONS VS EXECUTION\n");
    printf("Sample bill = Rs. 123.45\n\n");

    printf("Data type sizes and ranges:\n");
    printf("int       : %zu bytes, max = %d\n",
           sizeof(int), INT_MAX);
    printf("long      : %zu bytes, max = %ld\n",
           sizeof(long), LONG_MAX);
    printf("long long : %zu bytes, max = %lld\n",
           sizeof(long long), LLONG_MAX);
    printf("float     : %zu bytes, FLT_DIG = %d\n",
           sizeof(float), FLT_DIG);
    printf("double    : %zu bytes, DBL_DIG = %d\n\n",
           sizeof(double), DBL_DIG);

    for (i = 0; i < 3; i++)
    {
        int n = bill_counts[i];
        float float_total = 0.0f;
        double double_total = 0.0;
        long long paise_total = 0;
        int int_total = 0;
        long long j;
        int int_overflow = 0;
        int long_overflow = 0;
        int ll_overflow = 0;
        long long long_total = 0;
        long long ll_total = 0;

        for (j = 0; j < n; j++)
        {
            float_total += bill_float;
            double_total += bill_double;
            paise_total += bill_paise;

            if (!int_overflow)
            {
                if (int_total > INT_MAX - bill_paise)
                    int_overflow = 1;
                else
                    int_total += bill_paise;
            }

            if (!long_overflow)
            {
                if (long_total > LONG_MAX - bill_paise)
                    long_overflow = 1;
                else
                    long_total += bill_paise;
            }

            if (!ll_overflow)
            {
                if (ll_total > LLONG_MAX - bill_paise)
                    ll_overflow = 1;
                else
                    ll_total += bill_paise;
            }
        }

        printf("\nBills: %d\n", n);
        printf("Float total       : Rs. %.2f\n",
               (double)float_total);
        printf("Paise total       : Rs. %.2f\n",
               paise_total / 100.0);
        printf("Float difference  : Rs. %.8f\n",
               (double)float_total - paise_total / 100.0);
        printf("Double total      : Rs. %.2f\n",
               double_total);

        printf("int total         : ");
        if (int_overflow)
            printf("OVERFLOW RISK\n");
        else
            printf("%d paise\n", int_total);

        printf("long total        : ");
        if (long_overflow)
            printf("OVERFLOW RISK\n");
        else
            printf("%ld paise\n", (long)long_total);

        printf("long long total   : ");
        if (ll_overflow)
            printf("OVERFLOW RISK\n");
        else
            printf("%lld paise\n", ll_total);
    }

    printf("\nAll totals are checked before integer addition.\n");
    return 0;
}