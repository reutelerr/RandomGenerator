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

void generateDistribution(unsigned ValueRange, unsigned ThrowNum)
{
    int distributionTab[ValueRange];
    for(unsigned i=0; i<ValueRange; ++i)
    {
        *(distributionTab+i) = 0;
    }
    for(unsigned i=0; i<ThrowNum; ++i)
    {
        (*(distributionTab+rand()%ValueRange))++;
    }
}

void showDistributionLine();

void showDistribution();

int main()
{
    srand((unsigned)time(NULL));
    return 0;
}
