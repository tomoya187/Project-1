// 3_1_Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Jeffrey Baker 
//Class: CS-210-H7534 Programming Languages 22EW6
//Date: 7/17/22
using namespace std;
#include <iostream>
#include <string>

int hour = 0;
int* hourPtr = &hour;
int minute = 59;
int sec = 9;

string twoDigitString(int n) {
    string result = "";
    if (n < 10) {                       
        result = "0";
    }
    result = result.append(to_string(n));
    
    return result;
}
string nCharString(size_t n, char c) {
    string result = "";
    
    for (int i = 0; i < n; i++) {
        result += c;
    }
    return result;
}

string formatTime24(unsigned int h, unsigned int m, unsigned int s) {
    string result = "";
    
    result = result.append(twoDigitString(h));
    result += ':';
    result = result.append(twoDigitString(m));
    result += ":";
    result = result.append(twoDigitString(s));

    return result;
}

string formatTime12(unsigned int h, unsigned int m, unsigned int s) {
    string result = "";
    string time = "A M";

    if (h >= 12) {
        time = "P M";
        h -= 12;
    }
    if (h == 0) {
        h = 12;
    }

    result = result.append(twoDigitString(h));
    result += ':';
    result = result.append(twoDigitString(m));
    result += ":";
    result = result.append(twoDigitString(s));
    result += " ";
    result += time;
    return result;
}
/*
void printMenu(char* strings[], unsigned int numStrings, unsigned char width) {
    cout << nCharString(width, '*');

    cout << "\n";

    for (int i = 0; i < 4; i++) {
        cout << "* " << i + 1 << " - " << strings[i] << nCharString(width - strlen(strings[i]) - 7, ' ') << "*";
        cout << "\n";
        if (i != 3) {
            cout << "\n";
        }
    }

    cout << nCharString(width, '*');
}
*/

unsigned int getMenuChoice(unsigned int maxChoice) {
    int result = 0;
    bool flag = false;

    while (!flag) {
        cin >> result;
        if (result <= 1 && result >= maxChoice) {
            flag = true;
        }
    }
    return result;
}

void displayClocks(int h, int m, int s) {
    cout << nCharString(27, '*');
    cout << "   ";
    cout << nCharString(27, '*') << endl;
    cout << "*      " << "12-HOUR CLOCK" << "      *   ";
    cout << "*      " << "24-HOUR CLOCK" << "      *\n";
    cout << endl;
    cout << "*      " << formatTime12(h, m, s) << "       *   ";
    cout << "*        " << formatTime24(h, m, s) << "         *\n";
    cout << nCharString(27, '*');
    cout << "   ";
    cout <<nCharString(27, '*') << endl;
}
void addOneHour() {
    ::hour += 1;
}
void addOneMinute() {
    if (minute == 59) {
        minute = 0;
        addOneHour();
    }
    else {
        minute += 1;
    }
}
void addOneSecond() {
    if (sec == 59) {
        sec = 0;
        addOneMinute();
    }
    else {
        sec += 1;
    }
    
    
}

void printMenu() {
    cout << nCharString(27, '*') << endl;
    cout << "* 1-Add One hour         *" << endl;
    cout << "* 2-Add One Minute       *" << endl;
    cout << "* 3-Add One Second       *" << endl;
    cout << "* 4-Exit Program         *" << endl;
    cout << nCharString(27, '*') << endl;
    int input = 0;
 
}
int main()
{
    int input = 0;
    displayClocks(hour, minute, sec);
    printMenu();
    while (true) {
        
        cin >> input;
        if (input == 1) {
            system("CLS");
            addOneHour();
            displayClocks(hour, minute, sec);
            printMenu();
        }
        else if (input == 2) {
            system("CLS");
            addOneMinute();
            displayClocks(hour, minute, sec);
            printMenu();
        }
        else if (input == 3) {
            system("CLS");
            addOneHour();
            displayClocks(hour, minute, sec);
            printMenu();
        }
        else if (input == 4) {
            break;
        }

    }
}

