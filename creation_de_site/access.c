#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int nombreline(){
	char *car =(char*)malloc(sizeof(char)*1000);
	FILE*file;
	file=fopen("/var/log/apache2/access.log","r");
	
	if(file==NULL){
		printf("on n'a pas pu ouvrir le fichier\n");
	}
	int nbl=0;
	
	while(!feof(file)){
		fgets(car,1000,file);	
		nbl++;	
	}
	fclose(file);
	return nbl;
}
int main(){
	printf("Content-type: text/html\n\n");
	
	printf("<html lang=\"fr\"><head><meta charset=UTF-8><title>Access.log</title></head>");printf("<body width=100%%> ");
		
	FILE*enab=NULL;
	enab=popen("cat /var/log/apache2/access.log > /home/misa/Documents/recuperation/acces.txt","w");
	pclose(enab);
	FILE*sites=NULL;
	sites=fopen("/home/test/Documents/recuperation/acces.txt","r");
	char**enable=malloc(sizeof(char*)*1000);
	for(int i=0;i<1000;i++) {
		enable[i]=malloc(500);
	}
	char*ip=malloc(500);
	char*date=malloc(500);
	char*horaire=malloc(500);
	char*action=malloc(500);
	char*url=malloc(500);
	
	int comp=0;int i=0;
	i=nombreline();
	printf("<table>");
	printf("<tr><th>IP address</th><th>Date</th><th>Time</th><th>Url</th></tr>");
	if(sites!=NULL){
		while(feof(sites)!=1){
		fgets(enable[comp],255,sites);	
		if( comp<i){
		sscanf(enable[comp],"%[^ ] %*[^[][%[^:]:%[^ ] %*[^ ] %*[^ ] %*[^\"]\"%*[^\"]\"%[^\"]\"%*[^\n]\n",ip,date,action,url);
		//sscanf(enable[comp],"%[^ ] %*[^\n]\n",ip);
		printf(" <tr><td>%s</td><td>%s</td><td>%s</td><td>%s</td></tr>\n",ip,date,horaire,url);
			comp++;
			}
		}	
	}	
	printf("</table>");
	printf("</body>");
	printf("</html>");
	fclose(sites);

	
  return 0;	
}
