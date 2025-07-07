/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 10:15:46 by osancak           #+#    #+#             */
/*   Updated: 2025/07/07 16:16:35 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	err_exit(t_game *game, char *lines, const char *message)
{
	free(lines);
	write(2, "\033[0;31m\033[1mERROR : \033[0m\033[0;35m", 30);
	while (*message)
		write(2, message++, 1);
	write(2, "\033[0m\n", 5);
	free(game->map);
	free(game);
	exit(EXIT_FAILURE);
}

static int	is_playable(const char *line)
{
	while (*line)
	{
		if (*line != '1' && *line != '0' && *line != 'E' && *line != 'C'
			&& *line != 'P' && *line != '\n')
			return (0);
		line++;
	}
	return (1);
}

static void	ft_read_file(t_game *game, char *path, char **line, char **lines)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		err_exit(game, *lines, "file not found");
	while (*line)
	{
		*line = get_next_line(fd);
		if (!*line)
			break ;
		else if (**line == '\n' || !is_playable(*line))
		{
			free(*line);
			get_next_line(-42);
			err_exit(game, *lines, "map is invalid");
		}
		*lines = ft_strjoin(*lines, *line, 3);
	}
	close(fd);
	if (!**lines)
		err_exit(game, *lines, "file is empty");
}

void	free_map(t_map *map)
{
	char **p_map;

	p_map = map->full;
	if (map && map->full)
	{
		while (*(map->full))
			free(*(map->full)++);
		free(p_map);
	}
	if (map)
		free(map);
}

char	**read_map(t_game *game, char *map_path)
{
	char	*line;
	char	*lines;
	char	**res;

	if (!ft_strnstr(map_path, ".ber"))
		err_exit(game, NULL, "file not valid");
	line = "";
	lines = ft_strdup("");
	if (!lines)
		err_exit(game, lines, "memory problem from read_map");
	ft_read_file(game, map_path, &line, &lines);
	res = ft_split(lines, '\n');
	free(lines);
	return (res);
}
