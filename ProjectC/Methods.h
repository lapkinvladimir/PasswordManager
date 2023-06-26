//
// Created by User on 27.05.2023.
//

#ifndef PROJECTC_METHODS_H
#define PROJECTC_METHODS_H



class Methods {
public:
    static std::string generatePassword();
    static std::string validatePassword();
    static void decryptAll(const std::string& filePath);
    static void addPassword(const std::string& filePath);
    static void findPassword(const std::string& filePath);
    static void deletePassword(const std::string& filePath);
    static void sortPasswords(const std::string& filePath);
    static void deleteCategory(const std::string& filePath);
    static void changePassword(const std::string& filePath);
    static void addCategory();
    static void decryptCategories();
    static std::string findCategoriesFilePath();
    static std::string filePathCat;
    static void appendCurrentTimeToFile(const std::string& filePath);
    static void deleteLastLineFromFile(const std::string& filePath);
};

#endif //PROJECTC_METHODS_H
