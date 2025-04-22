/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:43:06 by tle-floc          #+#    #+#             */
/*   Updated: 2025/04/22 18:00:59 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include <stdint.h>

typedef struct s_color
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;
}	t_color;

uint32_t	ft_get_rgb(t_color c);
uint32_t	ft_get_rgba(t_color c);
t_vec3		ft_color_to_vec3(const t_color *c);
t_color		ft_vec3_to_color(const t_vec3 *v, uint8_t a);
t_color		ft_color_create(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

#endif