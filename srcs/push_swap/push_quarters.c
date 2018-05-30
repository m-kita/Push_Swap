/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_quarters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 18:47:46 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/30 18:47:52 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Pushes every number above or below quarters into Stack b, */
/* based on split flag */

void	push_quarters(t_frame *frame, int split)
{
	t_stack	*stack; // rename stack_a, same for rest of code
	t_stack	*stack_a_end;
	int		flag; 
	
	stack = frame->a;
	stack_a_end = frame->a->prev;
	flag = 0;
	while (1)
	{
		if (stack == stack_a_end)
			flag = 1;
		if (split == 1 && stack->num <= frame->quarter)
			do_pb(frame);
        else if (split == 2 && stack->num <= frame->median) //frame->half
			do_pb(frame);
		else if (split == 3 && stack->num <= frame->three_quarters)
			do_pb(frame);
		else if (split == 4 && stack->num > frame->three_quarters)
			do_pb(frame);
        else if (split == 4 && stack->num == frame->smallest)
			break;
		else
			do_ra(frame);
		if (flag == 1)
			break;
		stack = frame->a;
	}
}