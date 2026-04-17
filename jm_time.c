/* Converts jm's time to cappeia's time */

#include <stdio.h>

int main(void)
{
    int c_time;
    int j_time;
    int minutes;
    int month;
    int n;
    int m;

    printf("What month is it? (write month number): ");
    scanf("%d", &month);

    switch (month) {
        case 1: case 2: case 11: case 12: n = 16; break;
        case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: n = 15; break;
    }

    // Number of hours to subtract
    if (n == 16) {
        m = 1;
    } else if (n == 15) {
        m = 0;
    }

    /*
    -- Jm to Cappeia time technique --
    @ 15 hr
    Jm: 00:00 -> Cappeia: 9:00 AM
    Jm: 03:00 -> Cappeia: 12:00 PM

    @ 16 hr
    Jm: 09:30 -> Cappeia: 5:30 PM
    Jm: 12:00 -> Cappeia: 8:00 PM
    Jm: 16:00 -> Cappeia: 12:00 AM
    */

    printf("Enter a Jm's time: ");
    scanf("%d:%d", &c_time, &minutes);

    if (c_time >= 3 && c_time <= 14) {
        // Cappeia's time is PM
        switch (c_time) {
            case 3: j_time = 12 - m; break;
            case 4: j_time = 1 - m; if (j_time == 0) {j_time = 12;} break;
            case 5: j_time = 2 - m; break;
            case 6: j_time = 3 - m; break;
            case 7: j_time = 4 - m; break;
            case 8: j_time = 5 - m; break;
            case 9: j_time = 6 - m; break;
            case 10: j_time = 7 - m; break;
            case 11: j_time = 8 - m; break;
            case 12: j_time = 9 - m; break;
            case 13: j_time = 10 - m; break;
            case 14: j_time = 11 - m; break;

        }
        
    } else if (c_time >= 0 && c_time <= 2) {
        // Cappeia's time is AM
        switch (c_time) {
            case 0: j_time = 9 - m; break;
            case 1: j_time = 10 - m; break;
            case 2: j_time = 11 - m; break;

        }
    } else if (c_time >= 15 && c_time <= 24) {
        // Cappeia's time is AM
        switch (c_time) {
            case 15: j_time = 12 - m; break;
            case 16: j_time = 1 - m; if (j_time == 0) {j_time = 12;} break;
            case 17: j_time = 2 - m; break;
            case 18: j_time = 3 - m; break;
            case 19: j_time = 4 - m; break;
            case 20: j_time = 5 - m; break;
            case 21: j_time = 6 - m; break;
            case 22: j_time = 7 - m; break;
            case 23: j_time = 8 - m; break;
            case 24: j_time = 9 - m; break;

        }
    }

    /*
    @ 15 hrs
    00:00 to 09:00 -> Jm is PM
    09:00 to 21:00 -> Jm is AM
    22:00 to 00:00 -> Jm is PM
    
    @ 16 hrs
    0:00 to 8:00 -> Jm is PM
    8:00 to 20:00 -> Jm is AM
    */
    
    if (n == 15) {
        if (c_time >= 3 && c_time <= 14) {
            printf("Cappeia's time in 12-hour time: %d:%.2d PM\n", j_time, minutes);
        } else if (c_time >= 0 && c_time <= 2) {
            printf("Cappeia's time in 12-hour time: %d:%.2d AM\n", j_time, minutes);
        } else if (c_time >= 15 && c_time <= 24) {
            printf("Cappeia's time in 12-hour time: %d:%.2d AM\n", j_time, minutes);
        }
    } else if (n == 16) {
        if (c_time >= 4 && c_time <= 15) {
            printf("Cappeia's time in 12-hour time: %d:%.2d PM\n", j_time, minutes);
        } else if (c_time >= 1 && c_time <= 3) {
            printf("Cappeia's time in 12-hour time: %d:%.2d AM\n", j_time, minutes);
        } else if (c_time >= 16 && c_time <= 24) {
            printf("Cappeia's time in 12-hour time: %d:%.2d AM\n", j_time, minutes);
        } else if (c_time == 0) {
            printf("Cappeia's time in 12-hour time: %d:%.2d AM\n", j_time, minutes);
        }
    }
    return 0;
}
