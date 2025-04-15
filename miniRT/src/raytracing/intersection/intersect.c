/// @todo header

#include "minirt.h"

int	intersect_base(const t_vec3 *base_center, double r, double t,
	t_intersec *inter)
{
	t_vec3	p;

	if (t >= inter->soluce.t)
		return (0);
	p = ft_translation(&inter->ray.s, &inter->ray.dir, t);
	if (ft_distance_vec3(&p, base_center) > r)
		return (0);
	inter->soluce.t = t;
	inter->soluce.p = p;
	return (1);
}

void	update_n_soluce_lite(const t_vec3 *n, double raydir_dot_n,
	t_soluce *soluce)
{
	if (0 < raydir_dot_n)
		soluce->n = ft_scalmult_vec3(n, -1);
	else
		soluce->n = *n;
}

void	update_n_soluce(const t_vec3 *n, const t_vec3 *ray_dir,
	t_soluce *soluce)
{
	double	raydir_dot_n;

	raydir_dot_n = ft_dot_vec3(n, ray_dir);
	update_n_soluce_lite(n, raydir_dot_n, soluce);
}

void	update_soluce_sp(const t_obj *obj, const t_ray *ray, t_soluce *soluce)
{
	t_sphere_obj	*sp_obj;
	t_vec3			n;

	sp_obj = (t_sphere_obj *)obj->data;
	soluce->p = ft_translation(&ray->s, &ray->dir, soluce->t);
	n = ft_diff_vec3(&soluce->p, &sp_obj->sp.pos);
	n = ft_normalize_vec3(&n);
	update_n_soluce(&n, &ray->dir, soluce);
}

void	update_soluce_pl(const t_obj *obj, const t_ray *ray, t_soluce *soluce)
{
	t_plane_obj	*pl_obj;

	pl_obj = (t_plane_obj *)obj->data;
	soluce->p = ft_translation(&ray->s, &ray->dir, soluce->t);
	update_n_soluce(&pl_obj->pl.n, &ray->dir, soluce);
}
