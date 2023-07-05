NAME=libft.a

SRCS= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c\
ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c\
ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c\
ft_substr.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c\
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJS= $(SRCS:.c=.o)

B_SRC=  ft_lstadd_front.c \
			  ft_lstsize.c \
			  ft_lstlast.c \
		 	  ft_lstadd_back.c \
			  ft_lstnew.c		\
			  ft_lstdelone.c	\
			  ft_lstclear.c			
B_OBJ = $(B_SRC:.c=.o)

RM= rm -rf
CC = gcc
CFLAGS= -Wall -Werror -Wextra

all: $(NAME)


$(NAME): $(OBJS) 
	ar rc $(NAME) $(OBJS)


clean:
	$(RM) $(OBJS) 

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(B_OBJ) $(OBJ)
	ar rc $(NAME) $(B_OBJ) $(OBJ)

.PHONY: all clean fclean re bonus
