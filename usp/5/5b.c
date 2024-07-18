//Normal

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
 void sh( int sn )
 {
  printf("caught\n");
  struct sigaction st;
  st.sa_handler=SIG_DFL;
  sigaction(SIGINT,&st,NULL);

 }
 int main()
 {
    struct sigaction st;
    st.sa_handler=sh;
    sigaction(SIGINT,&st,NULL);
    while(1)
    {
      printf("hello\n");
      sleep(1);
    }
    return 0;
 }
