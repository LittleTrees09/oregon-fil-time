/* Converts cappeia's time to jm's time */

#include <stdio.h>

int main(void)
{
    int c_time;
    int j_time;
    int minutes;
    int month;
    int n;

    printf("What month is it? (write month number): ");
    scanf("%d", &month);

    switch (month) {
        case 1: case 2: case 11: case 12: n = 16; break;
        case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: n = 15; break;
    }

    printf("Enter a Cappeia's time: ");
    scanf("%d:%d", &c_time, &minutes);

    // Checks if AM or PM
    if (c_time >= 0 && c_time <= 12) {
        switch (c_time) {
            case 0: j_time = n; break;
            case 1: j_time = 1 + n; break;
            case 2: j_time = 2 + n; break;
            case 3: j_time = 3 + n; break;
            case 4: j_time = 4 + n; break;
            case 5: j_time = 5 + n; break;
            case 6: j_time = 6 + n; break;
            case 7: j_time = 7 + n; break;
            case 8: j_time = 8 + n; break;
            case 9: j_time = 9 + n; break;
            case 10: j_time = 10 + n; break;
            case 11: j_time = 11 + n; break;
            case 12: j_time = 12 + n; break;
        }
    } else if (c_time >= 13 && c_time <= 24) {
        c_time = c_time - 12;
        switch (c_time) {
            case 0: j_time = n; break;
            case 1: j_time = 1 + n; break;
            case 2: j_time = 2 + n; break;
            case 3: j_time = 3 + n; break;
            case 4: j_time = 4 + n; break;
            case 5: j_time = 5 + n; break;
            case 6: j_time = 6 + n; break;
            case 7: j_time = 7 + n; break;
            case 8: j_time = 8 + n; break;
            case 9: j_time = 9 + n; break;
            case 10: j_time = 10 + n; break;
            case 11: j_time = 11 + n; break;
            case 12: j_time = 12 + n; break;
        }
        c_time = c_time + 12;
    }

    // Converts 24-hour to 12-hour
    switch (j_time) {
        case 0: case 12: case 24: j_time = 12; break;
        case 1: case 13: case 25: j_time = 1; break;
        case 2: case 14: case 26: j_time = 2; break;
        case 3: case 15: case 27: j_time = 3; break;
        case 4: case 16: case 28: j_time = 4; break;
        case 5: case 17: case 29: j_time = 5; break;
        case 6: case 18: case 30: j_time = 6; break;
        case 7: case 19: case 31: j_time = 7; break;
        case 8: case 20: case 32: j_time = 8; break;
        case 9: case 21: case 33: j_time = 9; break;
        case 10: case 22: case 34: j_time = 10; break;
        case 11: case 23: case 35: j_time = 11; break;
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
    
    if (c_time >= 0 && c_time <= 9) {
        printf("Jm's time in 12-hour time: %d:%.2d PM\n", j_time, minutes);
    } else if (c_time >= 22 && c_time <= 24) {
        printf("Jm's time in 12-hour time: %d:%.2d PM\n", j_time, minutes);
    } else if (c_time >= 10 && c_time <= 21) {
        printf("Jm's time in 12-hour time: %d:%.2d AM\n", j_time, minutes);
    }
    return 0;
}
