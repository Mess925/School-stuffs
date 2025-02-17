/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_handlequote.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysetiawa <ysetiawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 19:47:30 by ysetiawa          #+#    #+#             */
/*   Updated: 2025/02/13 21:30:02 by ysetiawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char *ft_strcjoin(char *str, char c)
{
	char *result;
	int i;

	result = malloc(sizeof(char) * (ft_strlen(str) + 2));
	i = 0;
	while (str && str[i])
	{
		result[i] = str[i];
		i++;
	}
	result[i++] = c;
	result[i] = '\0';
	free(str);
	return (result);
}

char *handle_backslash(t_process *proc)
{
	if ((proc->str[proc->i] == '\\' ||
		 proc->str[proc->i] == '\'' ||
		 proc->str[proc->i] == '$' ||
		 proc->str[proc->i] == '\"'))
	{
		proc->result = ft_strcjoin(proc->result, proc->str[++proc->i]);
		proc->i++;
	}
	else if (proc->str[proc->i + 1] == '\n')
		proc->i += 2;
	else
		proc->result = ft_strcjoin(proc->result, proc->str[proc->i++]);
	return proc->result;
}

char *handle_single_quote(t_process *proc)
{
	proc->i++;
	while (proc->str[proc->i])
	{
		if (proc->str[proc->i] == '\'')
		{
			proc->result = ft_strcjoin(proc->result, '\0');
			proc->i++;
			break;
		}
		else
			proc->result = ft_strcjoin(proc->result, proc->str[proc->i++]);
	}
	return proc->result;
}

char *expand_variable(t_process *proc)
{
	int it;
	char *start;
	char *env_value;
	char *temp;

	proc->mini->flag = 1;
	it = 0;
	if (proc->str[proc->i + 1] == '?')
	{
		it = 1;
		env_value = ft_itoa(proc->mini->exit);
		proc->i += 2;
	}
	else
	{
		start = ++proc->i + proc->str;
		char *var = ft_strchr("@#$%^&*()", proc->str[proc->i + 1]);
		// char unders = (char)proc->str[proc->i + 1];
		// printf("unsers is %c\n",unders);
		// write(1, &unders, 1);
		// write(1, "\n", 1);
		// printf("var is %s\n", var);
		if (var == NULL)
		{
			printf("HIIII var is not NULL here\n");
			proc->result = ft_strcjoin(proc->result, '$');
			return proc->result;
		}
		printf("-----------------------------------------------------------\n");
		while (proc->str[proc->i] && !ft_strchr("\\\"\'$ ", proc->str[proc->i]))
			proc->i++;
		start = ft_strndup(start, proc->str + proc->i - start);
		if (!*start)
		{
			proc->result = ft_strcjoin(proc->result, '$');
			free(start);
			return proc->result;
		}
		env_value = get_env_value(start, proc->mini->env);
		free(start);
	}
	if (!proc->result)
		proc->result = ft_strdup("");
	if (env_value)
	{
		temp = proc->result;
		proc->result = ft_strjoin(proc->result, env_value);
		free(temp);
		if (it)
		{
			free(env_value);
			it = 0;
		}
	}
	else
		proc->result = ft_strcjoin(proc->result, '\0');
	return proc->result;
}

char *handle_double_quote(t_process *proc)
{
	proc->in_quote = proc->str[proc->i++];
	while (proc->str[proc->i] && proc->in_quote)
	{
		if (proc->str[proc->i] == '\\' && proc->str[proc->i + 1] != '\'')
			proc->result = handle_backslash(proc);
		else if (proc->str[proc->i] == '$' && proc->str[proc->i - 1] != '\\' && !proc->mini->here)
			proc->result = expand_variable(proc);
		else if (proc->str[proc->i] == proc->in_quote)
		{
			proc->in_quote = 0;
			proc->result = ft_strcjoin(proc->result, '\0');
			proc->i++;
		}
		else
			proc->result = ft_strcjoin(proc->result, proc->str[proc->i++]);
	}
	return proc->result;
}

char *process_character(t_process *proc)
{
	if (proc->str[proc->i] == '\\' && !proc->in_quote)
		proc->result = handle_backslash(proc);
	else if (proc->str[proc->i] == '$' && !proc->mini->here)
		proc->result = expand_variable(proc);
	else if (proc->str[proc->i] == '\'')
		proc->result = handle_single_quote(proc);
	else if (proc->str[proc->i] == '\"')
		proc->result = handle_double_quote(proc);
	else
		proc->result = ft_strcjoin(proc->result, proc->str[proc->i++]);
	return proc->result;
}

char *first_processing(char *str, t_minishell *mini)
{
	t_process proc;

	proc.str = str;
	proc.i = 0;
	proc.in_quote = 0;
	proc.result = NULL;
	proc.mini = mini;
	mini->flag = 0;

	while (proc.str[proc.i])
		process_character(&proc);

	return proc.result;
}

// char *expand_variable(t_process *proc)
// {
//     proc->mini->flag = 1;
//     char *start;
//     start = ++proc->i + proc->str;
//     while (proc->str[proc->i] && !ft_strchr("\\\"\'$ ", proc->str[proc->i]))
//         proc->i++;
//     start = ft_strndup(start, proc->str + proc->i - start);
//     char *env_value = get_env_value(start, proc->mini->env);
//     if (!proc->result)
// 			proc->result = ft_strdup("");
//     if (env_value)
//     {
//         char *temp = proc->result;
//         proc->result = ft_strjoin(proc->result, env_value);
//         free(temp);
//     }
//     else
//         proc->result = ft_strcjoin(proc->result, '\0');
//     free(start);
//     return proc->result;
// }