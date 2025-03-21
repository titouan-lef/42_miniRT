/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:44:34 by tle-floc          #+#    #+#             */
/*   Updated: 2024/12/23 16:28:30 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_create_rgb(t_color c)
{
	return (c.r << 16 | c.g << 8 | c.b);
}

int	ft_create_argb(t_color c)
{
	int	rgb;

	rgb = ft_create_rgb(c);
	return (c.a << 24 | rgb);
}

t_color	ft_color_create(int a, int r, int g, int b)
{
	t_color	c;

	c.a = a;
	c.r = r;
	c.g = g;
	c.b = b;
	return (c);
}
