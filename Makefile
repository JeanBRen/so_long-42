
CC = gcc

CFLAGS= -Wextra -Werror -Wall

NAME = so_long

#=============================================================
#							SOURCES
#=============================================================


#########################    DIRECTORY     ###################
SRC_DIR = ./sources/

KEY_DIR = key_bind/

INIT_DIR = init/

GNL_DIR = GNL/

CLEAN_DIR = cleaning/

END_DIR = endgame/

MAP_DIR = check_map/

RENDER_DIR = render/

#######################     FILES MANDATORY ##################

GNL_FILES = get_next_line.c get_next_line_utils.c 

INIT_FILES = init_map.c init_player.c init_win.c init_images.c

CLEAN_FILES = clean_map.c clean_images.c

END_FILES = win.c

KEY_FILES = moove.c close_win.c

MAP_FILES = check_map.c flood_fill.c

RENDER_FILES = render_game.c

SRCS_FILES = so_long.c 

SRCS = $(addprefix $(SRC_DIR), $(SRCS_FILES) $(addprefix $(KEY_DIR), $(KEY_FILES)) \
	$(addprefix $(GNL_DIR), $(GNL_FILES)) $(addprefix $(INIT_DIR), $(INIT_FILES)) \
	$(addprefix $(MAP_DIR), $(MAP_FILES)) $(addprefix $(CLEAN_DIR), $(CLEAN_FILES))\
	$(addprefix $(END_DIR), $(END_FILES)) $(addprefix $(RENDER_DIR), $(RENDER_FILES)))

#####################            BONUS      #############################################

SRC_DIR_BONUS = ./sources_bonus/

GNL_FILES_BONUS = get_next_line.c get_next_line_utils.c 

INIT_FILES_BONUS = init_map.c init_player.c init_win.c init_images.c\
	init_enemies.c init_score.c init_coin.c init_idle.c init_all.c

CLEAN_FILES_BONUS = clean_map.c clean_images.c clean_enemies.c clean_score.c clean_coins.c

END_FILES_BONUS = win.c loose.c

KEY_FILES_BONUS = moove.c close_win.c

MAP_FILES_BONUS = check_map.c flood_fill.c

RENDER_FILES_BONUS = render_game.c render_player.c render_enemies.c render_score.c render_coins.c

SRCS_FILES_BONUS = so_long_bonus.c 

SRCS_BONUS = $(addprefix $(SRC_DIR_BONUS), $(SRCS_FILES_BONUS) $(addprefix $(KEY_DIR), $(KEY_FILES_BONUS)) \
	$(addprefix $(GNL_DIR), $(GNL_FILES_BONUS)) $(addprefix $(INIT_DIR), $(INIT_FILES_BONUS)) \
	$(addprefix $(MAP_DIR), $(MAP_FILES_BONUS)) $(addprefix $(CLEAN_DIR), $(CLEAN_FILES_BONUS))\
	$(addprefix $(END_DIR), $(END_FILES_BONUS)) $(addprefix $(RENDER_DIR), $(RENDER_FILES_BONUS)))


#========================================================================================
#
#========================================================================================
INCLUDE = -I includes

MAKE = make -C

MLX_PATH = /home/jrenier/minilibx-linux/

MLX = -L $(MLX_PATH) 

LIBFT_PATH = libft

LIBFT = -L $(LIBFT_PATH) -lft 

OBJS = $(SRCS:.c=.o)
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

$(NAME) : $(OBJS)
	$(MAKE) $(LIBFT_PATH) all
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -L$(MLX_PATH) -lmlx_Linux -L/usr/lib -I$(MLX_PATH) -lXext -lX11 -lm -lz -o $(NAME)
	@clear
	@toilet -d ~/ -f A --gay --termwidth Welcome to $(NAME)

all : $(NAME)

clean :
	$(MAKE) $(LIBFT_PATH) clean
	rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
	${MAKE} ${LIBFT_PATH} fclean
	rm -f $(NAME)
	@clear
	@toilet -d ~/ -f A --gay --termwidth ALL CLEANED

re : fclean all

bonus : $(OBJS_BONUS)
	$(MAKE) $(LIBFT_PATH) all
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -L$(MLX_PATH) -lmlx_Linux -L/usr/lib -I$(MLX_PATH) -lXext -lX11 -lm -lz -o $(NAME)
	@clear
	@toilet -d ~/ -f A --gay --termwidth $(NAME) BONUS

.PHONY: all clean fclean re coffee


















coffee:
	@clear
	@echo ""
	@echo "                   ("
	@echo "	                     )     ("
	@echo "               ___...(-------)-....___"
	@echo '           .-""       )    (          ""-.'
	@echo "      .-''''|-._             )         _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |                             |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'
	@sleep 0.5
	@clear
	@echo ""
	@echo "                 ("
	@echo "	                  )      ("
	@echo "               ___..(.------)--....___"
	@echo '           .-""       )   (           ""-.'
	@echo "      .-''''|-._      (       )        _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |                             |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'
	@sleep 0.5
	@clear
	@echo ""
	@echo "               ("
	@echo "	                  )     ("
	@echo "               ___..(.------)--....___"
	@echo '           .-""      )    (           ""-.'
	@echo "      .-''''|-._      (       )        _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |                             |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'
	@sleep 0.5
	@clear
	@echo ""
	@echo "             (         ) "
	@echo "	              )        ("
	@echo "               ___)...----)----....___"
	@echo '           .-""      )    (           ""-.'
	@echo "      .-''''|-._      (       )        _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |                             |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'