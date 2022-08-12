#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to decide who wins
int game(char user, char comp) {
    // returns 1 if user win, -1 if user lose and 0 if draw

    if(user == comp)
        return 0;

    if(user=='r' && comp=='s')
        return 1;

    else if(user=='r' && comp=='p')
        return -1;

    if(user=='p' && comp=='r')
        return 1;

    else if(user=='p' && comp=='s')
        return -1;

    if(user=='s' && comp=='p')
        return 1;

    else if(user=='s' && comp=='r')
        return -1;
}

int main() {
    char user, comp;

    // Creating a random number and assigning the value of comp accordingly
    srand(time(0));
    int number = rand() % 3;

    if(number == 0)
        comp = 'r';
    else if(number == 1)
        comp = 'p';
    else
        comp = 's';
    
    printf("Enter 'r' for rock, 'p' for paper and 's' for scissors: \n");
    x:
    scanf("%c", &user);

    // Checks for incorrect input of user
    if(user != 'r') {
        if(user != 'p') {
            if(user != 's') {
                fflush(stdin);
                printf("Incorrect input.. Please try again!!\n");
                goto x;
            }
        }
    }

    printf("You choose %c and computer choose %c\n", user, comp);

    // Calling the game function to find out the result
    int result = game(user, comp);
    if(result == 0)
        printf("Game Draw!!\n");
    else if(result == 1)
        printf("You Win!!\n");
    else
        printf("You Lose!!\n");

    return 0;
}