/*
** main.c for minitalk in /home/exposi_p/rendu/PSU_2013_minitalk
**
** Made by exposi_p
** Login   <exposi_p@epitech.net>
**
** Started on  Mon Mar 17 15:11:15 2014 exposi_p
** Last update Sun Mar 23 14:42:23 2014 exposi_p
*/

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "../../inc/server/server.h"

int	c_pid = -1;

void server_pid(void)
{
  my_putstr("Server PID : ");
  my_put_nbr(getpid());
  my_putchar('\n');
}

void fill_char(int signal)
{
  static char	cs = 0;
  static int	bit = 0;

  if (signal == SIGUSR1)
    cs = (cs << 1) + 0;
  else
    cs = (cs << 1) + 1;
  bit++;
  if (bit == 8)
    {
      my_putchar(cs);
      bit = 0;
      if (cs == '\0')
	{
	  usleep(90);
	  if (kill(c_pid, SIGUSR2) == -1)
	    exit(-1);
	  c_pid = -1;
	  my_putchar('\n');
	}
      else
	if (kill(c_pid, SIGUSR1) == -1)
	  return (SIG_ERR);
    }
  else
    if (kill(c_pid, SIGUSR1) == -1)
      return (SIG_ERR);
}

void	fill_int(int signal)
{
  static int	i = 0;
  static int	bit = 0;

  if (signal == SIGUSR1)
    i = (i << 1) + 0;
  else
    i = (i << 1) + 1;
  bit++;
  if (bit == 32)
    {
      c_pid = i;
      bit = 0;
      my_putstr("Connected with : ");
      my_put_nbr(c_pid);
      my_putchar('\n');
      usleep(1000);
      if (kill(c_pid, SIGUSR1) == -1)
	{
	  write(2, "Error : Connection Lost\n", 24);
	  exit (-1);
	}
    }
}

static void	get_sig(int signal)
{
  if (c_pid == -1)
    fill_int(signal);
  else
    fill_char(signal);
}

int	main(void)
{
  server_pid();
  if (signal(SIGUSR1, get_sig) == SIG_ERR)
    return (-1);
  if (signal(SIGUSR2, get_sig) == SIG_ERR)
    return(-1);
  while (!(NULL));
  return (0);
}
