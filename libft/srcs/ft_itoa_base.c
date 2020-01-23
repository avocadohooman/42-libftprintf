/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 12:41:19 by gmolin            #+#    #+#             */
/*   Updated: 2020/01/20 11:48:35 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	length(unsigned long long value, int base)
{
	int		len;

	len = 1;
	if (value < 0)
		len++;
	while (value /= base)
		len++;
	return (len);
}

static char	*reverse(char *str)
{
	char	*rev;
	int		i;
	int		j;

	if (!(rev = ft_strnew(ft_strlen(str))))
		return (NULL);
	i = 0;
	j = ft_strlen(str) - 1;
	while (str[i])
	{
		rev[i] = str[j];
		i++;
		j--;
	}
	free(str);
	return (rev);
}

static char	alpha(unsigned long long set)
{
	char	*alpha;

	alpha = "abcdef";
	return (alpha[set % 10]);
}

char		*ft_itoa_base(unsigned long long value, int base)
{
	char					*str;
	unsigned long long		i;
	unsigned long long		set;
	unsigned long long		len;

	if (base < 2 || base > 16)
		return (NULL);
	len = length(value, base);
	if (!(str = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		set = value % base;
		if (set > 9)
			str[i] = alpha(set);
		else
			str[i] = set + '0';
		value /= base;
		i++;
	}
	return (reverse(str));
}
