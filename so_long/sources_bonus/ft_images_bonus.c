/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_images_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:15:48 by davigome          #+#    #+#             */
/*   Updated: 2024/11/29 23:40:18 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_load_textures(t_map *game)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("images/luffy.png");
	if (!texture)
		exit(ERROR);
	game->images.player = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("images/wall_2.png");
	if (!texture)
		exit(ERROR);
	game->images.wall = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("images/zoro_chibi.png");
	if (!texture)
		exit(ERROR);
	game->images.collectibles = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("images/zoro.png");
	if (!texture)
		exit(ERROR);
	game->images.exit = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	ft_load_textures_2(game);
}

void	ft_load_textures_2(t_map *game)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("images/floor.png");
	if (!texture)
		exit(ERROR);
	game->images.floor = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("images/mihawk.png");
	if (!texture)
		exit(ERROR);
	game->images.enemy = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
}

void	ft_render_map(t_map *game)
{
	int	y;
	int	x;

	y = -1;
	x = -1;
	ft_render_background(game);
	while (++y < game->size.height)
	{
		x = -1;
		while (++x < game->size.width)
		{
			if (game->grid[y][x] == 'C')
				mlx_image_to_window(game->mlx, game->images.collectibles,
					x * 64, y * 64);
			if (game->grid[y][x] == 'E')
				mlx_image_to_window(game->mlx, game->images.exit,
					x * 64, y * 64);
			if (game->grid[y][x] == 'P')
				mlx_image_to_window(game->mlx, game->images.player,
					x * 64, y * 64);
			if (game->grid[y][x] == 'X')
				mlx_image_to_window(game->mlx, game->images.enemy,
					x * 64, y * 64);
		}
	}
}

void	ft_render_background(t_map *game)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (game->grid[++y])
	{
		x = -1;
		while (game->grid[y][++x])
			mlx_image_to_window(game->mlx, game->images.floor, x * 64, y * 64);
	}
	y = -1;
	while (game->grid[++y])
	{
		x = -1;
		while (game->grid[y][++x])
		{
			if (game->grid[y][x] == '1')
				mlx_image_to_window(game->mlx, game->images.wall,
					x * 64, y * 64);
		}
	}
	ft_print_move(game);
	ft_cont_collectables(game);
}
