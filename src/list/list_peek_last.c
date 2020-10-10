/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_peek_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 17:52:24 by user              #+#    #+#             */
/*   Updated: 2020/10/10 23:37:49 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	list_peek_last(const t_list *list)
{
	return (list->size > 0 ? list->tail->content : -1);
}
