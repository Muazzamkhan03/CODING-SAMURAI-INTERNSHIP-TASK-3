#include "Book.h"

// Constructor to initialize book attributes
Book::Book(const std::string& title, const std::string& author, const std::string& ISBN)
    : title(title), author(author), ISBN(ISBN), available(true) {
}

// Getter functions for book attributes
std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthor() const {
    return author;
}

std::string Book::getISBN() const {
    return ISBN;
}

bool Book::isAvailable() const {
    return available;
}

// Setter function to update book availability
void Book::setAvailable(bool avail) {
    available = avail;
}
