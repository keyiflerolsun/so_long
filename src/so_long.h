/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 23:07:56 by osancak           #+#    #+#             */
/*   Updated: 2025/07/11 23:07:43 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf.h"
# include "get_next_line.h"
# include "mlx.h"
# include "mlx_int.h"

# define VALID_MAP_CHARS "10ECP\n"
# define UI_TITLE "so_long"
# define FT_PX 64

typedef struct s_wall
{
	void			*block;
	void			*up;
	void			*u_lft;
	void			*u_rght;
	void			*down;
	void			*d_lft;
	void			*d_rght;
	void			*left;
	void			*right;
}					t_wall;

typedef struct s_player
{
	unsigned int	row;
	unsigned int	column;
	unsigned int	step;
	unsigned int	score;
}					t_player;

typedef struct s_map
{
	char			**full;
	unsigned int	rows;
	unsigned int	columns;
	unsigned int	coins;
	unsigned int	exit;
	unsigned int	players;
}					t_map;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	t_map			map;
	size_t			ui_x;
	size_t			ui_y;
	t_player		player;
	t_wall			wall;
	void			*gem_idle_frames[4];
	void			*p_idle_frames[3];
}					t_game;

void				read_map(t_game *game, char *map_path);
void				free_map(t_map *map);
void				err_exit(const char *message, t_game *game);
int					game_close(t_game *game);
int					is_valid_char(const char *line, const char *charset);
int					is_map_valid(char **map);
int					fill_check(t_map *map, t_player *player);
int					init_game(t_game *game, char *map_path);
int					init_u_d(void *mlx, t_wall *wall);
int					init_l_r(void *mlx, t_wall *wall);
int					init_gem(void *mlx, void **frames);
int					init_player_frames(void *mlx, void **frames);
int					init_images(t_game *game);
void				destroy_walls(t_game *game);
void				destroy_gem(t_game *game);
void				destroy_player_frames(t_game *game);
void				*get_wall_image(t_game *game, int row, int col);
void				*get_gem_idle_frame(t_game *game);
void				*get_p_idle_frame(t_game *game);
int					render(t_game *game);
void				mahmut(t_game *game);
int					can_move_to(t_game *game, int new_row, int new_col);
void				collect_item(t_game *game, int row, int col);
void				move_player(t_game *game, int new_row, int new_col);

#endif
