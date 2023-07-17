# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glodi <glodi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/11 18:34:10 by gpeta             #+#    #+#              #
#    Updated: 2023/07/14 17:00:32 by glodi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		:= server
NAME2 		:= client

#-------------------------------------------------------#
#	INGREDIENTS											#
#-------------------------------------------------------#

LIBS		:= ft
LIBS_TARGET := \
lib/libft/libft.a \


INCS		:= \
include \
lib/libft/include \


SRC_DIR		:= src
SRCS		:= \
server.c \
error.c \

SRCS2		:= \
client.c \
error.c \

# list.c \
list_utils.c \
print.c \


SRCS		:= $(SRCS:%=$(SRC_DIR)/%)
SRCS2		:= $(SRCS2:%=$(SRC_DIR)/%)

BUILD_DIR	:= .build
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
OBJS2		:= $(SRCS2:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)
DEPS2		:= $(OBJS2:.o=.d)

CC 			:= cc
# CFLAGS 		:= -Wall -Wextra -Werror 
CFLAGS 		:= -Wextra -Werror 
CPPFLAG		:= $(addprefix -I ,$(INCS)) -MMD -MP
LDFLAGS		:= $(addprefix -L ,$(dir $(LIBS_TARGET)))
LDLIBS		:= $(addprefix -l ,$(LIBS))
NORMINETTE	:=	norminette

#-------------------------------------------------------#
#	UTENSILS											#
#-------------------------------------------------------#

RM			:= rm -f
MAKEFLAGS	+= --silent --no-print-directory
DIR_DUP		= mkdir -p $(@D)

#-------------------------------------------------------#
#	RECIPES												#
#-------------------------------------------------------#

all : $(NAME) $(NAME2)

$(NAME): $(OBJS) $(LIBS_TARGET)
	$(CC) -g $(LDFLAGS) $(OBJS) $(LDLIBS) $(MLX_FLAGS) -o $(NAME)
	$(info EXE ./$(NAME) CREATED)
#	$(CC) -g $(LDFLAGS) $(OBJS) $(LDLIBS) $(MLX_FLAGS) -o $(NAME)

$(NAME2): $(OBJS2) $(LIBS_TARGET)
	$(CC) -g $(LDFLAGS) $(OBJS2) $(LDLIBS) -o $(NAME2)
	$(info EXE ./$(NAME2) CREATED)
#	$(CC) -g $(LDFLAGS) $(OBJS2) $(LDLIBS) $(MLX_FLAGS) -o $(NAME2)

$(LIBS_TARGET):
	$(MAKE) -C $(@D)

# compilation des *.c en *.o sans linker
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAG) -ggdb -c -o $@ $<

clean:
	for f in $(dir $(LIBS_TARGET)) ; do $(MAKE) -C $$f clean; done
	$(RM) $(OBJS) $(DEPS)
	$(RM) $(OBJS2) $(DEPS2)

fclean: clean
	for f in $(strip(dir $(LIBS_TARGET))) ; do $(MAKE) -C $$f fclean; done
	$(RM) $(NAME)
	$(RM) $(NAME2)

re:
	$(MAKE) fclean
	$(MAKE) all

# ************************************* #
#				PUSH_SWAP				#
# ************************************* #

.PHONY: all clean fclean re
.SILENT:

###############################################
##	NORMINETTE : COLORMINETTE (@VEGRET)

RED          =    \033[0;91m
LIGHT_RED    =    \033[0;31m
GREEN        =    \033[0;92m

norminette:
	@$(NORMINETTE) | grep -v Norme | awk '{\
	if ($$NF == "OK!") { \
	    print "$(GREEN)"$$0"$(END)" \
	} else if ($$NF == "Error!") { \
	    print "$(RED)$(BOLD)"$$0"$(END)" \
	} else if ($$1 == "Error:") { \
	    print "$(LIGHT_RED)"$$0"$(END)" \
	} else { print }}'

###############################################
##	NORMINETTE : verif norminette (@VEGRET)

norm_verif:
	nm $(NAME)