/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_tab_int.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vicaster <vicaster@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/27 18:59:27 by vicaster     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/28 19:54:10 by vicaster    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_tab_int(int **tab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab[j])
	{
		while (tab[j][i])
		{
			ft_putnbr(tab[j][i]);
			i++;
		}
		j++;
	}
	ft_putchar('\n');
}
