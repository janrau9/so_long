/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 09:57:58 by jberay            #+#    #+#             */
/*   Updated: 2024/02/06 11:13:20 by jberay           ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_args	args;
	t_data	data;

	check_args(&args, argc, argv);
	init_map(&data, &args);
	ft_free_array(data.map);
	return (0);
}
