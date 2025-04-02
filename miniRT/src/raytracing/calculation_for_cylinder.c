/// @todo header

#include "minirt.h"

t_vector3	calculation_born(t_vector3 pos, t_vector3 dir, double dist)
{
	t_vector3	result;

	result = ft_scalarmult_vector3(dir, dist);
	result = ft_sum_vector3(pos, result);
	return (result);
}
