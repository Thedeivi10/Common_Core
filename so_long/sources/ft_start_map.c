/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 08:13:12 by davigome          #+#    #+#             */
/*   Updated: 2024/11/27 23:25:20 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_map	*ft_map(char *map, t_map *game)
{
	game = ft_init_map(game);
	game = ft_read_map(map, game);
	return (game);
}

t_map	*ft_init_map(t_map *game)
{
	game = malloc(sizeof(t_map));
	if (!game)
	{
		ft_printf("Error:\nThe map could not be allocated\n");
		exit(FAILURE);
	}
	game->grid = NULL;
	game->size.width = 0;
	game->size.height = 0;
	game->start.x = -1;
	game->start.y = -1;
	game->exit.x = -1;
	game->exit.y = -1;
	game->exit_reach = -1;
	game->collectibles = -1;
	game->valid_path = 0;
	game->player.moves = 0;
	return (game);
}

t_map	*ft_read_map(char *map, t_map *game)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error:\n Could not open te file properly.\n");
		exit(FAILURE);
	}
	game->grid = malloc(sizeof(char *) * (ft_count_lines(map, game) + 1));
	if (!game->grid)
	{
		ft_printf("Error:\nCould not allocate memory for grid.\n");
		ft_free_map(game);
		exit(ERROR);
	}
	line = get_next_line(fd);
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			game->grid[i] = ft_substr(line, 0, ft_strlen(line) - 1);
		else
			game->grid[i] = ft_strdup(line);
		if (!game->grid[i])
		{
			ft_printf("Error:\nCould not duplicate line.\n");
			free(line);
			ft_free_map(game);
			exit(ERROR);
		}
		free(line);
		i++;
		line = get_next_line(fd);
	}
	game->size.height = i;
	game->grid[i] = NULL;
	close(fd);
	return (game);
}

int	ft_count_lines(char *map,t_map *game)
{
	char	*line;
	int		len;
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error:\nCould not open the file to count lines.\n");
		ft_free_map(game);
		exit(ERROR);
	}
	line = get_next_line(fd);
	len = 0;
	while(line)
	{
		len++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (len);
}
