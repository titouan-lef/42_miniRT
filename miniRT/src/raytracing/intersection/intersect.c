/// @todo header

#include "minirt.h"

/**
 * @brief Update the soluce structure of inter if the point of intersection is
 * closer than the current one and on the cpas part of the object.
 * If there is no intersection, nothing is updated.
 * @details EPSILON allows to avoid nose when same objects are in the same
 * place.
 * @param base_center The base center of the object.
 * @param r The radius of the object.
 * @param t One of the two potential factors t of the infinite object.
 * @param inter The intersection structure.
 * @return 1 if the soluce structure is updated, 0 else.
 */
int	intersect_base(const t_vec3 *base_center, double r, double t,
	t_intersec *inter)
{
	t_vec3	p;
	t_vec3	pbase;
	double	sq_dist;

	if (t >= inter->soluce.t - EPSILON)
		return (0);
	p = ft_translation_vec3(&inter->ray.s, &inter->ray.dir, t);
	pbase = ft_diff_vec3(base_center, &p);
	sq_dist = ft_dot_vec3(&pbase, &pbase);
	if (sq_dist > r * r)
		return (0);
	inter->soluce.t = t;
	inter->soluce.p = p;
	return (1);
}

/**
 * @brief Update the direction of the normal when dot product is already
 * calculated.
 */
void	update_n_soluce_lite(const t_vec3 *n, double raydir_dot_n,
	t_soluce *soluce)
{
	if (0 < raydir_dot_n)
		soluce->n = ft_scalmult_vec3(n, -1);
	else
		soluce->n = *n;
}

/**
 * @brief Update the direction of the normal.
 */
void	update_n_soluce(const t_vec3 *n, const t_vec3 *ray_dir,
	t_soluce *soluce)
{
	double	raydir_dot_n;

	raydir_dot_n = ft_dot_vec3(n, ray_dir);
	update_n_soluce_lite(n, raydir_dot_n, soluce);
}

/**
 * @brief Update the soluce structure of the sphere.
 */
void	update_soluce_sp(const t_obj *obj, const t_ray *ray, t_soluce *soluce)
{
	t_sphere_obj	*sp_obj;
	t_vec3			n;

	sp_obj = (t_sphere_obj *)obj->data;
	soluce->p = ft_translation_vec3(&ray->s, &ray->dir, soluce->t);
	n = ft_create_normalized_vec3(&sp_obj->sp.pos, &soluce->p);
	update_n_soluce(&n, &ray->dir, soluce);
}

/**
 * @brief Update the soluce structure of the plane.
 */
void	update_soluce_pl(const t_obj *obj, const t_ray *ray, t_soluce *soluce)
{
	t_plane_obj	*pl_obj;

	pl_obj = (t_plane_obj *)obj->data;
	soluce->p = ft_translation_vec3(&ray->s, &ray->dir, soluce->t);
	update_n_soluce(&pl_obj->pl.n, &ray->dir, soluce);
}
