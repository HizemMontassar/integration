#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "coach.h"
#include <gtk/gtk.h>

void ajouter(char id[] ,char nom[], char prenom[],int jour,int mois,int annee)
{	
	
	char r_nom[30];char r_prenom[30];char r_id[30];int r_jour;int r_mois;int r_annee;
	FILE *f;
	
	f=fopen("/home/hizem/Desktop/MyGym/src/client","a+");
	if (f!=NULL)
	{
	while (fscanf(f,"%s %s %s %d %d %d\n",r_id,r_nom,r_prenom,&r_jour,&r_mois,&r_annee) != EOF)
	
	
	fprintf(f,"%s %s %s %d %d %d\n",id,nom,prenom,jour,mois,annee);
	fclose(f);
	}
	else printf("impossssible d'ouvrir\n");

}
void supprimer(char id[],char nom[],char prenom[],int jour,int mois,int annee)
{

	char id1[30];char nom1[30];char prenom1[30];int jour1;int mois1;int annee1;
	FILE *f1;
	FILE *f2;
	

	f1=fopen("/home/hizem/Desktop/MyGym/src/client","r");
	f2=fopen("/home/hizem/Desktop/MyGym/src/client_temp","a");
	

	if ( (f1!=NULL) || (f2!=NULL) )
	{
	
	while (fscanf(f1,"%s %s %s %d %d %d\n",id1,nom1,prenom1,&jour1,&mois1,&annee1) != EOF)
	{
		if (strcmp(id,id1)!=0)
		{
			fprintf(f2,"%s %s %s %d %d %d\n",id1,nom1,prenom1,jour1,mois1,annee1);
			
	
		}
		
	}
	}
	fclose(f1);
	fclose(f2);
	remove("/home/hizem/Desktop/MyGym/src/client");
	rename("/home/hizem/Desktop/MyGym/src/client_temp","/home/hizem/Desktop/MyGym/src/client");
}


void modification(char id[] ,char nom[], char prenom[],int jour,int mois,int annee)
{
	char id1[30];char nom1[30];char prenom1[30];int jour1;int mois1;int annee1;
		
		
	
	FILE *f1;
	FILE *f2;
	
	f1=fopen("/home/hizem/Desktop/MyGym/src/client","r");
	f2=fopen("/home/hizem/Desktop/MyGym/src/client_temp","a");

	if ( (f1!=NULL) || (f2!=NULL) )
	{
	
	while (fscanf(f1,"%s %s %s %d %d %d\n",id1,nom1,prenom1,&jour1,&mois1,&annee1) != EOF)
	{

		if(strcmp(id,id1)==0)
		{
			fprintf(f2,"%s %s %s %d %d %d\n",id,nom,prenom,jour,mois,annee);
			
		}
		else
		{
			fprintf(f2,"%s %s %s %d %d %d\n",id1,nom1,prenom1,jour1,mois1,annee1);
			
		}
	}
	fclose(f1);
  	fclose(f2);
	}
	else printf("impossssible d'ouvrir\n");
	
  	remove("/home/hizem/Desktop/MyGym/src/client");
  	rename("/home/hizem/Desktop/MyGym/src/client_temp","/home/hizem/Desktop/MyGym/src/client");
}
