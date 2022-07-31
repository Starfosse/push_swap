SRC = main.c \
get_next_line_bonus.c \
get_next_line_utils_bonus.c \
push_swap_instruct3.c \
push_swap_instruct4.c \
do_instructs.c \
create_list.c \
clean_list.c \

CC = gcc

HEADER = checker.h

OBJ = $(SRC:%.c=./.build/%.o)

NAME = checker

RM = rm -rf

LIBC = ar -rc

CFLAGS = -Wall -Wextra -Werror

LIBFT = @printf "\n\t\t${B_CYAN}GENERATE libft library ...\n\n${NONE}" && cd ../libft && make --no-print-directory

# COLORS
NONE			= \033[0m
CL_LINE			= \033[2K
B_RED			= \033[1;31m
B_GREEN			= \033[1;32m
B_MAGENTA 		= \033[1;35m
B_CYAN 			= \033[1;36m

./.build/%.o : %.c
	@$(CC) ${CFLAGS} -I. -o $@ -c $?
	@printf "${B_MAGENTA}Compilling $? ...\n${NONE}"

all :
	@mkdir -p .build
	@make ${NAME}

${NAME} : $(OBJ)
	${LIBFT}
	@${CC} -o ${NAME} ${OBJ} ../libft/libft.a
	@printf "${B_GREEN}==>{${NAME}} LINKED SUCCESFULLY<==${NONE}\n"

clean :
	@${RM} .build
	@${RM} *.o
	@printf "${B_RED}XX{${NAME}} CLEANED SUCCESFULLY XX${NONE}\n"

fclean :	clean
	@cd ../libft && make fclean --no-print-directory
	@${RM} ${NAME}
	@${RM} *.o
	@printf "${B_RED}XX{${NAME}} FCLEAN SUCCESFULL XX${NONE}\n"

re :	fclean all
