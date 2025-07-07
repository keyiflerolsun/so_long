/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 00:00:37 by osancak           #+#    #+#             */
/*   Updated: 2025/07/07 17:15:37 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void mahmut(t_game *game)
{
	int	text_x = 600 / 2 - 50;
	int	text_y = 300 / 2;
	mlx_string_put(game->mlx, game->win, text_x, text_y, 0xFFFFFF, "Merhaba Mahmut");
	ft_printf("\nmap->rows\t: %d\nmap->columns\t: %d\n", game->map->rows, game->map->columns);
	ft_printf("map->coins\t: %d\nmap->exit\t: %d\n", game->map->coins, game->map->exit);
	ft_printf("map->players\t: %d\n\n", game->map->players);

	ft_printf("player->x\t: %d\nplayer->y\t: %d\n", game->player->x, game->player->y);
	ft_printf("player->step\t: %d\nplayer->score\t: %d\n\n", game->player->x, game->player->y);
}
