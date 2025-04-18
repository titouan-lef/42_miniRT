/// @todo header

#include "minirt.h"

t_vec2	uv_sp(t_vec3 p, void *arg)
{
	t_vec2			uv;
	t_sphere_obj	*sp_obj;
	t_vec3			op;

	sp_obj = (t_sphere_obj *)arg;
	op = ft_diff_vec3(&p, &sp_obj->sp.pos);
	uv.x = acos(op.z / sp_obj->sp.r) / M_PI;
	if (uv.x == 1)
		uv.x = 0;
	uv.y = 0.5 + 0.5 * atan2(op.y, op.x) / M_PI;
	if (uv.y == 1)
		uv.y = 0;
	return (uv);
}

t_vec2	uv_pl(t_vec3 p, void *arg)
{
	t_vec2	uv;

	(void)arg;
	if (p.x >= 0)
		uv.x = p.x;
	else
		uv.x = -p.x + 0.5;
	if (p.z >= 0)
		uv.y = p.z;
	else
		uv.y = -p.z + 0.5;
	uv.x = fmod(uv.x, 1.0);
	uv.y = fmod(uv.y, 1.0);
	return (uv);
}

t_vec2	uv_cy(t_vec3 p, void *arg)
{
	t_vec2			uv;
	t_cylinder_obj	*cy_obj;
	t_vec3			op;
	t_intersec		*inter;
	double			m;

	inter = (t_intersec *)arg;
	cy_obj = (t_cylinder_obj *)inter->obj->data;
	op = ft_diff_vec3(&p, &cy_obj->cy.pos);
	m = ft_dot_vec3(&op, &cy_obj->cy.dir);
	uv.x = (m + cy_obj->cy.hh) / (2 * cy_obj->cy.hh);
	if (uv.x >= 1)
		uv.x = 0;
	uv.y = 0.5 + 0.5 * atan2(ft_dot_vec3(&op, &cy_obj->cy.right),
			ft_dot_vec3(&op, &cy_obj->cy.up)) / M_PI;
	if (uv.y >= 1)
		uv.y = 0;
	return (uv);
}

t_vec2	uv_co(t_vec3 p, void *arg)
{
	t_vec2		uv;
	t_cone_obj	*co_obj;
	t_vec3		op;
	t_intersec	*inter;
	double		m;

	inter = (t_intersec *)arg;
	co_obj = (t_cone_obj *)inter->obj->data;
	op = ft_diff_vec3(&p, &co_obj->co.pos);
	m = ft_dot_vec3(&op, &co_obj->co.dir);
	uv.x = (m + co_obj->co.h) / (2 * co_obj->co.h);
	if (uv.x >= 1)
		uv.x = 0;
	uv.y = 0.5 + 0.5 * atan2(ft_dot_vec3(&op, &co_obj->co.right),
			ft_dot_vec3(&op, &co_obj->co.up)) / M_PI;
	if (uv.y >= 1)
		uv.y = 0;
	return (uv);
}
