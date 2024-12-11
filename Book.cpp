#include "../include/Book.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// Constructor
Book::Book(string id, string title, string author) {
    this->id = id;
    this->title = title;
    this->author = author;
    this->isAvailable = true; // Default: buku tersedia
}

// Getters
string Book::getId() const { return id; }
string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
bool Book::getAvailability() const { return isAvailable; }

// Setters
void Book::setAvailability(bool status) { isAvailable = status; }

// Simpan buku ke file (append)
void Book::saveToFile() const {
    ofstream file("books.txt", ios::app);
    if (!file.is_open()) {
        cerr << "Error: Tidak dapat membuka file untuk menyimpan buku." << endl;
        return;
    }
    file << id << "," << title << "," << author << "," << (isAvailable ? "1" : "0") << endl;
    file.close();
}

// Simpan semua buku ke file (overwrite)
void Book::saveAllBooks(const vector<Book>& books) {
    ofstream file("books.txt");
    if (!file.is_open()) {
        cerr << "Error: Tidak dapat membuka file untuk menyimpan semua buku." << endl;
        return;
    }
    for (const Book& book : books) {
        file << book.id << "," << book.title << "," << book.author << "," 
             << (book.isAvailable ? "1" : "0") << endl;
    }
    file.close();
}

// Muat buku dari file
vector<Book> Book::loadFromFile() {
    vector<Book> books;
    ifstream file("books.txt");
    if (!file.is_open()) {
        cerr << "Error: File tidak ditemukan atau tidak dapat dibuka." << endl;
        return books;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string id, title, author, availableStr;

        getline(ss, id, ',');
        getline(ss, title, ',');
        getline(ss, author, ',');
        getline(ss, availableStr, ',');

        Book book(id, title, author);
        book.setAvailability(availableStr == "1");
        books.push_back(book);
    }

    file.close();
    return books;
}

// Tampilkan informasi buku
void Book::display() const {
    cout << "ID: " << id << endl
         << "Judul: " << title << endl
         << "Pengarang: " << author << endl
         << "Status: " << (isAvailable ? "Tersedia" : "Dipinjam") << endl
         << "------------------------" << endl;
}