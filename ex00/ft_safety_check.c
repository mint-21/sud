/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safety_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsedgeki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 21:02:50 by lsedgeki          #+#    #+#             */
/*   Updated: 2019/07/14 21:41:39 by etommy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SIZE 9

int		g_matrix[9][9];

int		check_subm(int row_start, int col_start, int n)
{
	int i;
	int j;

	i = row_start;
	while (i < (row_start + 3))
	{
		j = col_start;
		while (j < (col_start + 3))
		{
			if (g_matrix[i][j] == n)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		is_safe(int n, int r, int c)
{
	int i;
	int row_start;
	int col_start;

	i = 0;
	while (i < SIZE)
	{
		if (g_matrix[r][i] == n)
			return (0);
		i++;
	}
	i = 0;
	while (i < SIZE)
	{
		if (g_matrix[i][c] == n)
			return (0);
		i++;
	}
	row_start = (r / 3) * 3;
	col_start = (c / 3) * 3;
	return (check_subm(row_start, col_start, n));
}
