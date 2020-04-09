/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_push_back.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vicaster <vicaster@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/07 15:52:14 by vicaster     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 15:03:29 by vicaster    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_push_back(t_list **begin_list, void *content)
{
	t_list	*head;
	t_list	*elem;

	elem = ft_create_elem(content);
	if (!*begin_list)
		*begin_list = elem;
	else
	{
		head = *begin_list;
		while (head->next != NULL)
			head = head->next;
		head->next = elem;
	}
}
