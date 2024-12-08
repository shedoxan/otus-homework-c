#include <iostream>
#include <cstdlib>

int main() {
    const char* build_number_env = std::getenv("BUILD_NUMBER");
    std::string build_number = build_number_env ? build_number_env : "0";
    std::cout << "build " << build_number << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
