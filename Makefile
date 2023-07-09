NAME = regextest

SOURCES = main.cpp \
			FtRegex.cpp

OBJECTS = ${SOURCES:.cpp=.o}

CFLAGS = -Wall -Wextra -Werror -std=c++98

CC = c++

.cpp.o:
	${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o}

$(NAME): ${OBJECTS}
	${CC} ${CFLAGS} ${SOURCES} -o ${NAME}

all: $(NAME)

clean:
	rm -f ${OBJECTS}

fclean: clean
	rm -rf ${NAME}

re : fclean all

.PHONY: all clean fclean re