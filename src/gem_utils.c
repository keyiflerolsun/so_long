/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 10:03:56 by osancak           #+#    #+#             */
/*   Updated: 2025/07/11 10:25:23 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_gem(void *mlx, void **gem)
{
	int	px;

	px = FT_PX;
	*gem = mlx_xpm_file_to_image(mlx, "res/gem/egg.xpm", &px, &px);
	if (!*gem)
		return (0);
	return (1);
}

void	destroy_gem(t_game *game)
{
	if (game->gem)
		mlx_destroy_image(game->mlx, game->gem);
	destroy_player_frames(game);
}
