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

void	column(char *top, char *bottom)
{
	int	i;
	int	start;

	i = 1;
	start = 0;
	while (start < 3)
	{
		if (i == 3 && i != start)
        {
			start ++;
            i = start;
        }
        if ((top[start] || bottom[start]) != 2)
        {
            if (top[start] == top[i] || bottom[start] == bottom[i])
                write(1, "Error\n", 6);
        }
		i ++;
    }
    write(1, "Column: ", 8);
    write(1, &top[1], 1);
    write(1, "\n", 1);
}