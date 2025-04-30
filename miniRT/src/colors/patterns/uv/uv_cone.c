/// @todo header

#include "minirt.h"

static void	fill_uv_cb_caps(t_vec3 p, t_cone_obj *co_obj, t_vec2 *uv)
{
	t_vec3	op;
	double	dot[2];

	op = ft_diff_vec3(&p, &co_obj->co.pos);
	uv->x = 1;
	dot[0] = ft_dot_vec3(&op, &co_obj->co.right);
	dot[1] = ft_dot_vec3(&op, &co_obj->co.up);
	uv->y = 0.5 + 0.5 * atan2(dot[0], dot[1]) / M_PI;
}

static void	fill_uv_bm_caps(t_vec3 p, t_cone_obj *co_obj, t_vec2 *uv)
{
	t_vec3	op;

	op = ft_diff_vec3(&p, &co_obj->co.pos);
	uv->x = ft_dot_vec3(&op, &co_obj->co.right);
	uv->x = 0.5 - 0.5 * uv->x / co_obj->co.r;
	uv->y = ft_dot_vec3(&op, &co_obj->co.up);
	uv->y = 0.5 + 0.5 * uv->y / co_obj->co.r;
}

static void	fill_uv_lateral(t_vec3 p, t_cone_obj *co_obj, t_vec2 *uv)
{
	t_vec3	op;
	double	dot1;
	double	dot2;

	op = ft_diff_vec3(&p, &co_obj->co.pos);
	dot1 = ft_dot_vec3(&op, &co_obj->co.dir);
	uv->x = 0.5 - dot1 / co_obj->co.h;
	dot1 = ft_dot_vec3(&op, &co_obj->co.right);
	dot2 = ft_dot_vec3(&op, &co_obj->co.up);
	uv->y = 0.5 + 0.5 * atan2(dot1, dot2) / M_PI;
}

static void	manage_fill(t_intersec *inter, int is_cb, int is_bm)
{
	t_cone_obj	*co_obj;
	double		dot;

	co_obj = (t_cone_obj *)inter->obj->data;
	dot = ft_dot_vec3(&inter->soluce.n, &co_obj->co.dir);
	if (fabs(dot) < 0.9)
	{
		if (is_cb)
		{
			fill_uv_lateral(inter->soluce.p, co_obj, &inter->uv_cb);
			if (is_bm)
				inter->uv_bm = inter->uv_cb;
		}
		else if (is_bm)
			fill_uv_lateral(inter->soluce.p, co_obj, &inter->uv_bm);
	}
	else
	{
		if (is_cb)
			fill_uv_cb_caps(inter->soluce.p, co_obj, &inter->uv_cb);
		if (is_bm)
			fill_uv_bm_caps(inter->soluce.p, co_obj, &inter->uv_bm);
	}
}

void	fill_uv_co(t_intersec *inter)
{
	int	is_cb;
	int	is_bm;

	is_cb = inter->obj->pattern.checkerboard;
	is_bm = inter->obj->pattern.bump.name || inter->obj->pattern.texture.name;
	if (is_cb || is_bm)
		manage_fill(inter, is_cb, is_bm);
}
