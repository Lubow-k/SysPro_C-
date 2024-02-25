SOURCE=main.cpp AVL.cpp
OBJECTS=$(SOURCE:.cpp=.o)
EXECUTABLE=main

TEST=test_AVL.cpp
EXTEST=test

base: $(OBJECTS)
	clang++ $(OBJECTS) -o $(EXECUTABLE) 

main.o:
	clang++ -c main.cpp

AVL.o:
	clang++ -c AVL.cpp


sanitize:
	clang++ $(OBJECTS) -o $(EXECUTABLE) -fsanitize=address -fsanitize=leak -fsanitize=undefined

memory: 
	clang++ $(OBJECTS) -o $(EXECUTABLE) -fsanitize=memory 

thread:
	clang++ $(OBJECTS) -o $(EXECUTABLE) -fsanitize=thread

run:
	./$(EXECUTABLE) 


test:
	clang++ $(TEST) -o $(EXTEST) -lgtest -lgmock -pthread
	./$(EXTEST)
	rm $(EXTEST)
   

clean:
	rm $(EXECUTABLE)