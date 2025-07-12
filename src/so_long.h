/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 23:07:56 by osancak           #+#    #+#             */
/*   Updated: 2025/07/12 20:22:52 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf.h"
# include "get_next_line.h"
# include "mlx.h"
# include "mlx_int.h"

# define VALID_MAP_CHARS "10ECPX\n"
# define UI_TITLE "so_long"
# define FT_PX 64

# define DIR_DOWN 0
# define DIR_LEFT 1
# define DIR_RIGHT 2
# define DIR_UP 3

typedef struct s_wall
{
	void			*blck;
	void			*up;
	void			*u_l;
	void			*u_r;
	void			*down;
	void			*d_l;
	void			*d_r;
	void			*left;
	void			*rght;
}					t_wall;

typedef struct s_door
{
	void			*cls;
	void			*o_f[3];
	void			*d_i;
	void			*d_l;
	void			*d_r;
	void			*d_u;
}					t_door;

typedef struct s_player
{
	unsigned int	row;
	unsigned int	column;
	unsigned int	step;
	unsigned int	score;
	int				direction;
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
	t_door			door;
	void			*gem_i_f[4];
	void			*ply_i_f[3];
	void			*ply_l_f[3];
	void			*ply_r_f[3];
	void			*ply_u_f[3];
	void			*enemy[3];
}					t_game;

void				read_map(t_game *game, char *map_path);
void				free_map(t_map *map);
void				err_exit(const char *message, t_game *game);
int					game_close(t_game *game);
int					is_valid_char(const char *line, const char *charset);
int					is_map_valid(char **map);
int					fill_check(t_map *map, t_player *player);
int					init_game(t_game *game, char *map_path);
int					init_w_u_d(void *mlx, t_wall *wall);
int					init_w_l_r(void *mlx, t_wall *wall);
int					init_gem(void *mlx, void **frames);
int					init_ply_i_u_frames(void *mlx, void **i_f, void **u_f);
int					init_ply_l_r_frames(void *mlx, void **l_f, void **r_f);
int					init_door(void *mlx, t_door *door);
int					init_enemy(void *mlx, void **frames);
int					init_images(t_game *game);
void				destroy_walls(t_game *game);
void				destroy_gem(t_game *game);
void				destroy_player_frames(t_game *game);
void				destroy_door(t_game *game);
void				destroy_enemy(t_game *game);
void				*get_wall_image(t_game *game, int row, int col);
void				*get_gem_idle_frame(t_game *game);
void				*get_player_frame(t_game *game);
void				*get_door_frame(t_game *game);
void				*get_door_player_frame(t_game *game);
void				*get_enemy_idle_frame(t_game *game);
int					render(t_game *game);
int					can_move_to(t_game *game, int new_row, int new_col);
void				collect_item(t_game *game, int row, int col);
void				move_player(t_game *game, int new_row, int new_col);
void				draw_step(t_game *game);

#endif
