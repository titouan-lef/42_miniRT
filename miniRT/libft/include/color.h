/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:43:06 by tle-floc          #+#    #+#             */
/*   Updated: 2024/12/23 15:20:08 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef struct s_color
{
	int	a;
	int	r;
	int	g;
	int	b;
}	t_color;

int		ft_create_rgb(t_color c);
int		ft_create_argb(t_color c);
t_color	ft_color_create(int a, int r, int g, int b);

#endif