#include "Library.h"
#include <iostream>
#include <algorithm>
#include <fstream> 
#include <sstream>

void Library::addBook(const Book& book) {
    catalog.push_back(book);
}

void Library::removeBook(const std::string& ISBN) {
    auto it = std::remove_if(catalog.begin(), catalog.end(),
        [&ISBN](const Book& book) { return book.getISBN() == ISBN; });

    if (it != catalog.end()) {
        catalog.erase(it, catalog.end());
        std::cout << "Book removed from the catalog.\n";
    } else {
        std::cout << "Book not found in the catalog.\n";
    }
}

void Library::checkAvailability(const std::string& ISBN) {
    for (Book& book : catalog) {
        if (book.getISBN() == ISBN) {
            if (book.isAvailable()) {
                std::cout << "Book is available.\n";
            } else {
                std::cout << "Book is not available.\n";
            }
            return;
        }
    }
    std::cout << "Book not found in the catalog.\n";
}

void Library::displayCatalog() const {
    std::cout << "Library Catalog:\n";
    for (const Book& book : catalog) {
        std::cout << "Title: " << book.getTitle() << "\n";
        std::cout << "Author: " << book.getAuthor() << "\n";
        std::cout << "ISBN: " << book.getISBN() << "\n";
        std::cout << "Availability: " << (book.isAvailable() ? "Available" : "Not Available") << "\n";
        std::cout << "------------------------\n";
    }
}

void Library::saveCatalogToFile(const std::string& filename) const {
    std::ofstream outFile(filename);

    if (!outFile) {
        std::cerr << "Error opening the file for writing.\n";
        return;
    }

    for (const Book& book : catalog) {
        outFile << book.getTitle() << ","
                << book.getAuthor() << ","
                << book.getISBN() << ","
                << (book.isAvailable() ? "1" : "0") << "\n";
    }

    outFile.close();
    std::cout << "Catalog saved to file.\n";
}

void Library::loadCatalogFromFile(const std::string& filename) {
    std::ifstream inFile(filename);

    if (!inFile) {
        std::cerr << "Error opening the file for reading.\n";
        return;
    }

    catalog.clear(); // Clear the existing catalog

    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        std::string title, author, ISBN, availableStr;

        if (std::getline(iss, title, ',') &&
            std::getline(iss, author, ',') &&
            std::getline(iss, ISBN, ',') &&
            std::getline(iss, availableStr, ',')) {

            bool available = (availableStr == "1");
            Book book(title, author, ISBN);
            book.setAvailable(available);
            catalog.push_back(book);
        }
    }

    inFile.close();
    std::cout << "Catalog loaded from file.\n";
}
