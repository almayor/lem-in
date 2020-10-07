/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_add_edge.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 20:52:18 by unite             #+#    #+#             */
/*   Updated: 2020/10/07 12:30:18 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void	graph_add_edge(t_graph *graph, int from, int to)
{
	t_edge	*edge;

	edge = ft_xcalloc(sizeof(t_edge), 1);
	edge->to = to;
	edge->state = POSITIVE;
	edge->next = graph->nodes[from]->edges;
	graph->nodes[from]->edges = edge;
	graph->nedges++;
}
