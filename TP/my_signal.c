#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void catch_sighup(int signal)
{
  printf("signal : %d\n", signal);
  printf("prosper youpla boum! c'est le roid u pain dépice!\n");
}
int	main(void)
{
  printf("pid : %d\n", getpid());
  while (1)
    signal(SIGHUP, catch_sighup);
  return (0);
}
