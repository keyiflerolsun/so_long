/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 19:56:08 by osancak           #+#    #+#             */
/*   Updated: 2025/07/12 20:18:56 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_step(t_game *game)
{
	char	*str;

	str = ft_itoa(game->player.step);
	mlx_string_put(
		game->mlx, game->win,
		FT_PX / 2.3,
		game->ui_y - FT_PX / 3,
		0xE1AD01, str);
	free(str);
}
