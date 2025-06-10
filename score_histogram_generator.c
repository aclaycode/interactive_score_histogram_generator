/*-----------------------------------------------------------------------------
* Programmer: AJ Clay
* Date: 06/29/15
* Name: score_histogram_generator/main.c
* Description:  C program that displays a histogram of a set of scores entered from the keyboard.  There is a predefined maximum score and number of intervals.
                The user enters as many scores as he/she wishes and the program keeps track of how many numbers were entered in each interval.
                The histogram then uses horizontal bars of asterisks to show the number of scores in each interval as well as the number of perfect scores.

* Pseudocode: - User prompted to enter scores or print histogram (in main function which loops until sentinel value is entered)
              - "getScores" function gets scores from user and keeps track of how many times user enters a # in each interval (which loops until sentinel values is entered)
              - "printHistogram" function displays histogram of intervals and prints "*" for number entered in each interval
              - User prompted to exit program or enter new set of scores (program terminates or program restarts)
              - If user decides to restart, this process is repeated
 -----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#define MAXSCORE 50
#define INTSIZE 10

void getScores(int intervalCounts[], int intervalSize, int maxScore);         //prototype for function that gets scores and keeps track of which interval it is in
void printHistogram(int intervalCounts[], int intervalSize, int maxScore);    //prototype for function that prints histogram of scores

int main ()
{
    int input=0;
    while (input!=-2)                                                         //main function loops until user enters -2
    {
        int i;
        int intervalCounts[MAXSCORE/INTSIZE+1]={0};                           //this variable keeps track of how many #'s are entered in each interval

        getScores(intervalCounts, INTSIZE, MAXSCORE);                         //calling "getScores" function to get scores from user
        printHistogram(intervalCounts, INTSIZE, MAXSCORE);                    //calling "printHistogram" function to print histogram after user enters scores
        printf("Enter -2 to exit program OR enter any number to restart and enter new\n");  //prompts user to exit to enter or restart program
        printf("set of scores\n");
        scanf("%d", &input);
    }
    return 0;
}

void getScores(int intervalCounts[], int intervalSize, int maxScore)        //function that gets scores from user
{
    int numIntervals=maxScore/intervalSize;
    int c;
    int i;
    int input;
    printf("Enter score OR enter -1 to print histogram\n");                 //informs user to enter score or to print histogram

    while (input!=-1)
    {
        scanf("%d", &input);
        c=1;

        if(input==maxScore)                                                 //keeps track of how many times the max score is entered
        {
            intervalCounts[maxScore/intervalSize]=intervalCounts[maxScore/intervalSize]+1;
            printf("Enter score OR enter -1 to print histogram\n");
        }
        else if (input==-1)                                                 //user enters -1 when they are done entering scores
        {
            input=-1;
        }
        else if (input<1||input>maxScore)                                   //Error message is displayed if user does not enter score between 0 & the max score
        {
            printf("Error: please enter valid score\n");
        }
        else                                                                //keeps track of how many times user enters a number in each interval
        {
            for(i=0;i<numIntervals;i++)
            {
                if(input>=i*intervalSize && input<=c*intervalSize-1)
                {
                    intervalCounts[i]=intervalCounts[i]+1;           //for each valid number entered, its corresponding interval is incremented by 1 (for keeping track)
                }
            c=c+1;
            }
            printf("Enter score OR enter -1 to print histogram\n");
        }
    }
    return;
}

void printHistogram(int intervalCounts[], int intervalSize, int maxScore)       //function that prints histogram of scores
{
    int intervalSize2;
    int numIntervals=maxScore/intervalSize;
    int interval=intervalSize;
    int i;
    int j;
    int mult1=1;
    int mult2=2;
        for (i=0;i<numIntervals;i++)                            //displays first interval and how many times user entered #'s in that interval
        {
            if (i==0)
            {
                printf("\n");
                printf("Interval\n");
                printf("%d-%d", i,interval-1);
                printf("\t\t");
                printf("|");
                    for (j=0;j<intervalCounts[i];j++)          //loop prints * for every time user entered a # in each interval
                    {
                        printf("*");                        //prints "*" for every time user entered a number in each interval
                    }
            }
            else                                         //displays the rest of intervals (except for last interval) and how many times user entered #'s in that interval
            {
                printf("\n");
                interval=mult1*intervalSize;
                mult1=mult1+1;
                intervalSize2=mult2*intervalSize-1;
                mult2=mult2+1;
                printf("%d-%d", interval,intervalSize2);
                printf("\t\t");
                printf("|");
                for (j=0;j<intervalCounts[i];j++)
                {
                    printf("*");
                }
            }
        }
        printf("\n");                                          //the rest of the code displays the last interval and how many times user entered #'s in that interval
        printf("%d", maxScore);
        printf("\t\t");
        printf("|");
        for (i=0;i<intervalCounts[maxScore/intervalSize];i++)
        {
            printf("*");
        }
        printf("\n");
    return;
}