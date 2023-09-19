cmake_minimum_required(VERSION 3.25)
project(Lab_di_Programmazione_Francesca_Sani)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

add_subdirectory(test)

set(SOURCE_FILES Lista.cpp Lista.h Utente.cpp Utente.h Observer.h Subject.h Articolo.h)
add_executable(Lab_di_Programmazione_Francesca_Sani main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(Lab_di_Programmazione_Francesca_Sani core)
