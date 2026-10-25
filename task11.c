#include <stdio.h>

#define SLAB1_LIMIT 100
#define SLAB2_LIMIT 200

#define RATE1 150
#define RATE2 250
#define RATE3 400

#define MAX_BILLS 800000

int main(void)
{
    long long units;
    long long bill_paise;
    long long district_total_paise = 0;

    printf("Enter electricity units: ");
    if (scanf("%lld", &units) != 1 || units < 0)
    {
        printf("Invalid input!\n");
        return 1;
    }

    if (units <= SLAB1_LIMIT)
    {
        bill_paise = units * RATE1;
    }
    else if (units <= SLAB2_LIMIT)
    {
        bill_paise = SLAB1_LIMIT * RATE1
                   + (units - SLAB1_LIMIT) * RATE2;
    }
    else
    {
        bill_paise = SLAB1_LIMIT * RATE1
                   + SLAB1_LIMIT * RATE2
                   + (units - SLAB2_LIMIT) * RATE3;
    }

    district_total_paise += bill_paise;

    printf("\nElectricity units: %lld\n", units);
    printf("Bill amount: Rs. %lld.%02lld\n",
           bill_paise / 100, bill_paise % 100);
    printf("District total: Rs. %lld.%02lld\n",
           district_total_paise / 100,
           district_total_paise % 100);

    printf("Maximum planned bills: %d\n", MAX_BILLS);

    return 0;
}