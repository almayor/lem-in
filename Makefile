# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: unite <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/05 18:17:42 by unite             #+#    #+#              #
#    Updated: 2020/09/10 04:58:04 by unite            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Lem_in

SRC_NAME = \
array/array_append.c \
array/array_delete.c \
array/array_get.c \
array/array_grow.c \
array/array_indexof.c \
array/array_insertion_sort.c \
array/array_new.c \
array/array_quick_sort.c \
array/array_shrink.c \
array/array_size.c \
array/array_swap.c \
farm/farm_delete.c \
farm/farm_parse.c \
farm/farm_parse_links.c \
farm/farm_parse_nants.c \
farm/farm_parse_rooms.c \
farm/farm_run.c \
farm/farm_search.c \
graph/graph_add_edge.c \
graph/graph_adjacency.c \
graph/graph_delete.c \
graph/graph_new.c \
list/list_add.c \
list/list_delete.c \
list/list_new.c \
queue/queue_delete.c \
queue/queue_dequeue.c \
queue/queue_enqueue.c \
queue/queue_new.c \
queue/queue_size.c \
stdin/stdin_delete.c \
stdin/stdin_new.c \
stdin/stdin_next.c \
stdin/stdin_peek.c \
utils/ft_xcalloc.c \
utils/ft_xmalloc.c \
utils/is_comment.c \
utils/is_coord.c \
utils/is_end.c \
utils/is_link.c \
utils/is_nants.c \
utils/is_room.c \
utils/is_start.c \
utils/tab_delete.c \
utils/tab_len.c \
utils/terminate.c \
main.c \

################################################################################

PATHS = src
PATHO = obj
PATHI = include libftprintfgnl

TEST_PATH = test
TEST_PATHS = $(TEST_PATH)/src
TEST_PATHO = $(TEST_PATH)/obj
TEST_PATHI = $(TEST_PATH)/src/Unity

################################################################################

CC = gcc
RM = rm
MKDIR = /bin/mkdir

################################################################################

COMPILE = $(CC) -c
CFLAGS += -Werror
CFLAGS += -O3 -std=gnu11 -ffast-math -march=native
CFLAGS += -MMD
CFLAGS += $(foreach path, $(PATHI) $(TEST_PATHI), -I$(path))

LINK = $(CC)
LFLAGS += -lftprintfgnl -L libftprintfgnl

################################################################################

ifeq ($(DEBUG), 1) 
	COMPILE += -g
endif

################################################################################

SRC = $(patsubst %.c, $(PATHS)/%.c, $(SRC_NAME))
OBJ = $(patsubst %.c, $(PATHO)/%.o, $(SRC_NAME))

TEST_SRC = $(patsubst %.c, $(TEST_PATHS)/%.c, $(TEST_SRC_NAME))
TEST_OBJ = $(patsubst %.c, $(TEST_PATHO)/%.o, $(TEST_SRC_NAME))

TEST_BIN = $(TEST_PATH)/$(TEST_NAME)

################################################################################

$(NAME) : $(OBJ)
	$(LINK) $^ -o $@ $(LFLAGS)

$(TEST_BIN) : $(TEST_OBJ) $(OBJ)
	$(LINK) $^ -o $@ $(LFLAGS)

################################################################################

$(PATHO)/%.o : $(PATHS)/%.c
	$(MKDIR) -p $(@D)
	$(COMPILE) $(CFLAGS) $< -o $@

$(TEST_PATHO)/%.o : $(TEST_PATHS)/%.c
	$(MKDIR) -p $(@D)
	$(COMPILE) $(CFLAGS) $< -o $@

################################################################################

DEP += $(patsubst %.c, $(PATHO)/%.d, $(SRC_NAME))
DEP += $(patsubst %.c, $(TEST_PATHO)/%.d, $(TEST_SRC_NAME))

-include $(DEP)

################################################################################

.DEFAULT_GOAL = all

.PHONY : all clean fclean re test docs libftprintfgnl

all : libftprintfgnl $(NAME)

fclean : clean
	$(RM) -f $(NAME)

clean :
	$(RM) -rf $(PATHO)
# 	$(RM) -rf $(TEST_PATHO)
# 	$(RM) -f $(TEST_BIN)
	$(MAKE) -C libftprintfgnl fclean

re : fclean all

test: all $(TEST_BIN)
	./$(TEST_BIN)

docs :
	sh docs/.doxygen/42toDoxygen.sh

libftprintfgnl :
	$(MAKE) -C libftprintfgnl

################################################################################

