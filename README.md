# Interactive Score Histogram Generator

## Description  
C program that displays a histogram of a set of scores entered from the keyboard. There is a predefined maximum score and number of intervals.  
The user enters as many scores as they wish and the program keeps track of how many numbers were entered in each interval.  
The histogram then uses horizontal bars of asterisks to show the number of scores in each interval as well as the number of perfect scores.

## Pseudocode  
- User prompted to enter scores or print histogram (in main function which loops until sentinel value is entered)  
- `getScores` function gets scores from user and keeps track of how many times user enters a number in each interval (which loops until sentinel value is entered)  
- `printHistogram` function displays histogram of intervals and prints "*" for number entered in each interval  
- User prompted to exit program or enter new set of scores (program terminates or restarts)

## Example Output
![image alt](https://github.com/aclaycode/interactive_score_histogram_generator/blob/main/interactive_score_histogram_generator_example_output.png?raw=true)

## How to Compile  
```bash```
gcc score_histogram_generator.c -o score_histogram_generator.exe

## How to Run
On Windows PowerShell or Command Prompt, navigate to the rolder containing the executable and run:
./score_histogram_generator.exe

## Features
- Supports user input of multiple scores until sentinel value is entered
- Automatically categorizes scores into predefined intervals
- Prints a histogram with asterisks representing counts in each interval
- Allows restarting the program or exiting after each histogram

## Usage Notes
- Enter scores between 1 and the maximum score (50 by default)
- Enter -1 to stop entering scores and print the histogram
- Enter -2 after the histogram to exit the program or any other number to restart

## Author
AJ Clay
