/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vicaster <vicaster@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/11 18:03:19 by vicaster     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/12 17:36:15 by vicaster    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		*((unsigned char*)dest) = *((unsigned char*)src);
		if (*((unsigned char*)src) == ((unsigned char)c))
			return ((unsigned char*)(dest + 1));
		dest++;
		src++;
		i++;
	}
	return (NULL);
}
