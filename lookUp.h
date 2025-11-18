/***************************************************
* Programmer: Sophia Omar
* Assignment: G3 -- Add & Look Up Book
* Due Date: 14 October 2025
* Purpose: Header File for lookUp
*****************************************************/
#ifndef LOOKUP_H
#define LOOKUP_H

#include <vector>
#include "bookInfo.h"

//Function Prototypes
void lookUpBook(std::vector<bookInfo>& database); 
int lookUpBookDEL(std::vector<bookInfo>& database,bool returnIndex); // one that returns the index for delete book


#endif
