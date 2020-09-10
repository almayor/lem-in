/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 16:28:22 by unite             #+#    #+#             */
/*   Updated: 2020/09/10 17:26:24 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H

# define QUEUE_H

# include <stdlib.h>
# include "libftprintfgnl.h"
# include "list.h"
# include "utils.h"

typedef struct s_list	t_queue;

void	queue_delete(t_queue *queue);
int		queue_dequeue(t_queue *queue);
void	queue_enqueue(t_queue *queue, int val);
t_queue	*queue_new(void);
size_t	queue_size(const t_queue *queue);
int		queue_peek(const t_queue *queue);

#endif
