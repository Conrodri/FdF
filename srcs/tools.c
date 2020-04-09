/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: conrodri <conrodri@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/07 18:04:39 by conrodri     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/07 18:04:40 by conrodri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(void)
{
	ft_putendl("error");
	exit(1);
}

void	print_int_map(t_struct *mlx)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (i < mlx->sizey)
	{
		j = 0;
		while (j < mlx->sizex)
		{
			ft_putnbr(mlx->intmap[i][j]);
			ft_putchar(' ');
			j++;
		}
		if (j == mlx->sizex)
			write(1, "\n", 1);
		i++;
	}
}

int		**ft_feed_tab(t_struct *mlx, int i, int j, int k)
{
	char	tmp[11];
	int		l;

	l = 0;
	if (!(mlx->intmap = (int**)malloc(sizeof(int*) * mlx->sizey)))
		return (NULL);
	while (mlx->map[++i])
	{
		if (!(mlx->intmap[i] = (int*)malloc(sizeof(int) * (mlx->sizex))))
			return (NULL);
		while (mlx->map[i][j] && l < mlx->sizex)
		{
			while (mlx->map[i][j] && mlx->map[i][j] == ' ')
				j++;
			while (ft_isdigit(mlx->map[i][j]) || mlx->map[i][j] == '-')
				tmp[k++] = mlx->map[i][j++];
			k = 0;
			mlx->intmap[i][l] = ft_atoi(tmp);
			l++;
			ft_bzero(tmp, 11);
		}
		l = 0;
		j = 0;
	}
	return (mlx->intmap);
}

int		ft_sqrt(int nb)
{
	int racine;
	int sqrt;

	racine = 1;
	sqrt = 0;
	while (racine <= nb / 2)
	{
		sqrt = racine * racine;
		if (sqrt == nb)
		{
			return (racine);
		}
		racine = racine + 1;
	}
	return (0);
}

void	increase_z(t_struct *mlx)
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
			{
				if (mlx->intmap[i][j] + 6 != 0)
					mlx->intmap[i][j] += 6;
				else
					mlx->intmap[i][j] += 5;
			}
			j++;
		}
		i++;
	}
}
