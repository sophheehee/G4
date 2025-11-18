/*
NAME: Christian Schoffstoll
PROGRAM: addBook.cpp
DUE: 10/14/25
FOR: Adding books to database
*/

#include "addBook.h"
#include "bookInfo.h"
#include "lookUp.h"
#include "utilities.h"
#include <cctype>
#include <vector>
void addBookPrint(const bookInfo& b, const std::vector<bookInfo>& v) ;

void addBook(std::vector<bookInfo>& inventory, std::size_t capacity) {

		char choice = ' '; //user menu choice
		std::string data_s = " "; //user entered data for string values
		int data_i = 0; //user entered data for integer values
		float data_f = 0.0; //user entered data for floating values

		bookInfo blank; //blank book to prevent vector from crashing

		blank.setQty(0); //default values
		blank.setWholeCost(0.0);
		blank.setRetailCost(0.0);

		inventory.push_back(blank);

		char esc = ' '; //allows user choice to leave to main menu or stay

		while (inventory.size() < 21) { //prevents bookcout from increasing past 20

			addBookPrint(blank, inventory); //function call

			std::cin >> choice; //reads user input for menu

			std::cin.ignore();

			switch (choice) {

			case '1':

				std::getline(std::cin, data_s); //takes user input for title info
				blank.setTitle(data_s); //saves title info
				clear(); //clear screen
				break;

			case '2':

				std::getline(std::cin, data_s); //takes user input for ISBN info
				blank.setISBN(data_s); //saves ISBN info
				clear(); //clear screen
				break;

			case '3':

				std::getline(std::cin, data_s); //takes user input for author info
				blank.setAuthor(data_s); //save author info
				clear(); //clear screen
				break;

			case '4':

				std::getline(std::cin, data_s); //takes user input for publisher info
				blank.setPublisher(data_s); //saves publisher info
				clear(); //clear screen
				break;

			case '5':

				std::getline(std::cin, data_s); //takes user input for date info
				blank.setDate(data_s); //saves date info
				clear(); //clear screen
				break;

			case '6':

				std::cin >> data_i; //takes user input for quantity info
				blank.setQty(data_i); //saves quantity info
				std::cin.ignore();
				clear(); //clear screen
				break;

			case '7':

				std::cin >> data_f; //takes user input for wholesale cost info
				blank.setWholeCost(data_f); //saves wholesale cost info
				std::cin.ignore();
				clear(); //clear screen
				break;

			case '8':

				std::cin >> data_f; //takes user input for retail cost info
				blank.setRetailCost(data_f); //saves retail cost info
				std::cin.ignore();
				clear(); //clear screen
				break;

			case '9':

				inventory.push_back(blank); //saves data to database and resets displayed pending values
				blank.setTitle("NOT SET");
				blank.setISBN("NOT SET");
				blank.setAuthor("NOT SET");
				blank.setPublisher("NOT SET");
				blank.setDate("NOT SET");
				blank.setQty(0);
				blank.setWholeCost(0.0);
				blank.setRetailCost(0.0);
				clear();
				break;

			case '0':

				while (esc != 'y' && esc != 'n') {

					std::cout << "Return to main menu? (Y/N): ";
					std::cin >> esc;

					esc = tolower(esc);

				}

				if (esc == 'y') {

					invMenu(inventory);
				}

				clear();

				break;

			default:

				std::cout << "Invalid choice (1-0), press ENTER:"; //freezes screen and instructs user
				std::cin.ignore();
				std::cin.ignore();
				clear();
				break;
			}

			if (inventory.size() == 21) { //Force backout to inventory menu when database is full

				inventory.push_back(blank);

				std::cout << "Database is full, saving entered data.\n\n";

				std::cin.ignore();
				std::cin.ignore();

				invMenu(inventory);

			}

		};

}

void addBookPrint(const bookInfo& blank, const std::vector<bookInfo> &v) {

	std::string title = blank.getTitle(); //creates local variable for title truncation

	if (title.length() > 38) { //maximum length of title being 38 characters

		title = title.substr(0, 35) + "..."; //removes trailing 3 characters for ...
	}

	std::cout << std::setfill('-') << std::setw(120);
	std::cout << "\n" << std::setfill(' ') << std::setw(63) << "Serendipity Booksellers";
	std::cout << "\n" << std::setw(56) << "Add Book";
	std::cout << "\n" << std::setfill('-') << std::setw(121);
	std::cout << "\n " << "Database Size: " << 20 << std::setfill(' ') << std::setw(75) << "Book Count : " << v.size() - 1;
	std::cout << "\n\n" << std::setw(95) << "| Pending Values " << std::setw(26) << "\n";
	
	std::cout << "\n 1) Book Title:" << std::setw(65) << "| " << title;
	std::cout << "\n 2) ISBN:" << std::setw(71) << "| " << blank.getISBN();
	std::cout << "\n 3) Author:" << std::setw(69) << "| " << blank.getAuthor();
	std::cout << "\n 4) Publisher:" << std::setw(66) << "| " << blank.getPublisher();
	std::cout << "\n 5) Date Added (MM/DD/YYYY):" << std::setw(52) << "| " << blank.getDate();
	std::cout << "\n 6) Quantity on Hand:" << std::setw(59) << "| " << blank.getQty() << std::setw(29);
	std::cout << "\n 7) Wholesale Cost:" << std::setw(61) << "|$" << std::fixed << std::setprecision(2) << blank.getWholeCost();
	std::cout << "\n 8) Retail Price:" << std::setw(63) << "|$" << blank.getRetailCost();
	std::cout << "\n 9) Save Book to Database";
	std::cout << "\n 0) Return to Inventory Menu\n\n";

}
