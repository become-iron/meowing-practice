add_executable(Sorting test.cpp)

target_include_directories(Sorting PUBLIC "helpers" "qsort" "bubble" "selection" "merge")
