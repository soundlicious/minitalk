/*
** server.h for minitalk in /home/exposi_p/rendu/PSU_2013_minitalk
**
** Made by exposi_p
** Login   <exposi_p@epitech.net>
**
** Started on  Mon Mar 17 15:12:38 2014 exposi_p
** Last update Sat Mar 22 17:30:05 2014 exposi_p
*/

#ifndef SERVER_H_
#define SERVER_H_

typedef	struct	s_serv
{
  int		c_pid;
  int		sig;
}		t_serv;

void	*xmalloc(int size);
int	my_putchar(char c);
int	my_putstr(char *str);
int	my_put_nbr(int	nb);
void	server_pid(void);
void	fill_char(int signal);
void	fill_int(int signal);
int	my_put_nbr(int nb);

#endif /* SERVER_H_ ! */
