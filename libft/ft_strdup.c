/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:14:06 by osancak           #+#    #+#             */
/*   Updated: 2025/06/15 18:25:01 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	int		s_len;

	s_len = ft_strlen(s);
	res = malloc((s_len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[s_len--] = '\0';
	while (s_len >= 0)
	{
		res[s_len] = s[s_len];
		s_len--;
	}
	return (res);
}
