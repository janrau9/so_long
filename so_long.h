/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:49:19 by jberay            #+#    #+#             */
/*   Updated: 2024/02/06 10:08:37 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <stdio.h>
# include <fcntl.h>

# define MAP_CHARS "01CEP"

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
}			t_args;

typedef struct s_data
{
	char	**map;
}			t_data;


/*error exit*/
void	ft_free_error(char *message, char **array);
void	ft_error(char *message);
void	ft_free_array(char **array);

/*check args*/
void	check_args(t_args *args, int argc, char **argv);
void	is_valid_map(t_data *data, t_args *args);

#endif