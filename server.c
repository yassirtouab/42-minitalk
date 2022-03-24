/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:02:28 by ytouab            #+#    #+#             */
/*   Updated: 2021/11/20 19:05:14 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	get_char(char *binary)
{
	int	i;
	int	ret;
	int	base;

	i = 7;
	ret = 0;
	base = 1;
	while (i >= 0)
	{
		if (binary[i] == '1')
			ret = ret + base;
		base = base * 2;
		i--;
	}
	return (ret);
}

void	ft_signal_handler(int signum)
{
	static char	*binary;

	if (binary == NULL)
		binary = ft_strdup("");
	if (signum == SIGUSR1)
		binary = ft_strjoin(binary, "0\0");
	if (signum == SIGUSR2)
		binary = ft_strjoin(binary, "1\0");
	if (ft_strlen(binary) == 8)
	{
		ft_putchar_fd(get_char(binary), 1);
		free(binary);
		binary = NULL;
	}
}

int	main(void)
{
	pid_t	pid;
	char	*id;

	signal(SIGUSR1, ft_signal_handler);
	signal(SIGUSR2, ft_signal_handler);
	pid = getpid();
	id = ft_itoa(pid);
	ft_putstr_fd("******************************************************\n", 1);
	ft_putstr_fd("*                    | MINITALK |                    *\n", 1);
	ft_putstr_fd("******************************************************\n", 1);
	ft_putstr_fd("                      PID = ", 1);
	ft_putstr_fd(id, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("******************************************************\n", 1);
	ft_putstr_fd("\n", 1);
	free(id);
	id = NULL;
	while (1)
		pause();
	return (0);
}
