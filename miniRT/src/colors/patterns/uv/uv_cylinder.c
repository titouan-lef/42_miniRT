/// @todo header

#include "minirt.h"

static void	fill_uv_cb_caps(t_vec3 p, t_cylinder_obj *cy_obj, t_vec2 *uv)
{
	t_vec3	op;
	double	dot[2];

	op = ft_diff_vec3(&p, &cy_obj->cy.pos);
	uv->x = 1;
	dot[0] = ft_dot_vec3(&op, &cy_obj->cy.right);
	dot[1] = ft_dot_vec3(&op, &cy_obj->cy.up);
	uv->y = 0.5 + 0.5 * atan2(dot[0], dot[1]) / M_PI;
}

static void	fill_uv_bm_caps(t_vec3 p, t_cylinder_obj *cy_obj, t_vec2 *uv)
{
	t_vec3	op;

	op = ft_diff_vec3(&p, &cy_obj->cy.pos);
	uv->x = ft_dot_vec3(&op, &cy_obj->cy.right);
	uv->x = 0.5 + 0.5 * uv->x / cy_obj->cy.r;
	uv->y = ft_dot_vec3(&op, &cy_obj->cy.up);
	uv->y = 0.5 + 0.5 * uv->y / cy_obj->cy.r;
}

static void	fill_uv_lateral(t_vec3 p, t_cylinder_obj *cy_obj, t_vec2 *uv)
{
	t_vec3	op;
	double	dot[2];

	op = ft_diff_vec3(&p, &cy_obj->cy.pos);
	dot[0] = ft_dot_vec3(&op, &cy_obj->cy.dir);
	uv->x = 0.5 + 0.5 * dot[0] / cy_obj->cy.hh;
	dot[0] = ft_dot_vec3(&op, &cy_obj->cy.right);
	dot[1] = ft_dot_vec3(&op, &cy_obj->cy.up);
	uv->y = 0.5 + 0.5 * atan2(dot[0], dot[1]) / M_PI;
}

static void	manage_fill(t_intersec *inter, int is_cb, int is_bm)
{
	t_cylinder_obj	*cy_obj;
	double			dot;

	cy_obj = (t_cylinder_obj *)inter->obj->data;
	dot = ft_dot_vec3(&inter->soluce.n, &cy_obj->cy.dir);
	if (fabs(dot) < 0.9)
	{
		if (is_cb)
		{
			fill_uv_lateral(inter->soluce.p, cy_obj, &inter->uv_cb);
			if (is_bm)
				inter->uv_bm = inter->uv_cb;
		}
		else if (is_bm)
			fill_uv_lateral(inter->soluce.p, cy_obj, &inter->uv_bm);
	}
	else
	{
		if (is_cb)
			fill_uv_cb_caps(inter->soluce.p, cy_obj, &inter->uv_cb);
		if (is_bm)
			fill_uv_bm_caps(inter->soluce.p, cy_obj, &inter->uv_bm);
	}
}

void	fill_uv_cy(t_intersec *inter)
{
	int	is_cb;
	int	is_bm;

	is_cb = inter->obj->pattern.checkerboard;
	is_bm = inter->obj->pattern.bump.name || inter->obj->pattern.texture.name;
	if (is_cb || is_bm)
		manage_fill(inter, is_cb, is_bm);
}
