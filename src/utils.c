/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 20:09:10 by gfielder          #+#    #+#             */
/*   Updated: 2019/06/21 19:41:39 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

/* ----------------------------------------------------------------------------
** Appends a string to the log
** --------------------------------------------------------------------------*/

void		log_msg(const char *msg)
{
	time_t	t;
	char	timestr[27];
	FILE	*fp;

	bzero(timestr, 27);
	t = time(NULL);
	ctime_r(&t, timestr);
	for (int i = 26; i >= 0; i--)
		if (timestr[i] == '\n' || timestr[i] == '\r')
			timestr[i] = ' ';
	fp = fopen(LOG_FILE, "a");
	if (fp)
	{
		fprintf(fp, "%-27s: %s\n", timestr, msg);
		fclose(fp);
	}
}

/* ----------------------------------------------------------------------------
** The ft_match function is used for wildcard-based searches
** s2 has an indeterminate number of *, s1 is the function name to test.
** --------------------------------------------------------------------------*/
int			ft_match_helper(const char *s1, char *s2)
{
	int		i;
	char	next;
	int		found;

	i = 0;
	next = *(s2 + 1);
	found = 0;
	if (next == '\0')
		return (1);
	if (next == '*')
		return (ft_match(s1, s2 + 1));
	while (1)
	{
		if (s1[i] == next)
			found = (ft_match(s1 + i, s2 + 1));
		if (found)
			return (found);
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (-1);
}
int			ft_match(const char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	if (*s2 != '*' && (*s1 != *s2))
		return (0);
	if (*s2 == '*')
		return (ft_match_helper(s1, s2));
	else if (*s1 == *s2)
		return (ft_match(s1 + 1, s2 + 1));
	return (-1);
}

/* ----------------------------------------------------------------------------
** Writes to a buffer with a [time duration] ago statement
** --------------------------------------------------------------------------*/
void		write_ago(time_t prev_time, time_t now, char *buff)
{
	time_t	diff = now - prev_time;
	char *unit = "sec";

	if (diff > 86400)
	{
		diff /= 86400;
		unit = (diff > 1 ? "days" : "day");
	}
	else if (diff > 3600)
	{
		diff /= 3600;
		unit = "hr";
	}
	else if (diff > 60)
	{
		diff /= 60;
		unit = "min";
	}
	sprintf(buff, "%li %s ago", diff, unit);
}

/* ----------------------------------------------------------------------------
** Converts all invalid characters for function names into wildcards
** --------------------------------------------------------------------------*/
void 		convert_nonalphanum_to_wildcard(char *str)
{
	while (*str)
	{
		if (!((*str >= 'a' && *str <= 'z')
				|| (*str >= 'A' && *str <= 'Z')
				|| (*str >= '0' && *str <= '9')
				|| *str == '_'))
			*str = '*';
		str++;
	}
}

/* ----------------------------------------------------------------------------
** Some libft functions
** --------------------------------------------------------------------------*/

void	my_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
void	my_putnbr_fd(int nb, int fd)
{
	if (nb < 0)
	{
		my_putchar_fd('-', fd);
		if (nb == -2147483648)
		{
			my_putchar_fd('2', fd);
			nb = -147483648;
		}
		nb *= -1;
	}
	if (nb >= 10)
	{
		my_putnbr_fd(nb / 10, fd);
		my_putchar_fd('0' + (nb % 10), fd);
	}
	else
		my_putchar_fd('0' + nb, fd);
}

void	my_destroy_nullterm_ptrarray(void ***arr)
{
	int		i;

	if (arr == NULL || *arr == NULL)
		return ;
	i = 0;
	while ((*arr)[i] != NULL)
	{
		free(((*arr)[i]));
		(*arr)[i] = NULL;
		i++;
	}
	free(*arr);
	*arr = NULL;
}

char	*my_strdup(const char *str)
{
	char	*r;
	int		len;
	int		i;

	len = 0;
	while (str[len])
		len++;
	r = (char *)malloc((sizeof(char) * (len + 1)));
	if (r == NULL)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		r[i] = str[i];
		i++;
	}
	return (r);
}

char	*my_strdup_to(const char *str, char c)
{
	char	*r;
	int		len;
	int		i;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	r = (char *)malloc((sizeof(char) * (len + 1)));
	if (r == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		r[i] = str[i];
		i++;
	}
	r[len] = '\0';
	return (r);
}

size_t	my_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*my_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (*((unsigned char *)s + i) == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s + i);
	return (NULL);
}

char	*my_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (*((unsigned char *)s + i) == (unsigned char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}

int		my_strchr_idx(const char *s, int c)
{
	char	*p;

	if (!s)
		return (-1);
	p = my_strchr(s, c);
	if (!p)
		return (-1);
	return ((int)(p - s));
}

static int	my_count_words(const char *str, char c, char *groupers)
{
	int		i;
	int		count;
	int		idx;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		idx = my_strchr_idx(groupers, str[i]);
		if (str[i] && idx >= 0 && ((idx & 1) == 0))
		{
			count++;
			while (str[++i] && (str[i] != groupers[idx + 1] || !(i++)))
				;
		}
		else if (str[i])
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static void	strsplit_fill(char **ret, char const *str, char c, char *groupers)
{
	int		i;
	int		j;
	int		idx;

	i = 0;
	j = -1;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		idx = my_strchr_idx(groupers, str[i]);
		if (str[i] && idx >= 0 && ((idx & 1) == 0))
		{
			ret[++j] = my_strdup_to(str + (++i), groupers[idx + 1]);
			i += my_strlen(ret[j]);
			if (str[i] == groupers[idx + 1])
				i++;
		}
		else if (str[i])
		{
			ret[++j] = my_strdup_to(str + i, c);
			i += my_strlen(ret[j]);
		}
	}
}

char		**my_strsplit_grouping(char const *s, char c, char *groupers)
{
	char	**ret;
	int		word_count;

	if (!s || !groupers)
		return (NULL);
	word_count = my_count_words(s, c, groupers);
	ret = (char **)malloc(sizeof(char *) * (word_count + 1));
	strsplit_fill(ret, s, c, groupers);
	ret[word_count] = NULL;
	return (ret);
}

char		**my_strsplit(char const *s, char c)
{
	return (my_strsplit_grouping(s, c, ""));
}

void				my_printhexbyte_fd(int fd, const void *loc)
{
	const char base[] = "0123456789abcdef";
	if (*((unsigned char *)loc) < 16)
		write(fd, "0", 1);
	else
		write(fd, base + (*((unsigned char *)loc) / 16), 1);
	write(fd, base + (*((unsigned char *)loc) % 16), 1);
}

void	my_putnchar_np_hex_fd(int fd, const char *str, int n)
{
	int i;

	i = -1;
	while (++i < n)
	{
		if (str[i] >= 32 && str[i] <= 126)
			my_putchar_fd(str[i], fd);
		else
		{
			write(fd, "\\x", 2);
			my_printhexbyte_fd(fd, str + i);
		}
	}
}
