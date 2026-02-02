SRC = src/philo.c src/ft_inputs.c src/ft_philos_init.c src/ft_simulation.c src/ft_time.c src/mutexes_utils.c src/utils.c

OBJ = $(SRC:.c=.o)

NAME = philo

CC = cc -Wall -Wextra -Werror

RM = rm -f

%.o: %.c include/philo.h
	$(CC) -c $< -Iinclude -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lpthread -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all