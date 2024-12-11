#include "../include/Admin.h"
#include <iostream>
#include <ctime>
#include <limits>
#include <vector>
#include <fstream>

using namespace std;

// Helper function to clear the input buffer
void clearInputBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Constructor to initialize and load data
Admin::Admin() {
    loadData();
}

// Generate unique ID with a prefix
string Admin::generateId(const string& prefix) {
    static int counter = 0; // Tambahkan counter untuk menghindari ID duplikat
    time_t now = time(0);
    return prefix + to_string(now) + to_string(counter++);
}

// Load all data (books, members, rentals)
void Admin::loadData() {
    books = Book::loadFromFile();
    members = Member::loadFromFile();
    rentals = Rental::loadFromFile();
}

// Add a new book
void Admin::addBook() {
    string title, author;

    cout << "Masukkan judul buku: ";
    clearInputBuffer();
    getline(cin, title);

    cout << "Masukkan nama pengarang: ";
    getline(cin, author);

    string id = generateId("BK");
    Book book(id, title, author);
    book.saveToFile();
    books.push_back(book);

    cout << "Buku berhasil ditambahkan!" << endl;
}

// Display list of books
void Admin::displayBooks() {
    if (books.empty()) {
        cout << "Tidak ada buku dalam sistem." << endl;
        return;
    }

    cout << "\nDaftar Buku:" << endl;
    for (const Book& book : books) {
        book.display();
    }
}

// Register a new member
void Admin::registerMember() {
    string name, address, phone;

    cout << "Masukkan nama member: ";
    clearInputBuffer();
    getline(cin, name);

    cout << "Masukkan alamat: ";
    getline(cin, address);

    cout << "Masukkan nomor telepon: ";
    getline(cin, phone);

    string id = generateId("MB");
    Member member(id, name, address, phone);
    member.saveToFile();
    members.push_back(member);

    cout << "Member berhasil didaftarkan!" << endl;
}

// Display list of members
void Admin::displayMembers() {
    if (members.empty()) {
        cout << "Tidak ada member dalam sistem." << endl;
        return;
    }

    cout << "\nDaftar Member:" << endl;
    for (const Member& member : members) {
        member.display();
    }
}

// Create a new rental
void Admin::createRental() {
    string bookId, memberId;

    displayBooks();
    cout << "Masukkan ID buku: ";
    cin >> bookId;

    displayMembers();
    cout << "Masukkan ID member: ";
    cin >> memberId;

    Book* book = nullptr;
    Member* member = nullptr;

    // Validate book ID
    for (auto& b : books) {
        if (b.getId() == bookId && b.getAvailability()) {
            book = &b;
            break;
        }
    }

    // Validate member ID
    for (auto& m : members) {
        if (m.getId() == memberId) {
            member = &m;
            break;
        }
    }

    if (!book) {
        cout << "Buku tidak ditemukan atau sedang dipinjam." << endl;
        return;
    }

    if (!member) {
        cout << "Member tidak ditemukan." << endl;
        return;
    }

    string rentalId = generateId("RT");
    Rental rental(rentalId, bookId, memberId);
    rental.saveToFile();
    rentals.push_back(rental);

    book->setAvailability(false);
    Book::saveAllBooks(books);

    cout << "Peminjaman berhasil dibuat!" << endl;
}

// Return a book
void Admin::returnBook() {
    string bookId;
    cout << "Masukkan ID buku yang akan dikembalikan: ";
    cin >> bookId;

    for (auto& rental : rentals) {
        if (rental.getBookId() == bookId && !rental.isReturned()) {
            rental.returnBook();

            for (auto& book : books) {
                if (book.getId() == bookId) {
                    book.setAvailability(true);
                    break;
                }
            }

            Book::saveAllBooks(books);
            rental.saveToFile();

            cout << "Buku berhasil dikembalikan!" << endl;
            cout << "Denda: Rp" << rental.calculateFine() << endl;
            return;
        }
    }

    cout << "Peminjaman tidak ditemukan atau buku sudah dikembalikan." << endl;
}

// Display all rentals
void Admin::displayRentals() {
    if (rentals.empty()) {
        cout << "Tidak ada data peminjaman." << endl;
        return;
    }

    cout << "\nDaftar Peminjaman:" << endl;
    for (const Rental& rental : rentals) {
        rental.display();
    }
}