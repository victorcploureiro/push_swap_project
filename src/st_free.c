/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:16:14 by vcarrara          #+#    #+#             */
/*   Updated: 2024/06/07 18:14:08 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_args(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (argv[i])
			free(argv[i++]);
		if (argv)
			free(argv);
	}
}
