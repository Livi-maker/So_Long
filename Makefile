NAME = so_long

MY_SOURCES = $(wildcard *.c)

MY_OBJECTS = $(MY_SOURCES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

INCLUDE = -Ilibft -Iminilibx-linux  -I/usr/include

LIBFLAGS = -Lminilibx-linux -lmlx -Llibft -lft -L/usr/lib -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	make -C libft
	make -C minilibx-linux
	$(CC) $(MY_OBJECTS) $(LIBFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	rm -f $(MY_OBJECTS)
	make clean -C libft
	make clean -C minilibx-linux

fclean:
	rm -f $(MY_OBJECTS) $(NAME)
	make fclean -C libft

re: fclean $(NAME)

