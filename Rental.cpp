#include "../include/Rental.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>

using namespace std;

Rental::Rental(const std::string& rentalId, const std::string& bookId, const std::string& memberId)
    : rentalId(rentalId), bookId(bookId), memberId(memberId), borrowDate(time(0)), returnDate(0) {}

string Rental::getRentalId() const { return rentalId; }
string Rental::getBookId() const { return bookId; }
string Rental::getMemberId() const { return memberId; }
time_t Rental::getBorrowDate() const { return borrowDate; }
time_t Rental::getReturnDate() const { return returnDate; }
bool Rental::isReturned() const { return returnDate != 0; }

void Rental::returnBook() { returnDate = time(0); }

double Rental::calculateFine() const {
    if (returnDate == 0) return 0;
    double days = difftime(returnDate, borrowDate) / (60 * 60 * 24);
    return days > 7 ? (days - 7) * 1000 : 0;
}

void Rental::saveToFile() const {
    ofstream file("rentals.txt", ios::app);
    if (!file.is_open()) {
        cerr << "Error: Tidak dapat membuka file untuk menyimpan data rental." << endl;
        return;
    }
    file << rentalId << "," << bookId << "," << memberId << "," << borrowDate << "," << returnDate << endl;
    file.close();
}

vector<Rental> Rental::loadFromFile() {
    vector<Rental> rentals;
    ifstream file("rentals.txt");
    if (!file.is_open()) {
        cerr << "Error: Tidak dapat membuka file untuk membaca data rental." << endl;
        return rentals;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string rentalId, bookId, memberId, borrowDateStr, returnDateStr;
        getline(ss, rentalId, ',');
        getline(ss, bookId, ',');
        getline(ss, memberId, ',');
        getline(ss, borrowDateStr, ',');
        getline(ss, returnDateStr, ',');

        Rental rental(rentalId, bookId, memberId);
        rental.borrowDate = stol(borrowDateStr);
        rental.returnDate = !returnDateStr.empty() && returnDateStr != "0" ? stol(returnDateStr) : 0;
        rentals.push_back(rental);
    }
    file.close();
    return rentals;
}

void Rental::display() const {
    cout << "ID Peminjaman: " << rentalId << "\nID Buku: " << bookId << "\nID Member: " << memberId << "\n";
    char borrowStr[20], returnStr[20];
    strftime(borrowStr, sizeof(borrowStr), "%Y-%m-%d", localtime(&borrowDate));
    cout << "Tanggal Pinjam: " << borrowStr << "\n";
    if (returnDate != 0) {
        strftime(returnStr, sizeof(returnStr), "%Y-%m-%d", localtime(&returnDate));
        cout << "Tanggal Kembali: " << returnStr << "\nDenda: Rp" << fixed << setprecision(2) << calculateFine() << "\n";
    } else {
        cout << "Status: Masih dipinjam\n";
    }
    cout << "------------------------\n";
}