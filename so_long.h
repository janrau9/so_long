/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:49:19 by jberay            #+#    #+#             */
/*   Updated: 2024/02/02 15:18:24 by jberay           ###   ########.fr       */
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
	int		player;
	int		exit;
	int		collectible;
}			t_args;

typedef struct s_data
{
	char	**map;
}			t_data;

#endif