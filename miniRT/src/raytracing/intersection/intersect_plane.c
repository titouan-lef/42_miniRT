/// @todo header

#include "minirt.h"

/**
 * @brief Get the factor t of the equation : p = s + t * dir.
 * p is the intersect point between the object and the ray.
 * s is the start of the ray.
 * dir is the direction of the ray.
 * t is a positive factor.
 * @param pl The plane.
 * @param os_dot_odir The dot product between the vecor (object-start ray) and
 * the object direction.
 * @param ray_dir The ray direction.
 * @return A positive double or INFINITY if there is no solution are an
 * infinity.
 */
static double	intersect_pl(const t_plane *pl, double os_dot_odir,
	const t_vec3 *ray_dir)
{
	double	t;
	double	raydir_dot_odir;

	raydir_dot_odir = ft_dot_vec3(&pl->n, ray_dir);
	t = solve_eq_pl(os_dot_odir, raydir_dot_odir);
	return (t);
}

/**
 * @brief Update the intersect structure if the point of intersection is closer
 * than the current one. If there is no intersection, nothing is updated.
 * @param obj The plane object.
 * @param inter The intersection structure.
 * @warning obj must be a plane object.
 */
void	intersect_ray_pl(const t_obj *obj, t_intersec *inter)
{
	t_plane_obj	*pl_obj;
	double		t;

	pl_obj = (t_plane_obj *)obj->data;
	t = intersect_pl(&pl_obj->pl, pl_obj->math_os_dot_odir, &inter->ray.dir);
	if (t >= inter->soluce.t - EPSILON)
		return ;
	inter->soluce.t = t;
	inter->obj = obj;
}

/**
 * @brief Get the factor t of the equation : p = s + t * dir.
 * p is the intersect point between the object and the ray.
 * s is the start of the ray.
 * dir is the direction of the ray.
 * t is a positive factor.
 * @param obj The plane object.
 * @param ray The ray.
 * @return A positive double or INFINITY if there is no solution.
 * @warning obj must be a plane object.
 */
double	intersect_light_pl(const t_obj *obj, const t_ray *ray)
{
	t_plane_obj	*pl_obj;
	double		t;
	double		os_dot_odir;

	pl_obj = (t_plane_obj *)obj->data;
	init_math_pl(&ray->s, &pl_obj->pl, &os_dot_odir);
	t = intersect_pl(&pl_obj->pl, os_dot_odir, &ray->dir);
	return (t);
}
