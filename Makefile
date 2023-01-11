# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 14:38:57 by gkehren           #+#    #+#              #
#    Updated: 2023/01/11 15:53:20 by gkehren          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES:=	main
FILES_T:= main_test tests/tests_map tests/tests_time tests/tests_vector tests/tests_stack tests/tests_set
NAME:= ft_containers
NAME_T:= ft_containers_tests

# ------------------
CC:=c++
SRCPATH:=sources/
HDRPATH:=
CCHPATH:=obj/
IFLAGS:=-I ${HDRPATH}
CFLAGS:=-Wall -Wextra -Werror -std=c++98
# ==================

# ----- Colors -----
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;35m"
PURPLE:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"
# ==================

# ------ Auto ------
SRC:=$(addprefix $(SRCPATH),$(addsuffix .cpp,$(FILES)))
OBJ:=$(addprefix $(CCHPATH),$(addsuffix .o,$(FILES)))
SRC_T:=$(addprefix $(SRCPATH),$(addsuffix .cpp,$(FILES_T)))
OBJ_T:=$(addprefix $(CCHPATH),$(addsuffix .o,$(FILES_T)))
# ==================

all: ${NAME}

${NAME}: ${OBJ} ${OBJ_T}
	@echo ${CYAN} " - Compiling $@" $(RED)
	@${CC} ${CFLAGS} ${SRC} -o ${NAME}
	@${CC} ${CFLAGS} ${SRC_T} -o ${NAME_T}
	@echo $(GREEN) " - OK" $(EOC)

${CCHPATH}%.o: ${SRCPATH}%.cpp
	@mkdir -p $(@D)
	@echo ${PURPLE} " - Compiling $< into $@" ${EOC}
	@${CC} ${CFLAGS} -c $< -o $@

%.cpp:
	@echo ${RED}"Missing file : $@" ${EOC}

clean:
	@rm -rf ${CCHPATH}

fclean:	clean
	@rm -f ${NAME} ${NAME_T}
	@rm -rf ${NAME}.dSYM/

re:	fclean
	@${MAKE} all

.PHONY:	all clean fclean re
