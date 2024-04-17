#include <stdio.h>

#define MAX_WRONG_GUESSES 6
#define word_limit 7
void drawHangman(int );
int main() {
    char word[] = "hangman";
    char guessed_word[] = "_______";
   
    int wrong_guesses = 0;
    int guessed_all_letters = 0;

    printf("                                  Welcome to Hangman!\n");
    printf("----------------------------------------------------------------------------------------------------------------------\n");
    printf("                                      Game info:\n");
    printf("The object of hangman is to guess the secret word before the stick figure is hung.\n");
    printf("Players take turns selecting letters to narrow the word down.\nGameplay continues until the players guess the word or they run out of guesses and the stick figure is hung.\n");
    printf("----------------------------------------------------------------------------------------------------------------------\n");
     
     
    while (wrong_guesses < MAX_WRONG_GUESSES && !guessed_all_letters) {
        printf("\nWord: %s\n", guessed_word);
        printf("Enter a letter: ");

        char guess;
        scanf(" %c", &guess);

        int found = 0;
        for (int i = 0; i<word_limit; i++) {
            if (word[i] == guess && guessed_word[i] == '_') {
                guessed_word[i] = guess;
                found = 1;
            }
        }

        if (!found) {
            printf("Incorrect guess!\n");
            wrong_guesses++;
        }

        int flag = 1;
        for (int i = 0; i<word_limit; i++) {
            if (guessed_word[i] == '_') {
                flag = 0;
                break;
            }
            
            
        }

        if (flag) {
            printf("Congratulations! You guessed the word: %s\n", word);
            break;
        }

        if (wrong_guesses >= MAX_WRONG_GUESSES && !guessed_all_letters) {
            printf("Sorry, you ran out of guesses. The word was: %s\n", word);
        }
        drawHangman(wrong_guesses);
    }

    return 0;
}
void drawHangman(int wrong_guesses) {
    switch (wrong_guesses) {
        case 0:
            printf("  ____\n");
            printf("  |  |\n");
            printf("     |\n");
            printf("     |\n");
            printf("     |\n");
            printf("     |\n");
            printf("_____|___\n");
            break;
        case 1:
            printf("  ____\n");
            printf("  |  |\n");
            printf("  O  |\n");
            printf("     |\n");
            printf("     |\n");
            printf("     |\n");
            printf("_____|___\n");
            break;
        case 2:
            printf("  ____\n");
            printf("  |  |\n");
            printf("  O  |\n");
            printf("  |  |\n");
            printf("     |\n");
            printf("     |\n");
            printf("_____|___\n");
            break;
        case 3:
            printf("  ____\n");
            printf("  |  |\n");
            printf("  O  |\n");
            printf(" /|  |\n");
            printf("     |\n");
            printf("     |\n");
            printf("_____|___\n");
            break;
        case 4:
            printf("  ____\n");
            printf("  |  |\n");
            printf("  O  |\n");
            printf(" /|\\ |\n");
            printf("     |\n");
            printf("     |\n");
            printf("_____|___\n");
            break;
        case 5:
            printf("  ____\n");
            printf("  |  |\n");
            printf("  O  |\n");
            printf(" /|\\ |\n");
            printf(" /   |\n");
            printf("     |\n");
            printf("_____|___\n");
            break;
        case 6:
            printf("  ____\n");
            printf("  |  |\n");
            printf("  O  |\n");
            printf(" /|\\ |\n");
            printf(" / \\ |\n");
            printf("     |\n");
            printf("_____|___\n");
            break;
    }
}
