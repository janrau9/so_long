/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:53:44 by jberay            #+#    #+#             */
/*   Updated: 2024/02/02 16:20:16 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static void	ft_free_array(char **array)
// {
// 	int	i;

// 	i = 0;
// 	while (array[i] != NULL)
// 	{
// 		free(array[i]);
// 		i++;
// 	}
// 	free(array);
// }

static void	ft_error(char *message)
{
	ft_printf("Error\n%s\n", message);
	exit(1);
}

// static void	ft_mallloc_error(char *message, char **array)
// {
// 	ft_free_array(array);
// 	ft_error(message);
// }

static void	check_args(t_args *args, int argc, char **argv)
{
	t_list	*head;
	t_list	*last;
	t_list	*tmp;

	head = NULL;
	if (argc != 2)
		ft_error("Wrong number of arguments");
	if (ft_strlen(ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]))) != 4)
		ft_error("Wrong file extension");
	args->map_fd = open(argv[1], O_RDONLY);
	if (args->map_fd < 0)
		ft_error("File does not exist");
	args->row = 0;
	while (1)
	{
		args->line = get_next_line(args->map_fd);
		if (args->line == NULL)
		{
			last = ft_lstlast(head);
			if (((char *)last->content)[0] == '\n')
			{
				ft_lstclear(&head, free);
				ft_error("Malloc failed");
			}
			ft_lstclear(&head, free);
			break ;
		}
		tmp = ft_lstnew(args->line);
		if (tmp == NULL)
		{
			ft_lstclear(&head, free);
			ft_error("Malloc failed");
		}
		ft_lstadd_back(&head, tmp);
		args->row++;
	}
	close(args->map_fd);
}

// static void	is_walls(t_data *data, t_args *args, int i)
// {
// 	int	j;

// 	j = 0;
// 	if (data->map[i][0] != '1' || data->map[i][args->column - 1] != '1')
// 		ft_error("Map is not surrounded by walls");
// 	while (data->map[i][j])
// 	{
// 		if ((data->map[0][j] != '1')
// 			|| (data->map[args->row - 1][j] != '1'))
// 			ft_error("Map is not surrounded by walls");
// 		if (!ft_strchr(MAP_CHARS, data->map[i][j]))
// 			ft_error("Map contains invalid characters");
// 		if (data->map[i][j] == 'P')
// 			args->player++;
// 		if (data->map[i][j] == 'E')
// 			args->exit++;
// 		if (data->map[i][j] == 'C')
// 			args->collectible++;
// 		j++;
// 	}
// }

// static void	is_valid_map(t_data *data, t_args *args)
// {
// 	int	i;

// 	i = 0;
// 	args->column = ft_strlen(data->map[0]);
// 	args->player = 0;
// 	args->exit = 0;
// 	while (data->map[i])
// 	{
// 		if ((int)ft_strlen(data->map[i]) != args->column)
// 			ft_error("Map is not rectangular");
// 		is_walls(data, args, i);
// 		i++;
// 	}
// 	if (args->player != 1 || args->exit != 1 || args->collectible < 1)
// 		ft_error("Map is invalid");
// }

// static void	init_map(t_data *data, t_args *args, char **argv)
// {
// 	int		i;
// 	char	*tmp;

// 	data->map = (char **)malloc(sizeof(char *) * (args->row + 1));
// 	if (data->map == NULL)
// 		ft_error("Malloc failed");
// 	i = 0;
// 	args->map_fd = open(argv[1], O_RDONLY);
// 	if (args->map_fd < 0)
// 		ft_mallloc_error("File does not exist", data->map);
// 	while (i < args->row)
// 	{
// 		tmp = get_next_line(args->map_fd);
// 		data->map[i] = ft_strtrim(tmp, "\n");
// 		free(tmp);
// 		if (data->map[i] == NULL)
// 			ft_mallloc_error("Malloc failed", data->map);
// 		i++;
// 	}
// 	data->map[i] = NULL;
// 	close(args->map_fd);
// 	is_valid_map(data, args);
// 	ft_free_array(data->map);
// }

int	main(int argc, char **argv)
{
	t_args	args;
	// t_data	data;

	check_args(&args, argc, argv);
	// init_map(&data, &args, argv);
	return (0);
}