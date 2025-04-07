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

t_color	ft_scal_color(t_color color, double k)
{
	t_color	result;
	
	if (k < 0)
	{
		result.r = 0;
		result.g = 0;
		result.b = 0;
		//printf("%f\n", k);
	}
	else
	{
		if (k > 0 && color.r > 255.0 / k)
		result.r = 255;
		else
		result.r = color.r * k;
		if (k > 0 && color.g > 255.0 / k)
		result.g = 255;
		else
		result.g = color.g * k;
		if (k > 0 && color.b > 255.0 / k)
		result.b = 255;
		else
		result.b = color.b * k;
	}
	result.a = (uint8_t)255;
	return (result);
}

t_color	ft_mult_colors(t_color c1, t_color c2)
{
	t_color	result;

	int r, g, b;

	r = (int)c1.r * (int)c2.r / 255;
	g = (int)c1.g * (int)c2.g / 255;
	b = (int)c1.b * (int)c2.b / 255;

	result.r =  (uint8_t)r;
	result.g = (uint8_t)g;
	result.b = (uint8_t)b;
	result.a = (uint8_t)255;
	return (result);
}
