CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g
TARGET = webserver
SRCS = server.c


all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)
	@echo "Cleaned project files."

.PHONY: all clean
