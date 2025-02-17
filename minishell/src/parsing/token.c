/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocelynnns <yocelynnns@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:19:25 by ysetiawa          #+#    #+#             */
/*   Updated: 2025/02/12 03:00:48 by yocelynnns       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_token	*create_token(t_token_type type, const char *value)
{
	t_token	*new_token;

	new_token = malloc(sizeof(t_token));
	if (!new_token)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	new_token->type = type;
	new_token->value = ft_strdup(value);
	if (!new_token->value)
	{
		free_tokens(new_token);
		return (NULL);
	}
	new_token->next = NULL;
	return (new_token);
}

void	add_token(t_token **head, t_token *new_token)
{
	t_token	*temp;

	if (!*head)
		*head = new_token;
	else
	{
		temp = *head;
		while (temp->next)
			temp = temp->next;
		temp->next = new_token;
	}
}

t_ast_node	*build_ast(t_token *tokens, t_minishell *mini)
{
	int	i;

	i = count_cmds(tokens);
	return (parse_pipeline(tokens, mini, i));
}

void	init_lexstate(t_lexer_state *state)
{
	state->i = 0;
	state->start = 0;
	state->quote = 0;
	state->last_token_was_pipe = 0;
	state->token_list = NULL;
}

int	checkquote(t_lexer_state *state, t_minishell *mini)
{
	if (state->quote)
	{
		printf("Error: Unclosed quote '%c'\n", state->quote);
		free_tokens(state->token_list);
		mini->exit = 2;
		return (1);
	}
	return (0);
}

void	handle_quotes(const char *input, t_lexer_state *state)
{
	if (state->quote == 0)
		state->quote = input[state->i];
	else if (state->quote == input[state->i])
		state->quote = 0;
}

void	handle_spaces(const char *input, t_lexer_state *state,
		t_minishell *mini)
{
	char	*raw_token;
	char	*processed_token;

	if (state->i > state->start)
	{
		raw_token = ft_strndup(input + state->start, state->i - state->start);
		processed_token = first_processing(raw_token, mini);
		add_token(&state->token_list, create_token(WORD, processed_token));
		free(raw_token);
		free(processed_token);
	}
	state->start = state->i + 1;
}

void	handle_redirect_in(t_lexer_state *state, const char *input, t_minishell *mini)
{
	if (input[state->i + 1] == '<')
	{
        mini->here = 1;
		add_token(&state->token_list, create_token(HEREDOC, "<<"));
		state->i++;
	}
	else
		add_token(&state->token_list, create_token(REDIRECT_IN, "<"));
}

void	handle_redirect_out(t_lexer_state *state, const char *input)
{
	if (input[state->i + 1] == '>')
	{
		add_token(&state->token_list, create_token(APPEND, ">>"));
		state->i++;
	}
	else
		add_token(&state->token_list, create_token(REDIRECT_OUT, ">"));
}

void	handle_redir(const char *input, t_lexer_state *state, char direction,
		t_minishell *mini)
{
	char	*raw_token;
	char	*processed_token;

	if (state->i > state->start)
	{
		raw_token = ft_strndup(input + state->start, state->i - state->start);
		processed_token = first_processing(raw_token, mini);
		add_token(&state->token_list, create_token(WORD, processed_token));
		free(raw_token);
		free(processed_token);
	}
	if (direction == '<')
		handle_redirect_in(state, input, mini);
	else if (direction == '>')
		handle_redirect_out(state, input);
	state->start = state->i + 1;
}

void	handle_pipe(const char *input, t_lexer_state *state, t_minishell *mini)
{
	char	*raw_token;
	char	*processed_token;

	if (state->last_token_was_pipe)
	{
		fprintf(stderr,
			"Error: Invalid sequence of consecutive '|' operators\n");
		mini->exit = 217;
	}
	state->last_token_was_pipe = 1;
	if (state->i > state->start)
	{
		raw_token = ft_strndup(input + state->start, state->i - state->start);
		processed_token = first_processing(raw_token, mini);
		add_token(&state->token_list, create_token(WORD, processed_token));
		free(raw_token);
	}
	add_token(&state->token_list, create_token(PIPE, "|"));
	state->start = state->i + 1;
}

void	process_remaining_token(const char *input, t_lexer_state *state,
		t_minishell *mini)
{
	char	*raw_token;
	char	*processed_token;
	char	**split_tokens;
	int		i;

	raw_token = NULL;
	processed_token = NULL;
	split_tokens = NULL;
	if (state->i > state->start)
	{
		raw_token = ft_strndup(input + state->start, state->i - state->start);
		processed_token = first_processing(raw_token, mini);
		if (input[0] == '$')
		{
			split_tokens = ft_split(processed_token, ' ');
			free(processed_token);
			if (!split_tokens)
				return;
			i = 0;
			while (split_tokens[i])
			{
				add_token(&state->token_list, create_token(WORD, split_tokens[i]));
				free(split_tokens[i]);
				i++;
			}
			free(split_tokens);
		}
		else
			if (processed_token)
			{
				add_token(&state->token_list, create_token(WORD, processed_token));
				free(processed_token);
			}
		free(raw_token);
	}
}

int	checkpipe(const char *input, t_lexer_state *state, t_minishell *mini)
{
	if (input[state->i] == '|' && input[state->i + 1] != '|')
	{
		printf("Error: Syntax error near unexpected token `|'\n");
		mini->exit = 2;
		free_tokens(state->token_list);
		return (1);
	}
	if (((input[state->i] == '"' && input[state->i + 1] == '"') ||
	(input[state->i] == '\'' && input[state->i + 1] == '\'')) && (input[state->i + 2] == '\0'))
	{
		printf("Command not found: ''\n");
		mini->exit = 127;
		free_tokens(state->token_list);
		return (1);
	}
	return (0);
}

void lexer_checks(const char *input, t_lexer_state *state, t_minishell *mini)
{
	if ((input[state->i] == '\'' || input[state->i] == '"') && (state->i == 0 || input[state->i - 1] != '\\'))
		handle_quotes(input, state);
	else if (isspace(input[state->i]) && !state->quote)
		handle_spaces(input, state, mini);
	else if ((input[state->i] == '<' || input[state->i] == '>')
		&& !state->quote)
		handle_redir(input, state, input[state->i], mini);
	else if (input[state->i] == '|' && !state->quote)
		handle_pipe(input, state, mini);
	else
		state->last_token_was_pipe = 0;
}

t_token	*lexer(const char *input, t_minishell *mini)
{
	t_lexer_state	state;
	int				j;
	int				i;

	j = 0;
	i = 0;
	init_lexstate(&state);
	i = checkpipe(input, &state, mini);
	while (input[state.i])
	{
		lexer_checks(input, &state, mini);
		state.i++;
	}
	if (mini->exit == 217)
	{
		mini->exit = 2;
		return (NULL);
	}
	j = checkquote(&state, mini);
	if (j || i)
		return (NULL);
	process_remaining_token(input, &state, mini);
	mini->here = 0;
	return (state.token_list);
}

	// if (input[state->i] == '$')
	// 	handle_dollar(input, state, mini);
// void	handle_dollar(const char *input, t_lexer_state *state,
// 		t_minishell *mini)
// {
// 	// char	*status_str;
// 	char	*empty;

// 	(void)mini;
	// if (input[state->i + 1] == '?')
	// {
	// 	status_str = ft_itoa(mini->exit);
	// 	add_token(&state->token_list, create_token(WORD, status_str));
	// 	free(status_str);
	// 	state->i++;
	// 	state->start = state->i + 1;
	// }
	// if (input[state->i + 1] == '\0' && input[state->i - 1] != ' ')
	// {
	// 	empty = "$";
	// 	add_token(&state->token_list, create_token(WORD, empty));
	// 	state->start = state->i + 1;
	// }
// }
		// if (input[state.i] == '$')
		// 	handle_dollar(input, &state, mini);
		// else if ((input[state.i] == '\'' || input[state.i] == '"') && (state.i == 0 || input[state.i - 1] != '\\'))
    	// 	handle_quotes(input, &state);
		// else if (isspace(input[state.i]) && !state.quote)
		// 	handle_spaces(input, &state, mini);
		// else if ((input[state.i] == '<' || input[state.i] == '>')
		// 	&& !state.quote)
		// 	handle_redir(input, &state, input[state.i], mini);
		// else if (input[state.i] == '|' && !state.quote)
		// 	handle_pipe(input, &state, mini);
		// else
		// 	state.last_token_was_pipe = 0;

//   if (input[state.i] == '$' && (input[state.i - 1] != '=') &&
//         (input[state.i - 1] != '\'') && (input[state.i - 2] != '=')
	// && (input[state.i - 1] != '\\'))
