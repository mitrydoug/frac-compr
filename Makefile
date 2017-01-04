# Makefile for this entire project

CC       := g++ # This is the main compiler
# CC       := clang --analyze # and comment out the linker last line for sanity
SRCDIR   := src
BUILDDIR := build
TARGET   := bin/frac

TESTER_SRC := test/tester.cpp
TESTER     := bin/tester

SRCEXT  := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

CFLAGS := -g -Wall -Werror # -O3

LIB := -L/usr/local/boost_1_63_0/stage/lib -lboost_program_options
INC := -I include

$(TARGET): $(OBJECTS)
	@echo " Linking..."
	@echo " $(CC) $^ -o $(TARGET) $(LIB)"; $(CC) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning..."; 
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)

# Tests
tester:
	$(CC) $(CFLAGS) $(TESTER_SRC) $(INC) $(LIB) -o $(TESTER)

.PHONY: clean
