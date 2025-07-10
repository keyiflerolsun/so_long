/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 23:07:56 by osancak           #+#    #+#             */
/*   Updated: 2025/07/10 17:00:12 by osancak          ###   ########.fr       */
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
	int				row;
	int				column;
	int				step;
	int				score;
}					t_player;

typedef struct s_map
{
	char			**full;
	unsigned int	rows;
	unsigned int	columns;
	int				coins;
	int				exit;
	int				players;
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
}					t_game;

void				read_map(t_game *game, char *map_path);
void				free_map(t_map *map);
void				err_exit(const char *message, t_game *game);
int					is_valid_char(const char *line, const char *charset);
int					is_map_valid(char **map);
int					fill_check(t_map *map, t_player *player);
int					init_game(t_game *game, char *map_path);
void				destroy_walls(t_game *game);
void				*get_wall_image(t_game *game, int row, int col);
int					draw_walls(t_game *game);
void				mahmut(t_game *game);

#endif
