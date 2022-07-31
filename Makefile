SRC = main.c \
push_swap_instruct.c \
push_swap_instruct2.c \
push_swap.c \
lis.c \
push_swap_utils.c \
separate.c \
check.c \
push_swap_utils2.c \
save_pos.c \
choice.c \
push.c \
little.c \
clean.c \
little2.c \
push_swap2.c \

CC = gcc

HEADER = push_swap.h

OBJ = $(SRC:%.c=./.build/%.o)

NAME = push_swap

RM = rm -rf

LIBC = ar -rc

CFLAGS = -Wall -Wextra -Werror

LIBFT = @printf "\n\t\t${B_CYAN}GENERATE libft library ...\n\n${NONE}" && cd libft && make --no-print-directory

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
	@make ${NAME} --no-print-directory

${NAME} : $(OBJ)
	${LIBFT}
	@${CC} -o ${NAME} ${OBJ} ./libft/libft.a
	@printf "${B_GREEN}==>{${NAME}} LINKED SUCCESFULLY<==${NONE}\n"

bonus :
	@cd checker_prog && make --no-print-directory && cp checker ../

clean :
	@${RM} .build
	@cd checker_prog && make clean --no-print-directory
	@printf "${B_RED}XX{${NAME}} CLEANED SUCCESFULLY XX${NONE}\n"

fclean :	clean
	@${RM} ${NAME}
	@cd checker_prog && make fclean --no-print-directory
	@cd libft && make fclean --no-print-directory
	@${RM} checker
	@printf "${B_RED}XX{${NAME}} FCLEAN SUCCESFULL XX${NONE}\n"

re :	fclean all
