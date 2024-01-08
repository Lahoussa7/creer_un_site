#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void enabled_or_disabled(char*conf,char*ser);
char* withoutHex(char* tab);
int chartoint(char*ca);
char*placepourcent(char*t);
int*tableau2(char*ca);
int*tableau1(char*ca);
char* placedepoint(char*name);
char**configure();
char*valeur_action();
char*traite_name(char*name);
void create_directory(char*directory);
void write_in_host(char*name);
int main (){

		char*recup=getenv("QUERY_STRING");
		
	printf("Content-type: text/html\n\n");
	
	printf("<html lang=\"fr\"><head><meta charset=UTF-8><title>Configuration d'apache</title><link rel=\"stylesheet\" href=\"http://www.fock.com/decor.css\"></head>");
	printf("<body width=70%% style=\"text-decoration:none;\"> ");
		
		char*recup1=malloc(200);
	
		char*name=malloc(50);      
		char*nam=malloc(50);      
		char*webmaster=malloc(50);
		char*webmaster1=malloc(50);
		char*docRoot=malloc(100);
		char*docRoot1=malloc(100);
		char*option=malloc(50);
		char*option1=malloc(50);
		char*req=malloc(50);
		char*req1=malloc(100);
		char*override=malloc(50);
		char*override1=malloc(100);
		char*add=malloc(50);
		char*add0=malloc(50);
		char*add1=malloc(50);
		char*add2=malloc(50);
		char*conf=malloc(50);
		char*virtual=malloc(100);
		char*virtual1=malloc(100);
		char*op=malloc(200);
		char*dir=malloc(200);
		char*dir1=malloc(200);
		char*err=malloc(500);
		char*err1=malloc(500);
		char*direct=malloc(200);
		char*cmd=malloc(100);
		char*sername=malloc(40);
		char*ser=malloc(40);
		char**name1=malloc(sizeof(char)*50);
		for(int i=0;i<50;i++){
			name1[i]=malloc(40);
		}
		 strcpy(recup1,withoutHex(recup));
		 sscanf(recup1,"%*[^=]=%[^&]&%*[^=]=%[^&]&%*[^=]=%[^&]&%*[^=]=%[^&]&%*[^=]=%[^&]&%*[^=]=%[^&]&%*[^=]=%[^&]&%*[^=]=%[^&]&%*[^=]=%[^&]&",name,webmaster,docRoot,option,option1,add,add1,req,override);
	     strcpy(nam,traite_name(name));
		//~ if(strstr(recup1,"vari1")!=NULL){
        //~ sscanf(recup1,"%*[^=]=%[^&]&%*[^=]=%[^&]&%*[^=]=%[^&]&%*[^=]=%[^&]&%*[^=]=%[^&]&%*[^=]=%[^&]&%*[^=]=%[^&]&%*[^=]=%[^&]&%*[^=]=%[^&]&",name,webmaster,docRoot,option,option1,add,add1,req,override);
	    //~ }
		//~ if(strstr(recup1,"enab")!=NULL){
        //~ sscanf(recup1,"%*[^=]=%[^&]&%*[^=]=%[^&]&%*[^=]=%[^&]&%*[^=]=%[^&]&%*[^=]=%[^&]&%*[^=]=%[^&]&%*[^=]=%[^&]&%*[^=]=%[^&]&%*[^=]=%[^&]&%*[^=]=%[^&]&",ser,webmaster,docRoot,option,option1,add,add1,add2,req,override);
	    //~ }
		strcpy(conf,placedepoint(nam));
		//strcpy(conf,"sasa");
		FILE*file=NULL;
		file=fopen("/home/misa/Documents/recuperation/valeur.txt","w+");
		fprintf(file,"%s\n",conf);
		fclose(file);
		//name1=configure();
		//printf("<h2>ser=%s et conf=%s</h2>",ser,conf);
		sprintf(sername,"ServerName www.%s",nam);
		sprintf(webmaster1,"ServerAdmin %s",webmaster);
		sprintf(docRoot1,"DocumentRoot %s",docRoot);
		create_directory(docRoot);
		sprintf(err,"ErrorLog ${APACHE_LOG_DIR}/error.www.%s.log",nam);
		
		sprintf(err1,"CustomLog /var/log/apache2/access.%s.log combined",nam);
		
		strcpy(dir,"<Directory ");
		strcpy(dir1,"</Directory>");
		strcat (dir,docRoot);
		strcat(dir,">");
		
		sprintf(op,"Options %s %s %s",option,option1,add);

		strcpy(req1,"AllowOverride ");
		strcat(req1,req);
		strcpy(override1,"Require ");
		strcat(override1,override);
		//printf("<h1>%s</h1>",override1);
		strcpy(virtual,"<VirtualHost *:80>");
		strcpy(virtual1,"</VirtualHost>");
		
		sprintf(add0,"AddHandler %s %s",add1,add2);
		
	    strcpy(direct,"/home/misa/Documents/recuperation/");
		strcat(direct,conf);
		strcat(direct,".conf");
		FILE*ficonf=NULL;
		ficonf=fopen(direct,"w");
	    fprintf(ficonf,"%s\n\t%s\n\n\t%s\n\t%s\n\n\t%s\n\t%s\n\n\t%s\n\t\t%s\n\t\t%s\n\t\t%s\n\t\t%s\n\t%s\n%s",virtual,sername,webmaster1,docRoot1,err,err1,dir,op,req1,override1,add0,dir1,virtual1);
		//strcpy(cmd,"cp");
		//strcpy(direction,"/etc/apache2/sites-available/");
		
		strcpy(ser,valeur_action());
		enabled_or_disabled(conf,ser);
		//create_directory(docRoot);
	
		
    //printf("<p>%s<br>%s<br>%s<br>%s<br>%s<br>%s<br>%s<br>%s<br>%s<br>%s<br>%s<br></p>",name,webmaster,docRoot,option,option1,add,add1,add2,req,override,conf);
			
    printf("</body>");
    printf("</html>");
	
	
	fclose(ficonf); 
	write_in_host(name);
	sprintf(cmd,"cp %s /etc/apache2/sites-available/",direct); 
	system(cmd); 
    free(name);free(webmaster);free(webmaster1);free(docRoot);free(docRoot1);free(option);free(op);free(option1);
	free(req);free(req1);free(override);free(override1);free(add);free(add1);free(add2);free(conf);
	free(virtual);free(virtual1);free(dir);free(dir1);
	free(err);free(err1);free(direct);free(cmd);free(sername);
	return 0;
}
void write_in_host(char*name){
	FILE*host=NULL;
	host=fopen("/etc/hosts","a+");

	if(host!=NULL){
			char*ip=malloc(50);
			sprintf(ip,"127.0.0.1	%s",name);
			fprintf(host,"%s\n",ip);
	}
	else{
		printf("une erreur s'est produite");
	}
	fclose(host);
}
void create_directory(char*directory){
	char* allow = malloc(100);
	char*credir=malloc(200);
	char*index=malloc(200);
	if(strstr(directory,"/home/misa/")==NULL){
		sprintf(credir,"sudo mkdir -p /home/misa/%s",directory);
	
	}
	
	if(strstr(directory,"/home/misa/")!=NULL){
		sprintf(credir,"sudo mkdir -p %s",directory);
	}
	sprintf(allow, "sudo chown www-data %s",directory);
	
	system(credir);
	if(strstr(directory,"/home/misa/")==NULL){
	
	sprintf(index,"sudo cp /home/misa/Documents/recuperation/indexe.css /home/misa/Documents/recuperation/index.html /home/misa/%s/",directory);
    }
	if(strstr(directory,"/home/misa/")!=NULL){
	
	sprintf(index,"sudo cp /home/misa/Documents/recuperation/indexe.css /home/misa/Documents/recuperation/index.html %s/",directory);
    }
    //sprintf(index,"sudo cp /home/misa/Documents/recuperation/indexe.css /home/misa/Documents/recuperation/index.html %s/",directory);
   
	system(index);
	//~ printf("index = %d	créer dosssier = %d",ind, creer);
	//~ printf("<h2>%s</h2><br>",credir);
	//~ printf("<h2>%s</h2><br>",index);
}

char* placedepoint(char*name){
	
	int point=0;
	char*conf=malloc(50);
	for(int i=0;i<strlen(name);i++){
		if(name[i]=='.'){
			point=i;
			
		}
	}
	for(int i=0;i<point;i++){
		
			conf[i]=name[i];

	}
	return conf;
}
//~ void configurationapache(){
	//~ char*recup=getenv("QUERY_STRING");
	
	
	
	
//~ }
char*valeur_action(){
	char*save=malloc(100);
	
	FILE*fic=NULL;
	fic=fopen("/home/misa/Documents/recuperation/action.txt","r");
	
	fgets(save,199,fic);
	fclose(fic);
	//printf("<h1>%s</h1>\n",save);
	return save;
}
char*traite_name(char*name){
		char*nom=malloc(50);
	if(strstr(name,"www.")!=NULL){
		for(int i=4,j=0;i<strlen(name);i++,j++){
		nom[j]=name[i];
		//printf("%c",nom[j]);
		}

	}
	if(strstr(name,"www.")==NULL){
		for(int i=0;i<strlen(name);i++){
		nom[i]=name[i];
		}
	}
	//printf("%s",nom);
	return nom;
}

void enabled_or_disabled(char*conf,char*en){
	printf("<div style=\"background-color:rgb(46, 1, 38);width:80vw;height:30vw; margin: 2vw 5vw 2vw 10vw;\">");
	printf("<div style=\" font-size: 2.5vw; background:-moz-linear-gradient(to right,bisque,brown,gray,darkred);-webkit-background-clip: text;background-clip:text; color:transparent;text-align:center;\"><h3>VOTRE SITE A BIEN ÉTÉ CRÉER MAIS VOULEZ VOUS L'ACTIVER OU LE DESACTIVER</h3></div>");
	//char*en=malloc(40);
	char*ena=malloc(40);
	//sscanf(enable,"enab=%s",en);
	//printf("<h1> ici l'action %s</h1>",en);
	char*dis=malloc(400);
	printf("<div style=\"display:flex;justify-content:space-around;\">");
	printf("<a href=\"http://www.fock.com/cgi-bin/recup.cgi?enab=active\"><div style=\"width: max-content; height: 3vw; background-color:rgb(216, 241, 233); display: flex;  align-items: center; justify-content: center;  text-decoration: none; padding: 2vw 3vw 2vw 3vw; color: rgb(0, 15, 4); font-size: 3vw;\">Activate</div></a>");
	printf("<a href=\"http://www.fock.com/cgi-bin/recup.cgi?enab=desactive\"><div style=\"width: max-content; height: 3vw; background-color:rgb(216, 241, 233); display: flex;  align-items: center; justify-content: center;  text-decoration: none; padding: 2vw 3vw 2vw 3vw; color: rgb(0, 15, 4); font-size: 3vw;\" > Desactivate</div></a>");
	printf("</div>");
	printf("</div>");
	
}
int chartoint(char*ca){
	int n=0;
	int k=16;
	int*tab=malloc(sizeof(int)*2);
	int*tab1=malloc(sizeof(int)*2);
	
	tab=tableau2(ca);
	tab1=tableau1(ca);
	
	for(int i=0;i<strlen(ca);i++){
		if((ca[i]>='0'&& ca[i]<='9')||(ca[i]>='A' && ca[i]<='F')){
			if((ca[i]>='0'&& ca[i]<='9')){
		    n+=((ca[i]-'0')*pow(k,strlen(ca)-1-tab[i]));
	        }
	        if((ca[i]>='A' && ca[i]<='F')){
		     n+=((ca[i]-'A'+10)* pow(k,strlen(ca)-1-tab1[i]));
		    
		    }
	   }
	  }
	     
    
	return n;
}
char* withoutHex(char* tab){
    char* new = malloc(strlen(tab) + 1);
    int i = 0, j = 0;
    char hex[3];
    char car;

    while (tab[i] != '\0') {
        if (tab[i] == '%' && tab[i + 1] != '\0' && tab[i + 2] != '\0') {
            hex[0] = tab[i + 1];
            hex[1] = tab[i + 2];
            hex[2] = '\0';

            car=chartoint(hex);

            if (car != -1) {
                new[j] = car;
                i += 3;
            } else {
                new[j] = tab[i];
                i++;
            }
        } else if (tab[i] == '+') {
            new[j] = ' ';
            i++;
        } else {
            new[j] = tab[i];
            i++;
        }
        j++;
    }
    new[j] = '\0';

    return new;
}

int*tableau2(char*ca){
	int l=strlen(ca);
	int*tab=malloc(sizeof(int)*l);
	for(int i=0;i<strlen(ca);i++){
			if((ca[i]>='0'&& ca[i]<='9')){
				tab[i]=i;
			}
		}
	return tab;
}
int*tableau1(char*ca){
	int l=strlen(ca);
	int*tab1=malloc(sizeof(int)*l);
	for(int i=0;i<strlen(ca);i++){
			if((ca[i]>='A'&& ca[i]<='F')){
				tab1[i]=i;
			}
		}
	return tab1;
}

