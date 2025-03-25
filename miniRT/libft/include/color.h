/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:43:06 by tle-floc          #+#    #+#             */
/*   Updated: 2025/03/25 10:38:00 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include <stdint.h>

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	a;
}	t_color;

uint32_t	ft_get_rgb(t_color c);
uint32_t	ft_get_rgba(t_color c);
t_color		ft_color_create(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

#endif