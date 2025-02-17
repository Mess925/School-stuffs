/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sec_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:45:45 by hthant            #+#    #+#             */
/*   Updated: 2025/01/24 15:40:06 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void print_exit_error(char *av)
{
	ft_putstr_fd("minishell: exit: ", STDERR);
	ft_putstr_fd(av, STDERR);
	ft_putendl_fd(": numeric argument required", STDERR);
}
char *ft_strjoin_three(const char *s1, const char *s2, const char *s3,
					   const char *s4)
{
	char *result;
	size_t len;

	len = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + ft_strlen(s4) + 1;
	result = malloc(len);
	if (!result)
		return (NULL);
	ft_strcpy(result, (char *)s1);
	ft_strcat(result, (char *)s2);
	ft_strcat(result, (char *)s3);
	ft_strcat(result, (char *)s4);
	return (result);
}
char *format_env_value(const char *env_value)
{
	char *equal_sign;
	char *key;
	char *value;
	char *formatted_value;

	equal_sign = ft_strchr(env_value, '=');
	if (equal_sign)
	{
		key = ft_substr(env_value, 0, equal_sign - env_value);
		value = ft_substr(env_value, equal_sign - env_value + 1,
						  ft_strlen(env_value) - (equal_sign - env_value + 1));
		formatted_value = ft_strjoin_three(key, "=\"", value, "\"");
		free(key);
		free(value);
	}
	else
	{
		formatted_value = ft_strdup(env_value);
	}
	return (formatted_value);
}

int count_cmds(t_token *token)
{
	int i;

	i = 0;
	if (!token)
		return (-1);
	while (token)
	{
		token = token->next;
		i++;
	}
	return (i);
}
