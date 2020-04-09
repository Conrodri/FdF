/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_realloc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vicaster <vicaster@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/17 15:01:12 by vicaster     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/17 19:12:21 by vicaster    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_strrealloc(void *str, size_t size)
{
	char	*fraiche;

	if (!size && str)
	{
		if (!(fraiche = (char *)malloc(sizeof(char))))
			return (NULL);
		ft_memdel(&str);
		return (fraiche);
	}
	if (!(fraiche = ft_strnew(size + 1)))
		return (NULL);
	if (str)
	{
		ft_memcpy(fraiche, str, size);
		ft_memdel(&str);
	}
	return (fraiche);
}
