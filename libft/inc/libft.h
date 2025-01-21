/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:30:39 by gderoyqn          #+#    #+#             */
/*   Updated: 2025/01/21 03:06:45 by gderoyqn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdint.h>
# include <errno.h>
# include <stdbool.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/* PART 1 */

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strnstr(const char *big, const char *little, size_t len);
int			ft_atoi(const char *nptr);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strdup(const char *s);

/* PART 2 */

char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

/* BONUS */

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* FT_PRINTF */

void		p_char(va_list *ptr, int *ccount);
void		p_str(va_list *ptr, int *ccount);
void		p_percent(int *ccount);
void		p_else(const char *str, int *ccount);
size_t		strlen_safe(const char *s);
char		*ft_itoa_base(unsigned long long n, char *base);
void		p_ubase(va_list *ptr, int *ccount, char *base);
void		p_ptr(va_list *ptr, int *ccount);
void		p_int(va_list *ptr, int *ccount);
int			ft_printf(const char *str, ...);

/* NEW */
int			ft_isspace(int c);
void		ft_free_strs(char **strs);

/* DLST */
typedef struct s_dlist
{
	void			*content;
	int				index;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}	t_dlist;

t_dlist		*ft_dlstnew(void *content);
void		ft_dlstadd_front(t_dlist **lst, t_dlist *new);
t_dlist		*ft_dlstlast(t_dlist *lst);
void		ft_dlstadd_back(t_dlist **lst, t_dlist *new);
int			ft_dlstsize(t_dlist *lst);
void		ft_dlstfree(t_dlist *lst);
t_dlist		*get_lst_max(t_dlist *lst);

/* FT_SPLIT_CS */
char		**ft_split_cs(char const *s, char *cs);

/* MINI_STRTOLL */
typedef struct s_strtol_mt
{
	int					sign;
	int					index;
	int					empty;
	unsigned long long	n;
}	t_strtol_mt;

long long	mini_strtoll(const char *nptr, int radix);

#endif
