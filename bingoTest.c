#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define ROWS 5
#define COLS 5
#define FREE 2
#define SCALE 15
#define SHIFT 1
#define MAXVAL 75
#define FALSE 0
#define TRUE 1
#define MINVAL 1
#define VALUES 25
#define B 0
#define I 1
#define N 2
#define G 3
#define O 4
#define DOB 'X'


// function prototypes
void welcomeScreen ();
void displayExplicitCard();
void clearScreen();
void displayCard();
void displayRandomCard();
void fillCardRand(int card[ROWS][COLS], int used[MAXVAL]);
void setValue(int card[ROWS][COLS], int used[MAXVAL], int row, int col);
void displayBingoCard(int card[ROWS][COLS]);
void initializeArrays(int used[MAXVAL], int called[MAXVAL], char result[ROWS][COLS]);
void play(int card[ROWS][COLS], int called[MAXVAL], char result[ROWS][COLS]);
 int callNumber(int called[MAXVAL]);
void checkNumber(char letter, int number, int card[ROWS][COLS], char result[COLS][ROWS]);
void displayNumber(char letter, int number);
void displayBingoCardPlay(int card[ROWS][COLS], char result[ROWS][COLS]);

// main function

int main()
{
    int card[ROWS][COLS];
    int used[MAXVAL];
    int called[MAXVAL];
    char result[ROWS][COLS];
    srand(time(0));
    welcomeScreen();
    clearScreen();
    // call function displayExplicitBingoCard
//    displayExplicitCard();
//    // call function clearScreen
//    clearScreen();
//    // call function displayCard()
//    displayCard();
//    // call function clearScreen
//    clearScreen();
//    // generate a random bingo card
//    displayRandomCard();
//    // call function clearScreen
//    clearScreen();
//    // initialize the array
    initializeArrays(used, called, result);
    // populate the 2-d array with the random numbers
    fillCardRand(card, used);
    // receives an array to display the data stored
    displayBingoCard(card);
    play(card, called, result);
    // program executed successfully
    return 0;
}
// welcomeScreen function displays the BINGO logo and rules of the game
void welcomeScreen ()
{
printf ("\t\t\tBBBBB   II  NN     NN    GGGGG    OOOO  \n");
printf ("\t\t\tBB  BB  II  NN N   NN  GG        OO  OO \n");
printf ("\t\t\tBBBBB   II  NN  N  NN  GG        OO  OO \n");
printf ("\t\t\tBB  BB  II  NN   N NN  GG  GGGG  OO  OO \n");
printf ("\t\t\tBBBBB   II  NN     NN   GGGGGG    OOOO  \n");
printf ("\n\n");//
printf ("RULES OF THE GAME:\n");
    printf("1. A player receives a Bingo card\n");
    printf("2. Each card has a random placement of numbers for each column, B, I, N. G, O\n");
    printf("\t Column B contains values 1 - 15\n");
    printf("\t Column I contains values 16 - 30\n");
    printf("\t Column N contains values 31 - 45 in addition to a FREE space\n");
    printf("\t Column G contains values 46 - 60\n");
    printf("\t Column O contains values 61 - 75\n");
    printf("3. Various patterns are identified to accomplish a BINGO\n");
    printf("4. Each round of the game will identify which pattern should be accomplished to win a BINGO\n");
    printf("5. Winning numbers are randomly selected during play\n");
    printf("6. Good luck!\n");
}
// function displayExplicitBingoCard displays a hardcoded version of a bingo card
void displayExplicitCard()
{
    printf("\n Function displayExplicitCard \n");
    printf("|---------------------------------------|\n");
    printf("|   B   |   I   |   N   |   G   |   O   |\n");
    printf("|---------------------------------------|\n");
    printf("|   15  |   16  |   31  |   46  |   61  |\n");
    printf("|---------------------------------------|\n");
    printf("|   2   |   23  |   45  |   60  |   75  |\n");
    printf("|---------------------------------------|\n");
    printf("|   5   |   20  |  FREE |   51  |   68  |\n");
    printf("|---------------------------------------|\n");
    printf("|   12  |   27  |   40  |   55  |   70  |\n");
    printf("|---------------------------------------|\n");
    printf("|   9   |   30  |   37  |   49  |   64  |\n");
    printf("|---------------------------------------|\n");
}
void displayCard()
{
    int row;
    int col;
    int num;
    printf("\n Function displayCard \n");
    printf("|---------------------------------------|\n");
    printf("|   B   |   I   |   N   |   G   |   O   |\n");
    printf("|---------------------------------------|\n");
    for(row = 0; row < ROWS; row++)
    {
        printf("|");
        for(col = 0; col < COLS; col++)
        {
            num = (col + SHIFT) * SCALE - row;
            if(row == FREE && col == FREE)
            {
                printf("  FREE |");
            }
            else
            {
                printf("%s%-3d", "   ", num);
                printf(" |");
            }
        }
        printf("\n");
        printf("|---------------------------------------|\n");
    }
}
// function clearScreen clears the screen for display purposes
void clearScreen()
{
    printf("\n\t\t\t\tHit <ENTER> to continue!\n");
char enter;
scanf("%c", &enter);
// send the clear screen command Windows
    //system("cls");
    // send the clear screen command for UNIX flavor operating systems
    system("clear");
}
void displayRandomCard()
{
    int row;
    int col;
    int base;
    int num;
    printf("\n Function displayRandomCard \n");
    printf("|---------------------------------------|\n");
    printf("|   B   |   I   |   N   |   G   |   O   |\n");
    printf("|---------------------------------------|\n");
    for(row = 0; row < ROWS; row++)
    {
        printf("|");
        for(col = 0; col < COLS; col++)
        {
            base = SCALE * col;
            num = (rand() % SCALE) + SHIFT + base;
            if(row == FREE && col == FREE)
            {
                printf("  FREE |");
            }
            else
            {
                printf("%s%-3d", "   ", num);
                printf(" |");
            }
        }
        printf("\n");
        printf("|---------------------------------------|\n");
    }
}
void fillCardRand(int card[ROWS][COLS], int used[MAXVAL])
{
    int row;
    int col;
    for(col = 0; col < COLS; col++)
    {
        for(row = 0; row < ROWS; row++)
        {
            // if location is the FREE space, set the value to 0
            if(row == FREE && col == FREE)
            {
                card[row][col] = 0;
            }
            else
            {
                setValue(card, used, row, col);
            }
        }
    }
}
void setValue(int card[ROWS][COLS], int used[MAXVAL], int row, int col)
{
    int num;
    int base;
    int idx;
    base = SCALE * col;
    num = (rand() % SCALE) + SHIFT + base;
    idx = num - SHIFT;
    if(used[idx] == FALSE)
    {
        used[idx] = TRUE;
        card[row][col] = num;
    }
    else
    {
        // already used the number, try again
        setValue(card, used, row, col);
    }
}
void displayBingoCard(int card[ROWS][COLS])
{
    int row;
    int col;
    printf("\n Function displayBingoCard \n");
    printf("|---------------------------------------|\n");
    printf("|   B   |   I   |   N   |   G   |   O   |\n");
    printf("|---------------------------------------|\n");
    for(row = 0; row < ROWS; row++)
    {
        printf("|");
        for(col = 0; col < COLS; col++)
        {
            if(row == FREE && col == FREE)
            {
                printf("  FREE |");
            }
            else
            {
                printf("%s%-3d", "   ", card[row][col]);
                printf(" |");
            }
        }
        printf("\n");
        printf("|---------------------------------------|\n");
    }
}
void initializeArrays(int used[MAXVAL],int called[MAXVAL], char result[ROWS][COLS])
{
    int col;
    int row;
    for(col = 0; col < MAXVAL; col++)
    {
        used[col] = FALSE;
        called[col] = FALSE;
    }
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            result[row][col] = (char)" ";
        }
    }
}

void play(int card[ROWS][COLS], int called[MAXVAL], char result[ROWS][COLS]) {
    int number;
    bool bingo = false;
    char letter;
    int counter = 0;
    while (bingo == false) {
        number = callNumber(called);
        if (number > 0 && number < 16) {
            letter = 'B';
            break;
        }
        else if (number > 15 && number < 31) {
            letter = 'I';
            break;
        }
        else if (number > 30 && number < 46) {
            letter = 'N';
            break;
        }
        else if (number > 45 && number < 61) {
            letter = 'G';
            break;
        }
        else if ( number > 60 && number < 76) {
            letter = 'O';
            break;
        }
    }
    displayNumber(letter, number);
    checkNumber(letter, number, card, result);
    displayBingoCardPlay(card, result);
    counter++;
        if (counter == VALUES) {
        bingo = true;
    }
}

void displayNumber(char letter, int number) {
    printf("%c %d", letter, number);
    char enter;
    scanf("%c", &enter);
    
}

void checkNumber(char letter, int number, int card[ROWS][COLS], char result[COLS][ROWS]) {
    int row;
    int col;
        switch(letter) {
        case 'B' :
            col = B;
            break;
        case 'I' :
            col = I;
            break;
        case 'N' :
            col = N;
            break;
        case 'G' :
            col = G;
            break;
        case 'O' :
            col = O;
            break;
 }
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            if (card[row][col] == number) {
                card[row][col] = DOB;
            }
        }
    }
}

int callNumber(int called[MAXVAL]) {
    int num;
    int idx;
    idx = (rand() % MAXVAL);
    num = idx + SHIFT;
    if (called[idx] == FALSE) {
        called[idx] = TRUE;
    }
    else {
        callNumber(&num);
    }
    return num;
}

void displayBingoCardPlay(int card[ROWS][COLS], char result[ROWS][COLS]) {
    int row;
    int col;
    printf("\n Function displayBingoCardPlay \n");
    printf("|---------------------------------------|\n");
    printf("|   B   |   I   |   N   |   G   |   O   |\n");
    printf("|---------------------------------------|\n");
    for(row = 0; row < ROWS; row++)
    {
        printf("|");
        for(col = 0; col < COLS; col++)
        {
        
            if(row == FREE && col == FREE)
            {
                printf("  FREE |");
            }
            else
            {
                if (card[row][col] == DOB ) {
                printf("%d", result[row][col]);
            }
                printf("%s%-3d", "   ", card[row][col]);
                printf(" |");
            }
        }
        printf("\n");
        printf("|---------------------------------------|\n");
    }
}