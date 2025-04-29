/// @todo header

#include "minirt.h"

static void	fill_uv(t_vec3 p, void *arg, t_vec2 *uv)
{
	t_cone_obj	*co_obj;
	t_vec3		op;
	double		dot1;
	double		dot2;

	co_obj = (t_cone_obj *)arg;
	op = ft_diff_vec3(&p, &co_obj->co.pos);
	dot1 = ft_dot_vec3(&op, &co_obj->co.dir);
	uv->x = 0.5 + dot1 / co_obj->co.h;
	dot1 = ft_dot_vec3(&op, &co_obj->co.right);
	dot2 = ft_dot_vec3(&op, &co_obj->co.up);
	uv->y = 0.5 + 0.5 * atan2(dot1, dot2) / M_PI;
}

void	fill_uv_co(t_intersec *inter)
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
