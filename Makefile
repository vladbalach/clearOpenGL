FRAMEWORKS = -framework Cocoa\
	-framework OpenGL\
	-framework IOKit\
	-framework CoreVideo

all:
	clang++ main.cpp libGLEW.a libglfw3.a -I inc $(FRAMEWORKS) 

