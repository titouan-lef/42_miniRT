/// @todo header

#include "minirt.h"

t_color	ft_sum_colors(t_color c1, t_color c2)
{
	t_color	result;

	if (c1.r > 255 - c2.r)
		result.r = 255;
	else
		result.r = c1.r + c2.r;
	if (c1.g > 255 - c2.g)
		result.g = 255;
	else
		result.g = c1.g + c2.g;
	if (c1.b > 255 - c2.b)
		result.b = 255;
	else
		result.b = c1.b + c2.b;
	result.a = (uint8_t)255;
	return (result);
}

t_color	ft_dif_colors(t_color c1, t_color c2)
{
	t_color	result;

	if (c1.r < 0 + c2.r)
		result.r = 0;
	else
		result.r = c1.r - c2.r;
	if (c1.g < 0 + c2.g)
		result.g = 0;
	else
		result.g = c1.g - c2.g;
	if (c1.b < 0 + c2.b)
		result.b = 0;
	else
		result.b = c1.b - c2.b;
	result.a = (uint8_t)255;
	return (result);
}

static uint8_t 	ft_clamp(uint8_t color, double k)
{
	if (k > 0 && color > 255.0 / k)
		return (255);
	else
		return (color * k);
}
t_color	ft_scal_color(t_color color, double k)
{
	t_color	result;

	if (k < 0)
		result = ft_color_create(0, 0, 0, 255);
	else
	{
		result.r = ft_clamp(color.r, k);
		result.g = ft_clamp(color.g, k);
		result.b = ft_clamp(color.b, k);
		result.a = (uint8_t)255;
	}
	return (result);
}

t_color	ft_mult_colors(t_color c1, t_color c2)
{
	t_color	result;
	int		r;
	int		g;
	int		b;

	r = (int)c1.r * (int)c2.r / 255;
	g = (int)c1.g * (int)c2.g / 255;
	b = (int)c1.b * (int)c2.b / 255;
	result.r = (uint8_t)r;
	result.g = (uint8_t)g;
	result.b = (uint8_t)b;
	result.a = (uint8_t)255;
	return (result);
}
