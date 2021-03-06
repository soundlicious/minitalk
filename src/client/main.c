/*
** main.c for minitalk in /home/exposi_p/rendu/PSU_2013_minitalk
**
** Made by exposi_p
** Login   <exposi_p@epitech.net>
**
** Started on  Mon Mar 17 18:00:32 2014 exposi_p
** Last update Sun Mar 23 15:18:37 2014 exposi_p
*/

#include <signal.h>
#include <stdlib.h>
#include "../../inc/client/client.h"

t_client	*glob;

static void	nope(void)
{
  exit (-1);
}

char	*dec2bin(int pid, int n)
{
  char	*str;

  str = malloc((n + 1) * sizeof(char));
  str[n] = 0;
  n--;
  while (pid >= 2)
    {
      str[n] = pid % 2 + '0';
      pid = pid / 2;
      n--;
    }
  str[n--] = pid % 2 + '0';
  while (n >= 0)
    str[n--] = '0';
  return (str);
}

static int display_client_pid(int pid)
{
  my_putstr("Client PID : ");
  my_put_nbr(pid);
  my_putchar('\n');
  return (0);
}


static int		my_signal2(char c, int pid)
{
  char			*my_char;
  static int		n = 0;

  my_char = dec2bin(c , 8);
  if (my_char[n] == '0')
    {
      if (kill(pid, SIGUSR1) == -1)
	return (-1);
    }
  else
    if (kill(pid, SIGUSR2) == -1)
      return (-1);
  n++;
  if (n == 8)
    {
      n = 0;
      if (c != 0)
	glob->n++;
    }
  free(my_char);
  return (0);
}

void	send_char(int signal)
{
  if (signal == SIGUSR1)
    {
      if (glob->msn[glob->n])
	{
	  if (my_signal2(glob->msn[glob->n], glob->s_pid) != 0)
	    exit (-1);
	}
      else
	if (my_signal2('\0', glob->s_pid) != 0)
	  exit (-1);
    }/*
  return (0);*/
}

int	send_pid(int pid)
{
  char		*my_pid;
  int		n;
  int		c_pid;

  n = 0;
  c_pid = getpid();
  display_client_pid(c_pid);
  my_pid = dec2bin(c_pid, 32);
  while (my_pid[n])
    {
      if (my_pid[n] == '0')
	{
	  if (kill(pid, SIGUSR1) == -1)
	    return (-1);
	}
      else
	if (kill(pid, SIGUSR2) == -1)
	  return (-1);
      n++;
      usleep(1000);
    }
  free(my_pid);
  return (0);
}

void	my_exit(int signal)
{
  exit (0);
}

t_client	*init_client(int pid, char *str, t_client *ptr)
{
  ptr->msn = str;
  ptr->s_pid = pid;
  ptr->n = 0;
}

void		init_mess(int ac, char **av)
{
  int	pid;

  if (check_arg(ac, av) != 0)
    exit (-1);
  if (check_pid(av[1]) != 0)
    exit (-1);
  pid = my_getnbr(av[1]);
  if (send_pid(pid) != 0)
    {
      write(2, "Error : Sending Pid\n", 20);
      exit (-1);
    }
}

int		main(int ac, char **av)
{
  int		pid;
  t_client	ptr;

  init_mess(ac, av);
  pid = my_getnbr(av[1]);
  init_client(pid, av[2], &ptr);
  glob = &ptr;
  if (signal(SIGUSR1, send_char) == SIG_ERR)
    return (-1);
  if (signal(SIGUSR2, my_exit) == SIG_ERR)
    return (-1);
  while (!(NULL));
  return (0);
}
