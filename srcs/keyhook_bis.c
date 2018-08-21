/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 18:00:03 by fmadura           #+#    #+#             */
/*   Updated: 2018/08/20 15:19:53 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			key_hookbis(int keycode, void *param)
{
	t_env	*env;
	int		hooked;

	env = param;
	hooked = 0;
	if (keycode == 1)
		return (0);
	return (hooked);
}
