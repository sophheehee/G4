/***************************
* Programmer: Sophia Omar
* Assignment: Serendipity G4
* Due Date: 11/18/2025
* Purpose: Delete Book Function
*****************************/
#include <iostream>
#include <vector>
#include "deleteBook.h"
#include "lookUpBook.h"
#include "utilities.h" 
using namespace std;

void displayHeader(){
	cout <<"SERENDIPITY BOOKSELLERS\n";
		cout <<"Delete a Book\n\n"; 

} 

void deleteBook(std::vector<bookInfo>& database){
	while(true){
		
		clear(); 
		displayHeader(); 
		
		//return the index from lookup
		int index = lookUpBookDEL(database, true); 
		if (index = -1){
			cout << "No matching book found.\n"; 
			pauseEnter();
			return; // to go back to OG inv menu
		}

	}
}
