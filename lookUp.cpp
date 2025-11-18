/***************************************************
* Programmer: Sophia Omar
* Assignment: G3 -- Add & Look Up Book
* Due Date: 14 October 2025
* Purpose: Look Up Book Function Implementation
*****************************************************/
#include <iostream>
#include <limits>
#include <vector> 
#include "invmenu.h"
#include "bookInfo.h"
#include "utilities.h"
using namespace std; 

//Header Functions 
void displaySearchBy(){
	cout <<"What would you like to do?\n";
	cout << "1. Search by Title\n"; 
	cout << "2. Search by ISBN\n"; 
	cout << "3. Return to Inventory Menu\n";

}
void displaySearchHeader(){
		cout <<"SERENDIPITY BOOKSELLERS\n";
		cout <<"Inventory Search Menu\n\n"; 

}

/*************************Search Functions *****************/ 
//SEARCH BY TITLE (case insensitive & substring) 
static std::vector<size_t> findAllTitles(const std::vector<bookInfo>& database, const std::string& keyRaw) {
    std::vector<size_t> result;
    std::string key = toLowerString(keyRaw);
    for (size_t i = 0; i < database.size(); ++i) {
        if (toLowerString(database[i].getTitle()).find(key) != std::string::npos) {
            result.push_back(i);
        }
    }
    return result;
}

//SEARCH BY ISBN
static int searchISBN(const vector<bookInfo>& database, const string& isbn){
	for(size_t i =0; i <database.size(); ++i){
		if(database[i].getISBN() ==isbn){
			return(int)i; }
	} return-1;
} 


/**************************Print Functinos*************************/

static void printOneBook(const bookInfo& b, size_t indOne){
		cout << indOne << "." <<b.getTitle()
			 <<"\n   ISBN: "      << b.getISBN()
         << "\n   Author: "    << b.getAuthor()
         << "\n   Publisher: " << b.getPublisher()
         << "\n   Qty: "       << b.getQty()
         << "\n   Whole: $"    << b.getWholeCost()
         << "\n   Retail: $"   << b.getRetailCost()
         << "\n   Date: "      << b.getDate()
         << "\n------------------------------------------------------------\n";


}

/*******************Main driver menu ********/
void lookUpBook(const vector<bookInfo>& database){
		int choice; 
 	do{
		//Display header
		clear(); 
		displaySearchHeader(); 
		displaySearchBy(); 
		//get choice
		choice = readChoice("Enter Choice (1-3):",1,3); 

	//create switch menu
		switch(choice){
		case 1:{
			clear(); 
			string key = readLine("Enter Title to Search:");
			auto matches = findAllTitles(database, key); 
			if(matches.empty()){
				cout <<"\nNo books found\n";}
			else{
				cout <<"\nFound" <<matches.size() <<"matching book(s):\n";
				cout <<"------------------------------------------------------------\n";
				for(size_t i = 0; i < matches.size(); ++i){
					printOneBook(database[matches[i]], i+1); 
				}
			}
			 
			break; 
		}
		case 2: {
			//search by isbn
			clear(); 
			string key = readLine("Enter ISBN: "); 
			int index = searchISBN(database, key); 
			if(index == -1) {
				cout<< "\n No book with that ISBN. \n"; }
			else{
			cout <<"\nMatch:\n------------------------------------------------------------\n";
			printOneBook(database[(size_t)index], 1);
			}
			 
			break; 
			}
		case 3:  //exit loop
			break; 

				} 

			if(choice !=3){
				pauseEnter();
				clear();  
			}

	} while (choice !=3);

}
