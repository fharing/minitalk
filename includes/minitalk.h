/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:39:15 by fharing           #+#    #+#             */
/*   Updated: 2021/08/24 16:35:19 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *str);
int		ft_isspace(char a);
int		ft_isdigit(int argument);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *str);

#endif
