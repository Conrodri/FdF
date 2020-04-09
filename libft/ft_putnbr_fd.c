/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_fd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vicaster <vicaster@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 12:35:24 by vicaster     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 13:21:10 by vicaster    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_overflow_fd(int n, int fd)
{
	ft_putchar_fd('-', fd);
	ft_putchar_fd('2', fd);
	n = 147483648;
	return (n);
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putnbr_fd(ft_overflow_fd(n, fd), fd);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = -n;
		}
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
		if (n > 0 && n <= 9)
			ft_putchar_fd(n + '0', fd);
		if (n == 0)
			ft_putchar_fd('0', fd);
	}
}
