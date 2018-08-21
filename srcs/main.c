/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 22:14:59 by fmadura           #+#    #+#             */
/*   Updated: 2018/08/21 17:37:40 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static int	usage(void)
{
	printf("usage: ./fractol fractal_name\n");
	printf("\tfractal_name: Burningship, Julia,");
	printf(" Mandelbrot, Newton, Tripe\n");
	return (0);
}

static void	launch(t_env *env)
{
	init_thread(env);
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
