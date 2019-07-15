#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
using namespace std;
int main(){

   //ftok to generate unique key
   //key_t key = ftok("shmfile", 65);
   /*char hostname[256];
   char *home = getenv("HOME");
   char *vncfolder = "/.vnc/";
   gethostname(hostname, sizeof(hostname));
   char *num_string = getenv("DISPLAY");
   char *posfix = ".pid";

   char *filename = (char*)malloc(strlen(posfix) + strlen(num_string)+strlen(hostname)+strlen(vncfolder)+strlen(home)+16); // +1 for the null-terminator
   strcpy(filename, home);
   strcat(filename, vncfolder);
   strcat(filename, hostname);
   strcat(filename, num_string);
   strcat(filename, posfix);
   printf("FileName: %s\n",filename);*/
   
   key_t key = ftok("/tmp/vgl/1", 65);
   //key_t key = ftok(filename, 65);
   //shmget returns an identifier in shmid
   int shmid = shmget(key, 1024, 0666|IPC_CREAT);

   //shmat to attach to shared memory
   char *str = (char*) shmat(shmid, (void*)0, 0);
   cout << "Write Data: ";
   gets(str);
   printf("Display:%s, key: %d,Data written in memory: %s\n",getenv("DISPLAY"), key, str);

   //detach from shared memory
   shmdt(str);
   return 0;
}
