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
