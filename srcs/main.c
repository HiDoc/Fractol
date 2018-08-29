/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 22:14:59 by fmadura           #+#    #+#             */
/*   Updated: 2018/08/29 14:36:46 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static int	pstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		++str;
	}
	return (1);
}

static int	cmd(void)
{
	pstr("!     : Julia\n");
	pstr("@     : Mandelbrot\n");
	pstr("#     : Newton\n");
	pstr("$     : Tricorne\n");
	pstr("%     : Burningship\n");
	pstr("^     : Bichromoatic color\n");
	pstr("&     : Change color algorithmics\n");
	pstr("w     : Change colorr\n");
	pstr("move  : up, down, left, right\n");
	pstr("zoom  : mousewheel or + -\n");
	pstr("o     : iteration +\n");
	pstr("p     : iteration -\n");
	return (1);
}

static int	usage(void)
{
	pstr("usage: ./fractol fractal_name\n");
	pstr("\tfractal_name: Burningship, Julia,");
	pstr(" Mandelbrot, Newton, Tripe\n");
	return (0);
}

static void	launch(t_env *env)
{
	cmd();
	init_thread(env);
	mlx_do_key_autorepeaton(E_MLX);
	mlx_put_image_to_window(E_MLX, E_WIN, E_IMG, 0, 0);
	mlx_hook(E_WIN, 6, 3, mouse_move, env);
	mlx_mouse_hook(E_WIN, mouse_zoom, env);
	mlx_hook(E_WIN, KeyPress, KeyPressMask, &key_hook, env);
	mlx_loop(E_MLX);
}

int			main(int argc, char **argv)
{
	t_env	*env;
	int		(*algo)(t_env *env, double, double, t_complex c);

	if (argc > 1)
	{
		algo = NULL;
		if (ft_strequ(argv[1], "Julia"))
			algo = &julias;
		else if (ft_strequ(argv[1], "Mandelbrot"))
			algo = &mandel;
		else if (ft_strequ(argv[1], "Burningship"))
			algo = &burnin;
		else if (ft_strequ(argv[1], "Newton"))
			algo = &newton;
		else if (ft_strequ(argv[1], "Tripe"))
			algo = &tripe;
		if (algo == NULL)
			return (usage());
		env = fractol_init();
		E_ALG = algo;
		launch(env);
	}
	return (usage());
}
