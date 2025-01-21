/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messs <messs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:51:22 by yocelynnns        #+#    #+#             */
/*   Updated: 2025/01/21 10:40:13 by messs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char *resize_buffer(char *content, size_t total_length, size_t *current_size)
{
	char *new_content;

	*current_size *= 2;
	new_content = malloc(*current_size);
	if (!new_content)
	{
		perror("malloc");
		free(content);
		return (NULL);
	}
	ft_memcpy(new_content, content, total_length + 1);
	free(content);
	return (new_content);
}

ssize_t read_line(char *content, size_t total_length, size_t current_size)
{
	write(STDOUT, "> ", 2);
	return (read(STDIN, content + total_length, current_size - total_length - 1));
}

int is_delimiter(const char *content, const char *delimiter,
				 size_t total_length, size_t delimiter_length)
{
	return (ft_strncmp(content + total_length, delimiter, delimiter_length) == 0 && (content[total_length + delimiter_length] == '\n' || content[total_length + delimiter_length] == '\0'));
}

int read_until_delimiter(t_heredoc *hd, t_minishell *mini)
{
	ssize_t bytes_read;

	set_signal_handlers(HEREDOC_MODE);
	while (1)
	{
		bytes_read = read_line(hd->content, hd->total_length, hd->current_size);
		if (g_sig.sigint)
		{
			g_sig.sigint = 0; // Reset signal state
			mini->exit = g_sig.exit_value;
			set_signal_handlers(INTERACTIVE); // Reset handlers immediately
			return (-1);
		}
		if (bytes_read < 0)
		{
			perror("read");
			mini->exit = 1;
			set_signal_handlers(INTERACTIVE); // Reset handlers
			return (-1);
		}
		else if (bytes_read == 0)
		{
			ft_putstr_fd("Heredoc terminated (Ctrl+D)\n", STDERR_FILENO);
			set_signal_handlers(INTERACTIVE); // Reset handlers
			return (-1);
		}
		hd->content[hd->total_length + bytes_read] = '\0';
		if (is_delimiter(hd->content, hd->delimiter, hd->total_length,
						 hd->delimiter_length))
			break;
		hd->total_length += bytes_read;
		if (hd->total_length + 1 >= hd->current_size)
		{
			hd->content = resize_buffer(hd->content, hd->total_length,
										&hd->current_size);
			if (!hd->content)
			{
				mini->exit = 1;
				set_signal_handlers(INTERACTIVE); // Reset handlers
				return (-1);
			}
		}
	}
	mini->exit = 0;
	set_signal_handlers(INTERACTIVE); // Always reset before returning
	return (0);
}

char *read_heredoc(const char *delimiter, t_minishell *mini)
{
	t_heredoc *hd;
	char *final_content;

	hd = init_heredoc(delimiter);
	if (!hd)
		return (NULL);
	if (read_until_delimiter(hd, mini) < 0)
	{
		free(hd->content);
		free(hd);
		return (NULL);
	}
	final_content = malloc(hd->total_length + 1);
	if (!final_content)
	{
		perror("malloc");
		free(hd->content);
		free(hd);
		return (NULL);
	}
	ft_memcpy(final_content, hd->content, hd->total_length);
	final_content[hd->total_length] = '\0';
	free(hd->content);
	free(hd);
	return (final_content);
}
