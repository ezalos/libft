# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/12 15:04:16 by ldevelle          #+#    #+#              #
#    Updated: 2019/03/23 00:27:45 by ldevelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

DFLAGS = -Wall -Wextra -Werror -fsanitize=address,undefined -g3 -pedantic\
-ansi -O2 -Wchar-subscripts -Wcomment -Wformat=2 -Wimplicit-int\
-Werror-implicit-function-declaration -Wmain -Wparentheses -Wsequence-point\
-Wreturn-type -Wswitch -Wtrigraphs -Wunused -Wuninitialized -Wunknown-pragmas\
-Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast\
-Wwrite-strings -Wconversion -Wsign-compare -Waggregate-return\
-Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations\
-Wmissing-noreturn -Wformat -Wmissing-format-attribute\
-Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs\
-Winline -Wlong-long -Wunreachable-code

#CFLAGS = $(DFLAGS)

##############################################################################
##############################################################################
##																			##
##									----									##
##									IFEQ									##
##									----									##
##																			##
##############################################################################
##############################################################################


MAIN_FOLD = inout maths mem strings structures terminal

FT_H = libft.h

HEAD_DIR = ./includes

DIR_OBJ = ./objs/

update_head		=	$(MAIN_FOLD:%=sh scripts/get_protos.sh % srcs/;)
update_dep		=	$(MAIN_FOLD:%=sh scripts/get_mk_srcs.sh % srcs/;)
include_asrc	= 	$(MAIN_FOLD:%=./mk_dependencies/asrc_%.mk)
include_pat	=	$(MAIN_FOLD:%=./mk_dependencies/pat_%.mk)
include_src	=	$(MAIN_FOLD:%=./mk_dependencies/src_%.mk)

include_dep	= $(include_asrc) $(include_pat) $(include_src)

include $(include_dep)

SRC = $(SRC_in_out) $(SRC_maths) $(SRC_mem) $(SRC_strings) $(SRC_structures) $(SRC_terminal)
PAT = $(PAT_in_out) $(PAT_maths) $(PAT_mem) $(PAT_strings) $(PAT_structures) $(PAT_terminal)
DIR = $(DIR_in_out) $(DIR_maths) $(DIR_mem) $(DIR_strings) $(DIR_structures) $(DIR_terminal)
OBJS = $(SRC:%.c=%.o)

##########################
##						##
##	   ARCHITECTURE		##
##						##
##########################


##########################
##						##
##		 COLORS			##
##						##
##########################

RED     = \x1b[31m
GREEN   = \x1b[32m
YELLOW  = \x1b[33m
BLUE	= \x1b[34m
MAGENTA	= \x1b[35m
CYAN	= \x1b[36m
END     = \x1b[0m

COM_COLOR   = $(BLUE)
OBJ_COLOR   = $(CYAN)
OK_COLOR    = $(GREEN)
ERROR_COLOR = $(RED)
WARN_COLOR  = $(YELLOW)
NO_COLOR    = $(END)

OK_STRING    = [OK]
ERROR_STRING = [ERROR]
WARN_STRING  = [WARNING]
COM_STRING   = Compiling

define run_and_test
printf "%b" "$(COM_COLOR)$(COM_STRING) $(OBJ_COLOR)$(@F)$(NO_COLOR)\r"; \
	$(1) 2> $@.log; \
	RESULT=$$?; \
	if [ $$RESULT -ne 0 ]; then \
	printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"   ; \
	elif [ -s $@.log ]; then \
	printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(WARN_COLOR)$(WARN_STRING)$(NO_COLOR)\n"   ; \
	else  \
	printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"   ; \
	fi; \
	cat $@.log; \
	rm -f $@.log; \
	exit $$RESULT
endef

##############################################################################
##############################################################################
##																			##
##									-----									##
##									RULES									##
##									-----									##
##																			##
##############################################################################
##############################################################################

##########################
##						##
##		  BASIC			##
##						##
##########################

all :	$(NAME)
	@echo $(HEAD_DIR)
	@echo $@
	@echo $<

$(NAME):	$(OBJS) Makefile
	@echo $(HEAD_DIR)
	@echo $@
	@echo $<
			@$(call run_and_test, ar -rcs $(NAME) $(OBJS) -I$(HEAD_DIR))

$(DIR_OBJ)%.o:$(PAT)%.c
	@echo $(HEAD_DIR)
	@echo $@
	@echo $<
			@$(call run_and_test, $(CC) $(CFLAGS) -I$(HEAD_DIR) -o $@ -c $<)

clean :
	@rm -f $(OBJS) libft.h.gch
	@echo "\$(YELLOW)lib_objs \$(END)\\thas been \$(GREEN)\\t\\t\\t  $@\$(END)"

fclean : clean
	@rm -f $(NAME)
	@echo "\$(YELLOW)$(NAME) \$(END)\\thas been \$(GREEN)\\t\\t\\t  $@\$(END)"

re : fclean all

koko :
	@echo $(HEAD_DIR)
	#@echo $(SRCS)
	#@echo $(OBJS)

##############################################################################
##############################################################################
##																			##
##									-----									##
##									BONUS									##
##									-----									##
##																			##
##############################################################################
##############################################################################

order : fclean
ifneq ($(IFORDER), )
	@mkdir	$(MSRC_PATH) $(SRC_PATH1) $(SRC_PATH2) $(SRC_PATH3) objs\
			$(SRC_PATH4) $(SRC_PATH5) $(SRC_PATH6) $(SRC_PATH7) $(NHEAD_DIR)
	@mv -f $(HEAD_DIR)$(FT_H) $(NHEAD_DIR)
	@mv -f $(patsubst %, ft_%.c, $(SRCS1)) $(SRC_PATH1)
	@mv -f $(patsubst %, ft_%.c, $(SRCS2)) $(SRC_PATH2)
	@mv -f $(patsubst %, ft_%.c, $(SRCS3)) $(SRC_PATH3)
	@mv -f $(patsubst %, ft_%.c, $(SRCS4)) $(SRC_PATH4)
	@mv -f $(patsubst %, ft_%.c, $(SRCS5)) $(SRC_PATH5)
	@mv -f $(patsubst %, ft_%.c, $(SRCS6)) $(SRC_PATH6)
	@mv -f $(patsubst %, ft_%.c, $(SRCS7)) $(SRC_PATH7)
	@echo \$(GREEN) $(NAME) \$(END) Now in \$(MAGENTA)$@ mode \$(END)
endif

push : fclean
ifneq ($(IFPUSH), )
		@mv -f $(A_SRC) $(HEAD_DIR)/$(FT_H) $(SRC_PATH)
		@rm -rf $(MSRC_PATH) $(HEAD_DIR) objs
		@echo \$(GREEN) $(NAME) \$(END) Now in \$(MAGENTA)$@ mode \$(END)
endif

git :
		@git add -A
		@git status
		@git commit -am "Makefile automated push"
		@git push

file :
		@$(update_head)
		@$(update_dep)

check :
		bash /Users/ldevelle/42/TESTS/42FileChecker/42FileChecker.sh

##########################
##						##
##		 .PHONY			##
##						##
##########################

.PHONY : clean fclean re all a aclean afclean are f d order push git check
