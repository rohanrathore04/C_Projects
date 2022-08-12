#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int number, guess, attempt = 1;

    // Generates a random number between 1 - 100 and stores in variable number.
    srand(time(0));
    number = rand() % 101;

    do {
        printf ("Guess the number ranging between 1 to 100\n");
        scanf ("%d", &guess);

        // Checks if the number entered is in the range or not.
        if (guess > 100 || guess < 0) {
            printf ("Number is not in the range!! Type again..\n\n");
            continue;
        }

        // Check and tells if the number is smaller.
        else if (guess > number) {
            if (guess <= number + 5)
                printf ("The number is a bit smaller..\n\n");
            else if (guess <= number + 15)
                printf ("The number is smaller..\n\n");
            else
                printf ("The number is much smaller..\n\n");
        }

        // Checks and tells if the number is greater.
        else if (guess < number) {
            if (guess >= number - 5)
                printf ("The number is a bit greater..\n\n");
            else if (guess >= number - 15)
                printf ("The number is greater..\n\n");
            else
                printf ("The number is much greater..\n\n");
        }

        // If the guessed number is correct then prints the number of attempts made.
        else
            printf("\n->> You guessed it in %d attempts <<-\n", attempt);

        attempt++;
    } while(guess != number);
    
    return 0;
}