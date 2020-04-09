/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_creat_elem.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vicaster <vicaster@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/07 15:58:02 by vicaster     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/07 15:58:54 by vicaster    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_create_elem(void *content)
{
	t_list		*list;

	if (!(list = malloc(sizeof(*list))))
		return (0);
	list->content = content;
	list->next = NULL;
	return (list);
}
