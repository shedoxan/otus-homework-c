#include <iostream>
#include <cstdlib>

int main() {
    // Получаем номер сборки из переменной окружения или используем значение по умолчанию
    const char* buildNumber = std::getenv("BUILD_NUMBER");
    if (!buildNumber) {
        buildNumber = "1"; // Значение по умолчанию
    }
    
    // Вывод строк
    std::cout << "Version: " << buildNumber << std::endl;
    std::cout << "Hello, World!" << std::endl;

    return 0;
}
