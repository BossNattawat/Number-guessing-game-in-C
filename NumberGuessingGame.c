#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(){

    int min;
    int max;

    int guess;
    int guesses = 0;
    int chance;
    int answer;

    srand(time(0));

    do {
        printf("Enter Lower bound: ");
        scanf("%d", &min);

        printf("Enter Upper bound: ");
        scanf("%d", &max);

        if (max < min) {
            printf("Error: Upper bound must be greater than or equal to Lower bound.\n");
        }

    } while (max < min);

    answer = rand() % (max - min + 1) + min;

    chance = log2(max - min + 1) + 1;

    printf("\n\tYou've only %d chance to guess the number!\n", chance);

    do{
        printf("\nEnter a guess : ");
        scanf("%d", &guess);

        guesses++;

        if(guess > answer){
            printf("Too high!\n");
        }
        else if (guess < answer)
        {
            printf("Too low!\n");
        }
        else {
            printf("\n\tCorrect! You guessed it in %d attempts.\n\n", guesses);
            break;
        }

        if (guesses >= chance) {
            printf("\n\tSorry, you've run out of chances. The correct number was %d.\n\n", answer);
            break;
        }
        

    }while(guess != answer);
    

    return 0;
}