/// @todo header

#include "minirt.h"

/*static t_vec3	get_normal_sphere(const t_sphere_obj *sphere,
	const t_intersec *inter)
{
	t_vec3	n;

	n = ft_diff_vec3(&inter->soluce.p, &sphere->sp.pos);
	n = ft_normalize_vec3(&n);
	return (n);
}

static t_vec3	get_normal_plane(const t_vec3 *n_plane, const t_intersec *inter)
{
	t_vec3	n;

	if (0.0 < ft_dot_vec3(n_plane, &inter->ray.dir))
		n = ft_scalmult_vec3(n_plane, -1);
	else
		n = *n_plane;
	return (n);
}

static t_vec3	get_normal_cylinder(const t_cylinder_obj *cyl,
	const t_intersec *inter)
{
	t_vec3	n;
	t_vec3	op;
	t_vec3	m_odir;
	double	m;

	if (ft_distance_vec3(&cyl->mathcy.b, &inter->p) <= cyl->cy.r
		|| ft_distance_vec3(&cyl->mathcy.t, &inter->p) <= cyl->cy.r)
		n = get_normal_plane(&cyl->cy.dir, inter);
	else
	{
		op = ft_diff_vec3(&inter->p, &cyl->cy.pos);
		m = ft_dot_vec3(&op, &cyl->cy.dir);
		m_odir = ft_scalmult_vec3(&cyl->cy.dir, m);
		n = ft_diff_vec3(&op, &m_odir);
		n = ft_normalize_vec3(&n);
	}
	return (n);
}

static t_vec3	get_normal_cone(const t_cone_obj *co_obj,
	const t_intersec *inter)
{
	t_vec3	n;
	t_vec3	bp;
	t_vec3	m_odir;
	double	m;

	bp = ft_diff_vec3(&inter->soluce.p, &co_obj->mathco.b);
	m = ft_dot_vec3(&bp, &co_obj->co.dir);
	if (m >= co_obj->co.h - 0.01)
		n = get_normal_plane(&co_obj->co.dir, inter);
	else
	{
		m_odir = ft_scalmult_vec3(&co_obj->co.dir, m);
		n = ft_translation(&bp, &m_odir, -co_obj->mathco.c_factor);
		n = ft_normalize_vec3(&n);
	}
	return (n);
}

t_vec3	get_normal(const t_intersec *inter)
{
	const t_obj	*obj;
	t_vec3		n;

	obj = inter->obj;
	if (obj->type == PLANE)
		n = get_normal_plane(&((t_plane_obj *)obj->data)->pl.n, inter);
	else if (obj->type == SPHERE)
		n = get_normal_sphere((t_sphere_obj *)obj->data, inter);
	else if (obj->type == CYLINDER)
		n = inter->soluce.n;
	else
		n = get_normal_cone((t_cone_obj *)obj->data, inter);
	return (n);
}*/
