/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vicaster <vicaster@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 16:06:23 by vicaster     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 19:35:02 by vicaster    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (ft_strcmp((char*)needle, "") == 0)
		return ((char*)haystack);
	while (haystack[i])
	{
		while (haystack[i] && i < len)
		{
			j = 0;
			while (haystack[i + j] == needle[j] && i + j <= len)
			{
				j++;
				if (needle[j] == '\0')
					return ((char*)haystack + i);
			}
			i++;
			if (haystack[i] == 0)
				return (NULL);
		}
		i++;
	}
	return (NULL);
}
