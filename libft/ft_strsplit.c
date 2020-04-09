/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vicaster <vicaster@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/12 22:33:05 by vicaster     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 13:14:15 by vicaster    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	unsigned int		i;
	unsigned int		j;
	char				**dst;
	int					nb_words;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	nb_words = ft_count_words(s, c);
	if ((dst = malloc(sizeof(char*) * (nb_words + 1))) == NULL)
		return (NULL);
	while (nb_words > 0)
	{
		while (s[i] == c)
			i++;
		if (!(dst[j] = ft_strsub(s, i, ft_count_letter(s + i, c))))
			return (NULL);
		j++;
		while (s[i] && s[i] != c)
			i++;
		nb_words--;
	}
	dst[j] = NULL;
	return (dst);
}
