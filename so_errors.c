/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:45:43 by jberay            #+#    #+#             */
/*   Updated: 2024/02/08 11:45:46 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(t_data data)
{
	ft_printf(mlx_strerror(mlx_errno));
	mlx_delete_image_array(data, data.i);
	mlx_delete_texture_array(data, data.i);
	mlx_terminate(data.mlx);
	exit(EXIT_FAILURE);
}

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	ft_error(char *message)
{
	ft_printf("Error\n%s\n", message);
	exit(1);
}

void	ft_free_error(char *message, char **array)
{
	ft_free_array(array);
	ft_error(message);
}
