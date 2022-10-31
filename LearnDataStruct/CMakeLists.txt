# CMakeList.txt : CMake project for LearnDataStruct, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (LearnDataStruct "LearnDataStruct.cpp" "LearnDataStruct.h" "vector.h" "arrayList.h" "linearList.h" "illegalParameterValue.h")
add_executable (LearnVector "LearnVector.cpp" "vector.h")

# TODO: Add tests and install targets if needed.
