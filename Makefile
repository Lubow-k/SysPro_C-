CC=g++

# FLAGS=
FLAGS= -std=c++20 -fsanitize=address -fsanitize=leak -fsanitize=undefined

MAIN=main.cpp
SOURCE=scoped_pointer.cpp
OBJECTS=$(SOURCE:.cpp=.o)
EXECUTABLE=main

TEST=test_lines.cpp
EXTEST=test

base: $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o $(EXECUTABLE) 

main.o:
	$(CC) $(FLAGS) -c main.cpp

AVL.o:
	$(CC) $(FLAGS) -c AVL.cpp

lines.o:
	$(CC) $(FLAGS) -c lines.cpp

scoped_pointer.o:
	$(CC) $(FLAGS) -c scoped_pointer.cpp

run:
	./$(EXECUTABLE) 


test:
	$(CC) $(TEST) $(SOURCE) -o $(EXTEST) -lgtest -lgmock -pthread
	./$(EXTEST)
	rm $(EXTEST)
   

clean:
	rm -rf *.o $(EXECUTABLE)



# memory: 
# 	clang++ $(OBJECTS) -o $(EXECUTABLE) -fsanitize=memory 

# thread:
# 	clang++ $(OBJECTS) -o $(EXECUTABLE) -fsanitize=thread
