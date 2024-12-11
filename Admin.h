#ifndef ADMIN_H
#define ADMIN_H

#include "Book.h"
#include "Member.h"
#include "Rental.h"
#include <vector>

class Admin {
private:
    // Data members
    std::vector<Book> books;
    std::vector<Member> members;
    std::vector<Rental> rentals;

protected:
    // Helper method to generate unique IDs
    std::string generateId(const std::string& prefix);

public:
    // Constructor and destructor
    Admin();
    ~Admin();

    // Data loading
    void loadData();

    // Book management
    void addBook();          // Add a new book
    void displayBooks();     // Display all books

    // Member management
    void registerMember();   // Register a new member
    void displayMembers();   // Display all members

    // Rental management
    void createRental();     // Create a new rental
    void returnBook();       // Return a rented book
    void displayRentals();   // Display all rentals
};

#endif