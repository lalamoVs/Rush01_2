/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jason <wkoon-we@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 23:31:33 by jason             #+#    #+#             */
/*   Updated: 2026/04/12 09:34:56 by jason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(int x_array[], int x_len, int y, char ptrn);

void	rush(int x, int y)
{
	int		*x_cord;
	int		count_x;
	char	ptrn;

	count_x = 0;
	ptrn = 'C';
	x_cord = malloc(x * sizeof(int));
	free (x_cord);
	while (count_x < x)
	{
		x_cord[count_x] = 0;
		if (ptrn == 'C' || (count_x == x - 1 && ptrn == 'B'))
			x_cord[count_x] = 2;
		while (count_x < x - 2 && x > 2)
		{
			count_x ++;
			x_cord[count_x] = 1;
		}
		count_x ++;
	}
	ft_putchar(x_cord, x, y, ptrn);
}
