/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:41:53 by arudy             #+#    #+#             */
/*   Updated: 2022/03/31 12:16:50 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	find_cmd_length(t_token *lst)
{
	int	i;

	i = 0;
	while (lst && lst->type != PIPE)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int	count_nb_cmd(t_token **lst)
{
	int	i;

	i = 1;
	while (*lst)
	{
		if ((*lst)->type == PIPE)
			i++;
		lst = &(*lst)->next;
	}
	return (i);
}

int	check_line(char *s)
{
	int	i;
	int	j;

	i = ft_strlen(s);
	j = 0;
	while (s[j] == ' ')
		j++;
	if (j == i)
		return (1);
	return (0);
}