#include <stdio.h>
#include <limits.h>

#define READINGS_PER_YEAR 35040
#define PEAK_START_HOUR 18
#define PEAK_END_HOUR 22

int main(void)
{
    FILE *file;
    long long normal_rate;
    long long peak_percent;
    long long total_wh = 0;
    long long total_paise = 0;
    long long wh;
    long long cost;
    int hour;
    int i;

    /* Read tariff values from configuration file */
    file = fopen("tariff.txt", "r");

    if (file == NULL)
    {
        printf("Error: Cannot open tariff.txt\n");
        return 1;
    }

    if (fscanf(file, "%lld %lld",
               &normal_rate, &peak_percent) != 2 ||
        normal_rate < 0 || peak_percent < 0 ||
        peak_percent > 100)
    {
        printf("Invalid tariff configuration!\n");
        fclose(file);
        return 1;
    }

    fclose(file);

    printf("Smart Meter Billing System\n");
    printf("Normal rate: %lld paise per kWh\n", normal_rate);
    printf("Peak surcharge: %lld%%\n\n", peak_percent);

    for (i = 0; i < READINGS_PER_YEAR; i++)
    {
        printf("Enter reading %d (watt-hours) and hour (0-23): ",
               i + 1);

        if (scanf("%lld %d", &wh, &hour) != 2 ||
            wh < 0 || hour < 0 || hour > 23)
        {
            printf("Invalid input!\n");
            return 1;
        }

        if (total_wh > LLONG_MAX - wh)
        {
            printf("Watt-hour total overflow!\n");
            return 1;
        }

        total_wh += wh;

        /* Convert watt-hours to paise using integer arithmetic.
           Rate is in paise per kWh. */
        if (wh > LLONG_MAX / normal_rate && normal_rate != 0)
        {
            printf("Reading cost overflow!\n");
            return 1;
        }

        if (hour >= PEAK_START_HOUR &&
            hour < PEAK_END_HOUR)
        {
            /* Peak cost = normal cost * (100 + surcharge) / 100 */
            if (normal_rate != 0 &&
                wh > LLONG_MAX / normal_rate)
            {
                printf("Cost calculation overflow!\n");
                return 1;
            }

            cost = (wh * normal_rate) / 1000;
            cost = cost * (100 + peak_percent) / 100;
        }
        else
        {
            cost = (wh * normal_rate) / 1000;
        }

        if (total_paise > LLONG_MAX - cost)
        {
            printf("Bill total overflow!\n");
            return 1;
        }

        total_paise += cost;
    }

    printf("\nYearly consumption: %lld Wh\n", total_wh);
    printf("Yearly consumption: %.3f kWh\n",
           total_wh / 1000.0);
    printf("Total bill: Rs. %lld.%02lld\n",
           total_paise / 100, total_paise % 100);

    return 0;
}