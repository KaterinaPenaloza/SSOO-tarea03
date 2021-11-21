CXX=g++
RM=rm -f
TARGET=./main

DIR=src
CXXFLAGS=-std=c++17 -Wall -O2
LDFLAGS=-L/usr/local/lib 
LDLIBS=-lpthread



all: $(TARGET)
	@echo Made [ $? ] OK :\)


$(DIR)/main.o: $(DIR)/main.cpp


$(TARGET): $(DIR)/main.o
	@echo Linking [$@]
	@$(CXX) -o $@ $^ $(CXXFLAGS) $(LDLIBS) $(LDFLAGS) 

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