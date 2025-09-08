/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldei-sva <ldei-sva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:10:19 by ldei-sva          #+#    #+#             */
/*   Updated: 2025/09/08 23:41:37 by ldei-sva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		array_len(char **s1)
{
	int	i;

	i = 0;
	while (s1 && s1[i])
		i++;
	return (i);
}

void	ft_arrayjoin(char **s1, char *s2)
{
	int		len;
	char	**result;

	len = array_len(s1) + 2;
	result = (char **) malloc (len * (sizeof(char *)));
	len = 0;
	while (s1 && s1[len])
	{
		result[len] = s1[len];
		len++;
	}
	result[len] = s2;
	result[len + 1] = NULL;
	*s1 = *result;
	free(result);
}
