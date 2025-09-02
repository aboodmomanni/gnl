# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# Source files (mandatory)
SRCS = get_next_line.c \
       get_next_line_utils.c

# Bonus source files (if you have bonus)
SRCS_BONUS = get_next_line_bonus.c \
             get_next_line_utils_bonus.c

# Object files
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

# Header files
HEADERS = get_next_line.h

# Dummy target (Francinette doesn't expect an executable)
all:
	@echo "get_next_line compiled successfully"

# Compile object files for testing
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -D BUFFER_SIZE=42 -c $< -o $@

# Bonus target
bonus: $(OBJS_BONUS)
	@echo "get_next_line bonus compiled successfully"

# Compile object files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	$(RM) $(OBJS)

# Clean everything
fclean: clean
	$(RM) $(NAME)

# Rebuild everything
re: fclean all

# Test with different buffer sizes
test: $(NAME)
	@echo "Testing with BUFFER_SIZE=1"
	@$(CC) $(CFLAGS) -D BUFFER_SIZE=1 $(SRCS) -o test_1
	@./test_1
	@echo "\nTesting with BUFFER_SIZE=42"
	@$(CC) $(CFLAGS) -D BUFFER_SIZE=42 $(SRCS) -o test_42
	@./test_42
	@echo "\nTesting with BUFFER_SIZE=1000"
	@$(CC) $(CFLAGS) -D BUFFER_SIZE=1000 $(SRCS) -o test_1000
	@./test_1000
	@$(RM) test_1 test_42 test_1000

# Test with stdin
test_stdin: $(NAME)
	@echo "Testing with stdin (type some lines, then Ctrl+D):"
	@$(CC) $(CFLAGS) -D BUFFER_SIZE=42 ft_get_next_line.c ft_utilities.c main_stdin.c -o test_stdin
	@./test_stdin
	@$(RM) test_stdin

# Debug version
debug: CFLAGS += -g -fsanitize=address
debug: $(NAME)

# Norminette check
norm:
	@echo "Checking norminette..."
	@norminette $(SRCS) $(HEADERS)

# Create test files
create_test_files:
	@echo "Line 1" > file.txt
	@echo "Line 2" >> file.txt
	@echo "Line 3" >> file.txt
	@echo "This is a longer line with more text" >> file.txt
	@echo "" >> file.txt
	@echo "Line after empty line" >> file.txt
	@echo "Created test file: file.txt"

# Phony targets
.PHONY: all clean fclean re test test_stdin debug norm create_test_files