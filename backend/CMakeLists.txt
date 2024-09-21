# backend/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(my_backend)

set(CMAKE_CXX_STANDARD 17)

# Включение использования VCPKG
if(DEFINED ENV{VCPKG_ROOT})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
endif()

# Найти библиотеки PostgreSQL, Boost и crow
find_package(PostgreSQL REQUIRED)
find_package(Boost REQUIRED COMPONENTS system)
find_package(Crow CONFIG REQUIRED)
find_package(PQXX REQUIRED)

# Указать пути для включения заголовочных файлов
include_directories(${PostgreSQL_INCLUDE_DIRS})
include_directories(${Boost_INCLUDE_DIRS})
include_directories(${CROW_INCLUDE_DIRS})
include_directories(${PQXX_INCLUDE_DIRS})

# Скомпоновать исполняемый файл
add_executable(my_backend main.cpp Database.cpp endpoints.cpp)
target_link_libraries(my_backend ${PostgreSQL_LIBRARIES} ${Boost_LIBRARIES} Crow::Crow pqxx)