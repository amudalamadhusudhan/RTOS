#include<stdio.h>
#include<signal.h>
void sig_usr1_handler(int signum)
{


printf("signal UST1 is triggered\n");

}
void sig_usr2_handler(int signum)
{


printf("signal UST2 is triggered\n");

}
int main(int argc, char const *argv[])
{
 signal(12,sig_usr2_handler);   
signal(10,sig_usr1_handler);
while(1)
{
printf("sleeping...\n");
sleep(1);

}
return 0;
}