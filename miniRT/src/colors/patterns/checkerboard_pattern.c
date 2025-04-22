/// @todo header

#include "minirt.h"

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

static t_color	uv(t_color c[2], t_vec3 p,
	t_vec2 (*f)(t_vec3, void *), void *arg)
{
	const int	div = 3;
	int			sq;
	t_vec2		uv;

	uv = f(p, arg);
	sq = ft_exp(div);
	uv = ft_scalmult_vec2(&uv, sq);
	if (uv.x >= sq)
		uv.x = sq - 1;
	if (uv.y >= sq)
		uv.y = sq - 1;
	if ((int)uv.x % 2 == (int)uv.y % 2)
		return (c[0]);
	return (c[1]);
}

static t_color	inv_color(t_color c)
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
