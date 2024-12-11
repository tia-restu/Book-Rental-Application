#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <vector>

class Book {
private:
    std::string id;
    std::string title;
    std::string author;
    bool isAvailable;

public:
    // Constructor
    Book(std::string id, std::string title, std::string author);

    // Getters
    std::string getId() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    bool getAvailability() const;

    // Setters
    void setAvailability(bool status);

    // File operations
    void saveToFile() const;
    static void saveAllBooks(const std::vector<Book>& books);
    static std::vector<Book> loadFromFile();

    // Display information
    void display() const;
};

#endif