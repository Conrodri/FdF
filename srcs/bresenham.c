/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bresenham.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: conrodri <conrodri@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/07 18:04:24 by conrodri     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/07 18:04:26 by conrodri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	print_horizontal(t_struct *mlx, t_points *bresen, int i, int j)
{
	int mult;

	mult = mlx->sizex > 50 ? 10 : 100;
	while (i < mlx->sizey)
	{
		j = 1;
		while (j < mlx->sizex)
		{
			bresen->xi = (j * mult);
			bresen->yi = ((i + 1) * mult);
			bresen->xf = ((j + 1) * mult);
			bresen->yf = ((i + 1) * mult);
			bresen->xi = 0.5 * bresen->xi - 0.5 * bresen->yi;
			bresen->xf = 0.5 * bresen->xf - 0.5 * bresen->yf;
			bresen->yi = (mlx->intmap[i][j - 1] * 8 * -1)
			+ (0.5 / 2) * bresen->xi + 0.25 * bresen->yi;
			bresen->yf = (mlx->intmap[i][j] * 8 * -1)
			+ (0.5 / 2) * bresen->xf + 0.25 * bresen->yf;
			bresen->i = 0;
			plot_line(mlx, bresen, 0, 0);
			j++;
		}
		i++;
	}
}

void	print_vertical(t_struct *mlx, t_points *bresen, int j, int i)
{
	int mult;

	mult = mlx->sizex > 50 ? 10 : 100;
	while (j < mlx->sizex)
	{
		i = 1;
		while (i < mlx->sizey)
		{
			bresen->xi = ((j + 1) * mult);
			bresen->yi = (i * mult);
			bresen->xf = ((j + 1) * mult);
			bresen->yf = ((i + 1) * mult);
			bresen->xi = 0.5 * bresen->xi - 0.5 * bresen->yi;
			bresen->xf = 0.5 * bresen->xf - 0.5 * bresen->yf;
			bresen->yi = (mlx->intmap[i - 1][j] * 8 * -1)
			+ (0.5 / 2) * bresen->xi + 0.25 * bresen->yi;
			bresen->yf = (mlx->intmap[i][j] * 8 * -1)
			+ (0.5 / 2) * bresen->xf + 0.25 * bresen->yf;
			bresen->i = 0;
			plot_line(mlx, bresen, 0, 0);
			i++;
		}
		j++;
	}
}

void	ft_fdf(int key, t_struct *mlx, t_points *bresen)
{
	if (key == -1 || key == 82)
	{
		print_horizontal(mlx, bresen, 0, 1);
		print_vertical(mlx, bresen, 0, 1);
	}
	else if (key == 83)
	{
		parall_horiz(mlx, bresen, 1, 0);
		parall_vertical(mlx, bresen, 0, 1);
	}
}

void	plot_line(t_struct *mlx, t_points *bresen, int err, int e2)
{
	bresen->dx = abs(bresen->xf - bresen->xi);
	bresen->sx = bresen->xi < bresen->xf ? 1 : -1;
	bresen->dy = -abs(bresen->yf - bresen->yi);
	bresen->sy = bresen->yi < bresen->yf ? 1 : -1;
	err = bresen->dx + bresen->dy;
	while (1)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr,
		bresen->xi + X / 3, bresen->yi + Y / 3, bresen->color);
		if (bresen->xi == bresen->xf && bresen->yi == bresen->yf)
			break ;
		e2 = 2 * err;
		if (e2 >= bresen->dy)
		{
			err += bresen->dy;
			bresen->xi += bresen->sx;
		}
		if (e2 <= bresen->dx)
		{
			err += bresen->dx;
			bresen->yi += bresen->sy;
		}
	}
}
