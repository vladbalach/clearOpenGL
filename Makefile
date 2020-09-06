FRAMEWORKS = -framework Cocoa\
	-framework OpenGL\
	-framework IOKit\
	-framework CoreVideo

INC = -I inc\
	-I inc/glad\
	-I inc/KHR
all:
	clang++ main.cpp glad.cpp libglfw3.a $(INC) $(FRAMEWORKS) 

