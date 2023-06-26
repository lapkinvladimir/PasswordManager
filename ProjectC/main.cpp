#include "Encryption.h"
#include "Methods.h"

#include <iostream>
#include <string>
#include <filesystem>

bool start = true;





int main() {

    Methods::findCategoriesFilePath();

    std::string filePath = Encryption::getFilePath();

    std::string choice;

    while (start) {
        std::cout << "Select an action:" << std::endl;
        std::cout << "1. Add Password" << std::endl;
        std::cout << "2. Find Password" << std::endl;
        std::cout << "3. Delete Password" << std::endl;
        std::cout << "4. Decrypt all" << std::endl;
        std::cout << "5. Sort passwords" << std::endl;
        std::cout << "6. Delete category" << std::endl;
        std::cout << "7. Change Password" << std::endl;
        std::cout << "8. Add new category" << std::endl;
        std::cout << "9. Exit" << std::endl;
        std::cout << "Your choice: ";
        std::cin >> choice;


        if (choice == "1") {
            Methods::addPassword(filePath);
        } else if (choice == "2") {
            Methods::findPassword(filePath);
        } else if (choice == "3") {
            Methods::deletePassword(filePath);
        } else if (choice == "4") {
            Methods::decryptAll(filePath);
        } else if (choice == "5") {
            Methods::sortPasswords(filePath);
        } else if (choice == "6") {
            Methods::deleteCategory(filePath);
        } else if (choice == "7") {
            Methods::changePassword(filePath);
        } else if (choice == "8") {
            Methods::addCategory();
        } else if (choice == "9") {
            start = false;
        } else {
            std::cout << "Invalid input. Please try again." << std::endl;
            continue;
        }
    }


}
