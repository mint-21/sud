/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsedgeki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 21:06:48 by lsedgeki          #+#    #+#             */
/*   Updated: 2019/07/14 21:42:56 by etommy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define SIZE 9

void	ft_putchar(char c);
void	print_sudoku();
int		check_subm(int row_start, int col_start, int n);
int		is_safe(int n, int r, int c);
int		number_unassigned(int *row, int *col);
void	make_int_mass(char **argv);
int		solve_sudoku();

int		g_matrix[9][9];

int		check_in(char **argv)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	j = 0;
	count = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			j++;
			count++;
		}
		i++;
	}
	return (count);
}

int		main(int argc, char **argv)
{
	if (check_in(argv) != 81 || argc != 10)
		write(1, "Error\n", 6);
	else
	{
		make_int_mass(argv);
		if (solve_sudoku())
			print_sudoku();
		else
			write(1, "Error\n", 6);
	}
	return (0);
}
