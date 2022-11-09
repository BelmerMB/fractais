/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 23:44:59 by emetras-          #+#    #+#             */
/*   Updated: 2022/11/09 13:37:25 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/header.h"
#include <stdio.h>

int main()
{
	t_data	p_mlx;

	window_init(&p_mlx);

}

void window_init(t_data *p_mlx)
{
	p_mlx->mlx = mlx_init;
	p_mlx->win = mlx_new_window(p_mlx->mlx, W_WIDTH, W_HEIGHT, "Mandelbrot");
	p_mlx->img.mlx_img = mlx_new_image(p_mlx->mlx, W_WIDTH, W_HEIGHT);
	p_mlx->img.addr = mlx_get_data_addr(p_mlx->img.mlx_img, p_mlx.img.bpp,
	p_mlx->img.line_len, p_mlx->img.endian);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;
	int		i;

	i = img->bpp - 8;
    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		/* big endian, MSB is the leftmost bit */
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		/* little endian, LSB is the leftmost bit */
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}