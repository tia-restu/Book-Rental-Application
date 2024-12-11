#ifndef RENTAL_H
#define RENTAL_H

#include <string>
#include <vector>
#include <ctime>

/**
 * @brief Class untuk mengelola data peminjaman buku (rental).
 */
class Rental {
private:
    std::string rentalId;  ///< ID peminjaman
    std::string bookId;    ///< ID buku yang dipinjam
    std::string memberId;  ///< ID member yang meminjam
    time_t borrowDate;     ///< Tanggal peminjaman (timestamp)
    time_t returnDate;     ///< Tanggal pengembalian (timestamp), 0 jika belum dikembalikan

public:
    /**
     * @brief Konstruktor untuk membuat objek Rental.
     * @param rentalId ID peminjaman.
     * @param bookId ID buku.
     * @param memberId ID member.
     */
    Rental(const std::string& rentalId, const std::string& bookId, const std::string& memberId);
    
    // Getter methods
    /**
     * @brief Mendapatkan ID peminjaman.
     * @return ID peminjaman.
     */
    std::string getRentalId() const;

    /**
     * @brief Mendapatkan ID buku yang dipinjam.
     * @return ID buku.
     */
    std::string getBookId() const;

    /**
     * @brief Mendapatkan ID member yang meminjam.
     * @return ID member.
     */
    std::string getMemberId() const;

    /**
     * @brief Mendapatkan tanggal peminjaman.
     * @return Tanggal peminjaman dalam format timestamp.
     */
    time_t getBorrowDate() const;

    /**
     * @brief Mendapatkan tanggal pengembalian.
     * @return Tanggal pengembalian dalam format timestamp (0 jika belum dikembalikan).
     */
    time_t getReturnDate() const;

    /**
     * @brief Mengecek apakah buku sudah dikembalikan.
     * @return True jika sudah dikembalikan, false jika belum.
     */
    bool isReturned() const;

    // Operations
    /**
     * @brief Menandai buku sebagai dikembalikan.
     */
    void returnBook();

    /**
     * @brief Menghitung denda berdasarkan lama waktu peminjaman.
     * @return Denda dalam satuan mata uang.
     */
    double calculateFine() const;

    // File operations
    /**
     * @brief Menyimpan data peminjaman ke file.
     */
    void saveToFile() const;

    /**
     * @brief Memuat semua data peminjaman dari file.
     * @return Vector berisi objek Rental yang dimuat dari file.
     */
    static std::vector<Rental> loadFromFile();

    // Display
    /**
     * @brief Menampilkan informasi peminjaman.
     */
    void display() const;
};

#endif // RENTAL_H