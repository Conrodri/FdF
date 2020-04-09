/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vicaster <vicaster@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 14:42:36 by vicaster     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 19:20:24 by vicaster    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char				*str;
	int					i;
	unsigned int		nb;

	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * ft_count_int(n) + 1)))
		return (NULL);
	nb = (n < 0 ? -n : n);
	while (nb)
	{
		str[i++] = nb % 10 + 48;
		nb = nb / 10;
	}
	if (n <= 0)
		str[i++] = (n == 0 ? '0' : '-');
	str[i] = '\0';
	return (ft_strrev(str));
}
