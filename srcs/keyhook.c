/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 18:00:03 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/26 21:32:13 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	key_move(int keycode, t_env *env)
{
	if (keycode == 123 || keycode == 124)
		env->move->x += keycode == 123 ? 1 : - 1;
	else if (keycode == 125 || keycode == 126)
		env->move->y += keycode == 125 ? 1 : - 1;
	else
		return (0);
	return (1);
}

int			key_zoom(int keycode, t_env *env)
{
	if (keycode == 69 || keycode == 78)
	{
		(void)env;
		return (1);
	}
	return (0);
}

static int	key_exit(int keycode, t_env *env)
{
	if (keycode == 53)
	{
		mlx_clear_window(env->mlx, env->win);
		mlx_destroy_window(env->mlx, env->win);
		exit(0);
	}
	return (0);
}

static int	key_color(int keycode, t_env *env)
{
	int x;
	int y;
	int pos;

	pos = 0;
	y = 0;
	if (keycode == 13)
	{
		while (y < WIN_Y)
		{
			x = 0;
			while (x < WIN_X)
			{
				env->tab[pos] = fractol_color_change(env->tab[pos], 10);
				pos++;
				x++;
			}
			y++;
		}
		print_color();
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
	hooked += key_move(keycode, env);
	hooked += key_zoom(keycode, env);
	hooked += key_color(keycode, env);
	hooked += key_exit(keycode, env);
	if (hooked)
	{
		mlx_clear_window(env->mlx, env->win);
		mlx_put_image_to_window(env->mlx, env->win, env->img, env->move->x, env->move->y);
	}
	return (1);
}
