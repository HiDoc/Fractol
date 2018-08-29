/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 17:37:02 by fmadura           #+#    #+#             */
/*   Updated: 2018/08/29 17:49:16 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	key_move(int keycode, t_env *env)
{
	if (keycode == 123 || keycode == 124)
	{
		X_START += (keycode == 123 ? 10.0 : -10.0) * E_ZOOM;
		X_END += (keycode == 123 ? 10.0 : -10.0) * E_ZOOM;
	}
	else if (keycode == 125 || keycode == 126)
	{
		Y_START -= (keycode == 125 ? 10.0 : -10.0) * E_ZOOM;
		Y_END -= (keycode == 125 ? 10.0 : -10.0) * E_ZOOM;
	}
	else
		return (0);
	init_thread(env);
	return (1);
}

int			key_zoom(int keycode, t_env *env)
{
	if (keycode == 69 || keycode == 78)
	{
		E_PAD /= (keycode == 69 ? 1.0 : 0.5);
		X_START += E_PAD * (keycode == 69 ? 1.0 : -1.0);
		Y_START += E_PAD * (keycode == 69 ? 1.0 : -1.0);
		X_END -= E_PAD * (keycode == 69 ? 1.0 : -1.0);
		Y_END -= E_PAD * (keycode == 69 ? 1.0 : -1.0);
		E_PAD /= (keycode == 69 ? 2.0 : 1.0);
		E_ZOOM /= (keycode == 69 ? 2.0 : 0.5);
		init_thread(env);
		return (1);
	}
	return (0);
}

int			key_exit(int keycode, t_env *env)
{
	if (keycode == 53)
	{
		mlx_clear_window(env->mlx, env->win);
		mlx_destroy_window(env->mlx, env->win);
		free(env->move);
		free(env->wind);
		free(env);
		exit(0);
	}
	return (0);
}

static int	key_color(int keycode, t_env *env)
{
	if (keycode == 13)
	{
		env->color_modify += 10.0;
		if (env->color_modify > 360.0)
			env->color_modify = 0.0;
		init_thread(env);
		return (1);
	}
	return (0);
}

int			key_hook(int keycode, void *param)
{
	t_env	*env;
	int		hooked;

	env = param;
	hooked = 0;
	if (keycode == 49)
		env->flag = env->flag ^ 1;
	keycode == 15 ? set_zero(env) : 0;
	hooked += key_move(keycode, env);
	hooked += key_zoom(keycode, env);
	hooked += key_color(keycode, env);
	hooked += key_exit(keycode, env);
	hooked += key_hookbis(keycode, env);
	if (hooked)
	{
		mlx_clear_window(env->mlx, env->win);
		mlx_put_image_to_window(E_MLX, E_WIN, E_IMG, 0, 0);
	}
	return (1);
}
