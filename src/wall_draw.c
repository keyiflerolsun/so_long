/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:15:52 by osancak           #+#    #+#             */
/*   Updated: 2025/07/10 17:17:43 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	init_u_d(void *mlx, t_wall *wall)
{
	int	px;

	px = FT_PX;
	wall->up = mlx_xpm_file_to_image(mlx, "res/wall/up.xpm", &px, &px);
	if (!wall->up)
		return (0);
	wall->u_lft = mlx_xpm_file_to_image(mlx, "res/wall/u_lft.xpm", &px, &px);
	if (!wall->u_lft)
		return (0);
	wall->u_rght = mlx_xpm_file_to_image(mlx, "res/wall/u_rght.xpm", &px, &px);
	if (!wall->u_rght)
		return (0);
	wall->down = mlx_xpm_file_to_image(mlx, "res/wall/down.xpm", &px, &px);
	if (!wall->down)
		return (0);
	wall->d_lft = mlx_xpm_file_to_image(mlx, "res/wall/d_lft.xpm", &px, &px);
	if (!wall->d_lft)
		return (0);
	wall->d_rght = mlx_xpm_file_to_image(mlx, "res/wall/d_rght.xpm", &px, &px);
	if (!wall->d_rght)
		return (0);
	return (1);
}

static int	init_l_r(void *mlx, t_wall *wall)
{
	int	px;

	px = FT_PX;
	wall->block = mlx_xpm_file_to_image(mlx, "res/wall/block.xpm", &px, &px);
	if (!wall->block)
		return (0);
	wall->left = mlx_xpm_file_to_image(mlx, "res/wall/left.xpm", &px, &px);
	if (!wall->left)
		return (0);
	wall->right = mlx_xpm_file_to_image(mlx, "res/wall/right.xpm", &px, &px);
	if (!wall->right)
		return (0);
	return (1);
}

static void	put_walls(t_game *game)
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
			{
				img = get_wall_image(game, row, col);
				mlx_put_image_to_window(game->mlx, game->win, img, col * FT_PX,
					row * FT_PX);
			}
		}
	}
}

int	draw_walls(t_game *game)
{
	int	res;

	res = 1;
	if (init_u_d(game->mlx, &game->wall) && init_l_r(game->mlx, &game->wall))
		put_walls(game);
	else
		res = 0;
	destroy_walls(game);
	return (res);
}
