/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_delete.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:53:29 by jberay            #+#    #+#             */
/*   Updated: 2024/02/07 15:53:40 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_delete_image_array(t_data data, int i)
{
	while (i--)
		mlx_delete_image(data.mlx, data.img[i]);
}

void	mlx_delete_texture_array(t_data data, int i)
{
	while (i--)
		mlx_delete_texture(data.txr[i]);
}