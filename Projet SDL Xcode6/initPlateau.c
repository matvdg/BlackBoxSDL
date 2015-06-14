#include "initPlateau.h"

void initPlateau(int taillePlateau, int nbAtomes)
{
    
    int i=0;
    int j=0;
    int** plateau;
	srand(time(NULL));
    
    plateau = malloc(taillePlateau*sizeof(int*)); // Génération des lignes
    
    for(i=0; i<taillePlateau; i++)
    {
        plateau[i] = malloc(taillePlateau*sizeof(int)); // Génération des colonnes
        for(j=0; j<taillePlateau; j++)
        {
            plateau[i][j] = 0;
        }
        
    }
    for(i=1; i<taillePlateau-1; i++)
    {
        for(j=1; j<taillePlateau-1; j++)
        {
            plateau[i][j] = 1;
        }
        
    }
    
    while(nbAtomes > 0)  //regarde si la case retombé aléatoirement dessus est déjà à 2, si oui : on laisse et on refait la boucle pour le même atome, si non : on le laisse à 2 et on enlève 1 atome parmi ceux à trouver
    {
        int x = rand()%(taillePlateau - 2) + 1;
        int y = rand()%(taillePlateau - 2) + 1;
        int nombre = nbAtomes;
        nombre = (plateau[x][y]==2)?(nbAtomes):(nbAtomes-1); //? = if pour la condition ternaire
        nbAtomes = nombre;
        plateau[x][y] = 2;
		
		//on place les adjacents
		
		//adjacent de la gauche
        if(x > 1) // Si la case n'est pas sur la bande du haut
        {
            if(plateau[x-1][y] != 2)
            {
                plateau[x-1][y] = 3;
            }
        }
		//adjacent de la droite
        if(x < taillePlateau - 2) // Si la case n'est pas sur la bande du bas
        {
            if(plateau[x+1][y] != 2)
            {
                plateau[x+1][y] = 3;
            }
        }
		//adjacent du haut
        if(y > 1)  // Si la bande n'est pas sur la bande de gauche
        {
            if(plateau[x][y-1] != 2)
            {
                plateau[x][y-1] = 3;
            }
        }
		//adjacent du bas
        if(y < taillePlateau - 2) // Si la bande n'est pas sur la bande de droite
        {
            if(plateau[x][y+1] != 2)
            {
                plateau[x][y+1] = 3;
				
            }
        }
    }
	jouerUnJoueur(plateau, taillePlateau, nbAtomes);
    //dessinerPlateau(plateau, taillePlateau);
}