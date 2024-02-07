/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 09:57:58 by jberay            #+#    #+#             */
/*   Updated: 2024/02/07 17:04:23 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_map(t_data *data, t_args *args)
{
	int		i;
	char	*tmp;
	t_list	*tmp_lst;

	tmp_lst = args->head;
	args->row = ft_lstsize(tmp_lst);
	data->row = args->row;
	data->map = (char **)malloc(sizeof(char *) * (args->row + 1));
	if (data->map == NULL)
		ft_error("Malloc failed");
	i = 0;
	while (i < args->row)
	{
		tmp = tmp_lst->content;
		data->map[i] = ft_strtrim(tmp, "\n");
		if (data->map[i] == NULL)
			ft_free_error("Malloc failed", data->map);
		i++;
		tmp_lst = tmp_lst->next;
	}
	data->map[i] = NULL;
	ft_lstclear(&args->head, free);
	close(args->map_fd);
	is_valid_map(data, args);
}





static int	current_location(t_data *data, int x, int y)
{
	if (data->map[y / TILE_SIZE][x / TILE_SIZE] == '1')
	{
		printf("y %d x %d\n", y , x );
		printf(" y - %d x - %d\n", y / TILE_SIZE, x / TILE_SIZE);
		return (0);
	}
	else
		return (1);
}

void	hook(void *d)
{
	t_data	*data;

	data = (t_data *)d;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP)
		|| mlx_is_key_down(data->mlx, MLX_KEY_W))
		{
			printf("y: %d\n", data->img[MP_P]->instances[0].y);
			printf("x: %d\n", data->img[MP_P]->instances[0].x);
			if (current_location(data, data->img[MP_P]->instances[0].x, data->img[MP_P]->instances[0].y - 5) == 1
				&& current_location(data, data->img[MP_P]->instances[0].x + TILE_SIZE - 5, data->img[MP_P]->instances[0].y - 5) == 1)
				data->img[MP_P]->instances[0].y -= 5;
		}
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN)
		|| mlx_is_key_down(data->mlx, MLX_KEY_S))
		{
			printf("y: %d\n", data->img[MP_P]->instances[0].y);
			printf("x: %d\n", data->img[MP_P]->instances[0].x);
			if (current_location(data, data->img[MP_P]->instances[0].x, data->img[MP_P]->instances[0].y + TILE_SIZE) == 1
				&& current_location(data, data->img[MP_P]->instances[0].x + TILE_SIZE - 5, data->img[MP_P]->instances[0].y + TILE_SIZE) == 1)
				data->img[MP_P]->instances[0].y += 5;
		}
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT)
		|| mlx_is_key_down(data->mlx, MLX_KEY_A))
		{
			printf("y: %d\n", data->img[MP_P]->instances[0].y);
			printf("x: %d\n", data->img[MP_P]->instances[0].x);
			if (current_location(data, data->img[MP_P]->instances[0].x - 5, data->img[MP_P]->instances[0].y) == 1
				&& current_location(data, data->img[MP_P]->instances[0].x - 5, data->img[MP_P]->instances[0].y + TILE_SIZE - 5) == 1)
				data->img[MP_P]->instances[0].x -= 5;
		}
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(data->mlx, MLX_KEY_D))
		{
			printf("y: %d\n", data->img[MP_P]->instances[0].y);
			printf("x: %d\n", data->img[MP_P]->instances[0].x);
			if (current_location(data, data->img[MP_P]->instances[0].x + TILE_SIZE, data->img[MP_P]->instances[0].y) == 1
				&& current_location(data, data->img[MP_P]->instances[0].x + TILE_SIZE, data->img[MP_P]->instances[0].y + TILE_SIZE - 5) == 1)
				data->img[MP_P]->instances[0].x += 5;
		}
	printf("%c\n", data->map[data->img[MP_P]->instances[0].y / TILE_SIZE][data->img[MP_P]->instances[0].x / TILE_SIZE]);
	printf("%d \n", data->img[MP_E]->instances->z);
	printf("%d \n", data->img[MP_P]->instances->z);
	if (data->collectible > 0)
	{
		if (data->img[MP_P]->instances[0].x == data->img[MP_C]->instances[0].x
			&& data->img[MP_P]->instances[0].y == data->img[MP_C]->instances[0].y)
			{
				printf("del y: %d\n", data->img[MP_C]->instances[0].y);
				printf("del x: %d\n", data->img[MP_C]->instances[0].x);
				
				data->collectible = data->collectible - 1;
				data->map[data->img[MP_C]->instances[0].y / TILE_SIZE][data->img[MP_C]->instances[0].x / TILE_SIZE] = '0';
				printf("%d\n", data->collectible);
				printf("new %c\n", data->map[data->img[MP_C]->instances[0].y / TILE_SIZE][data->img[MP_C]->instances[0].x / TILE_SIZE]);
				mlx_delete_image(data->mlx, data->img[MP_C]);
			}
	}
	else
	{
		if (data->img[MP_P]->instances[0].x == data->img[MP_E]->instances[0].x
			&& data->img[MP_P]->instances[0].y == data->img[MP_E]->instances[0].y)
			mlx_close_window(data->mlx);
	}
}

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
		data->c[0] = x;
		data->c[1] = y;
		data->c[2] = data->instance++;
	}
	else if (MAP_CHARS[k] == data->map[y][x])
	{
		if (mlx_image_to_window(data->mlx, data->img[k], \
		x * TILE_SIZE, y * TILE_SIZE) < 0)
			error(*data);
	}
}

static void	draw_map(t_data *data)
{
	int	y;
	int	x;
	int	k;

	data->instance = 0;
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

int	main(int argc, char **argv)
{
	t_args			args;
	t_data			data;

	check_args(&args, argc, argv);
	init_map(&data, &args);

	// Start mlx

	data.mlx = mlx_init(args.column * TILE_SIZE, \
	args.row * TILE_SIZE, "So_long", true);
	if (!data.mlx)
		error(data);

	// Try to load the file
	load_img(&data);
	// Draw the map
	draw_map(&data);
	//keyhook
	mlx_loop_hook(data.mlx, hook, &data);
	// Loop
	mlx_loop(data.mlx);
	mlx_delete_image_array(data, 5);
	mlx_delete_texture_array(data, 5);
	mlx_terminate(data.mlx);
	ft_free_array(data.map);
	return (0);
}
