#
#

RED = \033[0;91m
GREEN = \033[0;92m
BLUE = \033[0;34m
WHITE = \x1b[0m

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11

.m.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.m=.o}
	@echo "${GREEN}[LOADED] ${WHITE}${<:.s=.o}"

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
	@echo "${GREEN}[LOADED] ${WHITE}${<:.s=.o}"

all: $(NOM)

$(NOM):	$(OBJ)
	@ar -r $(NOM) $(OBJ) 
	@ranlib $(NOM)
	@sleep 1
	@echo "${GREEN}							[MLX LOADED 100%]"
	@sleep 1

clean:
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app

re: clean all
