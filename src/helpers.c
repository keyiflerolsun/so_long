/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 00:00:37 by osancak           #+#    #+#             */
/*   Updated: 2025/07/06 19:59:47 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(void *param)
{
	(void)param;
	ft_printf("\n%sclose_window%s\n\n", RED, RESET);
	exit(0);
	return (0);
}

int key_hook(int keycode, void *param)
{
    (void)param;
	ft_printf("%s» Key : %s%d%s\n", MAGENTA, YELLOW, keycode, RESET);
    if (keycode == XK_Escape)
        close_window(param);
    return (0);
}

void	so_long_init(void)
{
	ft_printf("\n%sso_long%s\n\n", BLUE, RESET);

	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	if (!mlx)
		return ;

	int	win_width  = 600;
	int	win_height = 300;
	mlx_win = mlx_new_window(mlx, win_width, win_height, "Cokomelli Pencere");
	if (!mlx_win)
		return ;

	int	text_x = win_width / 2 - 50;
	int	text_y = win_height / 2;
	mlx_string_put(mlx, mlx_win, text_x, text_y, 0xFFFFFF, "Merhaba Mahmut");

	mlx_hook(mlx_win, DestroyNotify, 0, close_window, NULL);
	mlx_key_hook(mlx_win, key_hook, NULL);

	mlx_loop(mlx);
}
