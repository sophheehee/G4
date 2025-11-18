/***************************************************
* Programmer: Sophia Omar
* Assignment: G3 -- Add & Look Up Book
* Due Date: 14 October 2025
* Purpose: Header File for addBook Function
*****************************************************/

#ifndef ADDBOOK_H
#define ADDBOOK_H

#include <vector> 
#include "bookInfo.h" 
#include "invmenu.h"


// Function Def for addBook 
void addBook(std::vector<bookInfo>& inventory, std::size_t capacity = 20); 


#endif

