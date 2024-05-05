/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:33:23 by glajara-          #+#    #+#             */
/*   Updated: 2024/05/05 18:19:25 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>   // gettimeofday

// Returns the current timestamp in milliseconds.
long    get_timestamp()
{
	struct timeval	now;
	long		timestamp;

	gettimeofday(&now, NULL);
	timestamp = (long)now.tv_sec * 1000 + (long)now.tv_usec / 1000;
	return (timestamp);
}

void	*printmsg(void  *ptr)
{
    char	*str;

	str = (char *)ptr;
	printf("[%ld] %s: Hello World!\n", get_timestamp(), str);
	usleep(2000000);
	printf("[%ld] %s: Goodbye World...\n", get_timestamp(), str);
	return (NULL);
}

int main(void)
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
