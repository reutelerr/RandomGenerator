//
//  main.c
//  Random
//
//  Created by Robin Reuteler on 30.04.19.
//  Copyright © 2019 RobinReuteler. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define VIDER_BUFFER    while( getchar() != '\n')

unsigned askVal_inBounds(unsigned maxVal, char* message)
{
    bool ok;
    unsigned val;
    do{
        printf("%s [0..%u] : ", message, maxVal);
        ok = scanf("%u", &val);
        VIDER_BUFFER;
    }while((!ok || val > maxVal) && printf("Entree invalide\n"));
    return val;
}

void showDistributionLine(unsigned PercentValue)
{
    printf("%2d       ", PercentValue);
    for(size_t i=0; i<PercentValue; ++i)
    {
        printf("=");
    }
}

void showDistribution(double* distributionTab, unsigned UpperBound)
{
    for(size_t i=0; i<UpperBound; ++i)
    {
        printf("tableau [%2zu]     ", i);
        showDistributionLine(*(distributionTab+i));
        printf("\n");
    }
}

void generateDistribution(unsigned UpperBound, unsigned ThrowNum)
{
    double distributionTab[UpperBound];
    //Initialisation à 0
    for(unsigned i=0; i<UpperBound; ++i)
    {
        *(distributionTab+i) = 0;
    }
    //Compte le nombre de lancers pour chaque valeur
    for(unsigned i=0; i<ThrowNum; ++i)
    {
        (*(distributionTab+rand()%UpperBound)) ++;
    }
    //Divise (division décimale) chaque élément du tableau par le nombre de lancers, puis multiplie par 100 pour obtenir le pourcentage
    for(unsigned i=0; i<UpperBound; ++i)
    {
        *(distributionTab+i) = (*(distributionTab+i)/(double)(ThrowNum))*100;
    }
    
    showDistribution(distributionTab, UpperBound);
    
}



int main()
{
    srand((unsigned)time(NULL));
    printf("Ce programme affiche la distribution aléatoire de nombres contenus dans un intervalle, donné, sur un certain nombre de lancers\n");
    const unsigned MAX_UPPER_BOUND = 100;
    const unsigned MAX_THROWS = 10000;
    char recommencer = '\0';
    do{
        unsigned UpperBound;
        UpperBound = askVal_inBounds(MAXUPPERBOUND, "nbre d'elements");
        unsigned ThrowNum;
        ThrowNum = askVal_inBounds(MAXTHROWS, "nbre de lancers");
        printf("\n");
        generateDistribution(UpperBound, ThrowNum);
        printf("\n");
        do
        {
            printf("Voulez-vous recommencer ? [o|n] :");
            scanf("%c", &recommencer);
            VIDER_BUFFER;
        }while(recommencer != 'o' && recommencer != 'n');
    }while(recommencer == 'o');
    return 0;
}
