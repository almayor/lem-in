/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_pq_swim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 05:22:31 by unite             #+#    #+#             */
/*   Updated: 2020/10/10 23:38:12 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "min_pq.h"

void	min_pq_swim(t_min_pq *pq, size_t k)
{
	while (k > 1 && pq->vals[pq->pq[k / 2]] > pq->vals[pq->pq[k]])
	{
		min_pq_swap(pq, k / 2, k);
		k = k / 2;
	}
}
