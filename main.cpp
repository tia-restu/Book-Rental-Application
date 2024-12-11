#include "../include/Admin.h"
#include <iostream>
#include <limits>

using namespace std;

int main() {
    Admin admin;
    int choice;

    while (true) {
        cout << "\nSistem Rental Buku\n"
             << "1. Tambah Buku\n"
             << "2. Tampilkan Daftar Buku\n"
             << "3. Registrasi Member\n"
             << "4. Tampilkan Daftar Member\n"
             << "5. Peminjaman Buku\n"
             << "6. Pengembalian Buku\n"
             << "7. Tampilkan Daftar Peminjaman\n"
             << "8. Keluar\n"
             << "Pilihan Anda: ";
        
        while (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid! Masukkan angka: ";
        }

        switch (choice) {
            case 1:
                admin.addBook();
                break;
            case 2:
                admin.displayBooks();
                break;
            case 3:
                admin.registerMember();
                break;
            case 4:
                admin.displayMembers();
                break;
            case 5:
                admin.createRental();
                break;
            case 6:
                admin.returnBook();
                break;
            case 7:
                admin.displayRentals();
                break;
            case 8:
                cout << "Terima kasih telah menggunakan sistem ini!" << endl;
                return 0;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    }
}