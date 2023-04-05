// This is a test file. (Two functions: timer and displayclock are defined.)
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

void displayClock(int hours, int minutes, int seconds) {
    // This function takes in three integers and will print the timer on the screen (stdout).
    cout <<setfill(' ') <<setw(55) <<"         TIMER         \n";
    cout <<setfill(' ') <<setw(55) <<" --------------------------\n";
    cout <<setfill(' ') <<setw(29);
    cout <<"| " <<setfill('0') <<setw(2) <<hours <<" hrs | ";
    cout <<setfill('0') <<setw(2) <<minutes <<" min | ";
    cout <<setfill('0') <<setw(2) <<seconds <<" sec |" <<endl;
    cout <<setfill(' ') <<setw(55) <<" --------------------------\n";
}

void timer(int hours, int minutes, int seconds) {
    // A simple timer program which takes in three integer and execute increment and calculation.
    while (true) {
        displayClock(hours, minutes, seconds);
        sleep(1);
        // The program pauses every second and the variable seconds increase by 1.
        seconds++;
        if (seconds == 60) {
            minutes++;
            if (minutes == 60) {
                hours++;
                minutes = 0;
            }
            seconds = 0;
        }
    }
}