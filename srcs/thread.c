/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 13:46:55 by fmadura           #+#    #+#             */
/*   Updated: 2018/08/21 17:35:48 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_env		*fractol_thread(t_env *env, int start, int end)
{
	double		x;
	double		y;
	int			pos;
	t_complex	c;

	pos = start;
	y = Y_START + (pos * E_ZOOM) / 800.0;
	c = env->c;
	while (y < Y_END && pos < WIN_X * WIN_Y & pos < end)
	{
		x = X_START + pos % 800;
		while (x < X_END && pos < WIN_X * WIN_Y && pos < end)
		{
			env->tab[pos] = env->algo(env, x, y, c);
			pos++;
			x += E_ZOOM;
		}
		y += E_ZOOM;
	}
	return (env);
}

void *launch_thread(void *arg)
{
	t_thread	*tmp;
	int			res;

	res = WIN_X * WIN_Y;
	tmp = (t_thread *)arg;
	if (tmp->nbr == 1)
		fractol_thread(tmp->env, 0, res * 0.25 - 1);
	if (tmp->nbr == 2)
		fractol_thread(tmp->env, res * 0.25, res * 0.50 - 1);
	if (tmp->nbr == 3)
		fractol_thread(tmp->env, res * 0.50, res * 0.75 - 1);
	if (tmp->nbr == 4)
		fractol_thread(tmp->env, res * 0.75, res);
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

int init_thread(t_env *env)
{
	set_thread(env);
	if (pthread_create(&T_TH1, NULL, launch_thread, &(env->t1)))
	{
		perror("pthread_create");
		return EXIT_FAILURE;
	}
	if (pthread_create(&T_TH2, NULL, launch_thread, &(env->t2)))
	{
		perror("pthread_create");
		return EXIT_FAILURE;
	}
	if (pthread_create(&T_TH3, NULL, launch_thread, &(env->t3)))
	{
		perror("pthread_create");
		return EXIT_FAILURE;
	}
	if (pthread_create(&T_TH4, NULL, launch_thread, &(env->t4)))
	{
		perror("pthread_create");
		return EXIT_FAILURE;
	}	
	if (pthread_join(T_TH1, NULL))
	{
		perror("pthread_join");
		return EXIT_FAILURE;
	}
	if (pthread_join(T_TH2, NULL))
	{
		perror("pthread_join");
		return EXIT_FAILURE;
	}
	if (pthread_join(T_TH3, NULL))
	{
		perror("pthread_join");
		return EXIT_FAILURE;
	}
	if (pthread_join(T_TH4, NULL))
	{
		perror("pthread_join");
		return EXIT_FAILURE;
	}
	return (0);
}
