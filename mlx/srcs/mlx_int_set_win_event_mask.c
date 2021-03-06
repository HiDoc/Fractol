/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_int_set_win_event_mask.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 20:26:32 by wescande          #+#    #+#             */
/*   Updated: 2018/07/26 19:27:04 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Mise a la norme par wescande
** mlx_int_set_win_event_mask.c for MiniLibX in
**
** Made by Charlie Root
** Login   <ol@epitech.net>
**
** Started on  Thu Aug  3 11:49:06 2000 Charlie Root
** Last update Fri Feb 23 17:07:42 2001 Charlie Root
*/

#include "mlx_int.h"

int	mlx_int_set_win_event_mask(t_xvar *xvar)
{
	t_win_list				*win;
	int						i;
	XSetWindowAttributes	xwa;

	win = xvar->win_list;
	while (win)
	{
		xwa.event_mask = 0;
		i = MLX_MAX_EVENT;
		while (i--)
			xwa.event_mask |= win->hooks[i].mask;
		XChangeWindowAttributes(xvar->display, win->window, CWEventMask, &xwa);
		win = win->next;
	}
	return (0);
}
