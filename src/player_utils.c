/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:00:00 by osancak           #+#    #+#             */
/*   Updated: 2025/07/11 11:00:00 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_player_idle_frames(t_game *game)
{
	int	px;

	px = FT_PX;
	game->player.idle_frames[0] = mlx_xpm_file_to_image(game->mlx, 
		"res/ply/idle1.xpm", &px, &px);
	if (!game->player.idle_frames[0])
		return (0);
	game->player.idle_frames[1] = mlx_xpm_file_to_image(game->mlx, 
		"res/ply/idle2.xpm", &px, &px);
	if (!game->player.idle_frames[1])
		return (0);
	game->player.idle_frames[2] = mlx_xpm_file_to_image(game->mlx, 
		"res/ply/idle3.xpm", &px, &px);
	if (!game->player.idle_frames[2])
		return (0);
	game->player.current_frame = 0;
	game->player.frame_counter = 0;
	return (1);
}

void	update_player_animation(t_game *game)
{
	game->player.frame_counter++;
	if (game->player.frame_counter >= 30)
	{
		game->player.frame_counter = 0;
		game->player.current_frame = (game->player.current_frame + 1) % 3;
	}
}

void	destroy_player_frames(t_game *game)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (game->player.idle_frames[i])
			mlx_destroy_image(game->mlx, game->player.idle_frames[i]);
		i++;
	}
}

void	*get_current_player_frame(t_game *game)
{
	return (game->player.idle_frames[game->player.current_frame]);
}
