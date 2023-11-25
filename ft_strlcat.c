/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:23:24 by moel-fat          #+#    #+#             */
/*   Updated: 2023/11/19 13:37:53 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;
	size_t	as;

	i = 0;
	srclen = ft_strlen(src);
	if ((!dst && dstsize == 0) || dstsize == 0)
		return (srclen);
	dstlen = ft_strlen(dst);
	as = dstsize - dstlen - 1;
	if (dstsize <= dstlen) 
		return (dstsize + srclen);
	if (as > 0)
	{
		while (src[i] && i < as)
		{
			dst[dstlen + i] = src[i];
			i++;
		}
		dst[dstlen + i] = '\0';
	}
	return (dstlen + srclen);
}
