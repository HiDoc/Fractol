/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 22:14:59 by fmadura           #+#    #+#             */
/*   Updated: 2018/08/02 20:32:39 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static int	mouse_move(int x, int y, t_env *env)
{
	if (E_ALG == julias || E_ALG == tripe || E_ALG == newton)
	{
		if (E_ALG == julias || E_ALG == tripe)
		{
			if (x > 0 && x <= WIN_X && y >= 0 && y <= WIN_Y)
			{
				env->c.x = (double)(x - 400) / (double)WIN_X * 8;
				env->c.y = (double)(y - 400) / (double)WIN_Y * 8;
			}
		}
		else
		{
			if (x > 0 && x <= WIN_X && y >= 0 && y <= WIN_Y)
			{
				env->c.x = (double)(x - 400) / (double)WIN_X * 2;
				env->c.y = (double)(y - 400) / (double)WIN_Y * 2;
			}
		}
		env = fractol_iter(env);
		mlx_clear_window(E_MLX, E_WIN);
		mlx_put_image_to_window(E_MLX, E_WIN, E_IMG, E_MOVX, E_MOVY);
	}
	return (1);
}

static int	usage(void)
{
	ft_putstr("usage: ./fractol fractal_name\n", 2);
	ft_putstr("\tfractal_name: Burningship, Julia,", 2);
	ft_putstr(" Mandelbrot, Newton, Tripe\n", 2);
	return (0);
}

static void	launch(t_env *env)
{
	env = fractol_iter(env);
	mlx_put_image_to_window(E_MLX, E_WIN, E_IMG, 0, 0);
	mlx_key_hook(E_WIN, &key_hook, env);
	mlx_hook(E_WIN, 6, 3, mouse_move, env);
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
