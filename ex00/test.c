/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wong koon wei <wkoon-we@student.42.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 21:43:08 by wong koon w       #+#    #+#             */
/*   Updated: 2026/04/18 21:43:08 by wong koon w      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	count_visible(int line[4])
{
	int	i;
	int	maxh;
	int	visible;

	i = 0;
	maxh = 0;
	visible = 0;
	while (i < 4)
	{
		if (line[i] > maxh)
		{
			maxh = line[i];
			visible ++;
		}
		i ++;
	}
	return (visible);
}

int	check_rows(int *board, int column[2][4], int rows[2][4]);

int	safe(int *board, int pos, int value)
{
	int	i;
	int	r;
	int	column;

	r = pos / 4;
	column = pos % 4;
	i = 0;
	while (i < 4)
	{
		if (board[r * 4 + i] == value)
			return (0);
		if (board[i * 4 + column] == value)
			return (0);
		i ++;
	}
	return (1);
}

int	solve(int *board, int column[2][4], int rows[2][4], int pos)
{
	int	i;

	if (pos == 16)
		return (1);
	if (board[pos] != 0)
		return (solve(board, column, rows, pos + 1));
	i = 1;
	while (i <= 4)
	{
		if (safe(board, pos, i))
		{
			board[pos] = i;
			if (check_rows(board, column, rows))
			{
				if (solve(board, column, rows, pos + 1))
					return (1);
			}
			board[pos] = 0;
		}
		i ++;
	}
	return (0);
}

void	print_table(int board[16])
{
	int		i;
	char	convert;
	int		space;

	i = 0;
	space = 0;
	while (i < 16)
	{
		convert = board[i] + '0';
		write(1, &convert, 1);
		write(1, " ", 1);
		if (i > 0 && !(i % (space * 4 + 3)))
		{
			write(1, "\n", 1);
			space ++;
		}
		i ++;
	}
}

void	test(void)
{
	int	column[2][4] = {{4, 3, 2, 1}, {1, 2, 2, 2}};
	int	row[2][4] = {{4, 3, 2, 1}, {1, 2, 2, 2}};
	int	board[16] = {0};

	if (solve(board, column, row, 0))
		print_table(board);
	else
		write(1, "No solution\n", 12);
}

int	main(void)
{
	test();
	return (0);
}
