#include <stdio.h>
#include <math.h>

int main(void)
{
    int units = 199;
    int a = 5, b = 2;
    double price = 2.75;
    long long largeAmount = 3000000000LL;

    printf("--- Type Conversion and Precision ---\n");

    /* Example 1: Integer division */
    printf("1. Integer division: %d\n", units / 100);

    /* Example 2: Casting after division */
    printf("2. Cast after division: %.2f\n",
           (double)(a / b));

    /* Example 3: Casting before division */
    printf("3. Correct division: %.2f\n",
           (double)a / b);

    /* Example 4: Floating-point precision */
    printf("4. Float precision: %.17f\n", 0.1 + 0.2);

    /* Example 5: Mixed-type arithmetic */
    printf("5. Mixed calculation: %.2f\n", price * 3);

    /* Example 6: Large value without narrowing cast */
    printf("6. Large amount: %lld\n", largeAmount);

    /* Example 7: Convert rupees to paise with rounding */
    double chargeRupees = 12.345;
    long chargePaise = lround(chargeRupees * 100.0);

    printf("7. Rounded charge: %ld paise\n", chargePaise);
    printf("8. Charge in rupees: Rs %ld.%02ld\n",
           chargePaise / 100, chargePaise % 100);

    return 0;
}