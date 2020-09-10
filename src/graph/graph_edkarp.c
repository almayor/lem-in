/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_edkarp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:49:54 by unite             #+#    #+#             */
/*   Updated: 2020/09/11 00:33:45 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

/*
** Converts `edge_to` to a list of vertices along the path
** @param[in] edge_to An array that keeps track of
** the order of vertices on the path
** @param[out] marked An array where all vertices along the new path will be
** marked as unavailable
** @return The list of vertices along the path
*/

static t_list	*unroll_path(const t_graph *graph, const int *edge_to,
						   int *marked)
{
	t_list	*path;
	int		v;

	if (edge_to[graph->end] < 0)
		return (NULL);
	path = list_new();
	v = graph->end;
	while (v != graph->start)
	{
		list_add_first(path, v);
		if (v != graph->end)
			marked[v] = 1;
		v = edge_to[v];
	}
	return (path);
}

/*
** Runs breadth-first search on the graph in order to
** get the shortest from `start` to `end`, whilst
** ignoring all the `marked` vertices that have already been used in other paths
** @param[out] edge_to An array to keep track of
** the order of vertices on the path
** @param[out] marked An array marking which vertices have already been used
** in other paths
** @return A list of vertices along the new path, or `NULL` if no more paths
** exist
*/

static t_list	*graph_bst(const t_graph *graph, int *edge_to, int *marked)
{
	t_queue			*queue;
	t_iterator		*adj;
	int				v;
	int				w;

	queue = queue_new();
	queue_enqueue(queue, graph->start);
	while (queue_size(queue) > 0 && (v = queue_dequeue(queue)) != graph->end)
	{
		adj = graph_adjacency(graph, v);
		while (iterator_has_next(adj))
		{
			w = iterator_next(adj);
			if (w != graph->start && edge_to[w] < 0 && marked[w] == 0)
			{
				edge_to[w] = v;
				queue_enqueue(queue, w);
			}
		}
		iterator_delete(adj);
	}
	queue_delete(queue);
	return (unroll_path(graph, edge_to, marked));
}

size_t 		graph_edkarp(const t_graph *graph, t_list ***dest, size_t n)
{
	t_list	*path;
	int		*edge_to;
	int		*marked;
	size_t	i;

	*dest = ft_xcalloc(sizeof(t_list *), n);
	marked = ft_xcalloc(sizeof(int), graph->nverti);
	edge_to = ft_xcalloc(sizeof(int), graph->nverti);
	ft_memset(edge_to, -1, sizeof(int) * graph->nverti);
	i = 0;
	while (i < n && (path = graph_bst(graph, edge_to, marked)))
	{
		(*dest)[i++] = path;
		ft_memset(edge_to, -1, sizeof(int) * graph->nverti);
	}
	free(edge_to);
	free(marked);
	return (i);
}
