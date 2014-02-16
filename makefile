CC = g++
CPPFLAGS = -std=c++11 -fopenmp
INCLUDE = -I/opt/local/include
LIBS = -L/opt/local/lib
LDFLAGS = -lboost_program_options-mt -lboost_filesystem-mt -lboost_system-mt
TARGET = Nucleation

COMPILE = $(CC) $(CPPFLAGS) -c $(INCLUDE)
LINK = $(CC) $(CPPFLAGS) $(INCLUDE)

all: $(TARGET)

$(TARGET):	main.o nucleation.o potential.o transfer_matrix_functions.o transfer_matrix.o
	@echo "<**Linking**> $@"
	@$(LINK) main.o nucleation.o potential.o transfer_matrix_functions.o transfer_matrix.o $(LIBS) $(LDFLAGS) -o $(TARGET)

main.o: main.cpp
	@echo "<**Compiling**> $^"
	@$(COMPILE) $<

nucleation.o: nucleation.cpp
	@echo "<**Compiling**> $^"
	@$(COMPILE) $<

potential.o: potential.cpp
	@echo "<**Compiling**> $^"
	@$(COMPILE) $<
                
transfer_matrix_functions.o: transfer_matrix_functions.cpp
	@echo "<**Compiling**> $^"
	@$(COMPILE) $<

transfer_matrix.o: transfer_matrix.cpp
	@echo "<**Compiling**> $^"
	@$(COMPILE) $<

dna.o: dna.cpp
	@echo "<**Compiling**> $^"
	@$(COMPILE) $<
        
mathematical_functions.o: mathematical_functions.cpp
	@echo "<**Compiling**> $^"
	@$(COMPILE) $<

clean:
	@rm -f $(TARGET) *.o