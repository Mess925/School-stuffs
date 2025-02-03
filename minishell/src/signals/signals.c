/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 12:31:23 by messs             #+#    #+#             */
/*   Updated: 2025/02/03 15:14:08 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_signal	g_sig = {0};

void	sig_int_handler(int sigcode)
{
	(void)sigcode;
	if (g_sig.pid == 0)
	{
		ft_putstr_fd("\n", STDERR_FILENO);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_sig.sigint = 1;
	}
	else
	{
		ft_putchar_fd('\n', STDERR_FILENO);
		kill(g_sig.pid, SIGINT);
	}
	g_sig.exit_value = 130;
}

void	sig_quit_handler(int sigcode)
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
	g_sig.exit_value = 131;
}

void	heredoc_sigint_handler(int sigcode)
{
	(void)sigcode;
	ft_putstr_fd("\n", STDERR_FILENO);
	g_sig.sigint = 1;
	g_sig.exit_value = 130;
}

void	set_signal_handlers(int mode)
{
	struct sigaction	act;

	ft_memset(&act, 0, sizeof(act));
	act.sa_flags = SA_RESTART;
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
	else if (mode == CHILD_PROCESS_MODE)
	{
		act.sa_handler = SIG_DFL;
		sigemptyset(&act.sa_mask);
		sigaction(SIGINT, &act, NULL);
		sigaction(SIGQUIT, &act, NULL);
	}
}
void	init_signals(void)
{
	g_sig.sigint = 0;
	g_sig.sigquit = 0;
	g_sig.pid = 0;
	set_signal_handlers(0);
}

void	handle_eof(char *line, t_minishell *mini)
{
	int	i;

	if (!line)
	{
		i = g_sig.exit_value;
		ft_putstr_fd("exit\n", STDOUT_FILENO);
		free_env(mini->env);
		free(mini);
		exit(i);
	}
}
