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
	printf("%f, %f", uv.x, uv.y);
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
	dot2 = ft_dot_vec3(&p_resized, &pl_obj->up);
	uv.x = (fmod(dot1, 1) + 1) / 2.0;
	uv.y = (fmod(dot2, 1) + 1) / 2.0;
	return (uv);
}

t_vec2	uv_cy(t_vec3 p, void *arg)
{
	t_vec2			uv;
	t_cylinder_obj	*cy_obj;
	t_vec3			op;
	double			dot1;
	double			dot2;

	cy_obj = (t_cylinder_obj *)arg;
	op = ft_diff_vec3(&p, &cy_obj->cy.pos);
	dot1 = ft_dot_vec3(&op, &cy_obj->cy.dir);
	uv.x = 0.5 + 0.5 * dot1 / cy_obj->cy.hh;
	dot1 = ft_dot_vec3(&op, &cy_obj->cy.right);
	dot2 = ft_dot_vec3(&op, &cy_obj->cy.up);
	uv.y = 0.5 + 0.5 * atan2(dot1, dot2) / M_PI;
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
