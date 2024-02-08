/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:49:19 by jberay            #+#    #+#             */
/*   Updated: 2024/02/08 14:31:36 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include "MLX42/include/MLX42/MLX42.h"

# define MAP_CHARS "01CEP"
# define TILE_SIZE 100
# define MP_S 0
# define MP_W 1
# define MP_C 2
# define MP_E 3
# define MP_P 4

typedef struct s_args
{
	int		map_fd;
	char	*line;
	int		column;
	int		row;
	int		x;
	int		y;
	int		player;
	int		exit;
	int		collectible;
	t_list	*head;
	t_list	*tmp;
}			t_args;

typedef struct s_data
{
	char			**map;
	int				row;
	int				column;
	char			*texture_path;
	int				collectible;
	int				i;
	int				moves;
	mlx_t			*mlx;
	mlx_texture_t	*txr[5];
	mlx_image_t		*img[5];
}					t_data;

/*error exit*/
void	ft_free_error(char *message, char **array);
void	ft_error(char *message);
void	ft_free_array(char **array);
void	error(t_data data);
void	mlx_delete_image_array(t_data data, int i);
void	mlx_delete_texture_array(t_data data, int i);

/*check args*/
void	check_args(t_args *args, int argc, char **argv);
void	is_valid_map(t_data *data, t_args *args);
void	init_map(t_data *data, t_args *args);

/*utils*/
int		current_location(t_data *data, int x, int y);
int		ret_instance(t_data *data, int x, int y);
int		is_all_disabled(t_data *data);
void	check_collectibles(t_data *data);

void	load_img(t_data *data);
void	draw_map(t_data *data);
void	hook(void *d);

#endif