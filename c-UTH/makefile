TARGET=cpp2c_encapsulation

# all .cpp files in this directory are my sources
SOURCES=$(wildcard *.c)

OBJS=$(SOURCES:.c=.o)

INC_DIR=../include
CC=gcc
CFLAGS= -c -pedantic -Wall -Werror -Wconversion -ansi -g -I$(INC_DIR)
CXXFLAGS= $(CFLAGS)
LDFLAGS= -g

.PHONY: clean run gdb valgrind

$(TARGET): $(OBJS)

include .depends

.depends:
	$(CC) -MM -I$(INC_DIR) $(SOURCES) > .depends

clean:
	rm -f $(OBJS) $(TARGET) .depends

run: $(TARGET)
	./$(TARGET)

# Do not forget to add '-g' to CFLAGS
gdb: $(TARGET)
	gdb -q ./$(TARGET)
	
valgrind: $(TARGET)
	valgrind --leak-check=full ./$(TARGET)	
