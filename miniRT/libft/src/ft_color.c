/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:44:34 by tle-floc          #+#    #+#             */
/*   Updated: 2025/03/25 10:37:22 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Get the rgb value.
 * @return A value with 0xRRGGBB format.
 * @warning The Alpha composant isn't taken into account.
 */
uint32_t	ft_get_rgb(t_color c)
{
	return (c.r << 16 | c.g << 8 | c.b);
}

/**
 * @brief Get the rgba value.
 * @return A value with 0xRRGGBBAA format.
 * @warning The Alpha composant is taken into account.
 */
uint32_t	ft_get_rgba(t_color c)
{
	uint32_t	rgb;

	rgb = ft_get_rgb(c);
	rgb = rgb << 8;
	return (rgb | c.a);
}

/**
 * @brief Create a color.
 * @param r Red.
 * @param g Green.
 * @param b Blue.
 * @param a Alpha.
 * @return A t_color structure.
 */
t_color	ft_color_create(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	t_color	c;

	c.r = r;
	c.g = g;
	c.b = b;
	c.a = a;
	return (c);
}
