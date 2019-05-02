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
    printf("%d       ", PercentValue);
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
    generateDistribution(10, 1000);
    return 0;
}
