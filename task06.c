#include <stdio.h>

int main(void)
{
    int householdNo;
    unsigned int units;
    long energyChargePaise;
    long long totalPaise;
    float readingValue;
    double tariff;
    char category;
    char name[50];

    printf("Enter household number: ");
    if (scanf("%d", &householdNo) != 1) {
        printf("Invalid household number.\n");
        return 1;
    }

    printf("Enter units consumed: ");
    if (scanf("%u", &units) != 1) {
        printf("Invalid units.\n");
        return 1;
    }

    printf("Enter category (D/C): ");
    if (scanf(" %c", &category) != 1) {
        printf("Invalid category.\n");
        return 1;
    }

    printf("Enter consumer name (one word): ");
    if (scanf("%49s", name) != 1) {
        printf("Invalid name.\n");
        return 1;
    }

    printf("Enter meter reading as a decimal: ");
    if (scanf("%f", &readingValue) != 1) {
        printf("Invalid reading.\n");
        return 1;
    }

    printf("Enter tariff in rupees: ");
    if (scanf("%lf", &tariff) != 1) {
        printf("Invalid tariff.\n");
        return 1;
    }

    printf("Enter energy charge in paise: ");
    if (scanf("%ld", &energyChargePaise) != 1) {
        printf("Invalid energy charge.\n");
        return 1;
    }

    printf("Enter total bill in paise: ");
    if (scanf("%lld", &totalPaise) != 1) {
        printf("Invalid total bill.\n");
        return 1;
    }

    if (householdNo <= 0 || category != 'D' && category != 'd'
        && category != 'C' && category != 'c') {
        printf("Invalid household number or category.\n");
        return 1;
    }

    if (energyChargePaise < 0 || totalPaise < 0 ||
        readingValue < 0 || tariff < 0) {
        printf("Values cannot be negative.\n");
        return 1;
    }

    printf("\n--- Electricity Bill ---\n");
    printf("Household number: %d\n", householdNo);
    printf("Units consumed: %u\n", units);
    printf("Category: %c\n", category);
    printf("Consumer name: %s\n", name);
    printf("Meter reading: %.2f\n", readingValue);
    printf("Tariff: Rs %.2f\n", tariff);
    printf("Energy charge: Rs %ld.%02ld\n",
           energyChargePaise / 100,
           energyChargePaise % 100);
    printf("Total bill: Rs %lld.%02lld\n",
           totalPaise / 100,
           totalPaise % 100);

    return 0;
}