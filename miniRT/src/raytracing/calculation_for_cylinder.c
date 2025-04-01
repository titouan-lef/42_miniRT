/// @todo header

#include "minirt.h"

t_vector3	calculation_born(t_vector3 c, t_vector3 n, double d)
{
	t_vector3	result;

	result = ft_scalarmult_vector3(n, d);
	result = ft_sum_vector3(c, result);
	return (result);
}

void	calculation_cyl_s(t_vector3 *cyl_s, t_vector3 ra1, t_vector3 ra2)
{
	*cyl_s = ft_diff_vector3(ra2, ra1);
	*cyl_s = ft_scalarmult_vector3(*cyl_s, 1.0 / ft_norm_vector3(*cyl_s));
}

void	calculation_cyl_ra0(t_vector3 *ra0, t_vector3 s, t_vector3 low,
			t_vector3 r0)
{
	*ra0 = ft_diff_vector3(r0, low);
	*ra0 = ft_crossproduct_vector3(s, *ra0);
	*ra0 = ft_crossproduct_vector3(*ra0, s);
}
