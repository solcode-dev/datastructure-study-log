CC = clang
CFLAGS = -g -Wall -Wextra
TARGET = test_linked_list
SRCS = test_linked_list.c linked_list.c
OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: clean
