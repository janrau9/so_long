/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 09:58:13 by jberay            #+#    #+#             */
/*   Updated: 2024/02/06 11:14:33 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	call_gnl(t_args *args)
{
	t_list	*last;
	t_list	*tmp;

	while (1)
	{
		args->line = get_next_line(args->map_fd);
		if (args->line == NULL)
		{
			last = ft_lstlast(args->head);
			if (((char *)last->content)[ft_strlen(last->content) - 1] == '\n')
			{
				ft_lstclear(&args->head, free);
				ft_error("Malloc failed");
			}
			break ;
		}
		tmp = ft_lstnew(args->line);
		if (tmp == NULL)
		{
			ft_lstclear(&args->head, free);
			ft_error("Malloc failed");
		}
		ft_lstadd_back(&args->head, tmp);
	}
}

void	check_args(t_args *args, int argc, char **argv)
{
	args->head = NULL;
	if (argc != 2)
		ft_error("Wrong number of arguments");
	if (ft_strlen(argv[1]) < 5)
		ft_error("Cant read file extension");
	if (ft_strlen(ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]))) != 4)
		ft_error("Wrong file extension");
	args->map_fd = open(argv[1], O_RDONLY);
	if (args->map_fd < 0)
		ft_error("File does not exist");
	call_gnl(args);
	close(args->map_fd);
}
