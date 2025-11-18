#ifndef BOOKINFO_H
#define BOOKINFO_H
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

class bookInfo {

	private:

		std::string title; //book's title
		std::string isbn; //book's ISBN
		std::string author; //book's author
		std::string publisher; // book's publisher
		std::string date; //date book was added
		int qty; //quantity of book on hand
		float whole_cost; //book's wholesale cost
		float retail_cost; // book's retail cost

	public:

		/*********** CONSTRUCTORS & DESTRUCTORS ***********/

		bookInfo();

		 
		/*********** SETTERS ***********/


		void setTitle(std::string t);

		void setISBN(std::string i);

		void setAuthor(std::string a);

		void setPublisher(std::string p);

		void setDate(std::string d);

		void setQty(int q);

		void setWholeCost(float w);

		void setRetailCost(float r);

		/*********** GETTERS ***********/

		std::string getTitle() const;

		std::string getISBN() const;

		std::string getAuthor() const;

		std::string getPublisher() const;

		std::string getDate() const;

		int getQty() const;

		float getWholeCost() const;

		float getRetailCost() const;

};

#endif
