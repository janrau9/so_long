/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:19:36 by jberay            #+#    #+#             */
/*   Updated: 2024/01/31 11:36:11 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "MLX42/include/MLX42/MLX42.h"
#define WIDTH 512
#define HEIGHT 512

static void	error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int32_t	main(void)
{
	// Start mlx
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
	if (!mlx)
		error();

	// Try to load the file
	mlx_texture_t* texture = mlx_load_png("./tiny/Terrain/Ground/Tilemap_Elevation.png");
	if (!texture)
		error();
	
	// Convert texture to a displayable image
	mlx_image_t* img = mlx_texture_to_image(mlx, texture);
	if (!img)
		error();

	// Display the image
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
		error();

	mlx_loop(mlx);

	// Optional, terminate will clean up any leftovers, this is just to demonstrate.
	mlx_delete_image(mlx, img);
	mlx_delete_texture(texture);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}