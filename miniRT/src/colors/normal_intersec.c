/// @todo header

#include "minirt.h"

static t_vec3	get_normal_sphere(t_sphere_obj *sphere, t_intersec *inter)
{
	t_vec3	n;

	n = ft_diff_vec3(&inter->p, &sphere->sp.pos);
	n = ft_normalize_vec3(&n);
	return (n);
}

static t_vec3	get_normal_plane(t_vec3 *n_plane, t_intersec *inter)
{
	t_vec3	n;

	if (0.0 < ft_dot_vec3(n_plane, &inter->ray.dir))
		n = ft_scalmult_vec3(n_plane, -1);
	else
		n = *n_plane;
	return (n);
}

static t_vec3	get_normal_cylinder(t_cylinder_obj *cyl, t_intersec *inter)
{
	t_vec3	n;
	t_vec3	tmp_v;
	t_vec3	tmp_v2;
	double	m;

	tmp_v = ft_diff_vec3(&inter->p, &cyl->cy.pos);
	m = ft_dot_vec3(&tmp_v, &cyl->cy.dir);
	if (ft_distance_vec3(&cyl->mathcy.b, &inter->p) <= cyl->cy.r)
		n = get_normal_plane(&cyl->cy.dir, inter);
	else if (ft_distance_vec3(&cyl->mathcy.t, &inter->p) <= cyl->cy.r)
		n = get_normal_plane(&cyl->cy.dir, inter);
	else
	{
		tmp_v2 = ft_scalmult_vec3(&cyl->cy.dir, m);
		n = ft_diff_vec3(&tmp_v, &tmp_v2);
		n = ft_normalize_vec3(&n);
	}
	return (n);
}

static t_vec3	get_normal_cone(t_cone_obj *cone, t_intersec *inter)
{
	t_vec3	n;

	(void)inter;
	(void)cone;
	n = ft_create_vec3(0, 0, 0);
	//n = ft_diff_vec3(&inter->p, &cone->co);
	//n = ft_normalize_vec3(&n);
	return (n);
}

t_vec3	get_normal(t_intersec *inter)
{
	t_vec3	n;
	t_obj	*obj;

	obj = (t_obj *)inter->obj;
	if (obj->type == PLANE)
		n = get_normal_plane(&((t_plane_obj *)inter->obj->data)->pl.n, inter);
	else if (obj->type == SPHERE)
		n = get_normal_sphere((t_sphere_obj *)inter->obj->data, inter);
	else if (obj->type == CYLINDER)
		n = get_normal_cylinder((t_cylinder_obj *)inter->obj->data, inter);
	else
		n = get_normal_cone((t_cone_obj *)inter->obj->data, inter);
	return (n);
}
