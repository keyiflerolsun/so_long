/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 19:07:56 by osancak           #+#    #+#             */
/*   Updated: 2025/07/12 20:18:04 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_enemy(void *mlx, void **frames)
{
	int	px;

	px = FT_PX;
	frames[0] = mlx_xpm_file_to_image(mlx, "textures/enemy/enm0.xpm", &px, &px);
	frames[1] = mlx_xpm_file_to_image(mlx, "textures/enemy/enm1.xpm", &px, &px);
	frames[2] = mlx_xpm_file_to_image(mlx, "textures/enemy/enm2.xpm", &px, &px);
	return (frames[0] && frames[1] && frames[2]);
}

void	destroy_enemy(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		if (game->enemy[i])
			mlx_destroy_image(game->mlx, game->enemy[i]);
	}
}

void	*get_enemy_idle_frame(t_game *game)
{
	static int	current_index = 0;
	static int	call_counter = 0;
	static int	direction = 1;
	void		*frame;

	if (++call_counter >= 80)
	{
		call_counter = 0;
		current_index += direction;
		if (current_index == 2 || current_index == 0)
			direction *= -1;
	}
	frame = game->enemy[current_index];
	return (frame);
}
