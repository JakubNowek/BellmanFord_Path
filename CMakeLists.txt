# CMakeList.txt: projekt CMake dla elementu P2_Bellman, dołącz źródło i zdefiniuj
# tutaj logikę specyficzną dla projektu.
#
cmake_minimum_required (VERSION 3.8)

project ("P2_Bellman")
include_directories(inc)
file(GLOB SOURCE "src/*.cpp" "inc/*.hpp" "inc/*.h")
# Dodaj źródło do pliku wykonywalnego tego projektu.
add_executable( ${PROJECT_NAME} ${SOURCE} )

# TODO: Dodaj testy i zainstaluj elementy docelowe w razie potrzeby.
