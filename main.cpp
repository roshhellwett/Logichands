#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("\n----CREATED BY ROSHHELLWET----\n");
    char userChoice, choice;
    char options[] = {'R', 'P', 'S'};
    int randomIndex;
    char computerChoice;
    int userScore = 0, computerScore = 0, rounds = 0;

    srand(time(NULL));

    printf("\nWELCOME TO ROCK, PAPER & SCISSOR\n");
    printf("---- GAME GUIDE ----\n");
    printf("R for ROCK\n");
    printf("P for PAPER\n");
    printf("S for SCISSOR\n");

    do {
        printf("\n==========================\n");
        printf("ROUND %d\n", ++rounds);
        printf("==========================\n");

        printf("\nYOUR TURN (R/P/S): ");
        scanf(" %c", &userChoice);

        if (userChoice >= 'a' && userChoice <= 'z')
            userChoice -= 32;

        if (userChoice != 'R' && userChoice != 'P' && userChoice != 'S')
        {
            printf("\nINVALID INPUT ! PLEASE ENTER R, P, or S.\n");
            rounds--;
            continue;
        }

        randomIndex = rand() % 3;
        computerChoice = options[randomIndex];

        printf("\nCPU CHOOSE : %c\n", computerChoice);

        // Determine result
        if (userChoice == computerChoice)
        {
            printf("\n IT'S A TIE!\n");
        }
        else if ((userChoice == 'R' && computerChoice == 'S') || (userChoice == 'P' && computerChoice == 'R') || (userChoice == 'S' && computerChoice == 'P'))
        {
            printf("\nYOU WIN THIS ROUND !\n");
            userScore++;
        }
        else
        {
            printf("\nCPU WINS THIS ROUND !\n");
            computerScore++;
        }

        printf("\n--- SCOREBOARD ---\n");
        printf("YOU : %d | CPU : %d\n", userScore, computerScore);

        printf("\nWANNA PLAY AGAIN ? (Y/N): ");
        scanf(" %c", &choice);

    } while (choice == 'Y' || choice == 'y');

    printf("\n==========================\n");
    printf("\n    ----FINAL SCORE----   \n");
    printf("YOU : %d | CPU : %d\n", userScore, computerScore);

    if (userScore > computerScore)
        printf("\nCONGRATULATIONS, YOU ARE THE WINNER !\n");
    else if (computerScore > userScore)
        printf("\nCPU WINS THIS GAME, BETTER LUCK NEXT TIME !\n");
    else
        printf("\nIT'S OVERALL TIE !\n");

    printf("\nTHANKS FOR PLAYING !\n");

    return 0;
}
