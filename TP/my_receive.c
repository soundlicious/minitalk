#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

void catch(int signal)
{
  printf("Signal : %d\n Signal recus.\n", signal);
}

int	main(void)
{
  printf("pid : %d", getpid());
  signal(SIGINT, catch);
  sleep(120);
  return (0);
}
