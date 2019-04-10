# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/12 15:04:16 by ldevelle          #+#    #+#              #
#    Updated: 2019/04/10 22:52:02 by ldevelle         ###   ########.fr        #
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

MASTER		= srcs/

MAIN_FOLD = inout maths mem strings structures terminal big files

HEAD_DIR = ./includes/

HEADERS	=	$(AUTO_HEAD)\
			auto.h\
			ft_printf.h\
			libft.h\
			time_exe.h

DIR_OBJ = ./objs/

##########################
##						##
##	   ARCHITECTURE		##
##						##
##########################

AUTO_HEAD	= $(MAIN_FOLD:%=auto/auto_%.h)


HEADERS		=	$(HEADS:%=$(HEAD_DIR)%)

update_head	=	$(MAIN_FOLD:%=sh scripts/get_protos.sh % $(MASTER);)
update_dep	=	$(MAIN_FOLD:%=sh scripts/get_mk_srcs.sh % $(MASTER);)

mk			=	./mk_dependencies

mk_d		= 	$(mk)/DIR/
mk_s		= 	$(mk)/SRC/
mk_p		= 	$(mk)/PAT/

include_dir	=	$(MAIN_FOLD:%=$(mk_d)dir_%.mk)
include_pat	=	$(MAIN_FOLD:%=$(mk_p)pat_%.mk)
include_src	=	$(MAIN_FOLD:%=$(mk_s)src_%.mk)

include_dep	= $(include_src) $(include_pat) $(include_dir)

SRC =
PAT =
DIR =

include $(include_dep)

OBJ = $(PAT:%.c=%.o)
OBJS = $(PAT:$(MASTER)%.c=$(DIR_OBJ)%.o)

MSG ?= Makefile automated push
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

all :		$(NAME)

$(NAME):	Makefile $(HEAD) $(OBJS)
			@$(call run_and_test, ar -rcs $(NAME) $(OBJS))

$(DIR_OBJ)%.o:$(MASTER)%.c
			@$(call run_and_test, $(CC) $(CFLAGS) -I$(HEAD_DIR) -o $@ -c $<)

clean :
	@rm -f $(OBJS)
	@echo "\$(YELLOW)$(NAME) objs \$(END)\\thas been \$(GREEN)\\t\\t\\t  $@\$(END)"

fclean : clean
	@rm -f $(NAME)
	@echo "\$(YELLOW)$(NAME) \$(END)\\thas been \$(GREEN)\\t\\t\\t  $@\$(END)"

re : fclean all

##############################################################################
##############################################################################
##																			##
##									-----									##
##									BONUS									##
##									-----									##
##																			##
##############################################################################
##############################################################################

t	:	all
		$(CC) $(CFLAGS) -I$(HEAD_DIR) $(NAME) main.c -o test.out
		./test.out "$(MSG)"

git :
		@git add -A
		@git status
		git commit -am "$(MSG)"
		@git push


file :	object_ready
		@rm -rf $(mk_d) $(mk_s) $(mk_p)
		@mkdir $(mk_d) $(mk_s) $(mk_p)
		@$(update_head)
		$(update_dep)
		@sh scripts/get_master_head.sh $(HEAD_DIR)


object_ready :
				@rm -rf $(DIR_OBJ)/*
				@find $(MASTER) -type d -exec mkdir objs/{} \;
				@mv -f $(DIR_OBJ)$(MASTER)/* $(DIR_OBJ)
				@rm -rf $(DIR_OBJ)$(MASTER)

check :
		bash /Users/ldevelle/42/TESTS/42FileChecker/42FileChecker.sh

FORCE:

##########################
##						##
##		 .PHONY			##
##						##
##########################

.PHONY : all clean fclean re git file object_ready check FORCE
