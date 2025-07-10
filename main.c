/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 22:15:56 by osancak           #+#    #+#             */
/*   Updated: 2025/07/10 17:10:07 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	err_exit(const char *message, t_game *game)
{
	write(2, "\033[0;31m\033[1m[!] ERROR\t\033[0m\033[0;35m", 33);
	while (*message)
		write(2, message++, 1);
	write(2, "\033[0m\n", 5);
	if (game && game->map.full)
		free_map(&game->map);
	if (game && game->mlx)
	{
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game)
		free(game);
	exit(EXIT_FAILURE);
}

static int	game_close(t_game *game)
{
	free_map(&game->map);
	if (game->mlx)
	{
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
	}
	free(game->mlx);
	free(game);
	exit(EXIT_SUCCESS);
	return (1);
}

static int	key_hook(int keycode, void *param)
{
	(void)param;
	ft_printf("%s» Key : %s%d%s\n", MAGENTA, YELLOW, keycode, RESET);
	if (keycode == XK_Escape || keycode == XK_Q || keycode == XK_q)
		game_close(param);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		err_exit("Usage » ./so_long 'path/to/map/file.ber'", NULL);
	game = ft_calloc(sizeof(t_game), 1);
	if (!init_game(game, argv[1]))
		err_exit("Game initialization failed!", game);
	mahmut(game);
	if (!draw_walls(game))
		err_exit("res/wall/*.xpm", game);
	mlx_hook(game->win, DestroyNotify, ButtonPressMask, game_close, game);
	mlx_key_hook(game->win, key_hook, game);
	mlx_loop(game->mlx);
	return (0);
}
