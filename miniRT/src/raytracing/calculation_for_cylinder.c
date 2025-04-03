/// @todo header

#include "minirt.h"

t_vec3	calculation_born(t_vec3 pos, t_vec3 dir, double dist)
{
	t_vec3	result;

	result = ft_scalarmult_vec3(&dir, dist);
	result = ft_sum_vec3(&pos, &result);
	return (result);
}
