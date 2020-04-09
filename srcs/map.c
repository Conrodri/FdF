/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vicaster <vicaster@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/04 11:11:46 by fleonard     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/07 17:47:59 by vicaster    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

char	**addline(char **map, char *line)
{
	char	**res;
	int		i;

	i = 0;
	if (!map)
	{
		if (!(map = (char**)malloc(sizeof(char*) * (1))))
			return (NULL);
		map[0] = NULL;
	}
	while (map[i] != NULL)
		i++;
	if (!(res = (char**)malloc(sizeof(char*) * (i + 2))))
		return (NULL);
	i = 0;
	while (map[i] != NULL)
	{
		res[i] = ft_strdup(map[i]);
		i++;
	}
	res[i] = ft_strdup(line);
	res[i + 1] = NULL;
	return (res);
}

int		getsizemap(t_struct *mlx, int i, int j, int k)
{
	while (mlx->map[++i])
	{
		j = -1;
		k = 0;
		while (mlx->map[i][++j])
		{
			if (mlx->map[i][j] != ' ' && mlx->map[i][j] != '-'
				&& !(ft_isdigit(mlx->map[i][j])))
				return (0);
			if (ft_isdigit(mlx->map[i][j]))
			{
				while (mlx->map[i][j] && ft_isdigit(mlx->map[i][j]))
					j++;
				if (mlx->map[i][j] == ' ' || mlx->map[i][j] == '\0')
					k++;
			}
			if (mlx->map[i][j] == '\0')
				break ;
		}
	}
	mlx->sizey = i;
	mlx->sizex = k;
	return (1);
}

char	**getmap(t_struct *mlx, int *fd)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	j = 0;
	map = NULL;
	while (get_next_line(*fd, &(mlx->line)))
	{
		map = addline(map, mlx->line);
	}
	return (map);
}

int		**getintmap(t_struct *mlx, int i, int j, int k)
{
	mlx->intmap = ft_feed_tab(mlx, i, j, k);
	return (mlx->intmap);
}

void	ft_print_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		ft_putendl(map[i]);
		i++;
	}
}
