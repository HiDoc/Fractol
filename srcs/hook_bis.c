/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 17:37:27 by fmadura           #+#    #+#             */
/*   Updated: 2018/08/29 15:06:03 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			mouse_move(int x, int y, t_env *env)
{
	if (!env->flag)
		if (x > 0 && x <= WIN_X && y >= 0 && y <= WIN_Y)
		{
			if (E_ALG == julias || E_ALG == tripe || E_ALG == newton)
			{
				env->c.x = (((double)x - 400.0) / (double)WIN_X) * 8.0 / E_ZOOM;
				env->c.y = (((double)y - 400.0) / (double)WIN_Y) * 8.0 / E_ZOOM;
				if (E_ALG == newton)
				{
					env->c.x = (double)(x - 400) / (double)WIN_X;
					env->c.y = (double)(y - 400) / (double)WIN_Y;
				}
			}
			else
				env->color_modify = (x > y ? x : y) % 360;
			init_thread(env);
			mlx_clear_window(E_MLX, E_WIN);
			mlx_put_image_to_window(E_MLX, E_WIN, E_IMG, 0, 0);
		}
	return (1);
}

int			mouse_zoom(int button, int x, int y, t_env *env)
{
	X_START += (x - 400) * E_ZOOM;
	Y_START += (y - 400) * E_ZOOM;
	X_END += (x - 400) * E_ZOOM;
	Y_END += (y - 400) * E_ZOOM;
	if (button == 4)
		key_zoom(78, env);
	else if (button == 5)
		key_zoom(69, env);
	else
		return (0);
	mlx_clear_window(E_MLX, E_WIN);
	mlx_put_image_to_window(E_MLX, E_WIN, E_IMG, 0, 0);
	return (1);
}

int			key_hookbis(int keycode, void *param)
{
	t_env	*env;

	env = param;
	keycode == 18 ? E_ALG = &julias : 0;
	keycode == 19 ? E_ALG = &mandel : 0;
	keycode == 20 ? E_ALG = &newton : 0;
	keycode == 21 ? E_ALG = &tripe : 0;
	keycode == 23 ? E_ALG = &burnin : 0;
	keycode == 22 ? ft_ptr_swap(env, 2) : 0;
	keycode == 26 ? ft_ptr_swap(env, 1) : 0;
	keycode == 28 ? ft_ptr_swap(env, 3) : 0;
	keycode == 31 ? MAXITER += 10 : 0;
	keycode == 35 ? MAXITER -= 10 : 0;
	MAXITER <= 0 ? MAXITER = 1 : 0;
	printf("%d\n", keycode);
	init_thread(env);
	return (1);
}
