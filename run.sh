#!/bin/zsh


clang++ 8_task/file/FileSource.cpp 8_task/file/FileSourceBuffer.cpp 8_task/string/StringSourceBuffer.cpp  8_task/string/StringSource.cpp main.cpp -o main -fsanitize=address -fsanitize=undefined --std=c++17 


# clang++ main.cpp -o main -fsanitize=address -fsanitize=undefined -std=c++17 



./main in.txt
rm main 