/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vicaster <vicaster@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/23 16:59:08 by vicaster     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 17:02:26 by vicaster    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strccpy(char *dst, const char *src, int c)
{
	int		i;

	i = 0;
	while (src[i] && src[i] != (unsigned char)c)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
