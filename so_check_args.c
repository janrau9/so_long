/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:44:22 by jberay            #+#    #+#             */
/*   Updated: 2024/02/08 14:31:54 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	call_gnl(t_args *args)
{
	t_list	*last;

	while (1)
	{
		args->line = get_next_line(args->map_fd);
		if (args->line == NULL)
		{
			if (args->head == NULL)
				ft_error("Empty file");
			last = ft_lstlast(args->head);
			if (((char *)last->content)[ft_strlen(last->content) - 1] == '\n')
			{
				ft_lstclear(&args->head, free);
				ft_error("Malloc failed");
			}
			break ;
		}
		args->tmp = ft_lstnew(args->line);
		if (args->tmp == NULL)
		{
			ft_lstclear(&args->head, free);
			ft_error("Malloc failed");
		}
		ft_lstadd_back(&args->head, args->tmp);
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

void	init_map(t_data *data, t_args *args)
{
	int		i;
	char	*tmp;
	t_list	*tmp_lst;

	tmp_lst = args->head;
	args->row = ft_lstsize(tmp_lst);
	data->row = args->row;
	data->moves = 0;
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
