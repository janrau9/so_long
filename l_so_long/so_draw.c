/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:45:09 by jberay            #+#    #+#             */
/*   Updated: 2024/02/08 11:45:10 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	execute_draw(t_data *data, int x, int y, int k)
{
	if (MAP_CHARS[k] == '0')
	{
		if (mlx_image_to_window(data->mlx, data->img[k], \
		x * TILE_SIZE, y * TILE_SIZE) < 0)
			error(*data);
	}
	else if (data->map[y][x] == 'C' && MAP_CHARS[k] == 'C')
	{
		if (mlx_image_to_window(data->mlx, data->img[k], \
		x * TILE_SIZE, y * TILE_SIZE) < 0)
			error(*data);
	}
	else if (MAP_CHARS[k] == data->map[y][x])
	{
		if (mlx_image_to_window(data->mlx, data->img[k], \
		x * TILE_SIZE, y * TILE_SIZE) < 0)
			error(*data);
	}
}

void	draw_map(t_data *data)
{
	int	y;
	int	x;
	int	k;

	k = 0;
	while (MAP_CHARS[k])
	{
		y = 0;
		while (data->map[y])
		{
			x = 0;
			while (data->map[y][x])
			{
				execute_draw(data, x, y, k);
				x++;
			}
			y++;
		}
		k++;
	}
}
