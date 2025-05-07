/// @todo header

#include "minirt.h"

/**
 * @brief Get the t factor of the intersection between a ray and a plane.
 * @param os_dot_odir dot product between vector(obj pos, ray start) and
 * object direction.
 * @param raydir_dot_odir dot product between ray direction and object
 * direction.
 */
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

/**
 * @brief Initialize the pre-calculated mathematics.
 * @param ray_s The start of the ray.
 * @param pl The plane.
 * @param mathpl The pre-calculated mathematics.
 */
void	init_math_pl(const t_vec3 *ray_s, const t_plane *pl, double *mathpl)
{
	*mathpl = pl->d + ft_dot_vec3(&pl->n, ray_s);
}
