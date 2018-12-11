#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <gtk/gtk.h>
#include <support.h>

#include "kine.h"
#include "login.h"

//Creation de la liste à afficher
enum
{
        ID,
        COLUMNS
};

int kine_add_patient(int id){  //TODO corriger affichage + verfifier rôle + verfifier patient deja dans la liste
FILE *f;
int r =-1;
f = fopen("/home/haroun/Desktop/MyGym/src/data/kine_patients.dat","a");
if(check_id(id) == 0){
  r = 0;
  if (f!=NULL)
  {
    fprintf(f,"%d\n", id);
    fclose(f);
  }
  else
    printf("File kine_patients.dat not found !");
}
return r;
}


void kine_show_patients(GtkWidget *liste){
    GtkCellRenderer *renderer;
  	GtkTreeViewColumn *column;
  	GtkTreeIter    iter;
  	GtkListStore *store;

    char id[5];
    store=NULL;

    FILE *f;

  	store=gtk_tree_view_get_model(liste);
  	if (store==NULL)
  	{

      renderer = gtk_cell_renderer_text_new ();
  		column = gtk_tree_view_column_new_with_attributes("  ID  ", renderer, "text",ID, NULL);
  		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

  	}


  	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING);

  	f = fopen("/home/haroun/Desktop/MyGym/src/data/kine_patients.dat", "r");

  	if(f==NULL)
  	{

  		return;
  	}
  	else

  	{ f = fopen("/home/haroun/Desktop/MyGym/src/data/kine_patients.dat", "a+");
                while(fscanf(f,"%s\n",id)!=EOF)  //modifier
  		{
  	gtk_list_store_append (store, &iter);
  	gtk_list_store_set (store, &iter, ID, id, -1);
  		}
  		fclose(f);
  	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
      g_object_unref (store);
  	}
}

int isPatient(char idTest[]){
  FILE *f;
  int r ;
  char id[10];
  f = fopen("/home/haroun/Desktop/MyGym/src/data/kine_patients.dat","r");
    if (f!=NULL)
    {
      while((fscanf(f,"%s\n",id)!=EOF)&&(r!=1)){
        if(strcmp(idTest,id)==0)
          r = 1;
      }
      fclose(f);
    }
    else
      printf("File kine_patients.dat not found !");
      r = 0;
  // return r;
  return 1;
}
