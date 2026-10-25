#include <stdio.h>

int main() {
    int householdNo;
    int previousReading, currentReading;
    int units;
    char category;

    const double DOMESTIC_RATE = 5.0;
    const double COMMERCIAL_RATE = 8.0;
    const double FIXED_CHARGE = 50.0;

    double energyCharge, totalBill;

    printf("Enter Household Number: ");
    scanf("%d", &householdNo);

    printf("Enter Previous Meter Reading: ");
    scanf("%d", &previousReading);

    printf("Enter Current Meter Reading: ");
    scanf("%d", &currentReading);

    printf("Enter Category (D for Domestic, C for Commercial): ");
    scanf(" %c", &category);

    if (householdNo <= 0 ||
        previousReading < 0 ||
        currentReading < previousReading) {
        printf("Invalid input or meter reading.\n");
        return 1;
    }

    units = currentReading - previousReading;

    if (category == 'D' || category == 'd') {
        energyCharge = units * DOMESTIC_RATE;
    } else if (category == 'C' || category == 'c') {
        energyCharge = units * COMMERCIAL_RATE;
    } else {
        printf("Invalid consumer category.\n");
        return 1;
    }

    totalBill = energyCharge + FIXED_CHARGE;

    printf("\n----- Electricity Bill -----\n");
    printf("Household Number: %d\n", householdNo);
    printf("Previous Reading: %d\n", previousReading);
    printf("Current Reading: %d\n", currentReading);
    printf("Units Consumed: %d\n", units);
    printf("Energy Charge: Rs. %.2f\n", energyCharge);
    printf("Fixed Charge: Rs. %.2f\n", FIXED_CHARGE);
    printf("Total Bill: Rs. %.2f\n", totalBill);

    return 0;
}






