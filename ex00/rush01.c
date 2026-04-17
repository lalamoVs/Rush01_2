/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wong koon wei <wkoon-we@student.42.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 19:13:04 by wong koon w       #+#    #+#             */
/*   Updated: 2026/04/17 19:13:04 by wong koon w      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	row(char *left, char *right);
void	column(char *top, char *bottom);

int	main(int argc, char **argv)
{
	int		i;
	int		count;
	char	array1[4];
	char	array2[4];

	i = 0;
	count = 0;
	if (argc > 1)
	{
		while (i < 24)
		{
			array1[count] = argv[1][i];
			array2[count] = argv[1][i + 8];
			if (i == 6)
			{
				column(array1, array2);
                i = 16;
				count = 0;
			}
			if (i == 22)
				row(array1, array2);
			i += 2;
			count += 1;
		}
	}
	return (0);
}
