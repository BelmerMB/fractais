CFLAGS          = -g3 -O3 -Wall -Wextra -Werror

MLXFLAGS        = -lm -Imlx -Lmlx -lmlx -lXext -lX11

SRCS	= ./src/draw.c ./src/handle_keys.c ./src/window_init.c ./src/cal_func.c
all:
	cc ${CFLAGS} main.c ${SRCS}  ${MLXFLAGS}