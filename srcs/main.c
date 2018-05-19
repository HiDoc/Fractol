/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 13:38:55 by fmadura           #+#    #+#             */
/*   Updated: 2018/05/19 19:26:45 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(void)
{
	t_env	*env;

	env = fractol_init();
	env = fractol_iter(env, mandel);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_key_hook(env->win, &key_hook, env);
	mlx_loop(env->mlx);
	return (0);
}
