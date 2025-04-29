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
	if (inter->obj->pattern.checkerboard)
	{
		fill_uv(inter->soluce.p, (void *)inter->obj->data, &inter->uv_cb);
		if (inter->obj->pattern.bump.name != NULL)
			inter->uv_bm = inter->uv_cb;
	}
	else if (inter->obj->pattern.bump.name != NULL)
		fill_uv(inter->soluce.p, (void *)inter->obj->data, &inter->uv_bm);
}
