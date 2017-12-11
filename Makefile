##
## Makefile for  in /home/siqual/igraph/runner
## 
## Made by Siqual
## Login   <siqual@8570p>
## 
## Started on  Tue Oct 31 10:05:14 2017 Siqual
## Last update Thu Nov  2 14:12:24 2017 Siqual
##

NAME		=	my_runner

CC		=	gcc

CFLAGS		=	-W -Wall -Werror -Wno-deprecated-declarations

LDFLAGS 	=	-L$(LIBS_DIR) -lc_graph_prog -lm

RM		=	rm -f

SRCS_DIR	=	src/
SRCS		=	$(addprefix $(SRCS_DIR), \
						main.c			\
						events_handling.c	\
						program_handling.c	\
						buffer_handling.c	\
						collision_handling.c	\
			)

OBJS_DIR	=	obj/
OBJS		=	$(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

INCS_DIR	=	inc/

LIBS_DIR	=	lib/

TMP		=	$(SRCS_DIR)*~ $(SRCS_DIR)\#*\#


all		:	$(NAME)

$(NAME)		:	$(OBJS)
			$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

$(OBJS_DIR)%.o	:	$(SRCS_DIR)%.c
			@mkdir -p $(dir $@)
			$(CC) -c $(CFLAGS) -I$(INCS_DIR) $< -o $@

clean		:
			$(RM) $(OBJS)
			$(RM) $(TMP)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all
