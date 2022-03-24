/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:02:21 by ytouab            #+#    #+#             */
/*   Updated: 2021/11/20 18:49:10 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_binary(int character, int pid)
{
	int	i;
	int	check;

	i = 7;
	while (i >= 0)
	{
		if (character & (1 << i))
			check = kill(pid, SIGUSR2);
		else
			check = kill(pid, SIGUSR1);
		usleep(100);
		i--;
	}
	return (check);
}

void	check_confirmation(int check)
{
	if (check == 0)
		ft_putstr_fd("Message has been sent successfully\n", 1);
	else
		ft_putstr_fd("Something went wrong while sending the message\n", 1);
}

int	send_str(int pid, char *str)
{
	int		check;

	while (*str)
	{
		check = ft_binary(*str, pid);
		str++;
	}
	return (check);
}

int	main(int argc, char **argv)
{
	char	*message;
	int		check;
	int		pid;

	if (argc != 3)
		ft_putstr_fd("Error:\nProgram Takes Two Arguments PID and Message\n", 1);
	else
	{
		message = argv[2];
		pid = ft_atoi(argv[1]);
		send_str(pid, "Message: ");
		check = send_str(pid, message);
		ft_binary('\n', pid);
		check_confirmation(check);
	}
	return (0);
}
