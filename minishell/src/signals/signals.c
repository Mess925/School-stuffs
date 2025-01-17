/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messs <messs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 12:31:23 by messs             #+#    #+#             */
/*   Updated: 2025/01/17 23:33:27 by messs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_signal g_sig = {0};

void sig_int_handler(int sigcode)
{
	(void)sigcode;
	if (g_sig.pid == 0)
	{
		ft_putstr_fd("\nminishell $", STDERR_FILENO);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else
	{
		ft_putstr_fd("\n", STDERR_FILENO);
	}
	g_sig.sigint = 1;
}

void sig_quit_handler(int sigcode)
{
	(void)sigcode;
	if (g_sig.pid == 0)
	{
		ft_putstr_fd("\033[2K\r", STDERR_FILENO);
		rl_on_new_line();
		rl_redisplay();
	}
	else
	{
		ft_putstr_fd("Quit (core dumped)\n", STDERR_FILENO);
	}
}

void heredoc_sigint_handler(int sigcode)
{
	(void)sigcode;
	ft_putstr_fd("\n", STDERR_FILENO);
	g_sig.sigint = 1;
}
void set_signal_handlers(int mode)
{
	struct sigaction act;

	ft_memset(&act, 0, sizeof(act));
	if (mode == INTERACTIVE)
	{
		act.sa_handler = sig_int_handler;
		sigaction(SIGINT, &act, NULL);
		act.sa_handler = sig_quit_handler;
		sigaction(SIGQUIT, &act, NULL);
	}
	else if (mode == HEREDOC_MODE)
	{
		act.sa_handler = heredoc_sigint_handler;
		sigaction(SIGINT, &act, NULL);
		act.sa_handler = SIG_IGN;
		sigaction(SIGQUIT, &act, NULL);
	}
}
void init_signals(void)
{
	g_sig.sigint = 0;
	g_sig.sigquit = 0;
	g_sig.pid = 0;
	set_signal_handlers(INTERACTIVE);
}

void handle_eof(char *line, t_minishell *mini)
{
	if (!line)
	{
		mini->exit = 0;
		ft_putstr_fd("exit\n", STDOUT_FILENO);
		exit(mini->exit);
	}
}
