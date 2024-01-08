		
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char*configure();

int main(){	
		
		char*recup=getenv("QUERY_STRING");
		
	printf("Content-type: text/html\n\n");
	
	printf("<html lang=\"fr\"><head><meta charset=UTF-8><title>Configuration d'apache</title></head>");printf("<body width=70%%> ");
		char*save=malloc(200);
	sscanf(recup,"enab=%s",save);
	printf("%s je suis la",save);
		//~ FILE*file=NULL;
		//~ file=fopen("/home/misa/Documents/recuperation/action.txt","w");
		//~ fprintf(file,"%s\n",save);
		//~ fclose(file);
	printf("<head><meta http-equiv=\"refresh\"content=\"5;url=http://www.fock.com/cgi-bin/list.cgi\"></head>");	
		char*conf=malloc(40);
		char*ena=malloc(40);
		char*dis=malloc(400);
		char*apache=malloc(100);
	
	//sscanf(saveable,"saveab=%s",save);
	printf("<h1> ici l'action %s</h1>",save);
		
		strcpy(conf,configure());
	if(strcmp(save,"active")==0){

		//strcpy(savea,save);
		sprintf(ena," sudo a2ensite %s",conf);
	    //system(savea);
	  
	    popen(ena,"w");
	    sprintf(apache,"sudo systemctl reload apache2");
	    popen(apache,"w");
	    printf("<h1>eto creer %s </h1>",ena);
	
	    
	}  
	
	 if(strcmp(save,"desactive")==0){
		
		sprintf(dis,"sudo a2dissite %s",conf);
		popen(dis,"w");
		sprintf(apache,"sudo systemctl reload apache2");
	    popen(apache,"w");
		//system(di);
		printf("<h1>eto no create %s </h1>",dis);
	
	
		
	}
	
	  printf("</body>");
      printf("</html>");
	
	
	return 0;
		
}
char*configure(){
		FILE*fic=NULL;
		fic=fopen("/home/misa/Documents/recuperation/valeur.txt","r");
		char*name1=malloc(sizeof(char)*50);
		
		int i=0;
		while(feof(fic)!=1){
			fgets(name1,49,fic);
			i++;
			 
		}
	printf("<p>%s</p>",name1);
	return name1;
}
