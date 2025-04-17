/// @todo header

#include "minirt.h"

static t_vec2	uv_sp(t_vec3 p, void *arg)
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

static t_vec2	uv_pl(t_vec3 p, void *arg)
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

static t_vec2	uv_cy(t_vec3 p, void *arg)
{
	t_vec2			uv;
	t_cylinder_obj	*cy_obj;
	double			theta;

	cy_obj = (t_cylinder_obj *)arg;
	theta = atan2(p.z, p.x);
	uv.x = (theta / (2 * M_PI));
	uv.y = p.y / cy_obj->cy.hh;
	return (uv);
}

static t_vec2	uv_co(t_vec3 p, void *arg)
{
	t_vec2			uv;
	t_cone_obj	*co_obj;
	double			theta;

	co_obj = (t_cone_obj *)arg;
	theta = atan2(p.z, p.x);
	uv.x = (theta / (2 * M_PI));
	uv.y = p.y / co_obj->co.h;
	return (uv);
}

static int	ft_exp(int n)
{
	int	result;

	result = 1;
	while (n > 0)
	{
		result *= 2;
		--n;
	}
	return (result);
}

static t_color	uv(t_color c[2], t_vec3 p, t_vec2 (*f)(t_vec3, void *), void *arg)
{
	const int	div = 3;
	int			sq;
	t_vec2		uv;

	uv = f(p, arg);
	sq = ft_exp(div);
	if ((int)fmod(uv.x * sq, 2) == (int)fmod(uv.y * sq, 2))
		return (c[0]);
	return (c[1]);
}

t_color	inv_color(t_color c)
{
	t_color	inv_c;

	inv_c = ft_color_create(255 - c.r, 255 - c.g, 255 - c.b, c.a);
	return (inv_c);
}

t_color	uv_manager(const t_intersec *inter, t_color c_obj)
{
	t_color	c;
	t_color	tab_c[2];

	tab_c[0] = c_obj;
	tab_c[1] = inv_color(c_obj);
	if (inter->obj->type == SPHERE)
		c = uv(tab_c, inter->soluce.p, &uv_sp, (void *)inter->obj->data);
	else if (inter->obj->type == PLANE)
		c = uv(tab_c, inter->soluce.p, &uv_pl, (void *)inter->obj->data);
	else if (inter->obj->type == CYLINDER)
		c = uv(tab_c, inter->soluce.p, &uv_cy, (void *)inter->obj->data);
	else
		c = uv(tab_c, inter->soluce.p, &uv_co, (void *)inter->obj->data);
	return (c);
}
