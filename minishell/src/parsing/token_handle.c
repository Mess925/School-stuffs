/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocelynnns <yocelynnns@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:43:56 by ysetiawa          #+#    #+#             */
/*   Updated: 2025/01/15 01:23:34 by yocelynnns       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// void handle_variable_expansion(t_lexer_state *state, const char *input, int *i, t_minishell *mini)
// {
//     char *status_str;
// 	char *var_name;
// 	char *var_value;
// 	int var_start;
	
// 	if (input[*i + 1] == '?')
// 	{
// 		status_str = ft_itoa(g_exit_status);
// 		add_token(&state->token_list, create_token(WORD, status_str));
// 		free(status_str);
// 		(*i)++;
// 		state->start = *i + 1;
// 	}
// 	else if (isalpha(input[*i + 1]))
// 	{
// 		var_start = *i + 1;
// 		while (input[*i + 1] && (isalnum(input[*i + 1]) || input[*i + 1] == '_'))
// 			(*i)++;
// 		var_name = ft_strndup(input + var_start, *i + 1 - var_start);
// 		var_value = get_env_value(var_name, mini->env);
// 		free(var_name);
// 		if (var_value)
// 			add_token(&state->token_list, create_token(WORD, var_value));
// 		else
// 			add_token(&state->token_list, create_token(WORD, ""));
// 		state->start = *i + 1;
// 	}
// }

// void	handle_redirect_in(t_lexer_state *state, const char *input, int *i)
// {
// 	if (input[*i + 1] == '<')
// 	{
// 		add_token(&state->token_list, create_token(HEREDOC, "<<"));
// 		(*i)++;
// 	}
// 	else
// 		add_token(&state->token_list, create_token(REDIRECT_IN, "<"));
// 	state->start = *i + 1;
// }

// void	handle_redirect_out(t_lexer_state *state, const char *input, int *i)
// {
// 	if (input[*i + 1] == '>')
// 	{
// 		add_token(&state->token_list, create_token(APPEND, ">>"));
// 		(*i)++;
// 	}
// 	else
// 		add_token(&state->token_list, create_token(REDIRECT_OUT, ">"));
// 	state->start = *i + 1;
// }

// void	handle_special_char(t_lexer_state *state, const char *input, int *i, t_minishell *mini)
// {
// 	if (input[*i] == '<' && !state->quote)
// 	{
// 		if (*i > state->start)
// 			add_raw_token(state, input, i, mini);
// 		handle_redirect_in(state, input, i);
// 	}
// 	else if (input[*i] == '>' && !state->quote)
// 	{
// 		if (*i > state->start)
// 			add_raw_token(state, input, i, mini);
// 		handle_redirect_out(state, input, i);
// 	}
// 	else if (input[*i] == '|' && !state->quote)
// 	{
// 		if (*i > state->start)
// 			add_raw_token(state, input, i, mini);
// 		add_token(&state->token_list, create_token(PIPE, "|"));
// 		state->start = *i + 1;
// 	}
// }

    // if (input[*i + 1] == '?')
    // {
    //     status_str = ft_itoa(g_exit_status);
    //     add_token(&state->token_list, create_token(WORD, status_str));
    //     free(status_str);
    //     (*i)++;
    //     state->start = *i + 1;
    // }
    // else
    //     return ;
