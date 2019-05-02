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
        printf("tableau [%zu]     ", i);
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
    printf("nbre d'elements    [0..100] : ");
    unsigned UpperBound;
    scanf("%u", &UpperBound);
    unsigned ThrowNum;
    printf("nbre de lancers [0..100000] : ");
    scanf("%u", &ThrowNum);
    generateDistribution(UpperBound, ThrowNum);
    return 0;
}
