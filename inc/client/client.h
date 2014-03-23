/*
** client.h for minitalk in /home/exposi_p/rendu/PSU_2013_minitalk
**
** Made by exposi_p
** Login   <exposi_p@epitech.net>
**
** Started on  Mon Mar 17 18:01:44 2014 exposi_p
** Last update Sun Mar 23 11:36:16 2014 exposi_p
*/

#ifndef CLIENT_H_
# define CLIENT_H_

typedef struct	s_client
{
  char		*msn;
  int		s_pid;
  int		n;
}		t_client;

int	check_arg(int ac, char **av);
int	gentleman(int s_pid);
int	my_getnbr(char *str);
int	my_getnbrbase(char *str, char *base);
int	my_strlen(char *str);
char	*dec2bin(int pid, int n);
int	send_pid(int pid);
t_client	*init_client(int pid, char *str, t_client *ptr);
void	my_exit(int signal);
void	send_char(int sgnal);
void	init_mess(int ac, char **av);
#endif /* CLIENT_H_ ! */
