#include <stdio.h>
#include <math.h>

#define FIXED_CHARGE_PAISE 5000L

int main(void)
{
    int units = 150;
    long energyChargePaise;
    long totalPaise;

    energyChargePaise = (long)lround(units * 2.25 * 100);
    totalPaise = energyChargePaise + FIXED_CHARGE_PAISE;

#ifdef DEBUG
    printf("[DEBUG] Units: %d\n", units);
    printf("[DEBUG] Energy charge: %ld paise\n",
           energyChargePaise);
    printf("[DEBUG] Fixed charge: %ld paise\n",
           FIXED_CHARGE_PAISE);
    printf("[DEBUG] Total: %ld paise\n", totalPaise);
#endif

    printf("Units consumed: %d\n", units);
    printf("Energy charge: Rs %ld.%02ld\n",
           energyChargePaise / 100,
           energyChargePaise % 100);
    printf("Total bill: Rs %ld.%02ld\n",
           totalPaise / 100,
           totalPaise % 100);

    return 0;
}