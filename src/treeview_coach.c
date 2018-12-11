#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "treeview_coach.h"




enum
{
	ID,
	NOM,
	PRENOM,
	JOUR,
	MOIS,
	ANNEE,
	COLUMNS
};

void coach(GtkWidget *liste)
{
char id[30];char nom[30];char prenom[30];char jour[30];char mois[30];char annee[30];
GtkListStore *store;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;


store=NULL;


FILE *f1;



store = gtk_tree_view_get_model(liste);

	if(store==NULL)
	{
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" id",renderer,"text",ID,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
		
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" nom",renderer,"text",NOM,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" prenom",renderer,"text",PRENOM,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" jour",renderer,"text",JOUR,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" mois",renderer,"text",MOIS,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" annee",renderer,"text",ANNEE,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	

	
	}

store = gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	
	
	f1=fopen("/home/hizem/Desktop/MyGym/src/client","r");

	if(f1==NULL)
	{

		return;
	}
	else
	{
 		f1 = fopen("/home/hizem/Desktop/MyGym/src/client", "a+");

              while(fscanf(f1,"%s %s %s %s %s %S\n",id,nom,prenom,jour,mois,annee)!=EOF)
		{
			gtk_list_store_append (store, &iter);
			gtk_list_store_set (store,&iter,ID,id,NOM,nom,PRENOM,prenom,JOUR,jour,MOIS,mois,ANNEE,annee,-2);
		}
		fclose(f1);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    		g_object_unref (store);
	}
	

}
