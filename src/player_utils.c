/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:00:00 by osancak           #+#    #+#             */
/*   Updated: 2025/07/11 12:50:31 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_player_frames(void *mlx, void **frames)
{
	int	px;

	px = FT_PX;
	frames[0] = mlx_xpm_file_to_image(mlx, "res/ply/idle0.xpm", &px, &px);
	if (!frames[0])
		return (0);
	frames[1] = mlx_xpm_file_to_image(mlx, "res/ply/idle1.xpm", &px, &px);
	if (!frames[1])
		return (0);
	frames[2] = mlx_xpm_file_to_image(mlx, "res/ply/idle2.xpm", &px, &px);
	if (!frames[2])
		return (0);
	return (1);
}

void	destroy_player_frames(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		if (game->p_idle_frames[i])
			mlx_destroy_image(game->mlx, game->p_idle_frames[i]);
	}
}

void	*get_p_idle_frame(t_game *game)
{
	static int	current_index = 0;
	static int	call_counter = 0;
	void		*frame;

	frame = game->p_idle_frames[current_index];
	if (++call_counter >= 50)
	{
		call_counter = 0;
		current_index = (current_index + 1) % 3;
	}
	return (frame);
}
