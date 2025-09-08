NAME = so_long

MY_SOURCES = $(wildcard *.c)

MY_OBJECTS = $(MY_SOURCES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

INCLUDE = -Ilibft -I/usr/include

LIBFLAGS = -Llibft -lft -L/usr/lib

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	make -C libft
	$(CC) $(MY_OBJECTS) $(LIBFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	rm -f $(MY_OBJECTS)
	make clean -C libft

fclean:
	rm -f $(MY_OBJECTS) $(NAME)
	make fclean -C libft

re: fclean $(NAME)

