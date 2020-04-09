/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memalloc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vicaster <vicaster@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/11 16:27:06 by vicaster     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 16:51:24 by vicaster    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*fraiche;
	int				i;

	i = 0;
	if (!(fraiche = (void*)malloc(sizeof(char) * size)))
		return (NULL);
	while (size-- > 0)
		fraiche[i++] = 0;
	return ((void*)fraiche);
}
