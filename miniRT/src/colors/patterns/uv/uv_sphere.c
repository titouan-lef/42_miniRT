/// @todo header

#include "minirt.h"

static void	fill_uv(t_vec3 p, void *arg, t_vec2 *uv)
{
	t_sphere_obj	*sp_obj;
	t_vec3			op;

	sp_obj = (t_sphere_obj *)arg;
	op = ft_diff_vec3(&p, &sp_obj->sp.pos);
	uv->x = acos(op.z / sp_obj->sp.r) / M_PI;
	uv->y = 0.5 + 0.5 * atan2(op.y, op.x) / M_PI;
}

void	fill_uv_sp(t_intersec *inter)
{
	int	is_cb;
	int	is_bm;

	is_cb = inter->obj->pattern.checkerboard;
	is_bm = inter->obj->pattern.bump.name || inter->obj->pattern.texture.name;
	if (is_cb)
	{
		fill_uv(inter->soluce.p, (void *)inter->obj->data, &inter->uv_cb);
		if (is_bm)
			inter->uv_bm = inter->uv_cb;
	}
	else if (is_bm)
		fill_uv(inter->soluce.p, (void *)inter->obj->data, &inter->uv_bm);
}
