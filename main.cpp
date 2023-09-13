#include <iostream>
#include "Library.h"

int main() {
    Library library;
    std::string catalogFilename = "library_catalog.txt"; // Define the filename

    // Load the catalog from the file (if it exists)
    library.loadCatalogFromFile(catalogFilename);

    while (true) {
        std::cout << "Library Management System\n";
        std::cout << "1. Add Book\n";
        std::cout << "2. Remove Book\n";
        std::cout << "3. Check Availability\n";
        std::cout << "4. Display Catalog\n";
        std::cout << "5. Save Catalog to File\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string title, author, ISBN;
                std::cin.ignore();
                std::cout << "Enter book title: ";
                std::getline(std::cin, title);
                std::cout << "Enter author: ";
                std::getline(std::cin, author);
                std::cout << "Enter ISBN: ";
                std::getline(std::cin, ISBN);
                Book newBook(title, author, ISBN);
                library.addBook(newBook);
                std::cout << "Book added to the catalog.\n";
                break;
            }
            case 2: {
                std::string ISBN;
                std::cout << "Enter ISBN of the book to remove: ";
                std::cin.ignore();
                std::getline(std::cin, ISBN);
                library.removeBook(ISBN);
                break;
            }
            case 3: {
                std::string ISBN;
                std::cout << "Enter ISBN of the book to check availability: ";
                std::cin.ignore();
                std::getline(std::cin, ISBN);
                library.checkAvailability(ISBN);
                break;
            }
            case 4:
                library.displayCatalog();
                break;
            case 5:
                library.saveCatalogToFile(catalogFilename);
                break;
            case 6:
                std::cout << "Exiting the program.\n";
                return 0;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
