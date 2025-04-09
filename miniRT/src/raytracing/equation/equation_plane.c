/// @todo header

#include "minirt.h"

double	solve_eq_pl(double os_dot_odir, double raydir_dot_odir)
{
	double	t;

	if (raydir_dot_odir == 0)
		return (INFINITY);
	t = -os_dot_odir / raydir_dot_odir;
	if (t < 1)
		return (INFINITY);
	return (t);
}

void	init_math_pl(const t_vec3 *ray_s, const t_plane *pl, double *mathpl)
{
	*mathpl = pl->d + ft_dot_vec3(&pl->n, ray_s);
}
