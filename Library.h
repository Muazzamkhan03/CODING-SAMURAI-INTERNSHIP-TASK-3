#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "Book.h"

class Library {
public:
    // Function to add a book to the library catalog
    void addBook(const Book& book);

    // Function to remove a book from the library catalog
    void removeBook(const std::string& ISBN);

    // Function to check the availability of a book
    void checkAvailability(const std::string& ISBN);

    // Function to display the library catalog
    void displayCatalog() const;
    void saveCatalogToFile(const std::string& filename) const;
    void loadCatalogFromFile(const std::string& filename);

private:
    std::vector<Book> catalog;
};

#endif
