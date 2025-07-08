/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:54:39 by osancak           #+#    #+#             */
/*   Updated: 2025/07/08 22:27:11 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_player(t_player *player)
{
	player->x = 0;
	player->y = 0;
	player->step = 0;
	player->score = 0;
}

static void	init_map(t_map *map)
{
	int	x;
	int	y;

	map->rows = 0;
	map->columns = ft_strlen((map->full)[0]);
	map->coins = 0;
	map->exit = 0;
	map->players = 0;
	x = -1;
	while ((map->full)[++x])
	{
		map->rows += 1;
		y = -1;
		while ((map->full)[x][++y])
		{
			if ((map->full)[x][y] == 'E')
				map->exit += 1;
			if ((map->full)[x][y] == 'C')
				map->coins += 1;
			if ((map->full)[x][y] == 'P')
				map->players += 1;
		}
	}
}

int	init_game(t_game *game, char *map_path)
{
	int	i;

	game->map = ft_calloc(sizeof(t_map), 1);
	read_map(game, map_path);
	ft_printf("\n%s%s[~] Map is Loading..%s\n\n", YELLOW, BOLD, RESET);
	init_map(game->map);
	if (!validate_map_elements(game->map))
		err_exit("map elements validation failed", game);
	i = -1;
	while ((game->map->full)[++i])
		ft_printf("%s%s%s\n", BLUE, (game->map->full)[i], RESET);
	ft_printf("\n");
	game->mlx = mlx_init();
	if (!(game->mlx))
		return (0);
	game->win = mlx_new_window(game->mlx, 600, 300, "Cokomelli Pencere");
	if (!(game->win))
		return (0);
	game->player = ft_calloc(sizeof(t_player), 1);
	init_player(game->player);
	return (1);
}
