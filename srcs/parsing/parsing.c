/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:02:20 by arudy             #+#    #+#             */
/*   Updated: 2022/03/31 18:58:10 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_cmd	*cmd_lst_last(t_cmd *lst)
{
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	cmd_lst_addback(t_cmd **head, t_cmd *new)
{
	t_cmd	*tmp;

	if (new)
	{
		if (*head)
		{
			tmp = cmd_lst_last(*head);
			tmp->next = new;
		}
		else
			*head = new;
	}
}

t_cmd	*parse_cmd(t_token **tokens, int size, t_cmd *new, t_cmd *prev)
{
	int		i;

	i = 0;
	(void)prev;
	new->cmd = malloc(sizeof(char *) * (size + 1));
	if (!new->cmd)
		return (NULL);
	while (*tokens && i < size)
	{
		new->cmd[i] = ft_strdup((*tokens)->content);
		*tokens = (*tokens)->next;
		i++;
	}
	new->cmd[i] = 0;
	new->next = NULL;
	new->prev = prev;
	return (new);
}

t_cmd	*create_cmd_lst(t_token **tokens)
{
	int		size;
	t_token	*head_tokens;
	t_cmd	*head;
	t_cmd	*new;
	t_cmd	*prev;

	head = NULL;
	prev = NULL;
	head_tokens = *tokens;
	while (*tokens)
	{
		size = find_cmd_length(*tokens);
		new = malloc(sizeof(t_cmd));
		if (!new)
			return (NULL);
		new = parse_cmd(tokens, size, new, prev);
		if (!new)
			return (NULL);
		if (*tokens)
			*tokens = (*tokens)->next;
		prev = new;
		cmd_lst_addback(&head, new);
	}
	*tokens = head_tokens;
	return (head);
}

int	parsing(char *line, t_data *data)
{
	if (first_check(line) || check_line(line))
		return (1);
	if (lexer(line, &data->tokens))
		return (1);
	data->nb_cmd = count_nb_cmd(&data->tokens);
	data->cmd_lst = create_cmd_lst(&data->tokens);
	if (!data->cmd_lst)
	{
		ft_putstr_fd("Can't create cmd lst\n", 2);
		return (1);
	}
	return (0);
}