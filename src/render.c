/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:15:52 by osancak           #+#    #+#             */
/*   Updated: 2025/07/12 20:01:01 by osancak          ###   ########.fr       */
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
		return (get_player_frame(game));
	else if (tile == 'E')
		return (get_door_frame(game));
	else if (tile == '~')
		return (get_door_player_frame(game));
	else if (tile == 'X')
		return (get_enemy_idle_frame(game));
	return (NULL);
}

static int	init_all_assets(t_game *game)
{
	if (!init_gem(game->mlx, game->gem_i_f))
		return (0);
	if (!init_ply_i_u_frames(game->mlx, game->ply_i_f, game->ply_u_f))
		return (0);
	if (!init_ply_l_r_frames(game->mlx, game->ply_l_f, game->ply_r_f))
		return (0);
	if (!init_door(game->mlx, &game->door))
		return (0);
	if (!init_w_u_d(game->mlx, &game->wall))
		return (0);
	if (!init_w_l_r(game->mlx, &game->wall))
		return (0);
	if (!init_enemy(game->mlx, game->enemy))
		return (0);
	return (1);
}

int	init_images(t_game *game)
{
	if (init_all_assets(game))
		return (1);
	destroy_walls(game);
	destroy_gem(game);
	destroy_player_frames(game);
	destroy_door(game);
	destroy_enemy(game);
	return (0);
}

int	render(t_game *game)
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
				mlx_put_image_to_window(game->mlx, game->win, img, col * FT_PX,
					row * FT_PX);
		}
	}
	draw_step(game);
	return (1);
}
