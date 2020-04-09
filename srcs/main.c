/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vicaster <vicaster@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/27 12:07:03 by fleonard     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/07 17:52:53 by vicaster    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

t_struct	*init_struct(t_struct *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, X, Y, "fdf_101");
	mlx->map = NULL;
	mlx->intmap = NULL;
	mlx->line = NULL;
	mlx->sizez = 0;
	mlx->sizex = 0;
	mlx->sizey = 0;
	mlx->l = 0;
	mlx->bresen = (t_points*)malloc(sizeof(t_points) * 1);
	mlx->bresen = ft_init_bresen(mlx->bresen);
	return (mlx);
}

t_points	*ft_init_bresen(t_points *bresen)
{
	bresen->xi = 0;
	bresen->yi = 0;
	bresen->xf = 0;
	bresen->yf = 0;
	bresen->xinc = 0;
	bresen->yinc = 0;
	bresen->i = 0;
	bresen->color = 0xFFFFFF;
	return (bresen);
}

int			deal_key(int key, t_struct *mlx)
{
	if (key == 53)
		exit(0);
	if (key == 83)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		ft_fdf(key, mlx, mlx->bresen);
	}
	if (key == 82)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		ft_fdf(key, mlx, mlx->bresen);
	}
	if (key == 69)
		ft_increase_z(mlx);
	if (key == 78)
		ft_decrease_z(mlx);
	if (key == 84)
		ft_color_white(mlx);
	if (key == 85)
		ft_color_blue(mlx);
	return (0);
}

int			main(int argc, char **argv)
{
	t_struct	*mlx;
	int			fd;

	if (argc != 2)
		return (0);
	mlx = (t_struct*)malloc(sizeof(t_struct) * 1);
	mlx = init_struct(mlx);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_error();
		return (0);
	}
	mlx->map = getmap(mlx, &fd);
	if (getsizemap(mlx, -1, 0, 0) == 0)
	{
		ft_error();
		return (0);
	}
	mlx->intmap = getintmap(mlx, -1, 0, 0);
	ft_fdf(-1, mlx, mlx->bresen);
	mlx_key_hook(mlx->win_ptr, deal_key, mlx);
	mlx_loop(mlx->mlx_ptr);
}
