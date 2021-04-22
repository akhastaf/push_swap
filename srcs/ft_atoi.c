/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:08:36 by akhastaf          #+#    #+#             */
/*   Updated: 2021/04/22 15:58:58 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

long		ft_atoi(const char *str)
{
	int		i;
	int		signe;
	unsigned long	n;

	i = 0;
	signe = 1;
	n = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			signe = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57 && str[i] != '\0')
	{
		n = n * 10 + str[i] - 48;
		// if (n > 9223372036854775807)
		// 	return ((signe > 0) ? -1 : 0);
		i++;
	}
	return (n * signe);
}

// long long	ft_atoi(const char *str)
// {
// 	int					i;
// 	int					signe;
// 	unsigned long long	n;

// 	i = 0;
// 	signe = 1;
// 	n = 0;
// 	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
// 		i++;
// 	if (str[i] == 45 || str[i] == 43)
// 	{
// 		if (str[i] == 45)
// 			signe = -1;
// 		i++;
// 	}
// 	while (str[i] >= 48 && str[i] <= 57 && str[i] != '\0')
// 	{
// 		n = n * 10 + str[i] - 48;
// 		i++;
// 	}
// 	return ((long long)(n * signe));
// }