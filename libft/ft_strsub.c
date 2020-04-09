/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vicaster <vicaster@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 19:39:10 by vicaster     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/13 12:50:26 by vicaster    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fraiche;
	int		i;

	i = 0;
	if (!(s))
		return (NULL);
	if (!(fraiche = (char*)malloc(sizeof(char) * (int)len + 1)))
		return (NULL);
	while (len > 0)
	{
		fraiche[i++] = s[start++];
		len--;
	}
	fraiche[i] = '\0';
	return (fraiche);
}
