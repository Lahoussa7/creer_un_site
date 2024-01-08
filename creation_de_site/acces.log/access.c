#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int nombreline();
int main(){
	printf("Content-type: text/html\n\n");
	
	printf("<html lang=\"fr\"><head><meta charset=UTF-8><title>Fichier access.log</title><style>th,td{ border-color:white;border:solid 0.3vw rgb(236, 153, 97);}</style></head>");printf("<body width=70%%> ");
	FILE*acces=NULL;
	acces=popen(" cat /var/log/apache2/access.log","r");
	
	//~ FILE*file=NULL;
	//~ file=fopen("/home/misa/Documents/recuperation/access.txt","r");
	char**log=malloc(sizeof(char*)*1050);
	for(int i=0;i<1050;i++){
	log[i]=malloc(700);	
	}
	char*date=malloc(500);char*ip=malloc(500);char*sername=malloc(500);char*action=malloc(500);char*horaire=malloc(500);
	int nbl= nombreline();
	int i=0;
	printf("<table  style=\"border-collapse:collapse;\"border=2%%>");
	printf("<tr style=\"background-color:lightgoldenrodyellow;;color:rgb(5, 31, 71);\"><th>IP-ADDRESS</th><th>DATE</th><th>TIME</th><th>ACTION</th><th>URL</th></tr>");
	
		while(feof(acces)!=1){
			if (i<=nbl){
		    fgets(log[i],1040,acces) ; 
		    
			sscanf(log[i],"%[^ ] %*[^[][%[^:]:%[^ ] %*[^ ] %*[^ ] %[^\"]\"%*[^\"]\"%[^\"]\"%*[^\n]\n",ip,date,horaire,action,sername);
		
		
		    printf(" <tr style=\"background:-moz-linear-gradient(to right,black,brown,rgb(46, 1, 38));color:transparent;font-size:1.5vw;color:white;text-align:center;\"><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td></tr>\n",ip,date,horaire,action,sername);
			
	    
		    i++;
		}
	}
	
	pclose(acces);
	
	printf("</table></body>");
	printf("</html>");
	return 0;
	
}
int nombreline(){
	//char *car =(char*)malloc(sizeof(char)*1000);
	FILE*file=NULL;
	file=popen("cat /var/log/apache2/access.log","r");
	
	if(file==NULL){
		printf("on n'a pas pu ouvrir le fichier\n");
	}
	int nbl=0;
	
	while(!feof(file)){
		char c = fgetc(file);
		if (c == '\n'){	
			nbl++;	
		}
	}
	
	//fclose(file);
	return nbl;
}
