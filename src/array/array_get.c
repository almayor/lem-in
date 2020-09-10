/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 23:25:55 by unite             #+#    #+#             */
/*   Updated: 2020/09/10 23:23:23 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

char	*array_get(const t_array *array, size_t index)
{
	return (array->arr[index]);
}
