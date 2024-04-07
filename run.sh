#!/bin/zsh


clang++ 5_task/test_scoped_pointer.cpp -o main -fsanitize=address -fsanitize=undefined -std=c++17 

# clang++ 6_task/test_matrix.cpp 6_task/matrix.cpp -o main -fsanitize=address -fsanitize=undefined -std=c++17 

# clang++ 7_task/test_expressions.cpp -o main -fsanitize=address -fsanitize=undefined -std=c++17 


# clang++ main.cpp -o main -fsanitize=address -fsanitize=undefined -std=c++17 



./main in.txt
rm main 