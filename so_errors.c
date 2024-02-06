/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 09:58:55 by jberay            #+#    #+#             */
/*   Updated: 2024/02/06 09:58:56 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
