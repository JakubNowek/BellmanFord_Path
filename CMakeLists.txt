# CMakeList.txt: projekt CMake dla elementu P2_Bellman, dołącz źródło i zdefiniuj
# tutaj logikę specyficzną dla projektu.
#
cmake_minimum_required (VERSION 3.8)

project ("P2_Bellman")

# Dodaj źródło do pliku wykonywalnego tego projektu.
add_executable (P2_Bellman "P2_Bellman.cpp" "P2_Bellman.h" "vector.cpp" "bellmanford.cpp" "bellmanford.hpp" "graph.hpp" "graph_list.cpp" "graph_list.hpp" "graph_matrix.cpp" "graph_matrix.hpp" "vector.hpp"     )

# TODO: Dodaj testy i zainstaluj elementy docelowe w razie potrzeby.
