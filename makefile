CC = g++
CPPFLAGS = -std=c++11 -fopenmp
INCLUDE = -I/opt/local/include
LIBS = -L/opt/local/lib
LDFLAGS = -lboost_program_options-mt -lboost_filesystem-mt -lboost_system-mt
TARGET = Nucleation

SOURCE_DIR = src/
OBJ_DIR = /obj

SOURCES = main.cpp nucleation.cpp potential.cpp transfer_matrix_functions.cpp transfer_matrix.cpp
OBJECTS = $(SOURCES:%.cpp=%.o)

COMPILE = $(CC) $(CPPFLAGS) -c $(INCLUDE)
LINK = $(CC) $(CPPFLAGS) $(INCLUDE)

all: $(SOURCES) $(TARGET)

$(TARGET):	$(OBJECTS)
	@echo "<**Linking**> $@"
	@$(LINK) $(OBJECTS) $(LIBS) $(LDFLAGS) -o $(TARGET)

%.o: %.cpp
	@echo "<**Compiling**> $^"
	@$(COMPILE) $< -o $@

clean:
	@rm -f $(TARGET) $(OBJECTS)