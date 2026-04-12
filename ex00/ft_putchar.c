/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jason <wkoon-we@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 11:33:58 by jason             #+#    #+#             */
/*   Updated: 2026/04/12 09:22:22 by jason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static char	get_char2(int row, int col, int y, int *x)
{
	if (x[col] == 0)
	{
		if (row > 0 && row < y - 1)
			return ('*');
		if ((col == 0 && row == 0) || (row == y -1 && col > 0))
		{
			return ('/');
		}
		else if ((col == 0 && row == y - 1) || (col > 0 && row == 0))
		{
			return ('\\');
		}
	}
	else
	{
		if (row > 0 && row < y - 1)
			return (' ');
		return ('*');
	}
	return ('/');
}

static char	get_char3(int row, int col, int y, int *x)
{
	char	asci;

	asci = 65 + x[col];
	if (row > 0 && row < y - 1)
	{
		if (x[col] == 0)
			return (66);
		return (' ');
	}
	return (asci);
}

static char	get_char4(int row, int col, int y, int *x)
{
	char	asci;

	asci = 65 + x[col];
	if (row > 0 && row < y - 1)
	{
		if (x[col] == 0 || x[col] == 2)
			return (66);
		return (' ');
	}
	if (x[0] == 2)
	{
		if (col == 0 && x[0] == 2 && row == 0)
			return (65);
		if (row == y - 1 && col > 1 && x[col] == 2)
			return (65);
	}
	return (asci);
}

static char	get_char(int row, int col, int y, int *x)
{
	if (x[col] == 0)
	{
		if (row > 0 && row < y - 1)
			return ('|');
		return ('o');
	}
	else
	{
		if (row > 0 && row < y - 1)
			return (' ');
		return ('-');
	}
}

void	ft_putchar(int x[], int x_len, int y, char ptrn)
{
	int		row;
	int		col;
	char	c;

	row = 0;
	while (row < y)
	{
		col = 0;
		while (col < x_len)
		{
			if (ptrn == 'o')
				c = get_char(row, col, y, x);
			if (ptrn == '/')
				c = get_char2(row, col, y, x);
			if (ptrn == 'A')
				c = get_char3(row, col, y, x);
			if (ptrn == 'B' || ptrn == 'C')
				c = get_char4(row, col, y, x);
			write(1, &c, 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}
