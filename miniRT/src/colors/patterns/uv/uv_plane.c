/// @todo header

#include "minirt.h"

static void	fill_uv(t_vec3 p, void *arg, t_vec2 *uv)
{
	t_plane_obj	*pl_obj;
	t_vec3		p_resized;
	double		dot1;
	double		dot2;

	pl_obj = (t_plane_obj *)arg;
	p_resized = ft_scalmult_vec3(&p, 0.01);
	dot1 = ft_dot_vec3(&p_resized, &pl_obj->right);
	uv->x = fmod(dot1, 1.0);
	if (uv->x < 0)
		uv->x = 1 + uv->x;
	dot2 = ft_dot_vec3(&p_resized, &pl_obj->up);
	uv->y = fmod(dot2, 1.0);
	if (uv->y < 0)
		uv->y = 1 + uv->y;
}

void	fill_uv_pl(t_intersec *inter)
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
