#!/bin/zsh


clang++  8_task_new/file/FileRW.cpp 8_task_new/string/StringRW.cpp 8_task_new/tests/TestRW.cpp  -o main -fsanitize=address -fsanitize=undefined --std=c++17 


# clang++ main.cpp -o main -fsanitize=address -fsanitize=undefined -std=c++20 

./main in.txt
rm main 