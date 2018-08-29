/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 13:46:55 by fmadura           #+#    #+#             */
/*   Updated: 2018/08/29 13:55:44 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_env	*fractol_threadt(t_env *env, int line)
{
	double		x;
	double		y;
	int			pos;
	int			win;
	t_complex	c;

	--line;
	win = WIN_X * WIN_Y;
	pos = line * WIN_X;
	y = Y_START + ((double)(line) * E_ZOOM);
	c = env->c;
	while (y < Y_END && pos < win)
	{
		x = X_START;
		while (x < X_END && pos < win)
		{
			env->tab[pos] = env->algo(env, x, y, c);
			pos++;
			x += E_ZOOM;
		}
		y += (4 * E_ZOOM);
		pos += 3 * WIN_X;
	}
	return (env);
}

void	*launch_thread(void *arg)
{
	t_thread	*tmp;
	int			res;

	res = WIN_X * WIN_Y;
	tmp = (t_thread *)arg;
	fractol_threadt(tmp->env, tmp->nbr);
	pthread_exit(NULL);
}

void	set_thread(t_env *env)
{
	env->t1.env = env;
	env->t2.env = env;
	env->t3.env = env;
	env->t4.env = env;
	env->t1.nbr = 1;
	env->t2.nbr = 2;
	env->t3.nbr = 3;
	env->t4.nbr = 4;
}

int		init_thread(t_env *env)
{
	set_thread(env);
	if (pthread_create(&T_TH1, NULL, launch_thread, &(env->t1)))
		return (key_exit(53, env));
	if (pthread_create(&T_TH2, NULL, launch_thread, &(env->t2)))
		return (key_exit(53, env));
	if (pthread_create(&T_TH3, NULL, launch_thread, &(env->t3)))
		return (key_exit(53, env));
	if (pthread_create(&T_TH4, NULL, launch_thread, &(env->t4)))
		return (key_exit(53, env));
	if (pthread_join(T_TH1, NULL))
		return (key_exit(53, env));
	if (pthread_join(T_TH2, NULL))
		return (key_exit(53, env));
	if (pthread_join(T_TH3, NULL))
		return (key_exit(53, env));
	if (pthread_join(T_TH4, NULL))
		return (key_exit(53, env));
	return (0);
}
