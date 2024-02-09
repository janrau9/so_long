/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 09:57:58 by jberay            #+#    #+#             */
/*   Updated: 2024/02/08 14:21:16 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_args			args;
	t_data			data;

	check_args(&args, argc, argv);
	init_map(&data, &args);
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	data.mlx = mlx_init(args.column * TILE_SIZE, \
	args.row * TILE_SIZE, "So_long", true);
	if (!data.mlx)
		error(data);
	load_img(&data);
	draw_map(&data);
	mlx_loop_hook(data.mlx, hook, &data);
	mlx_loop(data.mlx);
	mlx_delete_image_array(data, 5);
	mlx_delete_texture_array(data, 5);
	mlx_terminate(data.mlx);
	ft_free_array(data.map);
	return (0);
}
