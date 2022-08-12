#include <stdio.h>
#include <windows.h>

int main() {
    int user_turn, sys_turn, i, j, remain_match = 30;
    printf("Total Number of Matchsticks are 30.\n\nYou can choose from 1 to 4.\n");

    for (i = 1; i <= 6; i++) {

        // Prints the remaining Matchsticks.
        printf("Remaining Matchsticks = %d\n\n", remain_match);
        j = 1;
        while (j <= remain_match) {
            printf ("|");
            j++;
        }
        printf ("\n\n");
        x:
        printf ("\n");

        // Takes user input.
        printf ("User's turn = \t\t");
        scanf ("%d", &user_turn);
        printf ("\n");
        if (user_turn <= 0 || user_turn >= 5)
        {
            printf ("Please enter the correct number\n");
            goto x;
        }

        // Calculate and prints system turns.
        sys_turn = 5 - user_turn;
        printf ("Computer's turn = \t");
        Sleep(500);
        printf ("%d\n", sys_turn);
        remain_match = remain_match - 5;
        printf ("\n");
    }

    printf ("Remaining Sticks = %d\n\n", remain_match);
    printf ("Last Stick picked by Computer!!!\n\n");
    Sleep(500);
    printf ("YOU LOSE!!!\n");

    return 0;
}