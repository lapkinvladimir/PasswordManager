//
// Created by User on 28.05.2023.
//

#include <ctime>
#include <vector>
#include "Encryption.h"
#include "Time.h"


std::string Time::encryptTime() {
    std::time_t now = std::time(nullptr);
    std::tm* timeInfo = std::localtime(&now);

    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeInfo);

    std::string timeString(buffer);
    std::string encryptedTime = Encryption::encrypt(timeString);

    return encryptedTime;
}
