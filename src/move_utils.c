/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 22:12:11 by osancak           #+#    #+#             */
/*   Updated: 2025/07/12 19:29:31 by osancak          ###   ########.fr       */
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
	return (1);
}

static void	die_player(t_game *game)
{
	ft_printf("\n%s» 💂 You Die! Score: %d/%d steps: %d%s\n",
		RED,
		game->player.score,
		game->player.score + game->map.coins,
		game->player.step,
		RESET);
	game_close(game);
}

void	collect_item(t_game *game, int row, int col)
{
	if (game->map.full[row][col] == 'C')
	{
		game->map.full[row][col] = '0';
		game->player.score++;
		game->map.coins--;
		ft_printf("%s» Collected! Score: %d/%d%s\n",
			GREEN,
			game->player.score, game->player.score + game->map.coins,
			RESET);
	}
	if (game->map.full[row][col] == 'E' && game->map.coins == 0)
	{
		ft_printf("\n%s» 🎉 You Win! Final Score: %d steps: %d%s\n",
			YELLOW,
			game->player.score, game->player.step,
			RESET);
		game_close(game);
	}
	if (game->map.full[row][col] == 'X')
		die_player(game);
}

void	move_player(t_game *game, int new_row, int new_col)
{
	static char	under_player = '0';

	if (!can_move_to(game, new_row, new_col))
		return ;
	game->map.full[game->player.row][game->player.column] = under_player;
	collect_item(game, new_row, new_col);
	under_player = game->map.full[new_row][new_col];
	if (under_player == 'E')
		game->map.full[new_row][new_col] = '~';
	else
		game->map.full[new_row][new_col] = 'P';
	game->player.row = new_row;
	game->player.column = new_col;
	game->player.step++;
	ft_printf("%s» Step %d - Position: (%d, %d)%s\n",
		CYAN,
		game->player.step, new_row, new_col,
		RESET);
}
