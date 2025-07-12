/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:41:05 by osancak           #+#    #+#             */
/*   Updated: 2025/07/12 20:23:25 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_w_u_d(void *mlx, t_wall *wall)
{
	int	px;

	px = FT_PX;
	wall->up = mlx_xpm_file_to_image(mlx, "textures/wall/up.xpm", &px, &px);
	wall->u_l = mlx_xpm_file_to_image(mlx, "textures/wall/u_l.xpm", &px, &px);
	wall->u_r = mlx_xpm_file_to_image(mlx, "textures/wall/u_r.xpm", &px, &px);
	wall->down = mlx_xpm_file_to_image(mlx, "textures/wall/down.xpm", &px, &px);
	wall->d_l = mlx_xpm_file_to_image(mlx, "textures/wall/d_l.xpm", &px, &px);
	wall->d_r = mlx_xpm_file_to_image(mlx, "textures/wall/d_r.xpm", &px, &px);
	return (
		wall->up && wall->u_l && wall->u_r
		&& wall->down && wall->d_l && wall->d_r
	);
}

int	init_w_l_r(void *mlx, t_wall *wall)
{
	int	px;

	px = FT_PX;
	wall->blck = mlx_xpm_file_to_image(mlx, "textures/wall/blck.xpm", &px, &px);
	wall->left = mlx_xpm_file_to_image(mlx, "textures/wall/left.xpm", &px, &px);
	wall->rght = mlx_xpm_file_to_image(mlx, "textures/wall/rght.xpm", &px, &px);
	return (wall->blck && wall->left && wall->rght);
}

void	destroy_walls(t_game *game)
{
	if (game->wall.blck)
		mlx_destroy_image(game->mlx, game->wall.blck);
	if (game->wall.up)
		mlx_destroy_image(game->mlx, game->wall.up);
	if (game->wall.u_l)
		mlx_destroy_image(game->mlx, game->wall.u_l);
	if (game->wall.u_r)
		mlx_destroy_image(game->mlx, game->wall.u_r);
	if (game->wall.down)
		mlx_destroy_image(game->mlx, game->wall.down);
	if (game->wall.d_l)
		mlx_destroy_image(game->mlx, game->wall.d_l);
	if (game->wall.d_r)
		mlx_destroy_image(game->mlx, game->wall.d_r);
	if (game->wall.left)
		mlx_destroy_image(game->mlx, game->wall.left);
	if (game->wall.rght)
		mlx_destroy_image(game->mlx, game->wall.rght);
}

void	*get_wall_image(t_game *game, int row, int col)
{
	if (row == 0)
	{
		if (col == 0)
			return (game->wall.u_l);
		else if (col == (int)game->map.columns - 1)
			return (game->wall.u_r);
		else
			return (game->wall.up);
	}
	else if (row == (int)game->map.rows - 1)
	{
		if (col == 0)
			return (game->wall.d_l);
		else if (col == (int)game->map.columns - 1)
			return (game->wall.d_r);
		else
			return (game->wall.down);
	}
	else if (col == 0)
		return (game->wall.left);
	else if (col == (int)game->map.columns - 1)
		return (game->wall.rght);
	else
		return (game->wall.blck);
}
