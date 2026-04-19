/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   columns.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wong koon wei <wkoon-we@student.42.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 23:10:11 by wong koon w       #+#    #+#             */
/*   Updated: 2026/04/17 23:10:11 by wong koon w      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	count_visible(int line[4]);

int	check_visible_col(int *board, int column[2][4], int c)
{
	int	r;
	int	line[4];

	r = 0;
	while (r < 4)
	{
		line[r] = board[r * 4 + c];
		r ++;
	}
	if (count_visible(line) != column[0][c])
		return (0);
	r = 0;
	while (r < 4)
	{
		line[r] = board[(3 - r) * 4 + c];
		r ++;
	}
	if (count_visible(line) != column[1][c])
		return (0);
	return (1);
}

int	check_cols(int *board, int column[2][4])
{
	int	r;
	int	complete;
	int	c;

	c = 0;
	while (c < 4)
	{
		complete = 1;
		r = 0;
		while (r < 4)
		{
			if (board[r * 4 + c] == 0)
				complete = 0;
			r++;
		}
		if (complete)
		{
			if (!check_visible_col(board, column, c))
				return (0);
		}
		c++;
	}
	return (1);
}

// void	valid(int *sample);

// void	column(int *top, int *bottom)
// {
// 	valid(top);
//     valid(bottom);

// }
