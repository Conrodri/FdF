/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_bzero.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vicaster <vicaster@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/11 17:21:57 by vicaster     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 17:33:34 by vicaster    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*tmp;
	int				i;

	i = 0;
	tmp = s;
	if (n == 0)
		return ;
	while (n-- != 0)
		tmp[i++] = 0;
	return ((void)tmp);
}
