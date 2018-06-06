/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 13:38:55 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/06 20:07:40 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static int mouse_move(int x, int y, t_env *env)
{
	(void)env;
	if (x > 0 && x <= WIN_X && y >= 0 && y <= WIN_Y)
	{
		env->c.x = (double)(x - 400) / (double)WIN_X * 2;	
		env->c.y = (double)(y - 400)/ (double)WIN_Y * 2;	
	}
	printf("%f , %f\n",env->c.x, env->c.y);
	env = fractol_iter(env, env->algo);
	mlx_clear_window(env->mlx, env->win);
	mlx_put_image_to_window(env->mlx, env->win, env->img, env->move->x, env->move->y);
	return (1);
}

int		main(int argc, char **argv)
{
	t_env	*env;

	if (argc > 1)
	{
		env = fractol_init();
		if (ft_strequ(argv[1], "Julia"))
			env->algo = &julias;
		else if (ft_strequ(argv[1], "Mandelbrot"))
			env->algo = &mandel;
		else if (ft_strequ(argv[1], "Burningship"))
			env->algo = &burnin;
		else if (ft_strequ(argv[1], "Newton"))
			env->algo = &newton;
		else if (ft_strequ(argv[1], "Tripe"))
			env->algo = &tripe;
		else
			return (0);
		env = fractol_iter(env, env->algo);
		mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
		mlx_key_hook(env->win, &key_hook, env);
		mlx_hook(env->win, 6, 3, mouse_move, env);
		mlx_loop(env->mlx);
	}
	return (0);
}
