/// @todo header

#include "minirt.h"

static void	fill_uv_cb_caps(const t_vec3 *op, const t_cone *co, t_vec2 *uv)
{
	double	right_ratio;
	double	up_ratio;

	uv->x = 1;
	right_ratio = ft_dot_vec3(op, &co->right);
	up_ratio = ft_dot_vec3(op, &co->up);
	uv->y = 0.5 + 0.5 * atan2(right_ratio, up_ratio) / M_PI;
}

static void	fill_uv_bm_caps(const t_vec3 *op, const t_cone *co, t_vec2 *uv)
{
	double	right_ratio;
	double	up_ratio;

	right_ratio = ft_dot_vec3(op, &co->right);
	uv->x = 0.5 - 0.5 * right_ratio / co->r;
	up_ratio = ft_dot_vec3(op, &co->up);
	uv->y = 0.5 + 0.5 * up_ratio / co->r;
}

static void	fill_uv_lateral(const t_vec3 *op, const t_cone *co, t_vec2 *uv)
{
	double	first_ratio;
	double	up_ratio;

	first_ratio = ft_dot_vec3(op, &co->dir);
	uv->x = 0.5 - first_ratio / co->h;
	first_ratio = ft_dot_vec3(op, &co->right);
	up_ratio = ft_dot_vec3(op, &co->up);
	uv->y = 0.5 + 0.5 * atan2(first_ratio, up_ratio) / M_PI;
}

static void	manage_fill(const t_cone *co, t_intersec *inter, int is_cb,
	int is_bm)
{
	double		dot;
	t_vec3		op;

	dot = ft_dot_vec3(&inter->soluce.n, &co->dir);
	op = ft_diff_vec3(&inter->soluce.p, &co->pos);
	if (-0.9 < dot && dot < 0.9)
	{
		if (is_cb)
		{
			fill_uv_lateral(&op, co, &inter->uv_cb);
			if (is_bm)
				inter->uv_bm = inter->uv_cb;
		}
		else
			fill_uv_lateral(&op, co, &inter->uv_bm);
	}
	else
	{
		if (is_cb)
			fill_uv_cb_caps(&op, co, &inter->uv_cb);
		if (is_bm)
			fill_uv_bm_caps(&op, co, &inter->uv_bm);
	}
}

void	fill_uv_co(t_intersec *inter)
{
	t_cone_obj	*co_obj;
	int			is_cb;
	int			is_bm;

	is_cb = inter->obj->pattern.checkerboard;
	is_bm = inter->obj->pattern.bump.name || inter->obj->pattern.texture.name;
	if (is_cb || is_bm)
	{
		co_obj = (t_cone_obj *)inter->obj->data;
		manage_fill(&co_obj->co, inter, is_cb, is_bm);
	}
}
