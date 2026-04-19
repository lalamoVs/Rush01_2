/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wong koon wei <wkoon-we@student.42.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 19:13:13 by wong koon w       #+#    #+#             */
/*   Updated: 2026/04/17 19:13:13 by wong koon w      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	check_cols(int *board, int column[2][4]);

int	count_visible(int line[4]);

int	check_visible_row(int *board, int row[2][4], int r)
{
	int	line[4];
	int	c;

	c = 0;
	while (c < 4)
	{
		line[c] = board[r * 4 + c];
		c++;
	}
	if (count_visible(line) != row[0][r])
		return (0);
	c = 0;
	while (c < 4)
	{
		line[c] = board[r * 4 + (3 - c)];
		c++;
	}
	if (count_visible(line) != row[1][r])
		return (0);
	return (1);
}

int	check_rows(int *board, int column[2][4], int rows[2][4])
{
	int	r;
	int	c;
	int	complete;

	r = 0;
	while (r < 4)
	{
		complete = 1;
		c = 0;
		while (c < 4)
		{
			if (board[r * 4 + c] == 0)
				complete = 0;
			c++;
		}
		if (complete)
		{
			if (!check_visible_row(board, rows, r))
				return (0);
		}
		r++;
	}
	return (check_cols(board, column));
}

// void	valid(int *sample);

// void	row(int *left, int *right)
// {
//     valid(left);
//     valid(right);
// }
