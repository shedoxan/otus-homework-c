cmake_minimum_required(VERSION 3.10)
project(helloworld VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)

add_executable(helloworld helloworld.cpp)

# Установка цели для установки исполняемого файла
install(TARGETS helloworld DESTINATION bin)

# Настройка CPack
include(CPack)

# Определение генератора пакетов
set(CPACK_GENERATOR "DEB")

# Основные параметры пакета
set(CPACK_PACKAGE_NAME "helloworld")
set(CPACK_PACKAGE_VERSION "0.0.${GITHUB_RUN_NUMBER}")
set(CPACK_PACKAGE_CONTACT "Your Name <youremail@example.com>")
set(CPACK_DEBIAN_PACKAGE_SECTION "base")
set(CPACK_DEBIAN_PACKAGE_PRIORITY "optional")
set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "amd64")
set(CPACK_DEBIAN_PACKAGE_DESCRIPTION "Hello World application")

# Использование переменной окружения для версии пакета
if(DEFINED ENV{GITHUB_RUN_NUMBER})
    set(CPACK_PACKAGE_VERSION_PATCH "$ENV{GITHUB_RUN_NUMBER}")
endif()

include(CPack)
