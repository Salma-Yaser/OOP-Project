//
// Created by hima1 on 5/16/2024.
//

#ifndef OOP_PROJECT_GLOBAL_H
#define OOP_PROJECT_GLOBAL_H

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// read integer from user between low and high
int getIntRange(int low, int high);

// display menu to user and return number of choosen option
int readMenu(vector <string> menu, string text, string color = "\033[1;36m");

void header(string s, string color = "\033[1;36m");

string colored(string s, string color);

// convert characters in string tolower case.
void to_lower(string& s);

void to_upper(string& s);

// ask user if he want to continue? return true or false
bool isContinue();

void pauseScreen();

enum Position {LEFT, CENTER, RIGHT};
string printAlign(string input, Position pos, int width);


#endif //OOP_PROJECT_GLOBAL_H