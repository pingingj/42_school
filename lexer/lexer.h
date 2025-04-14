/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:16:13 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/04/09 18:36:46 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum TokenType
{
	T_WORD,
	T_PIPE,
	T_HERE_DOC,
	T_IN_REDIR,
	T_OUT_REDIR,
	T_APPEND_REDIR,
}				t_tokentype;

typedef struct s_token
{
	char		*value;
	t_tokentype	type;
}				t_token;

bool			error_syntax(t_token *tokens, int amount);
bool			check_redir(t_token tokens);
bool			skip_wspaces(char **input);
bool			check_next(char *input);
void			*ft_calloc(size_t num, size_t size);
void			freetrix(char **matrix);
int				count_tokens(char *input, t_token *result);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strchr(const char *s, int c);
bool			is_token(char **input, int *len, int *flag);
bool			is_word(char **input, int *len, int flag);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
char			*ft_strdup(const char *s);

#endif