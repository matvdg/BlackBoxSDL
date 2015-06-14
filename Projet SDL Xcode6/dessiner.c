//
//  dessiner.c
//  SDL
//
//  Created by M@|Stane on 04/06/2015.
//  Copyright (c) 2015 Supinfo. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>



void dessinerPlateauConsole(int** plateau, int taille){

    
    int i = 0;
    int j = 0;
        
        for (i=0; i<taille; i++) {
            
            for (j=0; j<taille; j++) {
                
                printf(" %d ", plateau[i][j]);
                
            }
            printf("\n");
            
        }
    }
