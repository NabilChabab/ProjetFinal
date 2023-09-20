#include <stdio.h>
#include <stdlib.h>

struct  Todo {
    int id;
    char deadline[100];
    char Title[100];
    char Description[100];
    char Statut[100];
};

int n;


void AjouterP(){

    printf("================================================================================== Ajouter une Tache ====================================================================================\n");
    int i;
    struct Todo todo[100];

    printf("Entrez nombre des tachs: ");
    scanf("%d",&n);

    for (i = 0; i < n ; i++) {
        printf("Entrez tache %d detaills:\n", i+1);
        printf("ID: ");
        scanf("%d", &todo[i].id);
        printf("Deadline: ");
        scanf(" %29[^\n]", &todo[i].deadline);
        printf("Title: ");
        scanf(" %29[^\n]", &todo[i].Title);
        printf("Description: ");
        scanf(" %29[^\n]", &todo[i].Description);
        printf("Statut: ");
        scanf(" %29[^\n]", &todo[i].Statut);
    }
}
void AjouterN(){

    struct Todo todo[100];
    int i;
    n = 1;
    for (i = 0; i < n ; i++) {
        printf("Entrez une tache detaills:\n", i+1);
        printf("ID: ");
        scanf("%d", &todo[i].id);
        printf("Deadline: ");
        scanf(" %29[^\n]", &todo[i].deadline);
        printf("Title: ");
        scanf(" %29[^\n]", &todo[i].Title);
        printf("Description: ");
        scanf(" %29[^\n]", &todo[i].Description);
        printf("Statut: ");
        scanf(" %29[^\n]", &todo[i].Statut);
    }
    
}
void Afficher() {
    struct Todo todo[100];
    int i;

    printf("\nYour Todo List:\n");
    for (i = 0 ; i < n ; i++) {
        printf("\nTodo %d:\n",i+1);
        printf("ID: %d\n", todo[i].id);
        printf("Deadline: %s\n", todo[i].deadline);
        printf("Title: %s\n", todo[i].Title);
        printf("Description: %s\n", todo[i].Description);
        printf("Statut: %s\n", todo[i].Statut);
        
    }
}
void Modifier(){
    
}
void Supprimer(){
    
}
void Rechercher(){
    
}
void Statistique(){
    
}



void Menu(){


    char ChoixP;

        do{
        printf("===================================================================================== Welcome Back ======================================================================================\n");
        printf("=========================================================================================================================================================================================\n");
        printf("======================================================================================= Todo App ========================================================================================\n");
        printf("=========================================================================================================================================================================================\n");
        printf("========================================================================================= Menu ==========================================================================================\n");

        printf("1 ===> Ajouter une nouvelle tache");
        printf("\n2 ===> Ajouter plusieurs nouvelles taches.");
        printf("\n3 ===> Afficher la liste de toutes les taches");
        printf("\n4 ===> Modifier une tache");
        printf("\n5 ===> Supprimer une tache par identifiant");
        printf("\n6 ===> Rechercher les Taches");
        printf("\n7 ===> Statistiques");
        printf("\n8 ===> Quiter");

        printf("\n========================================================================================================================================================================================");
        printf("\nTapez votre choix [1-7] : ");
        scanf("%d",&ChoixP);

        switch (ChoixP){
        case 1:
            AjouterN();
            break;
        case 2:
            AjouterP();
            break;
        case 3:
            Afficher();
            break;
        case 4:
            Modifier();
            break;
        case 5:
            Supprimer();
            break;
        case 6:
            Rechercher();
            break;
        case 7:
            Statistique();
            break;  
        case 8:
            printf("See You next Time Bye !!");
            exit(0);
            break;;       
        }
        
    }
    while (ChoixP != 7);

}


int main(){

    Menu();

    return 0;
}
