/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:46:48 by jberay            #+#    #+#             */
/*   Updated: 2024/02/08 15:53:24 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	current_location(t_data *data, int x, int y)
{
	if (data->map[y / TILE_SIZE][x / TILE_SIZE] == '1')
	{
		return (0);
	}
	else
		return (1);
}

int	ret_instance(t_data *data, int x, int y)
{
	int	i;

	i = 0;
	while (i < data->collectible)
	{
		if (data->img[MP_C]->instances[i].x == x
			&& data->img[MP_C]->instances[i].y == y)
			return (i);
		i++;
	}
	return (-1);
}

int	is_all_disabled(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->collectible)
	{
		if (data->img[MP_C]->instances[i].enabled == true)
			return (0);
		i++;
	}
	return (1);
}

void	check_collectibles(t_data *data, int x, int y)
{
	int		instance;

	if (!is_all_disabled(data))
	{
		if (data->map[y / TILE_SIZE][x / TILE_SIZE] == 'C')
		{
			instance = ret_instance(data, x, y);
			if (instance == -1)
				return ;
			if (data->img[MP_C]->instances[instance].enabled == true)
			{
				data->img[MP_C]->instances[instance].enabled = false;
				data->map[y / TILE_SIZE][x / TILE_SIZE] = '0';
			}
		}
	}
	else
	{
		if (x == data->img[MP_E]->instances[0].x
			&& y == data->img[MP_E]->instances[0].y)
			mlx_close_window(data->mlx);
	}
}
