/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 17:37:27 by fmadura           #+#    #+#             */
/*   Updated: 2018/08/21 17:43:55 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_move(int x, int y, t_env *env)
{
	if (E_ALG == julias || E_ALG == tripe || E_ALG == newton)
	{
		if (E_ALG == julias || E_ALG == tripe)
		{
			if (x > 0 && x <= WIN_X && y >= 0 && y <= WIN_Y)
			{
				env->c.x = (((double)x - 400.0) / (double)WIN_X) * 8.0 * E_ZOOM;
				env->c.y = (((double)y - 400.0) / (double)WIN_Y) * 8.0 * E_ZOOM;
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
		init_thread(env);
		mlx_clear_window(E_MLX, E_WIN);
		mlx_put_image_to_window(E_MLX, E_WIN, E_IMG, E_MOVX, E_MOVY);
	}
	else
	{
		env->color_modify = (x > y ? x : y) % 360;
		init_thread(env);
		mlx_clear_window(E_MLX, E_WIN);
		mlx_put_image_to_window(E_MLX, E_WIN, E_IMG, E_MOVX, E_MOVY);
	}
	return (1);
}


int			key_hookbis(int keycode, void *param)
{
	t_env	*env;
	int		hooked;

	env = param;
	hooked = 0;
	printf("%d\n", keycode);
	return (hooked);
}
