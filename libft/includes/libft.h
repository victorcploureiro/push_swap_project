/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:10:41 by vcarrara          #+#    #+#             */
/*   Updated: 2024/05/29 22:22:39 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int		ft_abs(int n);
long	ft_atoi(const char *nptr);
int		ft_is_space(char c);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);

int		ft_isdigit(int c);

void	*ft_memset(void *s, int c, size_t n);

char	**ft_split(char const *s, char c);

#endif