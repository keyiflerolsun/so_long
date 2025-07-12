/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 00:03:41 by osancak           #+#    #+#             */
/*   Updated: 2025/07/12 20:17:55 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_door(void *mlx, t_door *door)
{
	int	px;

	px = FT_PX;
	door->cls = mlx_xpm_file_to_image(mlx, "textures/door/c.xpm", &px, &px);
	door->o_f[0] = mlx_xpm_file_to_image(mlx, "textures/door/o0.xpm", &px, &px);
	door->o_f[1] = mlx_xpm_file_to_image(mlx, "textures/door/o1.xpm", &px, &px);
	door->o_f[2] = mlx_xpm_file_to_image(mlx, "textures/door/o2.xpm", &px, &px);
	door->d_i = mlx_xpm_file_to_image(mlx, "textures/d_p/d_i.xpm", &px, &px);
	door->d_l = mlx_xpm_file_to_image(mlx, "textures/d_p/d_l.xpm", &px, &px);
	door->d_r = mlx_xpm_file_to_image(mlx, "textures/d_p/d_r.xpm", &px, &px);
	door->d_u = mlx_xpm_file_to_image(mlx, "textures/d_p/d_u.xpm", &px, &px);
	return (
		door->cls && door->o_f[0] && door->o_f[1] && door->o_f[2]
		&& door->d_i && door->d_l && door->d_r && door->d_u
	);
}

void	destroy_door(t_game *game)
{
	if (game->door.cls)
		mlx_destroy_image(game->mlx, game->door.cls);
	if (game->door.o_f[0])
		mlx_destroy_image(game->mlx, game->door.o_f[0]);
	if (game->door.o_f[1])
		mlx_destroy_image(game->mlx, game->door.o_f[1]);
	if (game->door.o_f[2])
		mlx_destroy_image(game->mlx, game->door.o_f[2]);
	if (game->door.d_i)
		mlx_destroy_image(game->mlx, game->door.d_i);
	if (game->door.d_l)
		mlx_destroy_image(game->mlx, game->door.d_l);
	if (game->door.d_r)
		mlx_destroy_image(game->mlx, game->door.d_r);
	if (game->door.d_u)
		mlx_destroy_image(game->mlx, game->door.d_u);
}

void	*get_door_player_frame(t_game *game)
{
	void	*res;

	if (game->player.direction == DIR_LEFT)
		res = game->door.d_l;
	else if (game->player.direction == DIR_RIGHT)
		res = game->door.d_r;
	else if (game->player.direction == DIR_UP)
		res = game->door.d_u;
	else
		res = game->door.d_i;
	return (res);
}

void	*get_door_frame(t_game *game)
{
	static int	frame_counter = 0;
	static int	animation_delay = 0;

	if (game->map.coins > 0)
		return (game->door.cls);
	animation_delay++;
	if (animation_delay >= 80)
	{
		frame_counter = (frame_counter + 1) % 3;
		animation_delay = 0;
	}
	return (game->door.o_f[frame_counter]);
}
