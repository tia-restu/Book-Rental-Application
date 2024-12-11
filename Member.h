#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <vector>

/**
 * @brief Class untuk mengelola data Member.
 */
class Member {
private:
    std::string id;       // ID member
    std::string name;     // Nama member
    std::string address;  // Alamat member
    std::string phone;    // Nomor telepon member

public:
    // Konstruktor
    Member(const std::string& id, const std::string& name, const std::string& address, const std::string& phone);
    
    /**
     * @brief Constructor untuk inisialisasi Member.
     * @param id ID Member.
     * @param name Nama Member.
     * @param address Alamat Member.
     * @param phone Nomor Telepon Member.
     */

    // Getter methods
    /**
     * @brief Mendapatkan ID Member.
     * @return ID Member.
     */
    std::string getId() const;

    /**
     * @brief Mendapatkan Nama Member.
     * @return Nama Member.
     */
    std::string getName() const;

    // File operations
    /**
     * @brief Menyimpan data Member ke file.
     */
    void saveToFile() const;

    /**
     * @brief Memuat semua data Member dari file.
     * @return Vector dari objek Member yang dimuat dari file.
     */
    static std::vector<Member> loadFromFile();

    // Display
    /**
     * @brief Menampilkan informasi Member.
     */
    void display() const;
};

#endif // MEMBER_H