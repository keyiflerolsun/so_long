/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 22:12:11 by osancak           #+#    #+#             */
/*   Updated: 2025/07/12 02:38:09 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	can_move_to(t_game *game, int new_row, int new_col)
{
	if (
		new_row < 0 || new_col < 0
		|| new_row >= (int)game->map.rows
		|| new_col >= (int)game->map.columns
	)
		return (0);
	if (game->map.full[new_row][new_col] == '1')
		return (0);
	if (game->map.full[new_row][new_col] == 'E' && game->map.coins > 0)
		return (0);
	return (1);
}

void	collect_item(t_game *game, int row, int col)
{
	if (game->map.full[row][col] == 'C')
	{
		game->map.full[row][col] = '0';
		game->player.score++;
		game->map.coins--;
		ft_printf("%s» Collected! Score: %d/%d%s\n", GREEN, game->player.score,
			game->player.score + game->map.coins, RESET);
	}
	else if (game->map.full[row][col] == 'E' && game->map.coins == 0)
	{
		ft_printf("\n%s» 🎉 You Win! Final Score: %d steps: %d%s\n",
			YELLOW,
			game->player.score, game->player.step,
			RESET);
		game_close(game);
	}
}

void	move_player(t_game *game, int new_row, int new_col)
{
	if (!can_move_to(game, new_row, new_col))
		return ;
	game->map.full[game->player.row][game->player.column] = '0';
	game->player.row = new_row;
	game->player.column = new_col;
	game->player.step++;
	collect_item(game, new_row, new_col);
	if (game->map.full[new_row][new_col] != 'E')
		game->map.full[new_row][new_col] = 'P';
	ft_printf("%s» Step %d - Position: (%d, %d)%s\n",
		CYAN,
		game->player.step, new_row, new_col,
		RESET);
}
