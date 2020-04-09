/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_key.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vicaster <vicaster@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/07 17:19:38 by fleonard     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/07 17:47:25 by vicaster    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	ft_color_white(t_struct *mlx)
{
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx->bresen->color = WHITE;
	ft_fdf(-1, mlx, mlx->bresen);
}

void	ft_color_blue(t_struct *mlx)
{
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx->bresen->color = BLUE;
	ft_fdf(-1, mlx, mlx->bresen);
}

void	ft_increase_z(t_struct *mlx)
{
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	increase_z(mlx);
	ft_fdf(-1, mlx, mlx->bresen);
}

void	ft_decrease_z(t_struct *mlx)
{
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	decrease_z(mlx);
	ft_fdf(-1, mlx, mlx->bresen);
}
