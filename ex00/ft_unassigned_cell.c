/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unassigned_cell.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsedgeki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 21:05:27 by lsedgeki          #+#    #+#             */
/*   Updated: 2019/07/14 21:42:21 by etommy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SIZE 9

int		g_matrix[9][9];

int		number_unassigned(int *row, int *col)
{
	int num_unassign;
	int i;
	int j;

	i = 0;
	num_unassign = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			if (g_matrix[i][j] == 0)
			{
				*row = i;
				*col = j;
				num_unassign = 1;
				return (num_unassign);
			}
			j++;
		}
		i++;
	}
	return (num_unassign);
}
