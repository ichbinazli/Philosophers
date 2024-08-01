/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naanapa <naanapa@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:50:23 by naanapa           #+#    #+#             */
/*   Updated: 2024/07/26 14:11:35 by naanapa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_rules	rules;

	if (!(argc == 5 || argc == 6))
		return (write_error("Invalid Argument"), 0);
	if (parse(&rules, argv))
		return (write_error("Mutex Start Error"), 0);
	if (init_philosophers(&rules))
		return (write_error("Philosophers Init Error"), 0);
	if (init_mutex(&rules))
		return (write_error("Mutex Init Error"), 0);
	if (launcher(&rules))
		return (write_error("Thread Create Error"), 0);
}
