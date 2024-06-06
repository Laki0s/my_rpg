##
## EPITECH PROJECT, 2023
## header*
## File description:
## lolm
##

SRC     =   src/main.c                                         	        \
            src/shape.c                                        	        \
            src/action/action.c                                	        \
            src/str_function/my_strdup.c                       	        \
            src/str_function/my_strcmp.c                       	        \
            src/str_function/my_strcpy.c                       	        \
            src/str_function/my_strlen.c                       	        \
            src/str_function/str_to_double.c                   	        \
            src/str_function/my_strcat.c                       	        \
            src/animation/animation.c                          	        \
            src/gestion_button/button.c                        	        \
            src/gestion/game/main.c                            	        \
            src/gestion/intro/main.c                           	        \
            src/gestion/loading/main.c                         	        \
            src/gestion/menu/main.c                            	        \
            src/gestion/lobby/main.c                           	        \
            src/gestion/setting/main.c                         	        \
            src/gestion/setting/binding.c                      	        \
            src/gestion/setting/binding2.c                     	        \
            src/gestion/setting/gameplay.c                     	        \
            src/gestion/setting/sound.c                        	        \
            src/gestion/setting/video.c                        	        \
            src/gestion/setting/video2.c                       	        \
            src/gestion/choose_perso/main.c                    	        \
            src/str_function/my_str_to_word_array.c            	        \
            src/get_backup.c                                   	        \
            src/gestion/game/scenes/s1.c                              	\
            src/gestion/game/scenes/s2.c                              	\
            src/gestion/game/scenes/s3.c                              	\
            src/gestion/game/scenes/s4.c                              	\
            src/gestion/game/scenes/s5.c                              	\
            src/gestion/game/scenes/s6.c                              	\
            src/gestion/game/scenes/s7.c                              	\
            src/gestion/game/scenes/s8.c                              	\
            src/gestion/game/scenes/s9.c                              	\
            src/gestion/game/scenes/s10.c                             	\
            src/gestion/game/scenes/s11.c                             	\
            src/gestion/game/scenes/s12.c                             	\
            src/gestion/game/scenes/s13.c                             	\
            src/gestion/game/scenes/s14.c                             	\
            src/gestion/game/scenes/s15.c                             	\
			src/gestion/game/characters.c						        \
            src/gestion/game/bullet.c                                   \
            src/gestion/game/scenes/init_scene.c                        \
            src/gestion/game/test_entity.c                              \
            src/gestion/game/mobs/poop_mob.c                            \
            src/gestion/game/animation.c                                \
            src/gestion/option.c                                        \
            src/invotory.c                                              \
            src/gestion/game/mobs/tear.c                                \
            src/gestion/game/mobs/bat.c                                 \
            src/gestion/game/mobs/bat2.c                                \
            src/gestion/game/mobs/slime.c                               \
            src/gestion/game/mobs/boul.c                                \
            src/gestion/game/mobs/b1.c                                  \
            src/gestion/game/mobs/b2.c                                  \
            src/gestion/game/mobs/b3.c                                  \
            src/gestion/game/mobs/b4.c                                  \

OBJ		=	$(SRC:.c=.o)
NAME	=	myrpg

CC		=	gcc
CFLAGS	=	-Wextra -Wall -W -I ./include/ -lm -g
CSFML	=	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(CSFML)

clean:
	rm -f *.c~ $(OBJ)

fclean: clean
	rm -f $(NAME)

test: 	make
		./myrpg

push: fclean
	@read -p "gitmoji : " g;		\
	read -p "commit : " c;	 		\
	git add *; 						\
	git commit -m "[ :$$g: ] : $$c";	\
	git push

re: fclean all

.PHONY: all clean fclean re debug
