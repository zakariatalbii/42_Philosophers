SRC = philo.c ft_inputs.c ft_philos_init.c ft_simulation.c ft_time.c mutexes_utils.c utils.c

OBJ = $(SRC:.c=.o)

NAME = philo

CC = cc -Wall -Wextra -Werror -g -fsanitize=thread 
RM = rm -f

%.o: %.c philo.h
	$(CC) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lpthread -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
