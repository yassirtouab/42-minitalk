/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:35:30 by ytouab            #+#    #+#             */
/*   Updated: 2021/10/07 12:21:16 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static size_t	ft_countint(int n, size_t len)
{
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static size_t	ft_check_neg(int n)
{
	if (n > 0)
		return (0);
	else
		return (1);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	size_t	len;

	nb = n;
	len = ft_check_neg(n);
	if (nb < 0)
		nb = -nb;
	len = ft_countint(n, len);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	str[len--] = '\0';
	while (nb > 0)
	{
		str[len--] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (!len && !str[1])
		str[len] = '0';
	else if (!len && str[1])
		str[len] = '-';
	return (str);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sym;
	size_t	nb;

	i = 0;
	sym = 1;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sym = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + str[i++] - 48;
	if (sym == -1 && nb >= 9223372036854775807)
		return (0);
	else if (sym == 1 && nb >= 9223372036854775807)
		return (-1);
	return (nb * sym);
}
