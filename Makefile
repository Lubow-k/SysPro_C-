SOURCE=AVL.cpp
EXECUTABLE=avl

base: $(SOURCE)
	clang++ $(SOURCE) -o $(EXECUTABLE) 

sanitize:
	clang++ $(SOURCE) -o $(EXECUTABLE) -fsanitize=address -fsanitize=leak -fsanitize=undefined

memory: 
	clang++ $(SOURCE) -o $(EXECUTABLE) -fsanitize=memory -fsanitize=thread

clean:
	rm $(EXECUTABLE)