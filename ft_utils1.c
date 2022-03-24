/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 18:59:41 by ytouab            #+#    #+#             */
/*   Updated: 2021/10/01 00:14:47 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	a[4];

	a[0] = 0;
	a[1] = 0;
	if (!s1 || !s2)
		return (0);
	a[2] = ft_strlen(s1);
	a[3] = ft_strlen(s2);
	ret = (char *)malloc((a[2] + a[3] + 1) * sizeof(char));
	if (!ret)
		return (0);
	while (a[0] < a[2])
	{
		ret[a[0]] = s1[a[0]];
		a[0]++;
	}
	while (a[1] < a[3])
		ret[a[0]++] = s2[a[1]++];
	ret[a[0]] = 0;
	return (ret);
}

char	*ft_strdup(const char *str)
{
	char	*ret;
	int		i;

	i = ft_strlen(str);
	ret = (char *)malloc((i + 1) * sizeof(char));
	if (!ret)
		return (0);
	i = 0;
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

size_t	ft_strlen(const char *str)
{
	size_t	l;

	l = 0;
	while (str[l])
		l++;
	return (l);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;
	size_t	l;

	i = 0;
	if (!s)
		return ;
	l = ft_strlen(s);
	while (i < l)
		ft_putchar_fd(s[i++], fd);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
