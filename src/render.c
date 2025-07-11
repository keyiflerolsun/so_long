/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:15:52 by osancak           #+#    #+#             */
/*   Updated: 2025/07/12 02:38:24 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*get_tile_image(t_game *game, char tile, int row, int col)
{
	if (tile == '1')
		return (get_wall_image(game, row, col));
	else if (tile == 'C')
		return (get_gem_idle_frame(game));
	else if (tile == 'P')
		return (get_p_idle_frame(game));
	else if (tile == 'E')
		return (get_door_frame(game));
	return (NULL);
}

static void	put_images(t_game *game)
{
	char	**map;
	int		row;
	int		col;
	void	*img;

	map = game->map.full;
	row = -1;
	while (map[++row])
	{
		col = -1;
		while (map[row][++col])
		{
			img = get_tile_image(game, map[row][col], row, col);
			if (img)
				mlx_put_image_to_window(game->mlx, game->win,
					img, col * FT_PX, row * FT_PX);
		}
	}
}

static int	init_all_assets(t_game *game)
{
	return (init_gem(game->mlx, game->gem_idle_frames)
		&& init_player_frames(game->mlx, game->p_idle_frames)
		&& init_door(game->mlx, &game->door)
		&& init_u_d(game->mlx, &game->wall)
		&& init_l_r(game->mlx, &game->wall));
}

int	init_images(t_game *game)
{
	if (init_all_assets(game))
		return (1);
	destroy_walls(game);
	destroy_gem(game);
	destroy_player_frames(game);
	destroy_door(game);
	return (0);
}

int	render(t_game *game)
{
	put_images(game);
	return (1);
}
