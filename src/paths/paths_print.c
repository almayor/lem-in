/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 19:15:58 by user              #+#    #+#             */
/*   Updated: 2020/10/07 13:39:24 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "paths.h"

void paths_print(const t_paths *paths)
{
	int i;

	i = 0;
	while (i < paths->npaths)
		list_print(paths->arr[i++]);
}
