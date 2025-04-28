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
	uv.y = 0.5 + 0.5 * atan2(op.y, op.x) / M_PI;
	return (uv);
}

t_vec2	uv_pl(t_vec3 p, void *arg)
{
	t_vec2		uv;
	t_plane_obj	*pl_obj;
	t_vec3		p_resized;
	double		dot1;
	double		dot2;

	pl_obj = (t_plane_obj *)arg;
	p_resized = ft_scalmult_vec3(&p, 0.01);
	dot1 = ft_dot_vec3(&p_resized, &pl_obj->right);
	uv.x = fmod(dot1, 1.0);
	if (uv.x < 0)
		uv.x = 1 + uv.x;
	dot2 = ft_dot_vec3(&p_resized, &pl_obj->up);
	uv.y = fmod(dot2, 1.0);
	if (uv.y < 0)
		uv.y = 1 + uv.y;
	return (uv);
}

t_vec2	uv_cy(t_vec3 p, void *arg)
{
	t_vec2			uv;
	t_intersec		*inter;
	t_cylinder_obj	*cy_obj;
	t_vec3			op;
	double			dot[2];

	inter = (t_intersec *)arg;
	cy_obj = (t_cylinder_obj *)inter->obj->data;
	op = ft_diff_vec3(&p, &cy_obj->cy.pos);
	dot[0] = ft_dot_vec3(&op, &cy_obj->cy.right);
	dot[1] = ft_dot_vec3(&op, &cy_obj->cy.up);
	uv.y = 0.5 + 0.5 * atan2(dot[0], dot[1]) / M_PI;
	dot[0] = ft_dot_vec3(&op, &cy_obj->cy.dir);
	dot[1] = ft_dot_vec3(&inter->soluce.n, &cy_obj->cy.dir);
	dot[1] = fabs(dot[1]);
	if (dot[1] > 0.9)
	{
		op = ft_scalmult_vec3(&cy_obj->cy.dir, -dot[0]);
		op = ft_sum_vec3(&p, &op);
		uv.x = ft_distance_vec3(&op, &cy_obj->cy.pos);
		uv.x = uv.x / cy_obj->cy.r;
		return (uv);
	}
	uv.x = 0.5 + 0.5 * dot[0] / cy_obj->cy.hh;
	return (uv);
}

t_vec2	uv_co(t_vec3 p, void *arg)
{
	t_vec2		uv;
	t_cone_obj	*co_obj;
	t_vec3		op;
	double		dot1;
	double		dot2;

	co_obj = (t_cone_obj *)arg;
	op = ft_diff_vec3(&p, &co_obj->co.pos);
	dot1 = ft_dot_vec3(&op, &co_obj->co.dir);
	uv.x = 0.5 + dot1 / co_obj->co.h;
	dot1 = ft_dot_vec3(&op, &co_obj->co.right);
	dot2 = ft_dot_vec3(&op, &co_obj->co.up);
	uv.y = 0.5 + 0.5 * atan2(dot1, dot2) / M_PI;
	return (uv);
}
