/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:16:21 by akhastaf          #+#    #+#             */
/*   Updated: 2021/06/14 17:00:31 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)malloc((n * sizeof(char)) + 1);
	if (!str)
		return (NULL);
	while (s1[i] != '\0' && i < n)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
