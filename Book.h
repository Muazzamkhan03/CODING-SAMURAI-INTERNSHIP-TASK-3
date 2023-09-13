#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
public:
    // Constructor to initialize book attributes
    Book(const std::string& title, const std::string& author, const std::string& ISBN);

    // Getter functions for book attributes
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getISBN() const;
    bool isAvailable() const;
    
    // Setter function to update book availability
    void setAvailable(bool available);

private:
    std::string title;
    std::string author;
    std::string ISBN;
    bool available;
};

#endif
