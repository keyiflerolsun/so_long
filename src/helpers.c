/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 00:00:37 by osancak           #+#    #+#             */
/*   Updated: 2025/07/10 16:54:23 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mahmut(t_game *game)
{
	ft_printf("\nmap.rows\t: %d\nmap.columns\t: %d\n", game->map.rows, game->map.columns);
	ft_printf("map.coins\t: %d\nmap.exit\t: %d\n", game->map.coins, game->map.exit);
	ft_printf("map.players\t: %d\n\n", game->map.players);

	ft_printf("player.row\t: %d\nplayer.column\t: %d\n", game->player.row, game->player.column);
	ft_printf("player.step\t: %d\nplayer.score\t: %d\n\n", game->player.step, game->player.score);
}
