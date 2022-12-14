/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:40:33 by emetras-          #+#    #+#             */
/*   Updated: 2023/01/07 03:07:11 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static int	destroy_all(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.mlx_img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

static int	handle_key(int key, t_data *data)
{
	if (key == ESC)
		destroy_all(data);
	return (0);
}

static int	handle_mouse(int key, int x, int y, t_data *data)
{
	(void) x;
	(void) y;
	if (key == SCROLL_DOWN)
	{
		data->var.scale *= 1.1;
		f_fractal(data);
	}
	else if (key == SCROLL_UP)
	{
		data->var.scale *= 0.9;
		f_fractal(data);
	}
	return (0);
}

int	handle_hooks(t_data *data)
{
	mlx_hook(data->win, 17, 0, destroy_all, data);
	mlx_mouse_hook(data->win, handle_mouse, data);
	mlx_key_hook(data->win, handle_key, data);
	mlx_loop_hook(data->mlx, f_fractal, data);
	return (0);
}
