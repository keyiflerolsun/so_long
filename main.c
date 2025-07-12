/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 22:15:56 by osancak           #+#    #+#             */
/*   Updated: 2025/07/12 20:24:18 by osancak          ###   ########.fr       */
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

static int	game_loop(t_game *game)
{
	usleep(2000);
	mlx_clear_window(game->mlx, game->win);
	if (!render(game))
		err_exit("textures/*/*.xpm", game);
	return (1);
}

int	game_close(t_game *game)
{
	free_map(&game->map);
	destroy_walls(game);
	destroy_gem(game);
	destroy_player_frames(game);
	destroy_door(game);
	destroy_enemy(game);
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

static int	key_hook(int keycode, t_game *game)
{
	if (keycode == XK_q || keycode == XK_Escape)
		game_close(game);
	if (keycode == XK_w || keycode == XK_Up)
	{
		game->player.direction = DIR_UP;
		move_player(game, game->player.row - 1, game->player.column);
	}
	else if (keycode == XK_s || keycode == XK_Down)
	{
		game->player.direction = DIR_DOWN;
		move_player(game, game->player.row + 1, game->player.column);
	}
	else if (keycode == XK_a || keycode == XK_Left)
	{
		game->player.direction = DIR_LEFT;
		move_player(game, game->player.row, game->player.column - 1);
	}
	else if (keycode == XK_d || keycode == XK_Right)
	{
		game->player.direction = DIR_RIGHT;
		move_player(game, game->player.row, game->player.column + 1);
	}
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
	mlx_hook(game->win, DestroyNotify, KeyPressMask, game_close, game);
	mlx_key_hook(game->win, key_hook, game);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_loop(game->mlx);
	return (0);
}
