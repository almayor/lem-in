/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 11:56:04 by unite             #+#    #+#             */
/*   Updated: 2020/09/10 11:56:25 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

size_t	list_size(const t_list *list)
{
	return (list->size);
}
