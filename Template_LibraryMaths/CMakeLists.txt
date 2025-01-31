# CMakeList.txt : projet CMake pour Template_LibraryMaths, incluez la source et définissez
# la logique spécifique au projet ici.
#

# Ajoutez une source à l'exécutable de ce projet.
add_executable (Template_LibraryMaths "main.cpp" "List.h" "ListImpl.h" "Array.h" "Sort.h" "IntrusiveList.h" "ArrayImpl.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Template_LibraryMaths PROPERTY CXX_STANDARD 20)
endif()

# TODO: Ajoutez des tests et installez des cibles si nécessaire.
