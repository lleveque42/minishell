/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:19:49 by arudy             #+#    #+#             */
/*   Updated: 2022/04/07 19:58:34 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// int	main(int ac, char **av, char **envp)
// {
// 	t_data	*data;

// 	(void)av;
// 	(void)ac;
// 	data = init_data(envp);
// 	// export_cmd(av, env);
// 	unset_cmd(av, &data->env);
// 	env_cmd(data->env);
// 	ft_free(data);
// 	return (0);
// }


// void	print_lst(t_cmd *lst)
// {
// 	int	i;

// 	while (lst)
// 	{
// 		i = 0;
// 		printf("---------\n");
// 		while (lst->cmd[i] != NULL)
// 		{
// 			printf("%s\n", lst->cmd[i]);
// 			i++;
// 		}
// 		printf("---------\n");
// 		if (lst->next == NULL)
// 			break ;
// 		lst = lst->next;
// 	}
// }

// int	main(int ac, char **av, char **envp)
// {
// 	char	*line;
// 	t_data	*data;

// 	(void)av;
// 	(void)ac;
// 	data = init_data(envp);
// 	while (1)
// 	{
// 		line = readline("Minishell : ");
// 		if (*line)
// 		{
// 			if (parsing(line, data) == 0)
// 			{
// 				// execve(data->cmd_lst->bin_path, data->cmd_lst->cmd, envp);
// 				// printf("coucouc\n");
// 				// exec
// 				// print_token_lst(&data->tokens);
// 				// print_lst(data->cmd_lst);
// 				free_lst(data);
// 			}
// 		}
// 	}
// 	ft_free(data);
// 	return (0);
// }
