/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vicaster <vicaster@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 20:58:03 by vicaster     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 19:11:46 by vicaster    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_creat_null(void)
{
	char	*str;

	if (!(str = malloc(sizeof(char))))
		return (NULL);
	str[0] = '\0';
	return (str);
}

char		*ft_strtrim(char const *s)
{
	char	*dest;
	int		i;
	int		j;
	int		k;

	j = 0;
	i = 0;
	k = 0;
	if ((char*)s == NULL)
		return (NULL);
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
		i++;
	if (s[i] == '\0')
		return (ft_creat_null());
	while (s[j])
		j++;
	j--;
	while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && j > 0)
		j--;
	if (!(dest = ft_strnew(j - i + 1)))
		return (NULL);
	while (i <= j)
		dest[k++] = s[i++];
	return (dest);
}
