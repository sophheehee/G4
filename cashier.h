
/*************************************
Programmer: Christian Schoffstoll 
Assignment: G2 - Serendipity
Due Date: 23 September 2025
Purpose: Cashier Function Stubs 
***************************************/
#ifndef CASHIER_H
#define CASHIER_H

#include <string> // i threw this in here bc compiler said to

//Function Prototype for Cashier Main
int cashier(); 
//prototypes for helper functions
void printRecipt(std::string, std::string, int, std::string, float, float, float);
float calcTot(int, float, float&);


#endif


