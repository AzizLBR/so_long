/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:08:07 by aloubar           #+#    #+#             */
/*   Updated: 2021/10/13 22:40:36 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int ft_esc_press(t_game *game)
{
	ft_exit_game(game);
	exit(0);
	return (1);
}

static int	ft_key_press(int keypressed, t_game *game)
{
	if (keypressed == 0)
		ft_mooveleft(game);
	if (keypressed == 2)
		ft_mooveright(game);
	if (keypressed == 1)
		ft_moovedown(game);
	if (keypressed == 13)
		ft_mooveup(game);
	if (keypressed == 53)
		ft_exit_game(game);
	return (keypressed);
}

static int	ft_color(t_game *game)
{
	int i;
	int j;

	i = -1;
	while (++i < game->y)
	{
		j = -1;
		while (++j < game->x)
		{
			if (game->map[i][j] == '1')
			{
				mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.mlx_win,
				game->mlx.txt[0], j * 16, i * 16);
			}
			if (game->map[i][j] == '0')
			{
				mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.mlx_win,
				game->mlx.txt[1], j * 16, i * 16);
			}
			if (game->map[i][j] == 'C')
			{
				mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.mlx_win,
				game->mlx.txt[3], j * 16, i * 16);
			}
			if (game->map[i][j] == 'E')
			{
				mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.mlx_win,
				game->mlx.txt[4], j * 16, i * 16);
			}
			mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.mlx_win,
			game->mlx.txt[2], game->player_position[0] * 16,
			game->player_position[1] * 16);
		}
	}
	return (1);
}

static void	ft_texture_loading(t_game *game)
{
	char **path_of_img;
	int i;

	path_of_img = ft_split(PATH, ' ');
	i = 0;
	while (i < 5)
	{
		if (path_of_img[i] == NULL)
		{
			ft_putendl_fd("Mlx Error", 2);
			ft_free(game);
			ft_free_tab(path_of_img);
			exit(0);
		}
		game->mlx.txt[i] = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			path_of_img[i], &game->mlx.xwidth, &game->mlx.yheight);
		i++;
	}
	ft_free_tab(path_of_img);
}

int minilib(t_game *game)
{
	game->mlx.mlx_ptr = mlx_init();
	if (game->mlx.mlx_ptr == NULL)
	{
		ft_putendl_fd("Mlx Error.", 2);
		ft_free(game);
		return (0);
	}
	ft_texture_loading(game);
	game->mlx.res_x = (int)(game->x * game->mlx.xwidth);
	game->mlx.res_y = (int)(game->y * game->mlx.yheight);
	game->mlx.mlx_win = mlx_new_window(game->mlx.mlx_ptr, game->mlx.res_x, game->mlx.res_y, "So_long");
	if (game->mlx.mlx_win == NULL)
	{
		ft_putendl_fd("Mlx Errir.", 2);
		return (0);
	}
	game->mlx.mlx_img = mlx_new_image(game->mlx.mlx_ptr, game->mlx.res_x, game->mlx.res_y);
	if (game->mlx.mlx_img == NULL)
	{
		ft_putendl_fd("Mlx Erryr.", 2);
		return (0);
	}
	mlx_hook(game->mlx.mlx_win, 2, 1L << 0, ft_key_press, game);
	mlx_hook(game->mlx.mlx_win, 33, 1L << 5, ft_esc_press, game);
	mlx_loop_hook(game->mlx.mlx_ptr, ft_color, game);
	mlx_loop(game->mlx.mlx_ptr);
	return (0);
}
