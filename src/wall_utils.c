/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:41:05 by osancak           #+#    #+#             */
/*   Updated: 2025/07/11 11:30:45 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_w_u_d(void *mlx, t_wall *wall)
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

int	init_w_l_r(void *mlx, t_wall *wall)
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

void	destroy_walls(t_game *game)
{
	if (game->wall.block)
		mlx_destroy_image(game->mlx, game->wall.block);
	if (game->wall.up)
		mlx_destroy_image(game->mlx, game->wall.up);
	if (game->wall.u_lft)
		mlx_destroy_image(game->mlx, game->wall.u_lft);
	if (game->wall.u_rght)
		mlx_destroy_image(game->mlx, game->wall.u_rght);
	if (game->wall.down)
		mlx_destroy_image(game->mlx, game->wall.down);
	if (game->wall.d_lft)
		mlx_destroy_image(game->mlx, game->wall.d_lft);
	if (game->wall.d_rght)
		mlx_destroy_image(game->mlx, game->wall.d_rght);
	if (game->wall.left)
		mlx_destroy_image(game->mlx, game->wall.left);
	if (game->wall.right)
		mlx_destroy_image(game->mlx, game->wall.right);
}

void	*get_wall_image(t_game *game, int row, int col)
{
	if (row == 0)
	{
		if (col == 0)
			return (game->wall.u_lft);
		else if (col == (int)game->map.columns - 1)
			return (game->wall.u_rght);
		else
			return (game->wall.up);
	}
	else if (row == (int)game->map.rows - 1)
	{
		if (col == 0)
			return (game->wall.d_lft);
		else if (col == (int)game->map.columns - 1)
			return (game->wall.d_rght);
		else
			return (game->wall.down);
	}
	else if (col == 0)
		return (game->wall.left);
	else if (col == (int)game->map.columns - 1)
		return (game->wall.right);
	else
		return (game->wall.block);
}
