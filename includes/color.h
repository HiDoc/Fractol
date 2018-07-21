/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 18:26:17 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/21 18:40:03 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef struct s_rgb
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
}				t_rgb;

typedef struct s_hsv
{
	double h;
	double s;
	double v;
}				t_hsv;
#endif
