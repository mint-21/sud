/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_solve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsedgeki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 21:08:54 by lsedgeki          #+#    #+#             */
/*   Updated: 2019/07/14 21:43:15 by etommy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SIZE 9

int		number_unassigned(int *row, int *col);
int		is_safe(int n, int r, int c);

int		g_matrix[9][9];

int		solve_sudoku(void)
{
	int row;
	int col;
	int i;

	if (number_unassigned(&row, &col) == 0)
		return (1);
	i = 1;
	while (i <= SIZE)
	{
		if (is_safe(i, row, col))
		{
			g_matrix[row][col] = i;
			if (solve_sudoku())
				return (1);
			g_matrix[row][col] = 0;
		}
		i++;
	}
	return (0);
}
