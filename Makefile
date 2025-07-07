CFILES = main.c

OBJDIR = obj
OFILES = $(addprefix $(OBJDIR)/, $(CFILES:.c=.o))

NAME      = so_long
CC        = cc
CFLAGS    = -std=gnu11 -Wall -Wextra -Werror -Ilibft -Ift_printf -Iminilibx-linux -Iget_next_line -Isrc
MLX_FLAGS = -Lminilibx-linux -lmlx -lX11 -lXext -lm

MAKEFLAGS += --no-print-directory --silent
LIBFT      = libft/libft.a
PRINTF     = ft_printf/libftprintf.a
MLX        = minilibx-linux/libmlx_Linux.a
GNL        = get_next_line/get_next_line.a
SRC        = src/so_long.a

GREEN   = \033[0;32m
YELLOW  = \033[0;33m
BLUE    = \033[0;36m
RED     = \033[0;31m
MAGENTA = \033[0;35m
CYAN    = \033[0;36m
RESET   = \033[0m

all: $(NAME)

$(NAME): $(OFILES) $(SRC) $(GNL) $(MLX) $(PRINTF) $(LIBFT)
	@printf "$(GREEN)» 📦 Linking   $(RESET)» $(MAGENTA)./$(NAME)$(RESET)\n"
	@$(CC) $(CFLAGS) $(MLX_FLAGS) $(OFILES) $(SRC) $(GNL) $(MLX) $(PRINTF) $(LIBFT) -o $(NAME)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	@printf "$(BLUE)» ⚙️  Compiling $(RESET)» $(YELLOW)%9s$(RESET) | $(GREEN)%s$(RESET)\n" "$<" "$@"
	@$(CC) $(CFLAGS) -c $< -o $@

$(SRC): FORCE
	@$(MAKE) -C $(dir $@)

$(GNL): FORCE
	@$(MAKE) -C $(dir $@)

$(MLX): FORCE
	@$(MAKE) -C $(dir $@)

$(PRINTF): FORCE
	@$(MAKE) -C $(dir $@)

$(LIBFT): FORCE
	@$(MAKE) -C $(dir $@)

clean:
	@printf "$(RED)» 🧹 Cleaning  $(RESET)» $(CYAN)./$(OBJDIR) $(RESET)\n"
	@rm -rf $(OBJDIR)
	@$(MAKE) -C $(dir $(SRC)) clean
	@$(MAKE) -C $(dir $(GNL)) clean
	@$(MAKE) -C $(dir $(MLX)) clean
	@$(MAKE) -C $(dir $(PRINTF)) clean
	@$(MAKE) -C $(dir $(LIBFT)) clean

fclean: clean
	@printf "$(RED)» 🔥 Removing  $(RESET)» $(MAGENTA)./$(NAME)$(RESET)\n"
	@rm -f $(NAME)
	@$(MAKE) -C $(dir $(SRC)) fclean
	@$(MAKE) -C $(dir $(GNL)) fclean
	@$(MAKE) -C $(dir $(PRINTF)) fclean
	@$(MAKE) -C $(dir $(LIBFT)) fclean

re: fclean all

FORCE:
.PHONY: all clean fclean re FORCE
