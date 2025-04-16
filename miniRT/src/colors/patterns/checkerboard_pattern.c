/// @todo header

#include "minirt.h"
 
t_vec2 uv_sp(t_vec3 p, void *ts)
{
	t_vec2	result;

	(void)ts;
	result.x = fmod(p.x, 2.0);
	result.y = fmod(p.y, 2.0);
	return (result);
}
t_vec2 uv_pl(t_vec3 p, void *ts)
{
	t_vec2	result;

	(void)ts;

	if (p.x >= 0)
		result.x = p.x;
	else
		result.x = -p.x + 0.5;
	if (p.z >= 0)
		result.y = p.z;
	else
		result.y = -p.z + 0.5;
	result.x = fmod(result.x, 1.0);
	result.y = fmod(result.y, 1.0);
	return (result);
}
t_vec2 uv_cy(t_vec3 p, void *ts)
{
	t_vec2	result;

	(void)ts;
	result.x = p.x / 2;
	result.y = p.y / 2;
	return (result);
}
t_vec2 uv_co(t_vec3 p, void *ts)
{
	t_vec2	result;

	(void)ts;
	result.x = p.x / 2;
	result.y = p.y / 2;
	return (result);
}

t_color uv(t_color c[2], t_vec3 p, t_vec2 (*f)(t_vec3, void *))
{
	t_vec2	uv;

	uv = f(p, NULL);
	if ((uv.x < 0.5 && uv.y < 0.5) || ((uv.x >= 0.5 && uv.y >= 0.5)))
		return (c[0]);
	else
		return (c[1]);
}

t_color inv_color(t_color c)
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
		c = uv(tab_c, inter->soluce.p, &uv_sp);
	else if (inter->obj->type == PLANE)
		c = uv(tab_c, inter->soluce.p, &uv_pl);
	else if (inter->obj->type == CYLINDER)
		c = uv(tab_c, inter->soluce.p, &uv_cy);
	else
		c = uv(tab_c, inter->soluce.p, &uv_co);
	return (c);
}
