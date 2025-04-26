#include <stdio.h>
#include <stdbool.h>

// Function Prototypes
bool is_leap_year(int year);
void add_days_to_date(int *mm_ptr, int *dd_ptr, int *yy_ptr, int days_to_add);

// Index 0 and 1-12 correspond to months Jan-Dec
const int DAYS_IN_MONTH[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Checks if a given year is a leap year
bool is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Adds a specified number of days to the date pointed to by mm_ptr, dd_ptr, yy_ptr
void add_days_to_date(int *mm_ptr, int *dd_ptr, int *yy_ptr, int days_to_add) {
    // Loop as long as there are days left to add
    while (days_to_add > 0) {
        // 1. Determine the number of days in the current month
        int days_in_current_month = DAYS_IN_MONTH[*mm_ptr];
        if (*mm_ptr == 2 && is_leap_year(*yy_ptr)) {
            days_in_current_month = 29;
        }

        // 2. Find how many days are remaining in the current month
        int days_remaining = days_in_current_month - *dd_ptr;

        // 3. Check if the days to add will go past the current month
        if (days_to_add > days_remaining) {
          
            // Subtract the days needed to get to the start of the next month
            days_to_add -= (days_remaining + 1);

            // Jump to the first day of the next month
            *dd_ptr = 1;
            if (*mm_ptr == 12) { // Check if month is December
                *mm_ptr = 1;     // If true, rollover to January
                (*yy_ptr)++;     // Increment the year
            } else {
                (*mm_ptr)++;     // Otherwise, increment the month
            }
        } else {
            *dd_ptr += days_to_add; // Add the remaining days
            days_to_add = 0; // Stop the loop
        }
    }
}

int main() {
    int mm, dd, yy, days_to_add_input;

    printf("Enter a date (mm dd yyyy) and days to add (e.g., 3 14 2021 500): ");
    scanf("%d %d %d %d", &mm, &dd, &yy, &days_to_add_input);

    // Call the function to modify the date variables (pass their addresses)
    add_days_to_date(&mm, &dd, &yy, days_to_add_input);

    // %02d to add leading zeros
    printf("The new date is: %02d/%02d/%d\n", mm, dd, yy);

    return 0;
}
