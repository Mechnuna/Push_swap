/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a79856 <a79856@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:12:05 by a79856            #+#    #+#             */
/*   Updated: 2021/10/18 03:17:41 by a79856           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define  LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include "get_next_line.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

size_t	ft_strlen(const char *str);
//проверить на CHECK_PTR_DEF(ptr, def) if (!(ptr)) return (def);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
// оставила там мейник (upd)Вроде работает корректно
size_t	ft_strlcat(char *dst, const char *src, size_t size);
//оставила мейник и тоже вообще не уверена (upd)
char	*ft_strchr(const char *str, int ch);
void	*ft_memset(void *destination, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *destination, const void *source, size_t n);
//не знаю какое решение лучше
void	*ft_memccpy(void *destination, const void *source, int c, size_t n);
//проверить после обновления
void	*ft_memmove(void *destination, const void *source, size_t n);
void	*ft_memchr(const void *arr, int c, size_t n);
int		ft_memcmp(const void *arr1, const void *arr2, size_t n);
char	*ft_strrchr(const char *str, int ch);
//все очень сложно (upd)
char	*ft_strnstr(const char	*big, const char *little, size_t len);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
void	*ft_calloc(size_t num, size_t size);
int		ft_isprint(int ch);
int		ft_isascii(int ch);
int		ft_isalpha(int c);
int		ft_toupper(int ch);
int		ft_tolower(int ch);
int		ft_isalnum(int c);
int		ft_isdigit(int c);
char	*ft_strdup(const char *str);
//проверить нужно ли на отрицательное значение делать и удалить мейник
char	*ft_substr(char const *s, unsigned int start, size_t len);
//вроде как да,но очень коряво
char	*ft_itoa(int n);
//проверить кое-что на счет is!(str1)
char	*ft_strjoin(char const *s1, char const *s2);
//попозже
char	*ft_strtrim(char const *s1, char const *set);
//доделать
char	**ft_split(char const *s, char c);
//выводы
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
//оставила закоммиченный второй вариант
void	ft_lstclear(t_list **lst, void (*del)(void*));
//надо проверить можно ли так
void	ft_lstiter(t_list *lst, void (*f)(void *));
//суупер не уверена
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *));
int		ft_atoi(const char *str);
int		get_next_line(int fd, char **line);
int		ft_strcmp(const char *s1, const char *s2);
t_list	*ft_lstpop_front(t_list **lst);
t_list	*ft_lstpop_back(t_list **lst);
void	**ft_lst_to_array(t_list *lst);
void	ft_lst_remove(t_list **begin_list, void *data_ref,
			int (*cmp)(), void (*free_fct)(void *));
t_list	*ft_lst_at(t_list *lst, size_t n);
char	*read_file(int fd, char *rem, char *buf);
char	*find_new_line(char *str);
void	ft_bubble_sort(int *array, int len);

#endif
