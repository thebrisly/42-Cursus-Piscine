/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:38:20 by lfabbian          #+#    #+#             */
/*   Updated: 2023/03/07 14:01:19 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	mini_unset(t_minishell *ms)
{
	t_env	*current;

	current = ms->env_dup;
	while (current)
	{
		if (current.key)
	}
}

// faire une fonction qui enleve
