/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 16:57:16 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/03/01 19:32:37 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pokemon_hex.h"
// #include </opt/X11/include/X11/cursorfont.h>

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
		throw_error(NULL);
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
	ft_putstr("Initializing MLX...\n");
	if (argc == 2)
		env.win = first_window(mlx_init(), argc - 1, NULL);
	else
		env.win = first_window(mlx_init(), argc - 1, argv + 1);
	// XCreateFontCursor(env.win->mlx, 0);
	ft_putstr("Generating srand...\n");
	srand(time(NULL));
	ft_putstr("Generating pokemon database...\n");
	env.poke_db = gen_pokemon_data(env.win->mlx);
	ft_putstr("Generating sprite bank...\n");
	env.sprite_bank = gen_sprite_bank(env.win->mlx);
	ft_putstr("Generating map...\n");
	env.map = gen_map(&env);
	ft_putstr("Generating entities...\n");
	env.entities = gen_entities(&env);
	ft_putstr("Generating camera...\n");
	env.cam = gen_default_camera();
	ft_putstr("Setting initial env values...\n");
	env.mouse_x = 0;
	env.mouse_y = 0;
	env.update = 0;
	ft_putstr("Initializing Default Image...\n");
	new_img(env.win);
	ft_putstr("Initializing Sprite Image Data...\n");
	gen_sprite_data(env.win);
	ft_putstr("Setting MLX Hook Funtions...\n");
	mlx_key_hook(env.win->win, hex_key_hook, &env);
	mlx_mouse_hook(env.win->win, hex_mouse_hook, &env);
	mlx_hook(env.win->win, 6, (1L << 6), hex_mouse_move_hook, &env);
	mlx_expose_hook(env.win->win, hex_expose_hook, &env);
	mlx_loop_hook(env.win->mlx, hex_loop_hook, &env);
	ft_putstr("Initiating MLX Loop...\n");
	mlx_loop(env.win->mlx);
	return (0);
}
