/***************************************************
* Programmer: Sophia Omar
* Assignment: G3 -- Add & Look Up Book
* Due Date: 14 October 2025
* Purpose: Helper functions/Utilities for Serendipity
*****************************************************/
#ifndef UTILITIES_H
#define UTILITIES_H


#include <string>

//Screen Related
void clear(); 
void pauseEnter(); 


//Input validation and stuff
int readChoice(const std::string& prompt, int min, int max); 

//String Tools
std::string readLine(const char* prompt); 
std::string toLowerString(std::string s); 


#endif
