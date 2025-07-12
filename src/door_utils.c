/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 00:03:41 by osancak           #+#    #+#             */
/*   Updated: 2025/07/12 02:37:43 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_door(void *mlx, t_door *door)
{
	int	px;

	px = FT_PX;
	door->_c = mlx_xpm_file_to_image(mlx, "res/door/c.xpm", &px, &px);
	door->o_f[0] = mlx_xpm_file_to_image(mlx, "res/door/o0.xpm", &px, &px);
	door->o_f[1] = mlx_xpm_file_to_image(mlx, "res/door/o1.xpm", &px, &px);
	door->o_f[2] = mlx_xpm_file_to_image(mlx, "res/door/o2.xpm", &px, &px);
	return (door->_c && door->o_f[0] && door->o_f[1] && door->o_f[2]);
}

void	destroy_door(t_game *game)
{
	if (game->door._c)
		mlx_destroy_image(game->mlx, game->door._c);
	if (game->door.o_f[0])
		mlx_destroy_image(game->mlx, game->door.o_f[0]);
	if (game->door.o_f[1])
		mlx_destroy_image(game->mlx, game->door.o_f[1]);
	if (game->door.o_f[2])
		mlx_destroy_image(game->mlx, game->door.o_f[2]);
}

void	*get_door_frame(t_game *game)
{
	static int	frame_counter = 0;
	static int	animation_delay = 0;

	if (game->map.coins > 0)
		return (game->door._c);
	animation_delay++;
	if (animation_delay >= 80)
	{
		frame_counter = (frame_counter + 1) % 3;
		animation_delay = 0;
	}
	return (game->door.o_f[frame_counter]);
}
