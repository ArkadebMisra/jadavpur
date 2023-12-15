#include <stdio.h>

typedef struct date {
    int day;
    int month;
    int year;
} DATE;

// Function to compare two dates
int compareDates( DATE date1,  DATE date2) {
    if (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day) {
        return 0; 
    } else {
        return 1; 
    }
}

int main() {
    
   DATE date1, date2;

    
    printf("Enter the first date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &date1.day, &date1.month, &date1.year);

    
    printf("Enter the second date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &date2.day, &date2.month, &date2.year);

    if (compareDates(date1, date2) == 0) {
        printf("The dates are equal.\n");
    } else {
        printf("The dates are unequal.\n");
    }

    return 0;
}
