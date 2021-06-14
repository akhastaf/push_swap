/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:15:02 by akhastaf          #+#    #+#             */
/*   Updated: 2021/06/14 17:02:22 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc((ft_strlen(s1) * sizeof(char)) + 1);
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = s1[i];
	return (str);
}
