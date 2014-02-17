CC = g++
CPPFLAGS = -std=c++11 -fopenmp
INCLUDE = -I/opt/local/include
LIBS = -L/opt/local/lib
LDFLAGS = -lboost_program_options-mt -lboost_filesystem-mt -lboost_system-mt
TARGET = Nucleation

COMPILE = $(CC) $(CPPFLAGS) -c $(INCLUDE)
LINK = $(CC) $(CPPFLAGS) $(INCLUDE)

VPATH = src
OBJ_DIR = obj
SOURCE_FILES = main.cpp nucleation.cpp potential.cpp transfer_matrix_functions.cpp transfer_matrix.cpp
OBJECT_FILES = $(SOURCE_FILES:%.cpp=%.o)
OBJS = $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SOURCE_FILES))

all: $(TARGET)

$(TARGET):	$(OBJS)
	@echo "<***Linking***> \t $@"
	@$(LINK) $^ $(LIBS) $(LDFLAGS) -o $(TARGET)

$(OBJ_DIR)/%.o : %.cpp | mkdir_obj
	@echo "<**Compiling**> \t $^ -> $@"
	@$(COMPILE) $^ -o $@

mkdir_obj:
	@mkdir -p $(OBJ_DIR)
	
clean:
	@rm -rf $(TARGET) $(OBJS) $(OBJ_DIR)

variables:
	@echo
	@echo "source files:\t $(SOURCE_FILES)"
	@echo "object files:\t $(OBJECT_FILES)"
	@echo "objects:\t $(OBJS)"
	@echo
