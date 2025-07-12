/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 10:03:56 by osancak           #+#    #+#             */
/*   Updated: 2025/07/11 13:11:35 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_gem(void *mlx, void **frames)
{
	int	px;

	px = FT_PX;
	frames[0] = mlx_xpm_file_to_image(mlx, "res/gem/egg0.xpm", &px, &px);
	if (!frames[0])
		return (0);
	frames[1] = mlx_xpm_file_to_image(mlx, "res/gem/egg1.xpm", &px, &px);
	if (!frames[1])
		return (0);
	frames[2] = mlx_xpm_file_to_image(mlx, "res/gem/egg2.xpm", &px, &px);
	if (!frames[2])
		return (0);
	frames[3] = mlx_xpm_file_to_image(mlx, "res/gem/egg3.xpm", &px, &px);
	if (!frames[3])
		return (0);
	return (1);
}

void	destroy_gem(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (game->gem_i_f[i])
			mlx_destroy_image(game->mlx, game->gem_i_f[i]);
	}
}

void	*get_gem_idle_frame(t_game *game)
{
	static int	current_index = 0;
	static int	call_counter = 0;
	static int	direction = 1;
	void		*frame;

	if (++call_counter >= 140)
	{
		call_counter = 0;
		current_index += direction;
		if (current_index == 3 || current_index == 0)
			direction *= -1;
	}
	frame = game->gem_i_f[current_index];
	return (frame);
}
