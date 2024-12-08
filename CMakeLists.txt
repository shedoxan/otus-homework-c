cmake_minimum_required(VERSION 3.10)
project(helloworld VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)

# Добавляем исполняемый файл, указывая путь к исходнику
add_executable(helloworld 1/helloworld.cpp)

# Установка цели для установки исполняемого файла
install(TARGETS helloworld DESTINATION bin)

# Использование переменной окружения для версии пакета
if(DEFINED ENV{GITHUB_RUN_NUMBER})
    set(CPACK_PACKAGE_VERSION "0.0.$ENV{GITHUB_RUN_NUMBER}")
else()
    set(CPACK_PACKAGE_VERSION "0.0.1")
endif()

# Основные параметры пакета
set(CPACK_PACKAGE_NAME "helloworld")
set(CPACK_PACKAGE_CONTACT "Your Name <youremail@example.com>")  # Укажите ваш контакт
set(CPACK_DEBIAN_PACKAGE_SECTION "base")
set(CPACK_DEBIAN_PACKAGE_PRIORITY "optional")
set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "amd64")
set(CPACK_DEBIAN_PACKAGE_DESCRIPTION "Hello World application")

# Определение генератора пакетов
set(CPACK_GENERATOR "DEB")

# Настройка CPack
include(CPack)

