/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_disabled_postprocess.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 18:34:12 by gfielder          #+#    #+#             */
/*   Updated: 2019/05/18 18:53:17 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//This file is a utility for show-disabled-tests. It decrements the line number
//to match the test number and removes tab literals.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		main(void)
{
	char *line = strdup("");
	size_t size = 0;
	int		number;
	char	*str;

	while (getline(&line, &size, stdin) > 0)
	{
		number = atoi(line);
		str = strchr(line, ':');
		for (int i = 0; str[i]; i++)
		{
			if (str[i] == '\t')
				str[i] = ' ';
		}
		printf("%i%s", number - 1, str);
	}
	free(line);
	return (0);
}
