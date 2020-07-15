/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_farm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 11:56:54 by unite             #+#    #+#             */
/*   Updated: 2020/07/15 16:05:11 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "farm.h"

void	free_farm(t_farm *farm)
{
	if (farm == NULL)
		return ;
	free(farm->ants);
	free(farm);
}
