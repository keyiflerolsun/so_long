CFILES = read_map.c \
		 map_utils.c \
		 flood_fill.c \
		 init_game.c \
		 wall_utils.c \
		 gem_utils.c \
		 player_utils.c \
		 move_utils.c \
		 door_utils.c \
		 enemy_utils.c \
		 text_utils.c \
		 render.c

OBJDIR = obj
OFILES = $(addprefix $(OBJDIR)/, $(CFILES:.c=.o))

NAME   = so_long.a
CC     = cc
CFLAGS = -std=c11 -Wall -Wextra -Werror -I../libft -I../ft_printf -I../minilibx-linux -I../get_next_line

GREEN   = \033[0;32m
YELLOW  = \033[0;33m
BLUE    = \033[0;36m
RED     = \033[0;31m
MAGENTA = \033[0;35m
CYAN    = \033[0;36m
RESET   = \033[0m

all: $(NAME)

$(NAME): $(OFILES)
	@printf "$(GREEN)» 📦 Creating  $(RESET)» $(MAGENTA)$(notdir $(CURDIR))/$(NAME)$(RESET)\n"
	@ar -rcs $(NAME) $(OFILES)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	@printf "$(BLUE)» ⚙️  Compiling $(RESET)» $(YELLOW)%14s$(RESET) | $(GREEN)%s$(RESET)\n" "$<" "$@"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@printf "$(RED)» 🧹 Cleaning  $(RESET)» $(CYAN)$(notdir $(CURDIR))/$(OBJDIR) $(RESET)\n"
	@rm -rf $(OBJDIR)

fclean: clean
	@printf "$(RED)» 🔥 Removing  $(RESET)» $(MAGENTA)$(notdir $(CURDIR))/$(NAME)$(RESET)\n"
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
