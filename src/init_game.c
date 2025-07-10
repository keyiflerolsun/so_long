/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:54:39 by osancak           #+#    #+#             */
/*   Updated: 2025/07/10 16:54:53 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_player(t_player *player, t_map *map, int row, int column)
{
	map->players += 1;
	player->row = row;
	player->column = column;
	player->step = 0;
	player->score = 0;
}

static void	map_check(t_game *game)
{
	int	w;
	int	h;

	if (game->map.players != 1)
		err_exit("Map must have exactly 1 player (P)", game);
	if (game->map.exit != 1)
		err_exit("Map must have exactly 1 exit (E)", game);
	if (game->map.coins < 1)
		err_exit("Map must have at least 1 coin (C)", game);
	if (!fill_check(&game->map, &game->player))
		err_exit("Map not Playable", game);
	game->ui_x = game->map.columns * 64;
	game->ui_y = game->map.rows * 64;
	mlx_get_screen_size(game->mlx, &w, &h);
	if (game->ui_x > (size_t)w || game->ui_y > (size_t)h)
		err_exit("Map is bigger than your screen", game);
}

static void	init_map(t_game *game, t_map *map, t_player *player)
{
	int	row;
	int	column;

	map->rows = 0;
	map->columns = ft_strlen((map->full)[0]);
	map->coins = 0;
	map->exit = 0;
	map->players = 0;
	row = -1;
	while ((map->full)[++row])
	{
		map->rows += 1;
		column = -1;
		while ((map->full)[row][++column])
		{
			if ((map->full)[row][column] == 'E')
				map->exit += 1;
			if ((map->full)[row][column] == 'C')
				map->coins += 1;
			if ((map->full)[row][column] == 'P')
				init_player(player, map, row, column);
		}
	}
	map_check(game);
}

int	init_game(t_game *game, char *map_path)
{
	int	i;

	read_map(game, map_path);
	ft_printf("\n%s%s[~] Map Initializing..%s\n\n", YELLOW, BOLD, RESET);
	game->mlx = mlx_init();
	if (!(game->mlx))
		return (0);
	init_map(game, &game->map, &game->player);
	i = -1;
	while ((game->map.full)[++i])
		ft_printf("%s%s%s\n", BLUE, (game->map.full)[i], RESET);
	ft_printf("\n");
	game->win = mlx_new_window(game->mlx, game->ui_x, game->ui_y, UI_TITLE);
	if (!(game->win))
		return (0);
	return (1);
}
