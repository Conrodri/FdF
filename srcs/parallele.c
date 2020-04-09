/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parallele.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vicaster <vicaster@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/07 16:11:31 by fleonard     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/07 17:48:05 by vicaster    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	parall_horiz(t_struct *mlx, t_points *bresen, int j, int i)
{
	int mult;

	mult = mlx->sizex > 50 ? 10 : 20;
	while (i < mlx->sizey)
	{
		j = 1;
		while (j < mlx->sizex)
		{
			bresen->xi = (j * mult);
			bresen->yi = ((i + 1) * mult);
			bresen->xf = ((j + 1) * mult);
			bresen->yf = ((i + 1) * mult);
			bresen->xi = bresen->xi + 0.5 * mlx->intmap[i][j - 1];
			bresen->xf = bresen->xf + 0.5 * mlx->intmap[i][j];
			bresen->yi = bresen->yi + 0.25 * (mlx->intmap[i][j - 1] * 8 * -1);
			bresen->yf = bresen->yf + 0.25 * (mlx->intmap[i][j] * 8 * -1);
			bresen->i = 0;
			plot_line(mlx, bresen, 0, 0);
			j++;
		}
		i++;
	}
}

void	parall_vertical(t_struct *mlx, t_points *bresen, int j, int i)
{
	int mult;

	mult = mlx->sizex > 50 ? 10 : 20;
	while (j < mlx->sizex)
	{
		i = 1;
		while (i < mlx->sizey)
		{
			bresen->xi = ((j + 1) * mult);
			bresen->yi = (i * mult);
			bresen->xf = ((j + 1) * mult);
			bresen->yf = ((i + 1) * mult);
			bresen->xi = bresen->xi + 0.5 * mlx->intmap[i - 1][j];
			bresen->xf = bresen->xf + 0.5 * mlx->intmap[i][j];
			bresen->yi = bresen->yi + 0.25 * (mlx->intmap[i - 1][j] * 8 * -1);
			bresen->yf = bresen->yf + 0.25 * (mlx->intmap[i][j] * 8 * -1);
			bresen->i = 0;
			plot_line(mlx, bresen, 0, 0);
			i++;
		}
		j++;
	}
}

void	decrease_z(t_struct *mlx)
{
	int i;
	int j;

	i = 0;
	while (i < mlx->sizey)
	{
		j = 0;
		while (j < mlx->sizex)
		{
			if (mlx->intmap[i][j] != 0)
				mlx->intmap[i][j] -= 6;
			j++;
		}
		i++;
	}
}
