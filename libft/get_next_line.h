/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a79856 <a79856@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:12:27 by a79856            #+#    #+#             */
/*   Updated: 2021/10/18 00:48:36 by a79856           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 1024
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include "libft.h"

char	*find_new_line(char *str);

#endif
