CXX=g++
RM=rm -f
TARGET=./main

DIR=src
DIROBJ=obj
INC=-I.src/inc -I.
CXXFLAGS=-std=c++17 -Wall -O2
LDFLAGS=-L/usr/local/lib 
LDLIBS=-lpthread



all: $(TARGET)
	@echo Made [ $? ] OK :\)


$(DIR)/$(DIROBJ)/main.o: $(DIR)/main.cpp


$(TARGET): $(DIR)/$(DIROBJ)/main.o
	@echo Linking [$@]
	@$(CXX) -o $@ $^ $(CXXFLAGS) $(LDLIBS) $(LDFLAGS) $(INC)

%.o: %.cpp
	@echo Compiling [$@]

	@$(CXX) -c -o $@ $< 

clean:
	@$(RM) *.o *exe
	@$(RM) *~ core

distclean: clean
	@$(RM) $(TARGET)
	@$(RM) -r $(DIR_OBJ)

.PHONY: all clean distclean
