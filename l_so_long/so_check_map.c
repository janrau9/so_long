/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 09:58:30 by jberay            #+#    #+#             */
/*   Updated: 2024/02/08 15:54:45 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	is_walls(t_data *data, t_args *args, int i)
{
	int	j;

	j = 0;
	if (data->map[i][0] != '1' || data->map[i][args->column - 1] != '1')
		ft_error("Map is not surrounded by walls");
	while (data->map[i][j])
	{
		if ((data->map[0][j] != '1')
			|| (data->map[args->row - 1][j] != '1'))
			ft_error("Map is not surrounded by walls");
		if (!ft_strchr(MAP_CHARS, data->map[i][j]))
			ft_error("Map contains invalid characters");
		if (data->map[i][j] == 'P')
			args->player++;
		if (data->map[i][j] == 'E')
			args->exit++;
		if (data->map[i][j] == 'C')
			args->collectible++;
		j++;
	}
}

static int	find_char(char **map, char c, t_args *args)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
			{
				args->x = j;
				args->y = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static void	fill_map(t_args *args, char **map, int y, int x)
{
	if (y < 0 || x < 0 || y >= args->row || x >= args->column)
		return ;
	map[y][x] = 'X';
	if (ft_strchr("0ECP", map[y - 1][x]))
		fill_map(args, map, y - 1, x);
	if (ft_strchr("0ECP", map[y + 1][x]))
		fill_map(args, map, y + 1, x);
	if (ft_strchr("0ECP", map[y][x - 1]))
		fill_map(args, map, y, x - 1);
	if (ft_strchr("0ECP", map[y][x + 1]))
		fill_map(args, map, y, x + 1);
}

static void	is_path(t_data *data, t_args *args)
{
	char	**map;
	int		i;

	i = 0;
	map = malloc(sizeof(char *) * (args->row + 1));
	if (map == NULL)
		ft_free_error("Malloc failed", data->map);
	while (data->map[i])
	{
		map[i] = ft_strdup(data->map[i]);
		if (map[i] == NULL)
		{
			ft_free_array(data->map);
			ft_free_error("Malloc failed", map);
		}
		i++;
	}
	map[i] = NULL;
	find_char(map, 'P', args);
	fill_map(args, map, args->y, args->x);
	if (find_char(map, 'C', args))
		ft_error("No valid path to collectible");
	if (find_char(map, 'E', args))
		ft_error("No valid path to exit");
	ft_free_array(map);
}

void	is_valid_map(t_data *data, t_args *args)
{
	int	i;

	i = 0;
	args->column = ft_strlen(data->map[0]);
	data->column = args->column;
	while (data->map[i])
	{
		if ((int)ft_strlen(data->map[i]) != args->column)
			ft_error("Map is not rectangular");
		is_walls(data, args, i);
		i++;
	}
	data->collectible = args->collectible;
	if (args->player != 1 || args->exit != 1 || args->collectible < 1)
		ft_error("Map is invalid");
	is_path(data, args);
}
