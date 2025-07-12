/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:00:00 by osancak           #+#    #+#             */
/*   Updated: 2025/07/12 20:17:39 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_ply_i_u_frames(void *mlx, void **i_f, void **u_f)
{
	int	px;

	px = FT_PX;
	i_f[0] = mlx_xpm_file_to_image(mlx, "textures/ply/idle0.xpm", &px, &px);
	i_f[1] = mlx_xpm_file_to_image(mlx, "textures/ply/idle1.xpm", &px, &px);
	i_f[2] = mlx_xpm_file_to_image(mlx, "textures/ply/idle2.xpm", &px, &px);
	u_f[0] = mlx_xpm_file_to_image(mlx, "textures/ply/u0.xpm", &px, &px);
	u_f[1] = mlx_xpm_file_to_image(mlx, "textures/ply/u1.xpm", &px, &px);
	u_f[2] = mlx_xpm_file_to_image(mlx, "textures/ply/u2.xpm", &px, &px);
	return (i_f[0] && i_f[1] && i_f[2] && u_f[0] && u_f[1] && u_f[2]);
}

int	init_ply_l_r_frames(void *mlx, void **l_f, void **r_f)
{
	int	px;

	px = FT_PX;
	l_f[0] = mlx_xpm_file_to_image(mlx, "textures/ply/l0.xpm", &px, &px);
	l_f[1] = mlx_xpm_file_to_image(mlx, "textures/ply/l1.xpm", &px, &px);
	l_f[2] = mlx_xpm_file_to_image(mlx, "textures/ply/l2.xpm", &px, &px);
	r_f[0] = mlx_xpm_file_to_image(mlx, "textures/ply/r0.xpm", &px, &px);
	r_f[1] = mlx_xpm_file_to_image(mlx, "textures/ply/r1.xpm", &px, &px);
	r_f[2] = mlx_xpm_file_to_image(mlx, "textures/ply/r2.xpm", &px, &px);
	return (l_f[0] && l_f[1] && l_f[2] && r_f[0] && r_f[1] && r_f[2]);
}

void	destroy_player_frames(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		if (game->ply_i_f[i])
			mlx_destroy_image(game->mlx, game->ply_i_f[i]);
		if (game->ply_l_f[i])
			mlx_destroy_image(game->mlx, game->ply_l_f[i]);
		if (game->ply_r_f[i])
			mlx_destroy_image(game->mlx, game->ply_r_f[i]);
		if (game->ply_u_f[i])
			mlx_destroy_image(game->mlx, game->ply_u_f[i]);
	}
}

void	*get_player_frame(t_game *game)
{
	static int	current_index = 0;
	static int	call_counter = 0;
	void		*frame;
	void		**frames;

	if (game->player.direction == DIR_LEFT)
		frames = game->ply_l_f;
	else if (game->player.direction == DIR_RIGHT)
		frames = game->ply_r_f;
	else if (game->player.direction == DIR_UP)
		frames = game->ply_u_f;
	else
		frames = game->ply_i_f;
	frame = frames[current_index];
	if (++call_counter >= 50)
	{
		call_counter = 0;
		current_index = (current_index + 1) % 3;
	}
	return (frame);
}
