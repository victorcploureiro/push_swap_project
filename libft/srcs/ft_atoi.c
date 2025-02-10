/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:58:55 by vcarrara          #+#    #+#             */
/*   Updated: 2024/05/29 21:15:08 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v'
		|| c == '\f');
}

long	ft_atoi(const char *nptr)
{
	long	sign;
	long	convert;

	sign = 1;
	convert = 0;
	while (ft_is_space(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= 48 && *nptr <= 57)
	{
		convert = convert * 10 + (*nptr - 48);
		nptr++;
	}
	return (convert * sign);
}
