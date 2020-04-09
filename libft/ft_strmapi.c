/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vicaster <vicaster@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 17:48:03 by vicaster     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 15:58:29 by vicaster    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*fraiche;

	i = 0;
	if (!((char*)s))
		return (NULL);
	if (!(fraiche = ft_strnew(ft_strlen((char*)s))))
		return (NULL);
	while (s[i])
	{
		fraiche[i] = f(i, s[i]);
		i++;
	}
	return (fraiche);
}
