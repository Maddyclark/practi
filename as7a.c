#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>

int main()
{
   int i=0;
   int fd,fd1;
   
     char *myfifo="myfifo";
     char *myfifo1="myfifo1";
     char buf[512];
     char temp;
     
     mkfifo(myfifo,0777);
     mkfifo(myfifo1,0777);
     fd=open(myfifo,O_WRONLY);
     printf("Enter your message in type * to terminate\n");
     while(1)
     {
       scanf("%c",& temp);
       if(temp!='*')
       {
         buf[i]=temp;
         i++;
       }
       else
        break;
     }
     write(fd,buf,sizeof(buf));
     printf("DAta written by the writer :\n");
     sleep(2);
     close(fd);
     unlink(myfifo);
       fd1=open(myfifo1,O_RDONLY);
       read(fd1,buf,sizeof(buf));
       
       printf("Data recieved by fifo2 by writer...\n");
       printf("%s",buf);
       close(fd1);
       unlink(myfifo1);
       return 0;
       
}       
      
       
