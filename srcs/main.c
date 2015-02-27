/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 16:57:16 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/02/27 16:10:19 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pokemon_hex.h"

t_win	*first_window(void *mlx, int argnum, char **argv)
{
	t_win	*win;

	ft_putendl("Creating window...");
	win = NULL;
	if (argnum < 2)
		win = gen_mlx_window(mlx, DEF_TITLE, DEF_X, DEF_Y);
	else if (argnum == 2)
		win = gen_mlx_window(mlx,
			DEF_TITLE, ft_atoi(argv[1]), ft_atoi(argv[1]));
	else if (argnum == 3)
		win = gen_mlx_window(mlx,
			DEF_TITLE, ft_atoi(argv[1]), ft_atoi(argv[2]));
	else if (argnum == 4)
		win = gen_mlx_window(mlx,
			argv[3], ft_atoi(argv[1]), ft_atoi(argv[2]));
	if (!win)
		fdf_error(NULL);
	return (win);
}

int			main(int argc, char **argv)
{
	t_env		env;

	if (argc < 2)
	{
		ft_putstr(USAGE);
		return (0);
	}
	ft_putendl("Initializing MLX...");
	if (argc == 2)
		env.win = first_window(mlx_init(), argc - 1, NULL);
	else
		env.win = first_window(mlx_init(), argc - 1, argv + 1);
	env.camera = gen_default_camera();
	env.update = 0;
	new_img(env.win);
	mlx_key_hook(env.win->win, hex_key_hook, &env);
	mlx_mouse_hook(env.win->win, hex_mouse_hook, &env);
	mlx_hook(env.win->win, 6, (1L << 6), hex_mouse_move_hook, &env);
	mlx_expose_hook(env.win->win, hex_expose_hook, &env);
	mlx_loop_hook(env.win->mlx, hex_loop_hook, &env);
	mlx_loop(env.win->mlx);
	return (0);
}
