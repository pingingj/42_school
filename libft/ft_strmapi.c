/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:25:24 by dgarcez-          #+#    #+#             */
/*   Updated: 2024/11/04 12:29:38 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*resultado;

	if (s == NULL)
		return (NULL);
	i = 0;
	resultado = (char *)malloc(ft_strlen(s) * sizeof(char) + 1);
	if (resultado == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		resultado[i] = f(i, s[i]);
		i++;
	}
	resultado[i] = '\0';
	return (resultado);
}
