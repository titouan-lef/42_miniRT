/// @todo header

#include "minirt.h"

static t_color	ft_saturation_colors(t_color color)
{
	t_color	result;

	result.r = (uint8_t)fmin(color.r, 255);
	result.r = (uint8_t)fmax(color.r, 0);
	result.g = (uint8_t)fmin(color.g, 255);
	result.g = (uint8_t)fmax(color.g, 0);
	result.b = (uint8_t)fmin(color.b, 255);
	result.b = (uint8_t)fmax(color.b, 0);
	result.a = (uint8_t)255;
	return (result);
}

t_color	ft_sum_colors(t_color c1, t_color c2)
{
	t_color	result;

	result.r = c1.r + c2.r;
	result.g = c1.g + c2.g;
	result.b = c1.b + c2.b;
	result.a = (uint8_t)255;
	result = ft_saturation_colors(result);
	return (result);
}

t_color	ft_scalprod_color(t_color color, double k)
{
	t_color	result;

	result.r = color.r * k;
	result.g = color.g * k;
	result.b = color.b * k;
	result.a = (uint8_t)255;
	result = ft_saturation_colors(result);
	return (result);
}

t_color	ft_multipl_colors(t_color c1, t_color c2)
{
	t_color	result;

	result.r = c1.r * c2.r / 255;
	result.g = c1.g * c2.g / 255;
	result.b = c1.b * c2.b / 255;
	result.a = (uint8_t)255;
	return (result);
}
