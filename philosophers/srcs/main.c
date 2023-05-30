/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:54:07 by lfabbian          #+#    #+#             */
/*   Updated: 2023/05/30 12:56:49 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"



//some code
int  main(int argc, char **argv)
{
	int			i;
	t_data		data;
	t_philo		*philo;
	pthread_t	*threads;

	i = 0;
	// philo = NULL;
	if (!args_check(argc, argv))
	{
		first_init(argc, argv, &data); //data init
		philo = malloc(sizeof(t_philo) * data.nbr_philo);
		threads = malloc((sizeof (pthread_t)) * data.nbr_philo);
		data.forks = malloc(sizeof(pthread_mutex_t) * data.nbr_philo);
		if (!philo || !threads || !data.forks) //le faire en plus clean
			return (1);
		if (philo_init(&data, threads, philo) == 1)
			return (1);
		i = 0;
		while (i < data.nbr_philo)
		{
			pthread_join(threads[i], NULL); //
			//+ free tout ce qui a ete init
			i++;
		}
	}
}

void	print_message(int id, int ms, char *message, t_philo *ph)
{
	(void) ph;
	printf("%d || Philosopher no %d %s\n",
		ms, id + 1, message);
}