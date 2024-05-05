/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:33:23 by glajara-          #+#    #+#             */
/*   Updated: 2024/05/05 16:52:50 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>		// usleep
#include <stdio.h>		// printf
#include <pthread.h>	// pthread_*

void	*printmsg(void	*ptr)
{
	char	*str;

	str = (char *)ptr;
	printf("%s : Hello World!\n", str);
	usleep(20000);
	printf("%s : Goodbye World...\n", str);
	return (NULL);
}

int	main(void)
{
	pthread_t	t1;
	pthread_t	t2;

	pthread_create(&t1, NULL, &printmsg, "A");
	pthread_create(&t2, NULL, &printmsg, "B");
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_detach(t1);
	pthread_detach(t2);
	return (0);
}
