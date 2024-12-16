CC := gcc
CFLAGS := -Wall -Werror -Wextra -g
AR := ar rcs
SRC := char_str.c numbers.c ft_printf.c
OBJ :=	$(SRC:.c=.o)
NAME:= libftprintf.a

$(NAME): $(OBJ)
	$(AR) $@ $^
	@echo "Libreria	$(NAME) compilata con successo."

%.o: %.c
	$(CC) -c $< $(CFLAGS) -o $@
clean:
	rm -f $(OBJ) $(BONUS_OBJ)
	@echo "File oggetto puliti."
fclean:	clean
	rm -f $(NAME)
	@echo "Libreria $(NAME) pulita."
re: fclean $(NAME)
all: $(NAME)

.PHONY: all clean fclean re
