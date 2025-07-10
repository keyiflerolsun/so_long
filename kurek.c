#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

#define WIN_WIDTH 600
#define WIN_HEIGHT 300
#define TILE_SIZE 64
#define GREY 0x808080

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*wall_img;
	void	*player_img;
	int		img_width;
	int		img_height;
}	t_game;

void	draw_background(t_game *game)
{
	for (int y = 0; y < WIN_HEIGHT; y++)
	{
		for (int x = 0; x < WIN_WIDTH; x++)
			mlx_pixel_put(game->mlx, game->win, x, y, GREY);
	}
}


int	main(void)
{
	t_game	game;

	game.mlx = mlx_init();

	draw_background(&game);

	mlx_loop(game.mlx);
	return (0);
}
