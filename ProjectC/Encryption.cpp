//
// Created by User on 27.05.2023.
//

#include <fstream>
#include <iostream>
#include <filesystem>
#include "Encryption.h"

std::string Encryption::password;

std::string Encryption::getFilePath() {
    std::string filePath;
    std::string pass;
    std::string choice;

    bool file = true;

    while (file) {
        std::cout << "Select an option:" << std::endl;
        std::cout << "1. Create a new file" << std::endl;
        std::cout << "2. Open an existing file" << std::endl;
        std::cout << "Your choice:";
        std::getline(std::cin, choice);


        std::filesystem::path currentPath = std::filesystem::current_path(); //возвращает путь к текущей рабочей директории
        std::filesystem::path parentPath = currentPath.parent_path(); //возвращает путь к родительской директории текущей рабочей директории
        std::filesystem::path directoryPath = parentPath / "txtFiles";

        if (choice == "1") {
            std::string fileName;
            std::cout << "Enter file name for the new file: ";
            std::getline(std::cin, fileName);

            // Проверка наличия точки и отсутствия текста перед точкой
            if (fileName.find('.') != std::string::npos && fileName.find('.') == 0) {
                std::cout << "Invalid file name. Please enter a valid file name." << std::endl;
                continue;  // Возврат к началу цикла для повторного ввода
            }


            if (!std::filesystem::exists(directoryPath))
                std::filesystem::create_directory(directoryPath);

            // Удаление специальных символов из имени файла
            std::string invalidChars = R"(/\\:*?"<>|)";
            fileName.erase(std::remove_if(fileName.begin(), fileName.end(), [&invalidChars](char c) {
                return invalidChars.find(c) != std::string::npos;
            }), fileName.end());

            // Добавление расширения .txt, если оно не указано
            if (fileName.empty() || fileName.find_last_of('.') == std::string::npos)
                fileName += ".txt";

            filePath = (directoryPath / fileName).string();

            std::ofstream newFile(filePath); //запись в файл
            if (!newFile) {
                std::cout << "Failed to create file." << std::endl;
                continue;
            }
            newFile.close();
            std::cout << "New file created successfully." << std::endl;

            std::cout << "Enter a password for the file: ";
            std::cin >> pass;
            password = pass;

            // Записываем пароль в переменную или в файл, как требуется

        } else if (choice == "2") {
            // Проверяем, существует ли директория
            if (!std::filesystem::exists(directoryPath)) {
                std::cout << "Directory 'txtFiles' does not exist." << std::endl;
                continue;  // Возврат к началу цикла для повторного ввода
            }

            // Выводим названия всех файлов в директории
            std::cout << "Existing files in 'txtFiles' directory:" << std::endl;
            for (const auto& entry : std::filesystem::directory_iterator(directoryPath)) { //итерация по содержимому
                std::cout << entry.path().filename() << std::endl;
            }

            std::cout << "Enter file name to open: ";
            std::string fileName;
            std::getline(std::cin, fileName);

            // Добавление расширения .txt, если оно не указано
            if (fileName.empty() || fileName.find_last_of('.') == std::string::npos)
                fileName += ".txt";

            filePath = (directoryPath / fileName).string();

            std::ifstream file(filePath); //открытие
            if (!file) {
                std::cout << "File does not exist." << std::endl;
                continue;  // Возврат к началу цикла для повторного ввода
            }
            file.close();

            std::cout << "Enter a password for the file: ";
            std::cin >> pass;
            password = pass;

            // Очистка символа новой строки из входного потока
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


        } else {
            std::cout << "Invalid input. Please try again." << std::endl;
            continue;  // Возврат к началу цикла для повторного ввода
        }

        file = false;
    }

    return filePath;
}






std::string Encryption::encrypt(const std::string& text) {
    std::string encryptedText = text;

    for (char& c : encryptedText) {
        if (std::islower(c)) {
            c = (c - 'a' + 6) % 26 + 'a';  // Сдвиг маленькой буквы на 6 позиций вправо
        } else if (std::isupper(c)) {
            c = (c - 'A' + 22) % 26 + 'A';  // Сдвиг большой буквы на 4 позиции влево
        } else if (std::isdigit(c)) {
            c = '0' + (c - '0' + 7) % 10;  // Сдвиг цифры на 7 позиций вправо
        } else if (c != ':') {
            c = (c - 5);  // Сдвиг символа на 5 позиций влево
        }
    }


    return encryptedText;
}


int Encryption::calculateHash(const std::string& key) {
    int hashSum = 0;
    for (char c : key) {
        hashSum += static_cast<int>(c);
    }
    return hashSum;
}

std::string Encryption::decrypt(const std::string& ciphertext, const std::string& key) {
    std::string decryptedText = ciphertext;
    if (key == password) {
        for (char& c : decryptedText) {
            if (std::islower(c)) {
                c = (c - 'a' + 20) % 26 + 'a';  // Обратный сдвиг маленькой буквы на 6 позиций влево
            } else if (std::isupper(c)) {
                c = (c - 'A' + 4) % 26 + 'A';  // Обратный сдвиг большой буквы на 4 позиции вправо
            } else if (std::isdigit(c)) {
                c = '0' + (c - '0' + 10 - 7) % 10;  // Обратный сдвиг цифры на 7 позиций влево
            } else if (c != ':') {
                c = (c + 5);  // Обратный сдвиг символа на 5 позиций вправо
            }
        }


    } else{
        int hashSum = calculateHash(key);
        for (char& c : decryptedText) {
            if (c != ' ') {
                c = c - hashSum;  // Сдвигаем символ на одну позицию влево
            }
        }
    }

    return decryptedText;
}




std::string Encryption::decryptText(const std::string& filePath, const std::string& decryptionKey) {
    std::ifstream inFile(filePath);
    std::string line;
    std::string decryptedData;

    while (std::getline(inFile, line)) {
        size_t pos; //позиция символа в строке +10
        std::string delimiter = ",";
        std::string passwordData[4];
        int i = 0;

        while ((pos = line.find(delimiter)) != std::string::npos) { //будет выполнятся пока есть разделитель
            passwordData[i] = line.substr(0, pos); //закидывает в массив от начала строки до разделителя
            line.erase(0, pos + delimiter.length());
            i++;
        }

        passwordData[i] = line;

        std::string decryptedWebsite = Encryption::decrypt(passwordData[0], decryptionKey);
        std::string decryptedCategory = Encryption::decrypt(passwordData[1], decryptionKey);
        std::string decryptedLogin = Encryption::decrypt(passwordData[2], decryptionKey);
        std::string decryptedPassword = Encryption::decrypt(passwordData[3], decryptionKey);

        decryptedData += decryptedWebsite + "," + decryptedCategory + "," + decryptedLogin + "," + decryptedPassword + "\n";
    }

    inFile.close();

    return decryptedData;
}


std::string Encryption::decryptLastLineFromFile(const std::string& filePath) {
    std::ifstream file(filePath);
    std::string line;
    std::string lastLine;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            if (!line.empty()) {
                lastLine = line;
            }
        }

        file.close();

        // Расшифровка последней строки
        std::string decryptedText = lastLine;
        for (char& c : decryptedText) {
            if (std::islower(c)) {
                c = (c - 'a' + 20) % 26 + 'a';  // Обратный сдвиг маленькой буквы на 6 позиций влево
            } else if (std::isupper(c)) {
                c = (c - 'A' + 4) % 26 + 'A';  // Обратный сдвиг большой буквы на 4 позиции вправо
            } else if (std::isdigit(c)) {
                c = '0' + (c - '0' + 10 - 7) % 10;  // Обратный сдвиг цифры на 7 позиций влево
            } else if (c != ':') {
                c = (c + 5);  // Обратный сдвиг символа на 5 позиций вправо
            }
        }


        return decryptedText;
    } else {
        std::cout << "Failed to open file." << std::endl;
        return "";
    }
}

