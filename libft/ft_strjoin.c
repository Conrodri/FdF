/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vicaster <vicaster@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 20:06:43 by vicaster     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/29 14:45:15 by vicaster    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*fraiche;
	size_t		lentot;

	if (s1 == '\0' || s2 == '\0')
		return (NULL);
	lentot = ft_strlen((char*)s1) + ft_strlen((char*)s2);
	if (!(fraiche = ft_strnew(lentot)))
		return (NULL);
	ft_strcpy(fraiche, (char*)s1);
	ft_strcat(fraiche, (char*)s2);
	return (fraiche);
}
