/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:41:05 by osancak           #+#    #+#             */
/*   Updated: 2025/07/10 17:02:46 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
