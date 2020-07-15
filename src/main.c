/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 01:27:50 by unite             #+#    #+#             */
/*   Updated: 2020/07/16 00:22:41 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "libftprintfgnl.h"
#include "map.h"
#include "list.h"
#include "farm.h"
#include "edmonds-karp.h"

/*
** Returns the number of ants read from `STDIN`.
** @note The function reprints what it read from `STDIN` to `STDOUT`.
** @return The number of ants and -1 if an error occured
** @exception EINVAL	The number of ants isn't given or largest than `MAX_INT`
*/
static int		get_n_ants(void);

/*
** Reads the vertices (rooms) from `STDIN`, assigns each vertex an integer id
** and creates a map between vertex id's and names.
** @note The function reprints what it read from `STDIN` to `STDOUT`.
** @return A bidirectional map between vertex id's and names.
** @exception ENOMEM	Memory allocation error
** @exception EINVAL	The format is wrong
*/
static t_map	*get_vertex_names(void);

/*
** Reads the edges (links) from `STDIN`, writes them to a graph, then uses
** the Edmonds-Karp algorithm to get paths from the source to the sink. The
** returned paths are sorted in the order from shortest to longest.
** @note The function reprints what it read from `STDIN` to `STDOUT`.
** @return	An ordered `NULL`-terminated array of paths from the source
** 			to the sink, or `NULL` if an error occurs
** @exception ENOMEM	Memory allocation error
** @exception EINVAL	The format is wrong, the edges connect vertices that
**						do not exist, or the source and the sink aren't
**						connected
*/
static t_list	**get_paths(int n_ants, t_map *vertex_names);
	
int main(void)
{
	t_map	*vertex_names;
	t_list	**paths;
	t_farm	*farm;
	int		n_ants;

	if ((n_ants = get_n_ants()) &&
		(vertex_names = get_vertex_names()) &&
		(paths = get_paths(n_ants, vertex_names)) &&
		(farm = make_farm(n_ants)))
		run_farm(farm, paths, n_paths, vertex_names);
	free_farm(farm);
	free_paths(paths);
	free_map(vertex_names);
}
