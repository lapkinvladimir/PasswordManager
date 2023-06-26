//
// Created by User on 27.05.2023.
//

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <filesystem>
#include <random>
#include "Encryption.h"
#include "Methods.h"

struct PasswordEntry {
    std::string website;
    std::string category;
    std::string login;
    std::string password;
};

std::string Methods::filePathCat;
bool run = true;
int a = 0;
std::string newPassword;


std::string Methods::generatePassword() {
    std::string password;

    bool validInput = false;

    int length;

    bool includeSpecialChars;

    bool includeUppercase;

    while (!validInput) {
        int length1;
        std::cout << "Enter the length of the password: ";
        std::cin >> length1;

        if (std::cin.fail() || length1 <= 4 || length1 > 20) {
            std::cin.clear(); //сброс флагов ошибок что бы еще раз считать
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid password length (5-20)." << std::endl;
        } else {
            validInput = true;
            length = length1;
            // Продолжение кода
        }
    }

    validInput = false;

    while (!validInput) {
        bool includeSpecialChars1;
        std::cout << "Include special characters? (1 for Yes, 0 for No): ";
        std::cin >> includeSpecialChars1;

        if (std::cin.fail() || (includeSpecialChars1 != 0 && includeSpecialChars1 != 1)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter either 1 or 0." << std::endl;
        } else {
            validInput = true;
            includeSpecialChars = includeSpecialChars1;
            // Продолжение кода
        }
    }

    validInput = false;

    while (!validInput) {
        bool includeUppercase1;
        std::cout << "Include uppercase letters? (1 for Yes, 0 for No): ";
        std::cin >> includeUppercase1;

        if (std::cin.fail() || (includeUppercase1 != 0 && includeUppercase1 != 1)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter either 1 or 0." << std::endl;
        } else {
            validInput = true;
            includeUppercase = includeUppercase1;
            // Продолжение кода
        }
    }




    // Символы для генерации пароля
    std::string lowercaseChars = "abcdefghijklmnopqrstuvwxyz";
    std::string specialChars = "!@#$%^&*()";
    std::string uppercaseChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string allChars = lowercaseChars;

    if (includeSpecialChars) {
        allChars += specialChars;
    }

    if (includeUppercase) {
        allChars += uppercaseChars;
    }

    // Генерация пароля
    std::random_device rd;
    std::mt19937 generator(rd()); // генератор алгоритм
    std::uniform_int_distribution<int> distribution(0, allChars.length() - 1); //распределение

    for (int i = 0; i < length; i++) {
        int randomIndex = distribution(generator);
        password += allChars[randomIndex];
    }


    if (length >= 8 && includeSpecialChars && includeUppercase) {
        a = 1;
        std::cout << "Generated password: " << password << std::endl;
        newPassword = password;
        return newPassword;
    }


    if (length < 8 && includeSpecialChars && includeUppercase) {
        std::cout << "Generated password: " << password << std::endl;
        newPassword = password;
        std::cout << "Your password is less than 8 characters." << std::endl;

        std::cout << "Do you want to keep it as is (1) or generate a new password (2)? Enter your choice: ";
        std::string choice;
        std::cin >> choice;

        while (choice != "1" && choice != "2") {
            std::cout << "Invalid choice. Please enter 1 or 2: ";
            std::cin >> choice;
        }

        if (choice == "1") {
            a = 1;
            std::cout << "Your password: " << newPassword << std::endl;
            return newPassword;
        } else if (choice == "2") {
            generatePassword();
        }
    }


    if (!includeUppercase && length >= 8 && includeSpecialChars) {
        std::cout << "Generated password: " << password << std::endl;
        newPassword = password;
        std::cout << "Your password does not contain uppercase letters." << std::endl;
        std::cout << "Do you want to keep it as is (1) or generate a new password (2)? Enter your choice: ";
        std::string choice;
        std::cin >> choice;

        while (choice != "1" && choice != "2") {
            std::cout << "Invalid choice. Please enter 1 or 2: ";
            std::cin >> choice;
        }

        if (choice == "1") {
            a = 1;
            std::cout << "Your password: " << newPassword << std::endl;
            return newPassword;
        } else if (choice == "2") {
            generatePassword();
        }
    }


    if (!includeSpecialChars && length >= 8 && includeUppercase) {
        std::cout << "Generated password: " << password << std::endl;
        newPassword = password;
        std::cout << "Your password does not contain special characters." << std::endl;
        std::cout << "Do you want to keep it as is (1) or generate a new password (2)? Enter your choice: ";
        std::string choice;
        std::cin >> choice;

        while (choice != "1" && choice != "2") {
            std::cout << "Invalid choice. Please enter 1 or 2: ";
            std::cin >> choice;
        }

        if (choice == "1") {
            a = 1;
            std::cout << "Your password: " << newPassword << std::endl;
            return newPassword;
        } else if (choice == "2") {
            generatePassword();
        }
    }

    if (!includeUppercase && !includeSpecialChars && length >= 8) {
        std::cout << "Generated password: " << password << std::endl;
        newPassword = password;
        std::cout << "Your password does not contain uppercase letters and special characters." << std::endl;
        std::cout << "Do you want to keep it as is (1) or generate a new password (2)? Enter your choice: ";
        std::string choice;
        std::cin >> choice;

        while (choice != "1" && choice != "2") {
            std::cout << "Invalid choice. Please enter 1 or 2: ";
            std::cin >> choice;
        }

        if (choice == "1") {
            a = 1;
            std::cout << "Your password: " << newPassword << std::endl;
            return newPassword;
        } else if (choice == "2") {
            generatePassword();
        }
    }

    if (length < 8 && !includeSpecialChars && includeUppercase) {
        std::cout << "Generated password: " << password << std::endl;
        newPassword = password;
        std::cout << "Your password does not contain special characters and is less than 8 characters" << std::endl;
        std::cout << "Do you want to keep it as is (1) or generate a new password (2)? Enter your choice: ";
        std::string choice;
        std::cin >> choice;

        while (choice != "1" && choice != "2") {
            std::cout << "Invalid choice. Please enter 1 or 2: ";
            std::cin >> choice;
        }

        if (choice == "1") {
            a = 1;
            std::cout << "Your password: " << newPassword << std::endl;
            return newPassword;
        } else if (choice == "2") {
            generatePassword();
        }
    }

    if (length < 8 && !includeUppercase && includeSpecialChars) {
        std::cout << "Generated password: " << password << std::endl;
        newPassword = password;
        std::cout << "Your password does not contain uppercase letters and is less than 8 characters" << std::endl;
        std::cout << "Do you want to keep it as is (1) or generate a new password (2)? Enter your choice: ";
        std::string choice;
        std::cin >> choice;

        while (choice != "1" && choice != "2") {
            std::cout << "Invalid choice. Please enter 1 or 2: ";
            std::cin >> choice;
        }


        if (choice == "1") {
            a = 1;
            std::cout << "Your password: " << newPassword << std::endl;
            return newPassword;
        } else if (choice == "2") {
            generatePassword();
        }
    }


}

std::string Methods::validatePassword() {
    std::string password;
    std::cout << "Enter your password: ";
    std::cin >> password;

    bool hasUppercase = false;
    bool hasSpecialChar = false;

    if (password.length() < 8) {
        std::cout << "Your password is less than 8 characters." << std::endl;
    }

    for (char c: password) {
        if (std::isupper(c)) {
            hasUppercase = true;
        }
        if (!std::isalnum(c)) {
            hasSpecialChar = true;
        }
    }

    if (!hasUppercase) {
        std::cout << "Your password does not contain uppercase letters." << std::endl;
    }

    if (!hasSpecialChar) {
        std::cout << "Your password does not contain special characters." << std::endl;
    }

    if (password.length() >= 8 && hasUppercase && hasSpecialChar) {
        std::cout << "Your password is strong!" << std::endl;
        std::cout << "Your password is: " << password << std::endl;
        return password;
    }

    while (run) {

        if (a == 1) {
            return newPassword;
        }

        std::cout
                << "Do you want to keep it as is (1), enter a new password manually (2), or generate a new password (3)? Enter your choice: ";
        std::string choice;
        std::cin >> choice;


        while (choice != "1" && choice != "2" && choice != "3") {
            std::cout << "Invalid choice. Please enter 1, 2, or 3: ";
            std::cin >> choice;
        }

        if (choice == "1") {
            std::cout << "Your password remains unchanged: " << password << std::endl;
            return password;
        } else if (choice == "2") {
            std::cout << "Enter a new password: ";
            std::cin >> password;
            hasUppercase = false;
            hasSpecialChar = false;

            if (password.length() < 8) {
                std::cout << "Your password is less than 8 characters." << std::endl;
            }

            for (char c: password) {
                if (std::isupper(c)) {
                    hasUppercase = true;
                }
                if (!std::isalnum(c)) {
                    hasSpecialChar = true;
                }
            }

            if (!hasUppercase) {
                std::cout << "Your password does not contain uppercase letters." << std::endl;
            }

            if (!hasSpecialChar) {
                std::cout << "Your password does not contain special characters." << std::endl;
            }

            if (password.length() >= 8 && hasUppercase && hasSpecialChar) {
                std::cout << "Your password is strong!" << std::endl;
                std::cout << "Your password is: " << password << std::endl;
                return password;
            }
        } else if (choice == "3") {
            password = generatePassword();
        }
    }
    return {};
}


void Methods::appendCurrentTimeToFile(const std::string &filePath) {
    std::ofstream file(filePath, std::ios::app); //запись хпахапхаапхапахпахпапхапхахп

    if (!file) { //все ли удачно нахуй хапхпхапхапхапхапахп
        std::cout << "Failed to open file." << std::endl;
        return;
    }

    // Получаем текущее время
    std::time_t currentTime = std::time(nullptr);
    std::tm *localTime = std::localtime(&currentTime);

    // Форматируем время в виде строки
    std::ostringstream oss;
    oss << std::put_time(localTime, "%Y-%m-%d %H:%M:%S");
    std::string formattedTime = oss.str(); //получить отфарм стркоу

    // Применяем шифрование к строке с текущим временем
    std::string encryptedTime = Encryption::encrypt(formattedTime);

    // Записываем зашифрованное время в файл
    file << encryptedTime << std::endl;
    file.close();

}


void Methods::deleteLastLineFromFile(const std::string &filePath) {
    std::ifstream inFile(filePath); //чтение
    if (!inFile) {
        std::cout << "Failed to open file." << std::endl;
        return;
    }

    std::vector<std::string> fileLines;
    std::string line;

    while (std::getline(inFile, line)) {
        fileLines.push_back(line);
    }

    inFile.close();

    if (fileLines.empty()) {
        return;
    }

    fileLines.pop_back();

    std::ofstream outFile(filePath);
    if (!outFile) {
        std::cout << "Failed to open file." << std::endl;
        return;
    }

    for (const auto &fileLine: fileLines) { //ссылка
        outFile << fileLine << std::endl; // Записываем оставшиеся строки обратно в файл
    }

    outFile.close();

}


std::string Methods::findCategoriesFilePath() {
    std::filesystem::path currentPath = std::filesystem::current_path();
    std::filesystem::path parentPath = currentPath.parent_path();

    std::filesystem::path directoryPath = parentPath / "categories";

    for (const auto &entry: std::filesystem::directory_iterator(directoryPath)) {
        if (entry.path().filename() == "categories.txt") {
            filePathCat = entry.path().string();
        }
    }
    return filePathCat;
}


void Methods::decryptAll(const std::string &filePath) {
    std::cout << "Enter the decryption key: ";
    std::string decryptionKey;
    std::cin >> decryptionKey;

    std::ifstream inFile(filePath);
    if (!inFile) {
        std::cout << "Failed to open file." << std::endl;
        return;
    }

    std::string line;
    std::vector<std::string> passwordData(4);

    std::vector<std::string> fileLines;
    while (std::getline(inFile, line)) {
        fileLines.push_back(line);
    }

    int numLines = fileLines.size();
    int counter = 1;

    inFile.close();

    std::cout << "Decrypted passwords:" << std::endl;
    std::cout << std::left << std::setw(30) << "Website"
              << std::left << std::setw(30) << "Login"
              << std::left << std::setw(30) << "Category"
              << std::left << std::setw(30) << "Password" << std::endl;

    for (const std::string &fileLine: fileLines) {
        std::istringstream iss(fileLine); //читать из строк, типо сина
        std::string token;
        int i = 0;

        while (std::getline(iss, token, ',')) {
            passwordData[i] = token;
            i++;
        }

        std::string decryptedWebsite = Encryption::decrypt(passwordData[0], decryptionKey);

        if (counter != numLines) {
            std::string decryptedLogin = Encryption::decrypt(passwordData[1], decryptionKey);
            std::string decryptedCategory = Encryption::decrypt(passwordData[2], decryptionKey);
            std::string decryptedPassword = Encryption::decrypt(passwordData[3], decryptionKey);

            std::cout << std::left << std::setw(30) << decryptedWebsite
                      << std::left << std::setw(30) << decryptedLogin
                      << std::left << std::setw(30) << decryptedCategory
                      << std::left << std::setw(30) << decryptedPassword << std::endl;
        }

        if (counter == numLines) {
            std::string decryptedTime = Encryption::decryptLastLineFromFile(filePath);
            std::cout << decryptedTime << std::endl;
        }

        counter++;
    }

    deleteLastLineFromFile(filePath);
    appendCurrentTimeToFile(filePath);
}


std::vector<std::string> splitLine(const std::string &line, char delimiter) {
    std::vector<std::string> tokens;
    std::istringstream stream(line);
    std::string token;

    while (std::getline(stream, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}


void Methods::addPassword(const std::string &filePath) {  //? 691 строка нахуй ?
    PasswordEntry entry;

    std::vector<std::string> popularDomainExtensions = {
            ".com",
            ".net",
            ".org",
            ".edu",
            ".gov",
            ".io",
            ".co",
            ".info",
            ".me",
            ".tv"
    };

    bool site = true;

    while (site) {

        std::cout << "Enter website: ";
        std::getline(std::cin >> std::ws, entry.website);


        if (entry.website.length() > 20) {
            std::cout << "Length of the login must be less then 20 characters" << std::endl;
            continue;
        } else {
            site = false;
            break;
        }
    }


    bool hasDot = (entry.website.find('.') != std::string::npos);

    if (hasDot) {
        std::cout << "It appears that you have used your own domain extension." << std::endl;
        std::cout << "Do you want to keep it as is (1) or choose a different domain extension (2)? Enter your choice: ";
        std::string choice;
        std::cin >> choice;

        while (choice != "1" && choice != "2") {
            std::cout << "Invalid choice. Please enter 1 or 2: ";
            std::cin >> choice;
        }

        if (choice == "2") {
            std::cout << "Please choose one of the following domain extensions:" << std::endl;

            for (int i = 0; i < popularDomainExtensions.size(); i++) { //тут был сайз_т апапхапхапхпап
                std::cout << i + 1 << ". " << popularDomainExtensions[i] << std::endl;
            }

            std::cout
                    << "Enter the ID of the desired domain extension, write any other number to continue without domain ";
            int chosenIndex;
            std::cin >> chosenIndex;

            if (chosenIndex >= 1 && chosenIndex <= popularDomainExtensions.size()) {
                std::string chosenExtension = popularDomainExtensions[chosenIndex - 1];
                entry.website = entry.website.substr(0, entry.website.find('.')) + chosenExtension;
            } else {
                std::cout << "Invalid domain extension ID. Keeping the original website." << std::endl;
            }
        }
    } else {
        std::cout
                << "Your website does not have a domain extension. Please choose one from the following popular options, write any other number to continue without domain "
                << std::endl;

        for (int i = 0; i < popularDomainExtensions.size(); i++) {
            std::cout << i + 1 << ". " << popularDomainExtensions[i] << std::endl;
        }

        std::cout << "Enter the ID of the desired domain extension: ";
        int chosenIndex;
        std::cin >> chosenIndex;

        if (chosenIndex >= 1 && chosenIndex <= popularDomainExtensions.size()) {
            std::string chosenExtension = popularDomainExtensions[chosenIndex - 1];
            entry.website += chosenExtension;
        } else {
            std::cout << "Invalid domain extension ID. Keeping the original website." << std::endl;
        }
    }

    bool login = true;

    while (login) {
        std::cout << "Enter login (optional), write 1 if you dont want to write login: ";
        std::string loginOption;
        std::cin >> loginOption;

        if (loginOption == "1") {
            entry.login = " ";
            login = false;
            break;
        } else {
            entry.login = loginOption;
        }

        if (loginOption == "1" || loginOption.length() > 20 || loginOption.length() < 4) {
            std::cout << "Length of the login must be less then 20 characters and more then 4" << std::endl;
            continue;
        } else {
            login = false;
            break;
        }

    }


    std::cout << "Do you want to (1) create a new category or (2) add other things to existing category?" << std::endl;
    std::cout << "1. Create a new category" << std::endl;
    std::cout << "2. Add other things to existing category" << std::endl;
    std::cout << "Your choice: ";
    std::string choice;
    std::cin >> choice;

    while (choice != "1" && choice != "2") {
        std::cout << "Invalid choice. Please enter 1 or 2: ";
        std::cin >> choice;
    }


    if (choice == "1") {


        std::cout << "Enter category: ";
        std::getline(std::cin >> std::ws, entry.category);

        while (entry.category.length() > 20 || entry.category.length() < 3) {
            std::cout << "Length of the category must be less then 20 characters";
            std::string cat;
            std::getline(std::cin >> std::ws, cat);
            entry.category = cat;
        }


        std::string generatePass;
        std::cout << "Do you want to generate your password automatically? (yes/no): ";
        std::cin >> generatePass;

        while (generatePass != "yes" && generatePass != "no") {
            std::cout << "Invalid choice. Please enter yes or no: ";
            std::cin >> generatePass;
        }


        if (generatePass == "yes") {

            deleteLastLineFromFile(filePath);

            std::string encryptedWebsite = Encryption::encrypt(entry.website);
            std::string encryptedLogin = Encryption::encrypt(entry.login);
            std::string encryptedCategory = Encryption::encrypt(entry.category);

//            std::ofstream outFileCat("D:\\ProjectC\\categories.txt", std::ios::app);
//            if (outFileCat.is_open()) {
//                outFileCat << encryptedCategory << "\n";
//                outFileCat.close();
//            } else {
//                std::cout << "Failed to open categories.txt for writing." << std::endl;
//            }

            Methods::generatePassword();

            std::ofstream outFile(filePath, std::ios::app);
            if (outFile.is_open()) {


                std::string encryptedPassword = Encryption::encrypt(newPassword);

                outFile << encryptedWebsite << "," << encryptedLogin << "," << encryptedCategory << ","
                        << encryptedPassword
                        << std::endl;
                outFile.close();
            } else {
                std::cout << "Failed to open file for writing." << std::endl;
                return;
            }

            appendCurrentTimeToFile(filePath);


            std::string checkDuplicateChoice;
            std::cout << "Do you want to check for password duplicates? (yes/no): ";
            std::cin >> checkDuplicateChoice;

            while (checkDuplicateChoice != "yes" && checkDuplicateChoice != "no") {
                std::cout << "Invalid choice. Please enter yes or no: ";
                std::cin >> checkDuplicateChoice;
            }


            if (checkDuplicateChoice == "yes") {

                std::string key;
                std::cout << "Write the password of file to see if there are any copies of password: " << std::endl;
                std::cin >> key;

                // Decrypt existing passwords and check for duplicates
                std::string decryptedData = Encryption::decryptText(filePath, key);
                std::stringstream decryptedStream(decryptedData); //нихуя рофл, стринг гот стронгер ин май айс
                std::string line;
                bool isDuplicate = false;
                std::ifstream inFile(filePath);

                while (std::getline(decryptedStream, line)) {
                    std::vector<std::string> passwordData = splitLine(line, ',');
                    std::string decryptedPassword = passwordData[3];

                    if (decryptedPassword == newPassword) {
                        isDuplicate = true;
                        break;
                    }
                }

                inFile.close();

                if (isDuplicate) {
                    std::cout << "You are already using this password." << std::endl;
                } else {
                    std::cout << "No duplicate passwords found." << std::endl;
                }


            } else if (checkDuplicateChoice == "no") {
//                     ? ? ? ? ? ? ?
            }


        } else if (generatePass == "no") {

            a = 0;

            std::string newPass = validatePassword();


            std::string checkDuplicateChoice;
            std::cout << "Do you want to check for password duplicates? (yes/no): ";
            std::cin >> checkDuplicateChoice;

            while (checkDuplicateChoice != "yes" && checkDuplicateChoice != "no") {
                std::cout << "Invalid choice. Please enter yes or no: ";
                std::cin >> checkDuplicateChoice;
            }


            if (checkDuplicateChoice == "yes") {

                std::string key;
                std::cout << "Write the password of file to see if there are any copies of password: "
                          << std::endl;
                std::cin >> key;

                // Decrypt existing passwords and check for duplicates
                std::string decryptedData = Encryption::decryptText(filePath, key);
                std::stringstream decryptedStream(decryptedData);
                std::string line;
                bool isDuplicate = false;
                std::ifstream inFile(filePath);

                while (std::getline(decryptedStream, line)) {
                    std::vector<std::string> passwordData = splitLine(line, ',');
                    std::string decryptedPassword = passwordData[3];

                    if (decryptedPassword == newPass) {
                        isDuplicate = true;
                        break;
                    }
                }

                inFile.close();

                if (isDuplicate) {
                    std::cout << "You are already using this password." << std::endl;
                } else {
                    std::cout << "No duplicate passwords found." << std::endl;
                }

                // Encrypt the entry
                std::string encryptedWebsite = Encryption::encrypt(entry.website);
                std::string encryptedLogin = Encryption::encrypt(entry.login);
                std::string encryptedCategory = Encryption::encrypt(entry.category);

//                std::ofstream outFileCat("D:\\ProjectC\\categories.txt", std::ios::app);
//                if (outFileCat.is_open()) {
//                    outFileCat << encryptedCategory << "\n";
//                    outFileCat.close();
//                } else {
//                    std::cout << "Failed to open categories.txt for writing." << std::endl;
//                }

                std::string encryptedPassword = Encryption::encrypt(newPass);

                deleteLastLineFromFile(filePath);

                // Write the entry to the file
                std::ofstream outFile(filePath, std::ios::app);
                if (outFile.is_open()) {
                    outFile << encryptedWebsite << "," << encryptedLogin << "," << encryptedCategory << ","
                            << encryptedPassword
                            << std::endl;
                    outFile.close();
                    std::cout << "Password successfully added." << std::endl;
                } else {
                    std::cout << "Failed to open file for writing." << std::endl;
                    return;
                }

                appendCurrentTimeToFile(filePath);

                // Check password strength

            } else if (checkDuplicateChoice == "no") {

                // Encrypt the entry
                std::string encryptedWebsite = Encryption::encrypt(entry.website);
                std::string encryptedLogin = Encryption::encrypt(entry.login);
                std::string encryptedCategory = Encryption::encrypt(entry.category);

//                std::ofstream outFileCat("D:\\ProjectC\\categories.txt", std::ios::app);
//                if (outFileCat.is_open()) {
//                    outFileCat << encryptedCategory << "\n";
//                    outFileCat.close();
//                } else {
//                    std::cout << "Failed to open categories.txt for writing." << std::endl;
//                }

                std::string encryptedPassword = Encryption::encrypt(newPass);

                deleteLastLineFromFile(filePath);

                // Write the entry to the file
                std::ofstream outFile(filePath, std::ios::app);
                if (outFile.is_open()) {
                    outFile << encryptedWebsite << "," << encryptedLogin << "," << encryptedCategory << ","
                            << encryptedPassword
                            << std::endl;
                    outFile.close();
                    std::cout << "Password successfully added." << std::endl;
                } else {
                    std::cout << "Failed to open file for writing." << std::endl;
                    return;
                }

                appendCurrentTimeToFile(filePath);

                // Check password strength

            }
        }


    } else if (choice == "2") {
        decryptCategories();

        std::cout << "Enter a category: ";
        std::string enteredCategory;
        std::cin.ignore();     //    ???  съебалось нахуй отсюда
        std::getline(std::cin, enteredCategory);

        std::string encryptedEnteredCategory = Encryption::encrypt(enteredCategory);

        std::ifstream categoryFile(filePathCat);
        if (!categoryFile) {
            std::cout << "Failed to open the categories file." << std::endl;
            return;
        }

        std::string line;
        bool found = false;

        while (std::getline(categoryFile, line)) {
            if (line == encryptedEnteredCategory) {
                found = true;
                break;
            }
        }

        categoryFile.close();

        if (found) {


            std::string generatePass;
            std::cout << "Do you want to generate your password automatically? (yes/no): ";
            std::cin >> generatePass;

            while (generatePass != "yes" && generatePass != "no") {
                std::cout << "Invalid choice. Please enter yes or no: ";
                std::cin >> generatePass;
            }


            if (generatePass == "yes") {

                deleteLastLineFromFile(filePath);


                std::string encryptedWebsite = Encryption::encrypt(entry.website);
                std::string encryptedLogin = Encryption::encrypt(entry.login);
                std::string encryptedCategory = Encryption::encrypt(enteredCategory);


                std::ofstream outFile(filePath, std::ios::app);
                if (outFile.is_open()) {
                    std::string newPass = Methods::generatePassword();
                    std::string encryptedPassword = Encryption::encrypt(newPass);
                    outFile << encryptedWebsite << "," << encryptedLogin << "," << encryptedCategory << ","
                            << encryptedPassword
                            << std::endl;
                    outFile.close();
                } else {
                    std::cout << "Failed to open file for writing." << std::endl;
                    return;
                }


                appendCurrentTimeToFile(filePath);


            } else if (generatePass == "no") {

                a = 0;


                std::string newPass = validatePassword();


                std::string checkDuplicateChoice;
                std::cout << "Do you want to check for password duplicates? (yes/no): ";
                std::cin >> checkDuplicateChoice;

                while (checkDuplicateChoice != "yes" && checkDuplicateChoice != "no") {
                    std::cout << "Invalid choice. Please enter yes or no: ";
                    std::cin >> checkDuplicateChoice;
                }

                if (checkDuplicateChoice == "yes") {

                    std::string key;
                    std::cout << "Write the password of file to see if there are any copies of password: "
                              << std::endl;
                    std::cin >> key;

                    // Decrypt existing passwords and check for duplicates
                    std::string decryptedData = Encryption::decryptText(filePath, key);
                    std::istringstream decryptedStream(decryptedData);
                    bool isDuplicate = false;
                    std::ifstream inFile(filePath);

                    while (std::getline(decryptedStream, line)) {
                        std::vector<std::string> passwordData = splitLine(line, ',');
                        std::string decryptedPassword = passwordData[3];

                        if (decryptedPassword == newPass) {
                            isDuplicate = true;
                            break;
                        }
                    }

                    inFile.close();

                    if (isDuplicate) {
                        std::cout << "You are already using this password." << std::endl;
                    } else {
                        std::cout << "No duplicate passwords found." << std::endl;
                    }

                    // Encrypt the entry
                    std::string encryptedWebsite = Encryption::encrypt(entry.website);
                    std::string encryptedLogin = Encryption::encrypt(entry.login);
                    std::string encryptedCategory = Encryption::encrypt(enteredCategory);


                    std::string encryptedPassword = Encryption::encrypt(newPass);

                    deleteLastLineFromFile(filePath);

                    // Write the entry to the file
                    std::ofstream outFile(filePath, std::ios::app);
                    if (outFile.is_open()) {
                        outFile << encryptedWebsite << "," << encryptedLogin << "," << encryptedCategory << ","
                                << encryptedPassword
                                << std::endl;
                        outFile.close();
                        std::cout << "Password successfully added." << std::endl;
                    } else {
                        std::cout << "Failed to open file for writing." << std::endl;
                        return;
                    }

                    appendCurrentTimeToFile(filePath);

                    // Check password strength

                } else if (checkDuplicateChoice == "no") {

                    // Encrypt the entry
                    std::string encryptedWebsite = Encryption::encrypt(entry.website);
                    std::string encryptedLogin = Encryption::encrypt(entry.login);
                    std::string encryptedCategory = Encryption::encrypt(enteredCategory);


                    std::string encryptedPassword = Encryption::encrypt(newPass);

                    deleteLastLineFromFile(filePath);

                    // Write the entry to the file
                    std::ofstream outFile(filePath, std::ios::app);
                    if (outFile.is_open()) {
                        outFile << encryptedWebsite << "," << encryptedLogin << "," << encryptedCategory << ","
                                << encryptedPassword
                                << std::endl;
                        outFile.close();
                        std::cout << "Password successfully added." << std::endl;
                    } else {
                        std::cout << "Failed to open file for writing." << std::endl;
                        return;
                    }

                    appendCurrentTimeToFile(filePath);

                    // Check password strength

                }
            }


        } else {
            std::cout << "Category not found." << std::endl;


            std::string generatePass;
            std::cout << "Do you want to generate your password automatically? (yes/no): ";
            std::cin >> generatePass;

            while (generatePass != "yes" && generatePass != "no") {
                std::cout << "Invalid choice. Please enter yes or no: ";
                std::cin >> generatePass;
            }


            if (generatePass == "yes") {

                deleteLastLineFromFile(filePath);

                std::string noCat;


                std::string encryptedWebsite = Encryption::encrypt(entry.website);
                std::string encryptedLogin = Encryption::encrypt(entry.login);


                std::ofstream outFile(filePath, std::ios::app);
                if (outFile.is_open()) {
                    std::string newPass = Methods::generatePassword();
                    std::string encryptedPassword = Encryption::encrypt(newPass);
                    outFile << encryptedWebsite << "," << encryptedLogin << "," << noCat << ","
                            << encryptedPassword
                            << std::endl;
                    outFile.close();
                } else {
                    std::cout << "Failed to open file for writing." << std::endl;
                    return;
                }


                appendCurrentTimeToFile(filePath);


            } else if (generatePass == "no") {

                a = 0;


                std::string newPass = validatePassword();


                std::string checkDuplicateChoice;
                std::cout << "Do you want to check for password duplicates? (yes/no): ";
                std::cin >> checkDuplicateChoice;

                while (checkDuplicateChoice != "yes" && checkDuplicateChoice != "no") {
                    std::cout << "Invalid choice. Please enter yes or no: ";
                    std::cin >> checkDuplicateChoice;
                }

                if (checkDuplicateChoice == "yes") {

                    std::string key;
                    std::cout << "Write the password of file to see if there are any copies of password: "
                              << std::endl;
                    std::cin >> key;

                    // Decrypt existing passwords and check for duplicates
                    std::string decryptedData = Encryption::decryptText(filePath, key);
                    std::stringstream decryptedStream(decryptedData);
                    bool isDuplicate = false;
                    std::ifstream inFile(filePath);

                    while (std::getline(decryptedStream, line)) {
                        std::vector<std::string> passwordData = splitLine(line, ',');
                        std::string decryptedPassword = passwordData[3];

                        if (decryptedPassword == newPass) {
                            isDuplicate = true;
                            break;
                        }
                    }

                    inFile.close();

                    if (isDuplicate) {
                        std::cout << "You are already using this password." << std::endl;
                    } else {
                        std::cout << "No duplicate passwords found." << std::endl;
                    }

                    std::string noCat;

                    // Encrypt the entry
                    std::string encryptedWebsite = Encryption::encrypt(entry.website);
                    std::string encryptedLogin = Encryption::encrypt(entry.login);
                    //std::string encryptedCategory = Encryption::encrypt(enteredCategory);


                    std::string encryptedPassword = Encryption::encrypt(newPass);

                    deleteLastLineFromFile(filePath);

                    // Write the entry to the file
                    std::ofstream outFile(filePath, std::ios::app);
                    if (outFile.is_open()) {
                        outFile << encryptedWebsite << "," << encryptedLogin << "," << noCat << ","
                                << encryptedPassword
                                << std::endl;
                        outFile.close();
                        std::cout << "Password successfully added." << std::endl;
                    } else {
                        std::cout << "Failed to open file for writing." << std::endl;
                        return;
                    }

                    appendCurrentTimeToFile(filePath);

                    // Check password strength

                } else if (checkDuplicateChoice == "no") {

                    std::string noCat;

                    // Encrypt the entry
                    std::string encryptedWebsite = Encryption::encrypt(entry.website);
                    std::string encryptedLogin = Encryption::encrypt(entry.login);
                    //std::string encryptedCategory = Encryption::encrypt(enteredCategory);


                    std::string encryptedPassword = Encryption::encrypt(newPass);

                    deleteLastLineFromFile(filePath);

                    // Write the entry to the file
                    std::ofstream outFile(filePath, std::ios::app);
                    if (outFile.is_open()) {
                        outFile << encryptedWebsite << "," << encryptedLogin << "," << noCat << ","
                                << encryptedPassword
                                << std::endl;
                        outFile.close();
                        std::cout << "Password successfully added." << std::endl;
                    } else {
                        std::cout << "Failed to open file for writing." << std::endl;
                        return;
                    }

                    appendCurrentTimeToFile(filePath);


                }

            }


        }


    }

}


void Methods::findPassword(const std::string &filePath) {

    deleteLastLineFromFile(filePath);
    std::string searchOption;
    std::string searchTerm;

    std::cout << "Enter the decryption key: ";
    std::string decryptionKey;
    std::cin >> decryptionKey;

    if (decryptionKey != Encryption::password) {
        std::cout << "You wrote wrong password" << std::endl;
        appendCurrentTimeToFile(filePath);
        return;
    }

    std::cout << "Select an option to search for a password:" << std::endl;
    std::cout << "1. Search by website" << std::endl;
    std::cout << "2. Search by login" << std::endl;
    std::cout << "3. Search by category" << std::endl;
    std::cout << "Your choice: ";

    bool pass = true;

    while (pass) {
        std::cin >> searchOption;

        if (searchOption == "1" || searchOption == "2" || searchOption == "3") {
            pass = false;
            break;
        } else {
            std::cout << "Please write the number from 1 to 3" << std::endl;
            continue;
        }
    }


    std::cout << "Enter the search term: ";
    std::getline(std::cin >> std::ws, searchTerm);

    std::ifstream inFile(filePath);
    std::string line;
    std::vector<PasswordEntry> foundPasswords;

    while (std::getline(inFile, line)) {
        size_t pos = 0;
        std::string delimiter = ",";
        std::string passwordData[4];
        int i = 0;

        while ((pos = line.find(delimiter)) != std::string::npos) {
            passwordData[i] = line.substr(0, pos);
            line.erase(0, pos + delimiter.length());
            i++;
        }

        passwordData[i] = line;

        PasswordEntry entry;
        entry.website = Encryption::decrypt(passwordData[0], decryptionKey);
        entry.login = Encryption::decrypt(passwordData[1], decryptionKey);
        entry.category = Encryption::decrypt(passwordData[2], decryptionKey);
        entry.password = Encryption::decrypt(passwordData[3], decryptionKey);

        if (searchOption == "1" && entry.website == searchTerm) {
            foundPasswords.push_back(entry);
        } else if (searchOption == "2" && entry.login == searchTerm) {
            foundPasswords.push_back(entry);
        } else if (searchOption == "3" && entry.category == searchTerm) {
            foundPasswords.push_back(entry);
        }
    }

    inFile.close();

    if (foundPasswords.empty()) {
        std::cout << "No passwords found matching the search criteria." << std::endl;
    } else {
        std::cout << "Found passwords:" << std::endl;
        std::cout << std::setw(30) << std::left << "Website"
                  << std::setw(30) << std::left << "Login"
                  << std::setw(30) << std::left << "Category"
                  << "Password" << std::endl;
        for (const auto &password: foundPasswords) {
            std::cout << std::setw(30) << std::left << password.website
                      << std::setw(30) << std::left << password.login
                      << std::setw(30) << std::left << password.category
                      << password.password << std::endl;
        }
    }

    appendCurrentTimeToFile(filePath);
}

//TODO
void Methods::deletePassword(const std::string &filePath) {

    deleteLastLineFromFile(filePath);

    std::cout << "Enter the decryption key: ";
    std::string decryptionKey;
    std::cin >> decryptionKey;

    if (decryptionKey != Encryption::password) {
        std::cout << "You wrote wrong password" << std::endl;
        appendCurrentTimeToFile(filePath);
        return;
    }

    std::ifstream inFile(filePath);
    std::string line;

    std::cout << "Decrypted passwords:" << std::endl;
    std::cout << std::setw(5) << std::left << "ID"
              << std::setw(25) << std::left << "Website"
              << std::setw(30) << std::left << "Login"
              << std::setw(30) << std::left << "Category"
              << "Password" << std::endl;

    std::vector<std::string> passwordData(4);
    std::vector<std::string> decryptedPasswords;

    int id = 1; // Счетчик айдишек

    while (!inFile.eof() && std::getline(inFile, line)) {
        size_t pos = 0;
        std::string delimiter = ",";
        int i = 0;

        while ((pos = line.find(delimiter)) != std::string::npos) {
            passwordData[i] = line.substr(0, pos);
            line.erase(0, pos + delimiter.length());
            i++;
        }

        passwordData[i] = line;

        std::string decryptedWebsite = Encryption::decrypt(passwordData[0], decryptionKey);
        std::string decryptedLogin = Encryption::decrypt(passwordData[1], decryptionKey);
        std::string decryptedCategory = Encryption::decrypt(passwordData[2], decryptionKey);
        std::string decryptedPassword = Encryption::decrypt(passwordData[3], decryptionKey);

        // Создаем строку с айдишкой и добавляем ее перед выводом полей
        std::string idString = std::to_string(id);

        std::cout << std::setw(5) << std::left << idString
                  << std::setw(25) << std::left << decryptedWebsite
                  << std::setw(30) << std::left << decryptedLogin
                  << std::setw(30) << std::left << decryptedCategory
                  << decryptedPassword << std::endl;

        decryptedPasswords.push_back(decryptedPassword);

        id++; // Увеличиваем счетчик айдишек
    }

    inFile.close();


    std::cout << "Enter the passwords id to delete (separated by commas): ";
    std::string idsToDelete;
    std::cin.ignore();
    std::getline(std::cin, idsToDelete);

    std::istringstream iss(idsToDelete);
    std::string idToDelete;

    std::vector<int> deletedIds;
    std::vector<std::string> remainingLines;

    while (std::getline(iss, idToDelete, ',')) {
        // Преобразование айдишки в целое число
        id = std::stoi(idToDelete); //строку в инт

        deletedIds.push_back(id);
    }

    std::ifstream inFile2(filePath);
    if (!inFile2) {
        std::cout << "Failed to open the file." << std::endl;
        return;
    }

    int currentLineId = 1;

    while (std::getline(inFile2, line)) {
        bool lineDeleted = false;

        for (const int deletedId: deletedIds) {
            if (currentLineId == deletedId) {
                lineDeleted = true;
                break;
            }
        }

        if (!lineDeleted) {
            remainingLines.push_back(line);
        }

        currentLineId++;
    }

    inFile2.close();

    std::ofstream outFile(filePath);
    if (!outFile) {
        std::cout << "Failed to open the file for writing." << std::endl;
        return;
    }

    for (const std::string &updatedLine: remainingLines) {
        outFile << updatedLine << std::endl;
    }
    outFile.close();

    std::cout << "Matching line(s) deleted successfully." << std::endl;

    appendCurrentTimeToFile(filePath);

}


void Methods::sortPasswords(const std::string &filePath) {

    deleteLastLineFromFile(filePath);

    std::cout << "Enter the decryption key: ";
    std::string decryptionKey;
    std::cin >> decryptionKey;

    if (decryptionKey != Encryption::password) {
        std::cout << "You wrote wrong password" << std::endl;
        appendCurrentTimeToFile(filePath);
        return;
    }

    std::vector<PasswordEntry> passwords;
    std::ifstream inFile(filePath);
    std::string line;

    while (std::getline(inFile, line)) {
        size_t pos = 0;
        std::string delimiter = ",";
        std::string passwordData[4];
        int i = 0;

        while ((pos = line.find(delimiter)) != std::string::npos) {
            passwordData[i] = line.substr(0, pos);
            line.erase(0, pos + delimiter.length());
            i++;
        }

        passwordData[i] = line;

        PasswordEntry entry;
        entry.website = passwordData[0];
        entry.login = passwordData[1];
        entry.category = passwordData[2];
        entry.password = passwordData[3];

        passwords.push_back(entry);
    }

    inFile.close();

    std::cout << "Choose the first sorting criterion:" << std::endl;
    std::cout << "1. Website" << std::endl;
    std::cout << "2. Login" << std::endl;
    std::cout << "3. Category" << std::endl;
    std::cout << "4. Password" << std::endl;

    int firstCriterion;
    std::cin >> firstCriterion;

    std::cout << "Choose the second sorting criterion:" << std::endl;
    std::cout << "1. Website" << std::endl;
    std::cout << "2. Login" << std::endl;
    std::cout << "3. Category" << std::endl;
    std::cout << "4. Password" << std::endl;

    int secondCriterion;
    std::cin >> secondCriterion;

    if (firstCriterion == secondCriterion) {
        std::cout << "You already chose that option" << std::endl;
        if (firstCriterion == 1) {
            std::cout << "2. Login" << std::endl;
            std::cout << "3. Category" << std::endl;
            std::cout << "4. Password" << std::endl;
            std::cin >> secondCriterion;
        } else if (firstCriterion == 2) {
            std::cout << "1. Website" << std::endl;
            std::cout << "3. Category" << std::endl;
            std::cout << "4. Password" << std::endl;
            std::cin >> secondCriterion;
        } else if (firstCriterion == 3) {
            std::cout << "1. Website" << std::endl;
            std::cout << "2. Login" << std::endl;
            std::cout << "4. Password" << std::endl;
            std::cin >> secondCriterion;
        } else {
            std::cout << "1. Website" << std::endl;
            std::cout << "2. Login" << std::endl;
            std::cout << "3. Category" << std::endl;
            std::cin >> secondCriterion;
        }
    }

        std::sort(passwords.begin(), passwords.end(),
              [decryptionKey, firstCriterion, secondCriterion](const PasswordEntry &a, const PasswordEntry &b) {
                  std::string valueA, valueB;

                  if (firstCriterion == 1) {
                      valueA = Encryption::decrypt(a.website, decryptionKey);
                      valueB = Encryption::decrypt(b.website, decryptionKey);
                  } else if (firstCriterion == 2) {
                      valueA = Encryption::decrypt(a.login, decryptionKey);
                      valueB = Encryption::decrypt(b.login, decryptionKey);
                  } else if (firstCriterion == 3) {
                      valueA = Encryption::decrypt(a.category, decryptionKey);
                      valueB = Encryption::decrypt(b.category, decryptionKey);
                  } else if (firstCriterion == 4) {
                      valueA = Encryption::decrypt(a.password, decryptionKey);
                      valueB = Encryption::decrypt(b.password, decryptionKey);
                  }

                  if (valueA != valueB) {
                      return valueA < valueB;
                  } else {
                      if (secondCriterion == 1) {
                          valueA = Encryption::decrypt(a.website, decryptionKey);
                          valueB = Encryption::decrypt(b.website, decryptionKey);
                      } else if (secondCriterion == 2) {
                          valueA = Encryption::decrypt(a.login, decryptionKey);
                          valueB = Encryption::decrypt(b.login, decryptionKey);
                      } else if (secondCriterion == 3) {
                          valueA = Encryption::decrypt(a.category, decryptionKey);
                          valueB = Encryption::decrypt(b.category, decryptionKey);
                      } else if (secondCriterion == 4) {
                          valueA = Encryption::decrypt(a.password, decryptionKey);
                          valueB = Encryption::decrypt(b.password, decryptionKey);
                      }

                      return valueA < valueB;
                  }
              });

    std::cout << "Sorted passwords:" << std::endl;
    std::cout << std::setw(30) << std::left << "Website"
              << std::setw(30) << std::left << "Login"
              << std::setw(30) << std::left << "Category"
              << "Password" << std::endl;

    for (const auto &password: passwords) {
        std::cout << std::setw(30) << std::left << Encryption::decrypt(password.website, decryptionKey)
                  << std::setw(30) << std::left << Encryption::decrypt(password.login, decryptionKey)
                  << std::setw(30) << std::left << Encryption::decrypt(password.category, decryptionKey)
                  << std::setw(30) << std::left << Encryption::decrypt(password.password, decryptionKey) << std::endl;
    }

    appendCurrentTimeToFile(filePath);
}


void Methods::deleteCategory(const std::string &filePath) {

    deleteLastLineFromFile(filePath);

    std::cout << "Enter the decryption key: ";
    std::string decryptionKey;
    std::cin >> decryptionKey;

    if (decryptionKey != Encryption::password) {
        std::cout << "You wrote wrong password" << std::endl;
        appendCurrentTimeToFile(filePath);
        return;
    }

    std::ifstream inFile(filePath);
    std::string line;

    std::cout << "Decrypted passwords:" << std::endl;
    std::cout << std::setw(30) << std::left << "Website"
              << std::setw(30) << std::left << "Login"
              << std::setw(30) << std::left << "Category"
              << "Password" << std::endl;

    std::vector<std::string> passwordData(4);

    while (!inFile.eof() && std::getline(inFile, line)) {
        size_t pos = 0;
        std::string delimiter = ",";
        int i = 0;

        while ((pos = line.find(delimiter)) != std::string::npos) {
            passwordData[i] = line.substr(0, pos);
            line.erase(0, pos + delimiter.length());
            i++;
        }

        passwordData[i] = line;

        std::string decryptedWebsite = Encryption::decrypt(passwordData[0], decryptionKey);
        std::string decryptedLogin = Encryption::decrypt(passwordData[1], decryptionKey);
        std::string decryptedCategory = Encryption::decrypt(passwordData[2], decryptionKey);
        std::string decryptedPassword = Encryption::decrypt(passwordData[3], decryptionKey);

        std::cout << std::setw(30) << std::left << decryptedWebsite
                  << std::setw(30) << std::left << decryptedLogin
                  << std::setw(30) << std::left << decryptedCategory
                  << decryptedPassword << std::endl;
    }

    inFile.close();

    std::cout << "Enter the category to delete: ";
    std::string word;
    std::cin >> word;

    std::string encryptedWord = Encryption::encrypt(word);

    std::ifstream inFile2(filePath);
    if (!inFile2) {
        std::cout << "Failed to open the file." << std::endl;
        return;
    }

    std::vector<std::string> fileLines;
    while (std::getline(inFile2, line)) {
        fileLines.push_back(line);
    }
    inFile2.close();

    std::vector<std::string> updatedContents;

    for (const std::string &fileLine: fileLines) {
        std::istringstream iss(fileLine);
        std::vector<std::string> passwordData;
        std::string token;

        while (std::getline(iss, token, ',')) {
            passwordData.push_back(token);
        }

        if (passwordData.size() == 4) {
            std::string encryptedCategory = passwordData[2];

            if (encryptedCategory != encryptedWord) {
                updatedContents.push_back(fileLine);
            }
        }
    }

    std::ofstream outFile(filePath);
    if (!outFile) {
        std::cout << "Failed to open the file for writing." << std::endl;
        return;
    }

    for (const std::string &updatedLine: updatedContents) {
        outFile << updatedLine << std::endl;
    }
    outFile.close();

    std::string encryptedCategory = passwordData[2];

    if (encryptedCategory == encryptedWord) {
        std::cout << "Matching line(s) deleted successfully." << std::endl;
    } else {
        std::cout << "No category in file" << std::endl;
    }

    appendCurrentTimeToFile(filePath);

}


void Methods::changePassword(const std::string &filePath) {
    deleteLastLineFromFile(filePath);

    std::cout << "Enter the decryption key: ";
    std::string decryptionKey;
    std::cin >> decryptionKey;

    if (decryptionKey != Encryption::password) {
        std::cout << "You wrote the wrong password" << std::endl;
        appendCurrentTimeToFile(filePath);
        return;
    }

    std::ifstream inFile(filePath);
    std::string line;
    std::vector<std::string> passwordLines;

    if (!inFile) {
        std::cout << "Error: Unable to open file." << std::endl;
        return;
    }

    std::cout << "Existing passwords:" << std::endl;
    std::cout << std::setw(5) << std::left << "ID"
              << std::setw(30) << std::left << "Website"
              << std::setw(30) << std::left << "Login"
              << std::setw(30) << std::left << "Category"
              << "Password" << std::endl;

    std::vector<std::string> passwordData(4);
    std::vector<std::string> decryptedPasswords;

    int id = 1; // Счетчик айдишек

    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        std::string token;

        for (int i = 0; i < 4; ++i) {
            if (std::getline(iss, token, ',')) {
                passwordData[i] = token;
            }
        }

        std::string decryptedWebsite = Encryption::decrypt(passwordData[0], decryptionKey);
        std::string decryptedCategory = Encryption::decrypt(passwordData[1], decryptionKey);
        std::string decryptedLogin = Encryption::decrypt(passwordData[2], decryptionKey);
        std::string decryptedPassword = Encryption::decrypt(passwordData[3], decryptionKey);

        std::cout << std::setw(5) << std::left << id
                  << std::setw(30) << std::left << decryptedWebsite
                  << std::setw(30) << std::left << decryptedLogin
                  << std::setw(30) << std::left << decryptedCategory
                  << decryptedPassword << std::endl;

        passwordLines.push_back(line);
        decryptedPasswords.push_back(decryptedPassword);
        id++; // Увеличиваем счетчик айдишек
    }

    inFile.close();

    std::cout << "Enter the ID of the password to change: ";
    int passwordID;
    std::cin >> passwordID;

    if (passwordID < 1 || passwordID > decryptedPasswords.size()) {
        std::cout << "Invalid password ID. Password not changed." << std::endl;
        appendCurrentTimeToFile(filePath);
        return;
    }

    std::string currentPassword = decryptedPasswords[passwordID - 1];

    std::cout << "Enter the new password: ";
    std::cin >> newPassword;

    bool changePass = true;

    while (changePass) {

        if (newPassword == currentPassword) {
            std::cout << "New password is the same as the current password. Do you want to keep it? (y/n): ";
            std::string choice;
            std::cin >> choice;

            if (choice != "y" && choice != "Y") {
                std::cout << "Enter the new password: ";
                std::cin >> newPassword;
                if (newPassword == currentPassword) {
                    continue;
                } else {
                    changePass = false;
                }
            } else {
                std::cout << "Password not changed." << std::endl;
                changePass = false;
            }
        } else{
            changePass = false;
            break;
        }
    }

    std::string encryptedCurrentPassword = Encryption::encrypt(currentPassword);
    std::string encryptedNewPassword = Encryption::encrypt(newPassword);

    bool passwordFound = false;

    for (std::string &passwordLine: passwordLines) {
        std::istringstream iss(passwordLine);
        std::string token;
        std::vector<std::string> passwordData1;

        for (int i = 0; i < 4; ++i) {
            if (std::getline(iss, token, ',')) {
                passwordData1.push_back(token);  //TODO
            }
        }

        std::string encryptedPassword = passwordData1[3];

        if (encryptedPassword == encryptedCurrentPassword) {
            passwordData1[3] = encryptedNewPassword;
            passwordLine = passwordData1[0] + "," + passwordData1[1] + "," + passwordData1[2] + "," + passwordData1[3];
            passwordFound = true;
            break;
        }
    }

    if (passwordFound) {
        std::ofstream outFile(filePath);

        for (const std::string &passwordLine: passwordLines) {
            outFile << passwordLine << std::endl;
        }

        outFile.close();

        std::cout << "Password changed successfully." << std::endl;
    } else {
        std::cout << "Current password not found. Password not changed." << std::endl;
    }

    appendCurrentTimeToFile(filePath);
}


void Methods::addCategory() {
    std::cout << "Enter the category: ";
    std::string category;
    std::cin >> category;

    std::string encryptedCategory = Encryption::encrypt(category);

    std::ofstream outFile(filePathCat, std::ios::app); // Открываем файл в режиме добавления (app)

    if (!outFile) {
        std::cout << "Failed to open the file for writing." << std::endl;
        return;
    }

    // Записываем новую строку с категорией в файл
    outFile << encryptedCategory << std::endl;

    outFile.close();

    std::cout << "Category added successfully." << std::endl;
}


void Methods::decryptCategories() {
    std::cout << "Enter the decryption key: ";
    std::string decryptionKey;
    std::cin >> decryptionKey;

    std::ifstream inFile(filePathCat);
    if (!inFile) {
        std::cout << "Failed to open the file for reading." << std::endl;
        return;
    }

    std::string line;
    std::cout << "Decrypted categories:" << std::endl;

    while (std::getline(inFile, line)) {
        std::string decryptedCategory = Encryption::decrypt(line, decryptionKey);
        std::cout << decryptedCategory << std::endl;
    }

    inFile.close();
}