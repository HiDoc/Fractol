/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 13:38:55 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/01 16:39:08 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	t_env	*env;

	if (argc > 1)
	{
		env = fractol_init();
		if (ft_strequ(argv[1], "Julia"))
			env = fractol_iter(env, julias);
		else if (ft_strequ(argv[1], "Mandelbrot"))
			env = fractol_iter(env, mandel);
		else if (ft_strequ(argv[1], "Burningship"))
			env = fractol_iter(env, burnin);
		else if (ft_strequ(argv[1], "Newton"))
			env = fractol_iter(env, newton);
		else
			return (0);
		mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
		mlx_key_hook(env->win, &key_hook, env);
		mlx_loop(env->mlx);
	}
	return (0);
}
