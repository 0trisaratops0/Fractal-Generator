CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Linker settings
LDFLAGS = -I MLX42/include/MLX42

# Source files and output executable
SRCS = input_utils.c input_parser.c utils.c mandelbrot.c color.c color_utils.c hooks.c main.c julia.c error.c burning_ship.c
OBJS = $(SRCS:.c=.o)
EXEC = fractal
MLXFLAGS = -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
MLXDIR = MLX42/
MLXLIB = $(MLXDIR)build/libmlx42.a

# Targets
%.o: %.c fractal.h
	@$(CC) $(CFLAGS) $(LDFLAGS) -c -o $@ $<

$(EXEC): $(OBJS)
	@echo "Compiling executable."
	@$(CC) $(MLXLIB) $(MLXFLAGS) $(CFLAGS) $(OBJS) -o $(EXEC)

$(MLXLIB):
	@echo "Compiling MLX library."
	@cmake -S $(MLXDIR) -B $(MLXDIR)build
	@make -C $(MLXDIR)build

clean:
	@echo "Cleaning files."
	@rm -f $(OBJS)

fclean: clean
	@echo "Cleaning executable."
	@rm -f $(EXEC)
	@echo "Cleaning MLX library."
# @rm -rf $(MLXDIR)build

re: fclean all

.PHONY: all clean fclean re
