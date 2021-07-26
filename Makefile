.SUFFIXES:

CC = clang
CFLAGS = -std=c11 -O2 -g -Wall -Wextra -Wpedantic -Wstrict-aliasing \
		 -Wno-pointer-arith -Wno-newline-eof -Wno-unused-parameter -Wno-gnu-statement-expression \
		 -Wno-gnu-compound-literal-initializer -Wno-gnu-zero-variadic-macro-arguments 

OUTDIR = ./bin
SRCDIR = ./src

TARGET = typing_test
SRC = $(wildcard ./src/*.c)
OBJS = $(SRC:.c=.o)

all: dirs $(TARGET) clean

$(TARGET): $(OBJS) 
	$(CC) -o $(OUTDIR)/$@ $^

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

dirs:
	mkdir -p $(OUTDIR)

run:
	@cd ./bin && $(TARGET)
	
clean:
	rm $(OBJS)
