/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:22:04 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/09/15 21:22:06 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

int		ft_countlines(char *file)
{
	int		fd;
	int		count;
	int		ret;
	char	buffer[1];

	count = 0;
	ret = 1;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	while ((ret = read(fd, buffer, 1)) && buffer[0] == '\n')
		;
	while (ret)
	{
		while ((ret = read(fd, buffer, 1)) && *buffer != '\n')
			;
		while ((ret = read(fd, buffer, 1)) && *buffer == '\n')
			;
		count++;
	}
	close(fd);
	return (count);
}

int		ft_beforecolon(int fd, char buffer[1])
{
	int		ret;

	if (*buffer != ' ')
		return (0);
	while ((ret = read(fd, buffer, 1)) && *buffer == ' ')
		;
	if (*buffer != ':')
		return (0);
	return (1);
}

int		ft_readline(int fd, t_definition *dict, int *ret, char buffer[1])
{
	char	str[STR_SIZE];
	int		i;

	if (*buffer < '0' || *buffer > '9')
		return (0);
	i = 0;
	str[0] = *buffer;
	while ((*ret = read(fd, buffer, 1)) && *buffer >= '0' && *buffer <= '9')
		str[++i] = *buffer;
	str[i + 1] = '\0';
	ft_strcpy(dict->dgt, str);
	if (*buffer != ':' && !ft_beforecolon(fd, buffer))
		return (0);
	while ((*ret = read(fd, buffer, 1)) && *buffer == ' ')
		;
	str[0] = *buffer;
	i = 0;
	while ((*ret = read(fd, buffer, 1)) && *buffer >= 32 && *buffer <= 126)
		str[++i] = *buffer;
	str[i + 1] = '\0';
	ft_strcpy(dict->str, str);
	return (1);
}

int		ft_filldict(t_definition *dict, char *file)
{
	int		ret;
	int		fd;
	char	buffer[1];

	ret = 1;
	fd = open(file, O_RDONLY);
	while (read(fd, buffer, 1) && buffer[0] == '\n')
		;
	while (ret)
	{
		if (!ft_readline(fd, dict, &ret, buffer))
			return (0);
		if (*buffer != '\n')
			return (0);
		while ((ret = read(fd, buffer, 1)) && *buffer == '\n')
			;
		dict++;
	}
	dict->str[0] = 0;
	return (1);
}

int		ft_parsefile(t_definition **dict, char *file)
{
	int	linecount;

	linecount = ft_countlines(file);
	if (!linecount)
	{
		return (ERREUR_DICT);
	}
	*dict = malloc(sizeof(**dict) * (linecount + 1));
	if (!*dict)
		return (ERREUR_MALLOC);
	if (!ft_filldict(*dict, file))
	{
		return (ERREUR_DICT);
	}
	return (SUCCESS);
}
