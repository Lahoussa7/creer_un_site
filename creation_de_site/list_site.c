#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char**recupsitesavailable(){
	
	FILE*enab=NULL;
	enab=popen("ls /etc/apache2/sites-available > /home/misa/Documents/recuperation/site_ava.csv","w");
	pclose(enab);
	FILE*sites=NULL;
	int comp=0;
	sites=fopen("/home/misa/Documents/recuperation/site_ava.csv","r");
	char**site=malloc(sizeof(char*)*255);
	for(int i=0;i<255;i++) {
		site[i]=malloc(500);
	}
	
	if(sites!=NULL){
		while(feof(sites)!=1){
			fgets(site[comp],255,sites);
				comp++;
			
		}
	}	
	fclose(sites);
	
	return site;
}
int nombreline(){
	FILE*sites=NULL;
	
	sites=fopen("/home/misa/Documents/recuperation/site_ava.csv","r");
	char cara;
	int comp=0;
	if(sites!=NULL){
		while(feof(sites)!=1){
		cara=fgetc(sites);
		   if(cara =='\n'){
			comp++;
		   }
		}
	}
		
	fclose(sites);
	
	
	return comp;
}
int nombreline_enabled(){
	FILE*sites=NULL;
	
	sites=fopen("/home/misa/Documents/recuperation/site_enable.csv","r");
	char cara;
	int comp=0;
	if(sites!=NULL){
		while(feof(sites)!=1){
		cara=fgetc(sites);
		   if(cara =='\n'){
			comp++;
		   }
		}
	}
		
	fclose(sites);
	return comp;
}
void active_desactive(char*conf,char*save){
		char*ena=malloc(40);
		char*dis=malloc(400);
		char*apache=malloc(100);
	
	if(strcmp(save,"activate")==0){
		sprintf(ena," sudo a2ensite %s",conf);
	    popen(ena,"w");
	    printf("<head><meta http-equiv=\"refresh\"content=\"0;url=http://www.fock.com/cgi-bin/list.cgi\"></head>");
	 
	    sprintf(apache,"sudo systemctl reload apache2");
	    popen(apache,"w");
	 
	}  
	 if(strcmp(save,"desactivate")==0){
		
			sprintf(dis,"sudo a2dissite %s",conf);
			popen(dis,"w");
			printf("<head><meta http-equiv=\"refresh\"content=\"0;url=http://www.fock.com/cgi-bin/list.cgi\"></head>");	

			sprintf(apache,"sudo systemctl reload apache2");
			popen(apache,"w");
	}
}
char**recupsiteenabled(){
	
	FILE*enab=NULL;
	enab=popen("ls /etc/apache2/sites-enabled > /home/misa/Documents/recuperation/site_enable.csv","w");
	pclose(enab);
	FILE*sites=NULL;
	sites=fopen("/home/misa/Documents/recuperation/site_enable.csv","r");
	char**enable=malloc(sizeof(char*)*255);
	for(int i=0;i<255;i++) {
		enable[i]=malloc(500);
	}
	int comp=0;
	if(sites!=NULL){
		while(feof(sites)!=1){
			fgets(enable[comp],255,sites);	
				comp++;
	    }
	}
	fclose(sites);

	return enable;
}

int premierjan(int y){
	float k=4.0;
	float b=400.0;
	float t=100.0;
	float u=36+(y-1);
	float r=7.0;
	float l=((y-1)/k);float lu=((y-1)/(t));float la=((y-1)/b);
	float s=((u+l)-(lu+la));
	int n=s-((s/r)*r);
	return n;
}
int jourdumois(int m,int y){
	int jour=0;
	if((m%2==1 && m<=7 && m!=2) || (m%2==0 && m>7)){
		jour=31;
	}
	 else if((m%2==0 && m<7) || (m%2==1 && m>7)){
		 jour=30;
	 }
     if(m==2){
		 if(y%4==0 && y%100!=0){
			 jour=29;
		 }
		 else{
			 jour=28;
		 }
	 }
	return jour;
}

char*jourjan(int n,char**jour){
	char*car=malloc(120);
	
	  strcpy(car,jour[n]);
	
   return car;	
}
int nombremois(char*m){
    char**cal=malloc((sizeof(char*)*13));
	
		for(int i=0;i<13;i++){
			cal[i]=(char*)malloc(100);}
	
			strcpy(cal[1],"Janoary");
			strcpy(cal[2],"Febroary");strcpy(cal[12],"Desambra");
			strcpy(cal[3],"Martsa");strcpy(cal[11],"Novambra");
			strcpy(cal[4],"Aprily");strcpy(cal[10],"Octobra");
			strcpy(cal[5],"May");strcpy(cal[9],"Septembra");
			strcpy(cal[6],"June");strcpy(cal[7],"July");strcpy(cal[8],"August");

	    int n=1;
		for(int i=1;i<13;i++){
			if(strstr(cal[i],m)!=NULL){
			n=i;
		    }
        }
			//printf(" %s\n",car[n]);
		 
		 return n;
}

int jour1dumois(int n,int mois,int*d,int y){
	int new=0;
	
	new=(31+n)%7;
	for(int i=0,j=0;i<12;i++,j++){
		
		if(i==(mois-1)){
		    if(i==0){
	           new =n;
            }
	        if(i==1){
	           new =(28+(n+31)%7)%7;
          
            }  
	        if (i==2){
	            new=(31+(28+n)%7)%7;
	     
            }  
   
	        if(i==3){
	           new =(30+(31+(28+n)%7)%7)%7;

            }
	        if(i==4){
		
              new =(31+(30+(31+(28+n)%7)%7)%7)%7;
     
            }
	       if(i==5){
              new =(30+(31+(30+(31+(28+n)%7)%7)%7)%7)%7;
           }
	       if(i==6){
	          new =(31+(30+(31+(30+(31+(28+n)%7)%7)%7)%7)%7)%7;
           }
	       if(i==7){
              new =(31+(31+(30+(31+(30+(31+(28+n)%7)%7)%7)%7)%7)%7)%7;
           }
	       if(i==8){
	          new =(30+(31+(31+(30+(31+(30+(31+(28+n)%7)%7)%7)%7)%7)%7)%7)%7;
           }
	       if(i==9){
	          new=(31+(30+(31+(31+(30+(31+(30+(31+(28+n)%7)%7)%7)%7)%7)%7)%7)%7)%7;
           }
	       if(i==10){
	          new =(30+(31+(30+(31+(31+(30+(31+(30+(31+(28+n)%7)%7)%7)%7)%7)%7)%7)%7)%7)%7;
           }
	       if(i==11){
	          new=(31+(30+(31+(30+(31+(31+(30+(31+(30+(31+(28+n)%7)%7)%7)%7)%7)%7)%7)%7)%7)%7)%7;
	
           }
           if(d[i]==30){
	          new= (new+1)%7;	
		
	       }
      }
 	
	}
    
return new;	
}
char*jourtoday(int jo,char ca[7][200],int n,int u){
	char*car=malloc(123);
	int l=0;
	for(int i=n,j=1;i<u+n;i++,j++){
		 
			  if(j==jo){
		      if(i>=7){
			  
			   l=i%7;
			       strcpy(car,ca[l]);
		      }
		      else{
				  strcpy(car,ca[i]);
	          }
	  
         }
	}
	return car;
}
int main(){
	char*recup=getenv("QUERY_STRING");
		
	printf("Content-type: text/html\n\n");
	
	printf("<html lang=\"fr\"><head><meta charset=UTF-8><title>Liste-site</title>");
	  printf("<style>");
	    printf(".decor{width:30vw;height:5vw;border-radius:30vw;color:rgb(253, 142, 68);background-color:rgb(87, 7, 23);text-align:center;font-size:2vw;}");
	    printf(".boite{width:90vw;height:8vw;border-radius:40vw;color:pink;background-color:floralwhite;text-align:center;font-size:3.4vw;display:flex;justify-content:space around;}");
		printf(".decor2{padding-left:12vw;}");
		printf(".decor1{padding-left:4vw;}");
		printf(".decor3{padding-left:16vw;}");
		printf("button:hover{ background-color:floralwhite;width:30vw;height:5vw;border-radius:30vw}");
		printf("button{background-color:rgb(87, 7, 23);font-size:2vw;color:rgb(253, 142, 68);width:30vw;height:5vw;border-radius:30vw;border:none;}");
	  printf("</style></head>");	
	
	printf("<body width=70%% style=\"background-color:rgba(237, 241, 185, 0.966);\"> ");
		char*save=malloc(200);int nbrli;
		int nbr;
		char*sername=malloc(200);
		char*config=malloc(sizeof(char)*255);
		char*acti=malloc(100);
		char**site=malloc(sizeof(char*)*255);
			for(int i=0;i<255;i++) {
				site[i]=malloc(500);
			}
		char**enab=malloc(sizeof(char*)*255);
			for(int i=0;i<255;i++) {
				enab[i]=malloc(500);
			}
		char**dis=malloc(sizeof(char*)*255);
			for(int i=0;i<255;i++) {
				dis[i]=malloc(500);
			}
		
	sscanf(recup,"%[^=]=%[^\n]\n",sername,save);
	if(*sername!='\0'){
		 active_desactive(sername,save);
		 strcpy(acti,strtok(sername,"."));
	 }
	nbr=nombreline_enabled();
	nbrli=nombreline();
	site=recupsitesavailable();
	enab=recupsiteenabled();
	
	printf("<div class=\"decor1\"><table >");
	printf("<h1 style=\"font-family:cursive;font-size:3vw;color:red;padding-left:8vw;\">LIST OF SITE THAT YOU CAN ENABLE OR DISABLE</h1><br>");
	//printf("<tr ><div class=\"boite\"><th>SITE </th><th>HIS STATUS</th><th>ENABLED or DISABLED</th></div></tr>");
	printf("<div class=\"boite\"><div class=\"decor2\">SITE </div><div class=\"decor3\">HIS STATUS</div><div class=\"decor2\">ENABLED or DISABLED</div></div></tr>");
	
	for(int i=0;i<nbrli;i++){
		for(int j=0;j<nbr;j++){
            
			if(strcmp(site[i],enab[j])==0){
				strcpy(dis[i],"activate");
				break;
			}
			else if(strstr(site[i],enab[j])==NULL){
				strcpy(dis[i],"desactivate");
			}		
		} 
			if(strstr(dis[i],"activate")!=NULL){
				strcpy(config,"desactivate");
			}
			if(strstr(dis[i],"desactivate")!=NULL){
				strcpy(config,"activate");
			}	
		 printf("<tr><td class=\"decor\">%s</td><td class=\"decor\">%s</td><td class=\"decor\"><a href='http://www.fock.com/cgi-bin/list.cgi?%s=%s'><button>%s</button></a></td>",site[i],dis[i],site[i],config,config);
	 	}
	 printf("</table></div>");
	printf("</body>");
	printf("</html>");
		
	return 0;
}

