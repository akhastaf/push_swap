/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 16:05:55 by akhastaf          #+#    #+#             */
/*   Updated: 2021/06/14 17:40:08 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "struct.h"
# include "utils.h"

void	sort_three(t_stack **a);
void	sort_five(t_stack **a, t_stack **b, int *chunk);
void	sort(t_stack **a, t_stack **b);
void	fill_stack(t_stack **a);
t_stack	*copy(t_stack *a);
int		get_position(t_stack *a, int data);
int		is_chunkempty(t_stack *a, int chunk);
void	first(t_stack **a, t_stack **b, int *chunk);
void	from_a_to_b(t_stack **a, t_stack **b, t_range r, int *chunk);
void	second(t_stack **a, t_stack **b, int *chunk);
int		get_pofhigher(t_stack *a, int chunk);
int		get_poflower(t_stack *a, int chunk);
#endif
