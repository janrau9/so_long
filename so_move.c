/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:46:25 by jberay            #+#    #+#             */
/*   Updated: 2024/02/08 11:46:27 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	call_up(t_data *data, int x, int y)
{
	if (current_location(data, x, y - 5) == 1
		&& current_location(data, x + TILE_SIZE - 5, y - 5) == 1)
	{
		data->img[MP_P]->instances[0].y -= 5;
		ft_printf("You moved %d times!\n", data->moves++);
	}
}

static void	call_down(t_data *data, int x, int y)
{
	if (current_location(data, x, y + TILE_SIZE) == 1
		&& current_location(data, x + TILE_SIZE - 5, y + TILE_SIZE) == 1)
	{
		data->img[MP_P]->instances[0].y += 5;
		ft_printf("You moved %d times!\n", data->moves++);
	}
}

static void	call_left(t_data *data, int x, int y)
{
	if (current_location(data, x - 5, y) == 1
		&& current_location(data, x - 5, y + TILE_SIZE - 5) == 1)
	{
		data->img[MP_P]->instances[0].x -= 5;
		ft_printf("You moved %d times!\n", data->moves++);
	}
}

static void	call_right(t_data *data, int x, int y)
{
	if (current_location(data, x + TILE_SIZE, y) == 1
		&& current_location(data, x + TILE_SIZE, y + TILE_SIZE - 5) == 1)
	{
		data->img[MP_P]->instances[0].x += 5;
		ft_printf("You moved %d times!\n", data->moves++);
	}
}

void	hook(void *d)
{
	t_data	*data;
	int		x;
	int		y;

	data = (t_data *)d;
	x = data->img[MP_P]->instances[0].x;
	y = data->img[MP_P]->instances[0].y;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP)
		|| mlx_is_key_down(data->mlx, MLX_KEY_W))
		call_up(data, x, y);
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN)
		|| mlx_is_key_down(data->mlx, MLX_KEY_S))
		call_down(data, x, y);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT)
		|| mlx_is_key_down(data->mlx, MLX_KEY_A))
		call_left(data, x, y);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(data->mlx, MLX_KEY_D))
		call_right(data, x, y);
	check_collectibles(data);
}
