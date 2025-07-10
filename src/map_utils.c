/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 21:13:47 by osancak           #+#    #+#             */
/*   Updated: 2025/07/09 14:29:39 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_char(const char *line, const char *charset)
{
	while (*line)
	{
		if (!ft_strchr(charset, *line))
			return (0);
		line++;
	}
	return (1);
}

static int	check_map_borders(char **map, int rows, int cols)
{
	int	i;

	i = -1;
	while (++i < rows)
	{
		if (map[i][0] != '1' || map[i][cols - 1] != '1')
			return (0);
	}
	i = -1;
	while (++i < cols)
	{
		if (map[0][i] != '1' || map[rows - 1][i] != '1')
			return (0);
	}
	return (1);
}

int	is_map_valid(char **map)
{
	int	rows;
	int	cols;
	int	line_len;

	if (!map || !map[0])
		return (0);
	cols = ft_strlen(map[0]);
	rows = 0;
	while (map[rows])
	{
		line_len = ft_strlen(map[rows]);
		if (line_len != cols)
			return (0);
		rows++;
	}
	if (rows < 3 || cols < 3)
		return (0);
	if (!check_map_borders(map, rows, cols))
		return (0);
	return (1);
}

void	free_map(t_map *map)
{
	char	**_map;

	_map = map->full;
	if (map && map->full)
	{
		while (*(map->full))
			free(*(map->full)++);
		free(_map);
	}
	if (map)
		free(map);
}
