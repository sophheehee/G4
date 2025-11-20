void editBook(std::vector<bookInfo>& inventory)
{
    // 1. If no books, bail immediately
    if (inventory.empty())
    {
        std::cout << "\nNo books in inventory.\n";
        // optional: pauseEnter();
        return;
    }

    bool edit = true;

    while (edit)
    {
        // 2. Get index from lookup
        int idx = lookUpBook(inventory);   // -1 if user cancels / not found
        int idx = lookUpBook(inventory);
			if (idx <0 || idx >=inventory.size()){
				return; 
			}	// sophie's slight change to fix return screen crash
			
		  bookInfo original = inventory[idx];
    	  bookInfo temp = original;

		  if (inventory.empty()) {

        	std::cout << "\nNo books in inventory.";
        //	invMenu(inventory);

			return;

			}

        // 3. Handle not-found / cancel case according to the spec
        if (idx == -1)
        {
            std::cout << "\nBook not found.\n";

            char again;
            while (true)
            {
                std::cout << "Edit another? (y/n): ";
                if (std::cin >> again)
                {
                    std::cin.ignore(1000, '\n');
                    again = static_cast<char>(
                        std::tolower(static_cast<unsigned char>(again)));
                    if (again == 'y' || again == 'n')
                        break;
                }
                std::cout << "  !! Please enter y or n.\n";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }

            if (again == 'n')
            {

                // return to inventory menu caller

                //invMenu(inventory);  // go back to inventory menu

                return;
            }
            else
            {
                // go back to lookup another book
                continue;
            }
        }

        // 4. At this point, idx must be valid
        //    (lookUpBook should never return any other bad value)
        bookInfo original = inventory[idx];
        bookInfo temp = original;

        bool done = false; // to exit editing this book

        while (!done)
        {
            showRecord(temp);
            showEditMenu();

            char choice;
            if (!(std::cin >> choice))
            {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Invalid input.\n";
                continue;
            }
            std::cin.ignore(1000, '\n');      // eat newline

            switch (choice)
            {
            case '1': // title
            {
                std::string s;
                std::cout << "Current Title: " << temp.getTitle() << '\n';
                std::cout << "New Title: ";
                std::getline(std::cin, s);
                temp.setTitle(s);
                break;
            }

            case '2': // ISBN (string, handle duplicates)
            {
                std::string s;
                std::cout << "Current ISBN: " << temp.getISBN() << '\n';
                std::cout << "New ISBN: ";
                std::getline(std::cin, s);

                if (s == temp.getISBN())
                    break; // nothing changed

                bool dup = false;
                for (std::size_t i = 0; i < inventory.size(); ++i)
                {
                    if (static_cast<int>(i) == idx)
                        continue;

                    if (inventory[i].getISBN() == s)
                    {
                        dup = true;
                        break;
                    }
                }

                if (dup)
                {
                    std::cout << "WARNING: Another record already uses this ISBN.\n";
                    char ok;
                    while (true)
                    {
                        std::cout << "Keep this duplicate ISBN anyway? (y/n): ";
                        if (std::cin >> ok)
                        {
                            std::cin.ignore(1000, '\n');
                            ok = static_cast<char>(
                                std::tolower(static_cast<unsigned char>(ok)));
                            if (ok == 'y' || ok == 'n')
                                break;
                        }
                        std::cout << "  !! Please enter y or n.\n";
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                    }
                    if (ok == 'n')
                    {
                        std::cout << "ISBN change cancelled.\n";
                        break;
                    }
                }

                temp.setISBN(s);
                break;
            }

            case '3': // Author
            {
                std::string s;
                std::cout << "Current Author: " << temp.getAuthor() << '\n';
                std::cout << "New Author: ";
                std::getline(std::cin, s);
                temp.setAuthor(s);
                break;
            }

            case '4': // Publisher
            {
                std::string s;
                std::cout << "Current Publisher: " << temp.getPublisher() << '\n';
                std::cout << "New Publisher: ";
                std::getline(std::cin, s);
                temp.setPublisher(s);
                break;
            }

            case '5': // Date Added (string)
            {
                std::string s;
                std::cout << "Current Date Added: " << temp.getDate() << '\n';
                std::cout << "New Date Added: ";
                std::getline(std::cin, s);
                temp.setDate(s);
                break;
            }

            case '6': // Quantity on hand: int >= 0
            {
                std::cout << "Current Quantity: " << temp.getQty() << '\n';

                int q;
                while (true)
                {
                    std::cout << "New Quantity (>= 0): ";
                    if (std::cin >> q && q >= 0)
                    {
                        std::cin.ignore(1000, '\n');
                        break;
                    }
                    std::cout << "  !! Please enter an integer >= 0.\n";
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                }

                temp.setQty(q);
                break;
            }

            case '7': // Wholesale: float >= 0.0
            {
                std::cout << "Current Wholesale: " << temp.getWholeCost() << '\n';

                float w;
                while (true)
                {
                    std::cout << "New Wholesale (>= 0.0): ";
                    if (std::cin >> w && w >= 0.0f)
                    {
                        std::cin.ignore(1000, '\n');
                        break;
                    }
                    std::cout << "  !! Please enter a number >= 0.0.\n";
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                }

                temp.setWholeCost(w);
                break;
            }

            case '8': // Retail: float >= 0.0
            {
                std::cout << "Current Retail: " << temp.getRetailCost() << '\n';

                float r;
                while (true)
                {
                    std::cout << "New Retail (>= 0.0): ";
                    if (std::cin >> r && r >= 0.0f)
                    {
                        std::cin.ignore(1000, '\n');
                        break;
                    }
                    std::cout << "  !! Please enter a number >= 0.0.\n";
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                }

                temp.setRetailCost(r);
                break;
            }

            case '9': // Save changes
            {
                inventory[idx] = temp;   // apply staged changes
                std::cout << "\nChanges saved.\n";
                done = true;
                break;
            }

            case '0': // Cancel changes
            {
                std::cout << "\nEdit cancelled. Original record kept.\n";
                done = true;
                break;
            }

            default:
                std::cout << "Please choose 0-9.\n";
                break;
            }
        }

        // After save/cancel, ask to edit another
        char again;
        while (true)
        {
            std::cout << "\nEdit another book? (y/n): ";
            if (std::cin >> again)
            {
                std::cin.ignore(1000, '\n');
                again = static_cast<char>(
                    std::tolower(static_cast<unsigned char>(again)));
                if (again == 'y' || again == 'n')
                    break;
            }
            std::cout << "  !! Please enter y or n.\n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }

        edit = (again == 'y');
    }
}
