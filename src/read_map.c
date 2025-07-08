/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 10:15:46 by osancak           #+#    #+#             */
/*   Updated: 2025/07/08 22:27:13 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	cleanup_and_exit(t_game *game, char *lines, const char *message)
{
	if (lines)
		free(lines);
	err_exit(message, game);
}

static void	ft_read_file(t_game *game, char *path, char **line, char **lines)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		cleanup_and_exit(game, *lines, "file not found");
	while (*line)
	{
		*line = get_next_line(fd);
		if (!*line)
			break ;
		else if (**line == '\n' || !is_valid_char(*line))
		{
			free(*line);
			get_next_line(-42);
			cleanup_and_exit(game, *lines, "map contains invalid characters");
		}
		*lines = ft_strjoin(*lines, *line, 3);
	}
	close(fd);
	if (!**lines)
		cleanup_and_exit(game, *lines, "file is empty");
}

void	read_map(t_game *game, char *map_path)
{
	char	*line;
	char	*lines;

	if (!ft_strnstr(map_path, ".ber"))
		err_exit("file extension must be .ber", game);
	line = "";
	lines = ft_strdup("");
	if (!lines)
		err_exit("memory allocation failed in read_map", game);
	ft_read_file(game, map_path, &line, &lines);
	game->map->full = ft_split(lines, '\n');
	free(lines);
	if (!is_map_structure_valid(game->map->full))
	{
		free(game->map->full);
		err_exit("map structure is invalid", game);
	}
}
