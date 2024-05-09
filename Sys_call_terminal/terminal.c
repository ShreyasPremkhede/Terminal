#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<readline/readline.h>
#include<readline/history.h>
#include<errno.h>
void help(){
	system("bash -c help");
}
int main(){
	while(1){
	char *username=getlogin();
	if(username==NULL){
		printf("Error getting username\n");
		exit(0);
	}
        char host[100];
	if(gethostname(host,100)!=0){
		printf("Error getting hostname\n");
		exit(0);
	}
	char currdir[100];
	if(getcwd(currdir,100)==NULL){
		printf("Error getting current directory\n");
		exit(0);
	}
	char *start=strcat(username,"@");
	start=strcat(start,host);
	start=strcat(start,":");
	start=strcat(start,currdir);
	start=strcat(start,"$ ");
       char *cmd;
      cmd=readline(start);
      char cmbuf[100];
               strcpy(cmbuf,cmd);
               char *argv[4];
               argv[0]=strtok(cmbuf," ");
               argv[1]=strtok(NULL," ");
               argv[2]=strtok(NULL," ");

      if(strlen(cmd)>0){add_history(cmd);}
      if(argv[0]==NULL)continue;
       if(system(NULL)!=0){
               if(strcmp(argv[0],"exit")==0)break;
               else if(strcmp(argv[0],"help")==0)help();
               else if(strcmp(argv[0],"cd")==0){
                       char dir[100];
                       if(argv[1]==NULL)
                               chdir(getenv("HOME"));
                       else{
                       int i=3,j=1;
                       dir[0]='/';
                       while(cmd[i]!='\0'){
                               dir[j]=cmd[i];
                               i++;j++;
                       }
                       dir[j]='\0';
                       strcat(currdir,dir);
                       if(chdir(currdir)!=0)printf("error in changing directory: %i\n",errno);
               }}

	       else{
        	system(cmd);
	       }
       }
       else{
	       printf("Error getting the shell!!\n");
	       continue;
       }

}}
