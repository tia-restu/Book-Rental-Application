#include "../include/Member.h"
#include <iostream>
#include <fstream>

// Implementasi konstruktor
Member::Member(const std::string& id, const std::string& name, const std::string& address, const std::string& phone)
    : id(id), name(name), address(address), phone(phone) {}

// Implementasi getter
std::string Member::getId() const {
    return id;
}

std::string Member::getName() const {
    return name;
}

// Implementasi metode saveToFile
void Member::saveToFile() const {
    // Contoh implementasi untuk menyimpan data member ke file
    std::ofstream file("members.txt", std::ios::app);
    file << id << "," << name << "," << address << "," << phone << "\n";
    file.close();
}

// Implementasi metode loadFromFile
std::vector<Member> Member::loadFromFile() {
    std::vector<Member> members;
    std::ifstream file("members.txt");

    std::string id, name, address, phone;
    while (std::getline(file, id, ',') && std::getline(file, name, ',') &&
           std::getline(file, address, ',') && std::getline(file, phone)) {
        members.push_back(Member(id, name, address, phone));
    }

    file.close();
    return members;
}

// Implementasi display
void Member::display() const {
    std::cout << "ID: " << id << "\nName: " << name << "\nAddress: " << address << "\nPhone: " << phone << std::endl;
}