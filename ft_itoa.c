/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 18:09:40 by slaajour          #+#    #+#             */
/*   Updated: 2022/07/05 04:23:11 by slaajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	len(long int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			count;
	long int	temp;

	count = len(n);
	str = malloc(sizeof(char) * count + 1);
	if (str == NULL)
		return (NULL);
	temp = n;
	str[count] = '\0';
	if (temp < 0)
		temp = temp * -1;
	while (count != 0)
	{
		str[count - 1] = (temp % 10) + 48;
		temp = temp / 10;
		count--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
