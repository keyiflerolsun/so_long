/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:15:52 by osancak           #+#    #+#             */
/*   Updated: 2025/07/11 13:12:35 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			if (map[row][col] == '1')
				img = get_wall_image(game, row, col);
			else if (map[row][col] == 'C')
				img = get_gem_idle_frame(game);
			else if (map[row][col] == 'P')
				img = get_p_idle_frame(game);
			else
				img = NULL;
			if (img)
				mlx_put_image_to_window(game->mlx, game->win, img, col * FT_PX,
					row * FT_PX);
		}
	}
}

int	init_images(t_game *game)
{
	if (
		init_gem(game->mlx, game->gem_idle_frames)
		&& init_player_frames(game->mlx, game->p_idle_frames)
		&& init_u_d(game->mlx, &game->wall)
		&& init_l_r(game->mlx, &game->wall)
	)
		return (1);
	destroy_walls(game);
	destroy_gem(game);
	destroy_player_frames(game);
	return (0);
}

int	render(t_game *game)
{
	put_images(game);
	return (1);
}
