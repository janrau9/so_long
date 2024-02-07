/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_load_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:19:41 by jberay            #+#    #+#             */
/*   Updated: 2024/02/07 16:43:24 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*call_texture_path(char c)
{
	if (c == '0')
		return ("textures/grass.png");
	else if (c == '1')
		return ("textures/wall.png");
	else if (c == 'C')
		return ("textures/meat.png");
	else if (c == 'E')
		return ("textures/exit.png");
	else if (c == 'P')
		return ("textures/hero.png");
	return (NULL);
}

void	load_img(t_data *data)
{
	data->i = 0;
	while (MAP_CHARS[data->i])
	{
		data->texture_path = call_texture_path(MAP_CHARS[data->i]);
		data->txr[data->i] = mlx_load_png(data->texture_path);
		if (!data->txr[data->i])
			error(*data);
		data->img[data->i] = mlx_texture_to_image(data->mlx, \
		data->txr[data->i]);
		if (!data->img[data->i])
			error(*data);
		mlx_resize_image(data->img[data->i], TILE_SIZE, TILE_SIZE);
		data->i++;
	}
}