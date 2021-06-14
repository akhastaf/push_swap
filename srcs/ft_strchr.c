/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:15:52 by akhastaf          #+#    #+#             */
/*   Updated: 2021/06/14 17:03:51 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	if (!s)
		return (NULL);
	if (!c)
		return (str + ft_strlen(s));
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (NULL);
}
