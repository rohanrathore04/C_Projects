#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h>

// Declaring 9 positions, users turn and input by user as global variable
char position[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int pTurn = 1, input;

// Function to print the game with positions
void gdraw (char x[20], char y[20]) {
    int i, j, k = 0;
    system("cls");
    printf("\n\n\tTIC TAC TOE\n");
    printf("\n%s (X) | %s (O)\n\n\n", x, y);

    for (i=1; i<10; i++) {
        for (j=1; j<=11; j++) {

            if (j%4 == 0)
                printf("|");
            else if (i%3==0 && i!=9)
                printf("__");
            else if ((i==2 || i==5 || i==8) && (j==2 || j==6 || j==10)) {
                if (position[k] == k+1)
                    printf(" %d", position[k]);
                else
                    printf(" %c", position[k]);
                k++;
            }
            else
                printf("  ");
        }
        printf("\n");
    }
}

// Function to return the result of the winner
int gres() {
    if((position[0]==position[1])&&position[1]==position[2])
        return 1;
    else if((position[3]==position[4])&&position[4]==position[5])
        return 1;
    else if((position[6]==position[7])&&position[7]==position[8])
        return 1;
    else if((position[0]==position[3])&&position[3]==position[6])
        return 1;
    else if((position[1]==position[4])&&position[4]==position[7])
        return 1;
    else if((position[2]==position[5])&&position[5]==position[8])
        return 1;
    else if((position[2]==position[4])&&position[4]==position[6])
        return 1;
    else if((position[0]==position[4])&&position[4]==position[8])
        return 1;
    else if(position[0]!=1 && position[1]!=2 && position[2]!=3 && position[3]!=4 && position[4]!=5 && position[5]!=6 && position[6]!=7 && position[7]!=8 && position[8]!=9)
        return 0;
    else
        return -1;
}

// Function to mark the position with 'O' or 'X', where user or computer chooses to input
int gmark() {
    if (input < 1 || input > 9) {
        printf("\n Input Not Valid !! Try Again..\t");
        return 1;
    }
    else if (input != position[input-1]) {
        printf("\n Incorrect Move !! Try Again..\t");
        return 1;
    }
    else {
        if(pTurn == 1)
            position[input-1] = 'X';
        else
            position[input-1] = 'O';
        return 0;
    }
}

/* Function to return computers next move on the basis of turn
This function consists of every possible moves that user can make and never lets user to win the game */
int comp (int turn) {
    int compMove;
    
    // If its the 1st move or turn
    if(turn == 1) {

        if(position[4] == 'X') {
            time_t t;
            srand((unsigned)time(&t));

            while(1) {
                int rNum = rand() % 10;
                if (rNum % 2 != 0 && rNum != 5) {
                    compMove = rNum;
                    break;
                }
            }   
        }
        else
            compMove = 5;
    }

    // If its the 2nd move or turn
    else if (turn == 2) {

        if((position[1]=='X'&&position[2]=='X') || (position[3]=='X'&&position[6]=='X') || (position[1]=='X'&&position[3]=='X') || (position[8]=='X'&&position[4]=='X'&&position[0]!='O'))
            compMove=1;
        else if((position[0]=='X'&&position[1]=='X') || (position[5]=='X'&&position[8]=='X') || (position[1]=='X'&&position[5]=='X') || (position[6]=='X'&&position[4]=='X'&&position[2]!='O'))
            compMove=3;
        else if((position[0]=='X'&&position[3]=='X') || (position[7]=='X'&&position[8]=='X') || (position[3]=='X'&&position[7]=='X') || (position[2]=='X'&&position[4]=='X'&&position[6]!='O'))
            compMove=7;
        else if((position[2]=='X'&&position[5]=='X') || (position[6]=='X'&&position[7]=='X') || (position[5]=='X'&&position[7]=='X') || (position[0]=='X'&&position[4]=='X'&&position[8]!='O'))
            compMove=9;
        else if((position[5]=='X'&&position[6]=='X') || (position[3]=='X'&&position[8]=='X') || (position[0]=='X'&&position[2]=='X') || (position[4]=='X'&&position[7]=='X'))
            compMove=2;
        else if((position[2]=='X'&&position[7]=='X') || (position[1]=='X'&&position[8]=='X') || (position[0]=='X'&&position[6]=='X') || (position[4]=='X'&&position[5]=='X'))
            compMove=4;
        else if((position[0]=='X'&&position[7]=='X') || (position[1]=='X'&&position[6]=='X') || (position[2]=='X'&&position[8]=='X') || (position[3]=='X'&&position[4]=='X'))
            compMove=6;
        else if((position[0]=='X'&&position[5]=='X') || (position[2]=='X'&&position[3]=='X') || (position[6]=='X'&&position[8]=='X') || (position[1]=='X'&&position[4]=='X'))
            compMove=8;  
        else if((position[0]=='X'&&position[8]=='X') || (position[2]=='X'&&position[6]=='X')) {
            time_t t;
            srand((unsigned)time(&t));

            while(1) {
                int rNum = rand() % 10;
                if(rNum%2 == 0) {
                    compMove = rNum;
                    break;
                }
            } 
        }
        else if((position[1]=='X'&&position[7]=='X') || (position[3]=='X'&&position[5]=='X')) {
            time_t t;
            srand((unsigned)time(&t));

            while(1) {
                int rNum = rand() % 10;
                if(rNum%2 != 0 && rNum != 5) {
                    compMove=rNum;
                    break;
                }
            }
        }
        else if((position[6]=='X'&&position[4]=='X'&&position[2]=='O') || (position[2]=='X'&&position[4]=='X'&&position[6]=='O')) {
            time_t t;
            srand((unsigned)time(&t));

            while(1) {
                int rNum = rand() % 10;
                if(rNum%2 != 0 && rNum != 3 && rNum != 5 && rNum != 7) {
                    compMove=rNum;
                    break;
                }
            }
        }
        else if((position[8]=='X'&&position[4]=='X'&&position[0]=='O') || (position[0]=='X'&&position[4]=='X'&&position[8]=='O')) {
            time_t t;
            srand((unsigned)time(&t));

            while(1) {
                int rNum = rand() % 10;
                if(rNum%2 != 0 && rNum != 1 && rNum != 5 && rNum != 9) {
                    compMove=rNum;
                    break;
                }
            }
        }
    }

    // If its the 3rd move or turn
    else if (turn == 3) {

        if((position[1]=='O'&&position[2]=='O'&&position[0]==1) || (position[3]=='O'&&position[6]=='O'&&position[0]==1) || (position[4]=='O'&&position[8]=='O'&&position[0]==1))
            compMove=1;
        else if((position[0]=='O'&&position[1]=='O'&&position[2]==3) || (position[4]=='O'&&position[6]=='O'&&position[2]==3) || (position[5]=='O'&&position[8]=='O'&&position[2]==3))
            compMove=3;
        else if((position[0]=='O'&&position[3]=='O'&&position[6]==7) || (position[2]=='O'&&position[4]=='O'&&position[6]==7) || (position[7]=='O'&&position[8]=='O'&&position[6]==7))
            compMove=7;
        else if((position[0]=='O'&&position[4]=='O'&&position[8]==9) || (position[2]=='O'&&position[5]=='O'&&position[8]==9) || (position[6]=='O'&&position[7]=='O'&&position[8]==9))
            compMove=9;
        else if((position[0]=='O'&&position[2]=='O'&&position[1]==2) || (position[4]=='O'&&position[7]=='O'&&position[1]==2))
            compMove=2;
        else if((position[0]=='O'&&position[6]=='O'&&position[3]==4) || (position[4]=='O'&&position[5]=='O'&&position[3]==4))
            compMove=4;
        else if((position[2]=='O'&&position[8]=='O'&&position[5]==6) || (position[3]=='O'&&position[4]=='O'&&position[5]==6))
            compMove=6;
        else if((position[1]=='O'&&position[4]=='O'&&position[7]==8) || (position[6]=='O'&&position[8]=='O'&&position[7]==8))
            compMove=8;
        else if((position[1]=='X'&&position[2]=='X'&&position[0]==1) || (position[3]=='X'&&position[6]=='X'&&position[0]==1) || (position[4]=='X'&&position[8]=='X'&&position[0]==1))
            compMove=1;
        else if((position[0]=='X'&&position[1]=='X'&&position[2]==3) || (position[4]=='X'&&position[6]=='X'&&position[2]==3) || (position[5]=='X'&&position[8]=='X'&&position[2]==3))
            compMove=3;
        else if((position[0]=='X'&&position[3]=='X'&&position[6]==7) || (position[2]=='X'&&position[4]=='X'&&position[6]==7) || (position[7]=='X'&&position[8]=='X'&&position[6]==7))
            compMove=7;
        else if((position[0]=='X'&&position[4]=='X'&&position[8]==9) || (position[2]=='X'&&position[5]=='X'&&position[8]==9) || (position[6]=='X'&&position[7]=='X'&&position[8]==9))
            compMove=9;
        else if((position[0]=='X'&&position[2]=='X'&&position[1]==2) || (position[4]=='X'&&position[7]=='X'&&position[1]==2))
            compMove=2;
        else if((position[0]=='X'&&position[6]=='X'&&position[3]==4) || (position[4]=='X'&&position[5]=='X'&&position[3]==4))
            compMove=4;
        else if((position[2]=='X'&&position[8]=='X'&&position[5]==6) || (position[3]=='X'&&position[4]=='X'&&position[5]==6))
            compMove=6;
        else if((position[1]=='X'&&position[4]=='X'&&position[7]==8) || (position[6]=='X'&&position[8]=='X'&&position[7]==8))
            compMove=8;
        else if((position[1]=='O'&&position[6]=='O'&&position[0]==1) || (position[2]=='O'&&position[3]=='O'&&position[0]==1))
            compMove=1;
        else if((position[0]=='O'&&position[5]=='O'&&position[2]==3) || (position[1]=='O'&&position[8]=='O'&&position[2]==3))
            compMove=3;
        else if((position[0]=='O'&&position[7]=='O'&&position[6]==7) || (position[3]=='O'&&position[8]=='O'&&position[6]==7))
            compMove=7;
        else if((position[2]=='O'&&position[7]=='O'&&position[8]==9) || (position[5]=='O'&&position[6]=='O'&&position[8]==9))
            compMove=9;
        else if(position[3]==4&&position[5]==6) {
            time_t t;
            srand((unsigned)time(&t));

            while(1) {
                int rNum = rand() % 10;
                if(rNum%2 == 0 && rNum != 2 && rNum != 8) {
                    compMove = rNum;
                    break;
                }
            }
        }
        else if(position[1]==2&&position[7]==8) {
            time_t t;
            srand((unsigned)time(&t));

            while(1) {
                int rNum = rand() % 10;
                if(rNum%2 == 0 && rNum != 4 && rNum != 6) {
                    compMove = rNum;
                    break;
                }
            }
        }
        else if(position[0]==1&&position[8]==9) {
            time_t t;
            srand((unsigned)time(&t));

            while(1) {
                int rNum = rand() % 10;
                if(rNum%2 != 0 && rNum != 3 && rNum != 5 && rNum != 7) {
                    compMove=rNum;
                    break;
                }
            }
        }
        else if(position[2]==3&&position[6]==7) {
            time_t t;
            srand((unsigned)time(&t));

            while(1) {
                int rNum = rand() % 10;
                if(rNum%2 != 0 && rNum != 1 && rNum != 5 && rNum != 9) {
                    compMove = rNum;
                    break;
                }
            }
        }
    }

    // If its the 4th or last move or turn
    else {
        if((position[1]=='O'&&position[2]=='O'&&position[0]==1) || (position[3]=='O'&&position[6]=='O'&&position[0]==1) || (position[4]=='O'&&position[8]=='O'&&position[0]==1))
            compMove=1;
        else if((position[0]=='O'&&position[1]=='O'&&position[2]==3) || (position[4]=='O'&&position[6]=='O'&&position[2]==3) || (position[5]=='O'&&position[8]=='O'&&position[2]==3))
            compMove=3;
        else if((position[0]=='O'&&position[3]=='O'&&position[6]==7) || (position[2]=='O'&&position[4]=='O'&&position[6]==7) || (position[7]=='O'&&position[8]=='O'&&position[6]==7))
            compMove=7;
        else if((position[0]=='O'&&position[4]=='O'&&position[8]==9) || (position[2]=='O'&&position[5]=='O'&&position[8]==9) || (position[6]=='O'&&position[7]=='O'&&position[8]==9))
            compMove=9;
        else if((position[0]=='O'&&position[2]=='O'&&position[1]==2) || (position[4]=='O'&&position[7]=='O'&&position[1]==2))
            compMove=2;
        else if((position[0]=='O'&&position[6]=='O'&&position[3]==4) || (position[4]=='O'&&position[5]=='O'&&position[3]==4))
            compMove=4;
        else if((position[2]=='O'&&position[8]=='O'&&position[5]==6) || (position[3]=='O'&&position[4]=='O'&&position[5]==6))
            compMove=6;
        else if((position[1]=='O'&&position[4]=='O'&&position[7]==8) || (position[6]=='O'&&position[8]=='O'&&position[7]==8))
            compMove=8;
        else if((position[1]=='X'&&position[2]=='X'&&position[0]==1) || (position[3]=='X'&&position[6]=='X'&&position[0]==1) || (position[4]=='X'&&position[8]=='X'&&position[0]==1))
            compMove=1;
        else if((position[0]=='X'&&position[1]=='X'&&position[2]==3) || (position[4]=='X'&&position[6]=='X'&&position[2]==3) || (position[5]=='X'&&position[8]=='X'&&position[2]==3))
            compMove=3;
        else if((position[0]=='X'&&position[3]=='X'&&position[6]==7) || (position[2]=='X'&&position[4]=='X'&&position[6]==7) || (position[7]=='X'&&position[8]=='X'&&position[6]==7))
            compMove=7;
        else if((position[0]=='X'&&position[4]=='X'&&position[8]==9) || (position[2]=='X'&&position[5]=='X'&&position[8]==9) || (position[6]=='X'&&position[7]=='X'&&position[8]==9))
            compMove=9;
        else if((position[0]=='X'&&position[2]=='X'&&position[1]==2) || (position[4]=='X'&&position[7]=='X'&&position[1]==2))
            compMove=2;
        else if((position[0]=='X'&&position[6]=='X'&&position[3]==4) || (position[4]=='X'&&position[5]=='X'&&position[3]==4))
            compMove=4;
        else if((position[2]=='X'&&position[8]=='X'&&position[5]==6) || (position[3]=='X'&&position[4]=='X'&&position[5]==6))
            compMove=6;
        else if((position[1]=='X'&&position[4]=='X'&&position[7]==8) || (position[6]=='X'&&position[8]=='X'&&position[7]==8))
            compMove=8;
        else if(position[0]==1)
            compMove=1;
        else if(position[1]==2)
            compMove=2;
        else if(position[2]==3)
            compMove=3;
        else if(position[3]==4)
            compMove=4;
        else if(position[4]==5)
            compMove=5;
        else if(position[5]==6)
            compMove=6;
        else if(position[6]==7)
            compMove=7;
        else if(position[7]==8)
            compMove=8;
        else if(position[8]==9)
            compMove=9;
    }

    sleep(1);
    return compMove;
}

int main() {
    int check, turn=1, choice;
    char player1[20], player2[20], pName1[20], pName2[20];
    system("cls");
    printf("\n\tWelcome to TIC TAC TOE !!\n\n");

    // Taking users choice whether user wants to play single player or multiplayer
    printf("\tEnter a Choice :\n\n\t1. Player Vs Player\t(Press 1)\n\t2. Player Vs Computer\t(Press 2)\n");
    q:
    scanf("%d", &choice);

    // Switch according to users choice
    switch (choice) {

        // If user chooses to play Multiplayer
        case 1:
            printf("\nEnter 1st Player's Name :\t");
            scanf("%s", player1);
            strcpy(pName1, player1);
            strcat(pName1, "'s");

            printf("\nEnter 2nd Player's Name :\t");
            scanf("%s", player2);
            strcpy(pName2, player2);
            strcat(pName2, "'s");

            gdraw(player1, player2);

            while (gres() == -1) {
                if (pTurn == 1)
                    printf("\n %s Turn, Enter a Number :\t", pName1);
                else if (pTurn == 2)
                    printf("\n %s Turn, Enter a Number :\t", pName2);
                z:
                scanf("%d", &input);
                check = gmark();

                if (check == 1)
                    goto z;
                gdraw(player1, player2);

                if (gres() != -1)
                    break;
                pTurn++;

                if (pTurn > 2)
                    pTurn = pTurn/2;
            }

            // Declaring results
            if (gres() == 0)
                printf("\n\n ==> Draw !!! :|\n\n\n");
            else
                if (pTurn == 1)
                    printf("\n\n ==> %s Wins !!! :)\n\n\n", player1);
                else
                    printf("\n\n ==> %s Wins !!! :)\n\n\n", player2); 
            break;

        // If user chooses to play vs Computer
        case 2:
            printf("\nEnter Player's Name :\t");
            scanf("%s", player1);
            strcpy(pName1, player1);
            strcat(pName1, "'s");
            strcpy(player2, "Computer");

            gdraw(player1, player2);

            while (gres() == -1) {
                if (pTurn == 1) {
                    printf("\n %s Turn, Enter a Number :\t", pName1);
                    zz:
                    scanf("%d", &input);
                }
                else {
                    input = comp(turn);
                    turn++;
                }
                check = gmark();

                if (check == 1)
                    goto zz;
                gdraw(player1, player2);

                if (gres() != -1)
                    break;
                pTurn++;

                if (pTurn > 2)
                    pTurn = pTurn/2;
            }

            // Declaring results
            if (gres() == 0)
                printf("\n\n ==> Draw !!! :|\n\n\n");
            else
                if (pTurn == 1)
                    printf("\n\n ==> %s Wins !!! :(\n\n\n", player1);
                else
                    printf("\n\n ==> %s Wins !!! :)\n\n\n", player2); 
            break;

        // If user enter incorrect input
        default:
            printf("Incorrect Input.. Try Again !!\t");
            goto q;
            break;
    }
    return 0;
}