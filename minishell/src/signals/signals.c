/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysetiawa <ysetiawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 12:31:23 by messs             #+#    #+#             */
/*   Updated: 2025/02/04 20:20:23 by ysetiawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_signal	g_sig = {0};

void	signal_reset_prompt(int signo)
{
	(void)signo;
	ft_putstr_fd("\n", STDOUT_FILENO);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_sig.sigint = 1;
}

void	handle_sigquit(int signo)
{
	(void)signo;
	ft_putstr_fd("\033[2K\r", STDERR_FILENO);
	rl_on_new_line();
	rl_redisplay();
}

void	set_signals_interactive(void)
{
	struct sigaction	act;

	ft_memset(&act, 0, sizeof(act));
	act.sa_handler = &signal_reset_prompt;
	sigaction(SIGINT, &act, NULL);
	ft_memset(&act, 0, sizeof(act));
	act.sa_handler = &handle_sigquit;
	sigaction(SIGQUIT, &act, NULL);
}

void	signal_print_newline(int signal)
{
	(void)signal;
	g_sig.sigint = 1;
	ft_putstr_fd("\n", STDOUT_FILENO);
	rl_on_new_line();
}

void	set_signals_heredoc(void)
{
	struct sigaction	act;

	ft_memset(&act, 0, sizeof(act));
	act.sa_handler = &signal_print_newline;
	sigaction(SIGINT, &act, NULL);

	ft_memset(&act, 0, sizeof(act));
	act.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &act, NULL);
}

void	ignore_sigquit(int signo)
{
	(void) signo;
	ft_putstr_fd("\033[2K\r", STDERR_FILENO);
	ft_putstr_fd("> ",STDERR);
}

void	init_signals(void)
{
	set_signals_interactive();
}

void	handle_eof(char *line, t_minishell *mini)
{
	int	i;

	if (!line)
	{
		i = 0;
		ft_putstr_fd("exit\n", STDOUT_FILENO);
		free_env(mini->env);
		free_env_array(mini->env2);
		free(mini);
		exit(i);
	}
}
void stop_signals(void)
{
	signal(SIGINT,SIG_IGN);
	signal(SIGQUIT,SIG_IGN);
}
