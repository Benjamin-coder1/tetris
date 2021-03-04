#include <iostream>
#include <stdlib.h>
#include <stdio.h>

// tableau contenant toutes les valeurs des differentes roations des differentes pieces
const int piece_value[7][4][4][4] =
{
    { // O
        {
            {0, 0, 0, 0},
            {0, 1, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}
        },
 
        {
            {0, 0, 0, 0},
            {0, 1, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}
        },
 
        {
            {0, 0, 0, 0},
            {0, 1, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}
        },
 
        {
            {0, 0, 0, 0},
            {0, 1, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}
        }
    },
 
    { // I
        {
            {0, 0, 0, 0},
            {2, 2, 2, 2},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },
 
        {
            {0, 0, 2, 0},
            {0, 0, 2, 0},
            {0, 0, 2, 0},
            {0, 0, 2, 0}
        },
 
        {
            {0, 0, 0, 0},
            {2, 2, 2, 2},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },
 
        {
            {0, 0, 2, 0},
            {0, 0, 2, 0},
            {0, 0, 2, 0},
            {0, 0, 2, 0}
        }
    },
 
    { // S
        {
            {0, 0, 0, 0},
            {0, 0, 3, 3},
            {0, 3, 3, 0},
            {0, 0, 0, 0}
        },
 
        {
            {0, 0, 3, 0},
            {0, 0, 3, 3},
            {0, 0, 0, 3},
            {0, 0, 0, 0}
        },
 
        {
            {0, 0, 0, 0},
            {0, 0, 3, 3},
            {0, 3, 3, 0},
            {0, 0, 0, 0}
        },
 
        {
            {0, 0, 3, 0},
            {0, 0, 3, 3},
            {0, 0, 0, 3},
            {0, 0, 0, 0}
        }
    },
 
    { // Z
        {
            {0, 0, 0, 0},
            {0, 4, 4, 0},
            {0, 0, 4, 4},
            {0, 0, 0, 0}
        },
 
        {
            {0, 0, 0, 4},
            {0, 0, 4, 4},
            {0, 0, 4, 0},
            {0, 0, 0, 0}
        },
 
        {
            {0, 0, 0, 0},
            {0, 4, 4, 0},
            {0, 0, 4, 4},
            {0, 0, 0, 0}
        },
 
        {
            {0, 0, 0, 4},
            {0, 0, 4, 4},
            {0, 0, 4, 0},
            {0, 0, 0, 0}
        }
    },
    
    { // L
        {
            {0, 0, 0, 0},
            {0, 5, 5, 5},
            {0, 5, 0, 0},
            {0, 0, 0, 0}
        },
 
        {
            {0, 0, 5, 0},
            {0, 0, 5, 0},
            {0, 0, 5, 5},
            {0, 0, 0, 0}
        },
 
        {
            {0, 0, 0, 5},
            {0, 5, 5, 5},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },
 
        {
            {0, 5, 5, 0},
            {0, 0, 5, 0},
            {0, 0, 5, 0},
            {0, 0, 0, 0}
        }
    },
 
    { // J
        {
            {0, 0, 0, 0},
            {0, 6, 6, 6},
            {0, 0, 0, 6},
            {0, 0, 0, 0}
        },
 
        {
            {0, 0, 6, 6},
            {0, 0, 6, 0},
            {0, 0, 6, 0},
            {0, 0, 0, 0}
        },
 
        {
            {0, 6, 0, 0},
            {0, 6, 6, 6},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },
 
        {
            {0, 0, 6, 0},
            {0, 0, 6, 0},
            {0, 6, 6, 0},
            {0, 0, 0, 0}
        }
    },
 
    { // T
        {
            {0, 0, 0, 0},
            {0, 7, 7, 7},
            {0, 0, 7, 0},
            {0, 0, 0, 0}
        },
 
        {
            {0, 0, 7, 0},
            {0, 0, 7, 7},
            {0, 0, 7, 0},
            {0, 0, 0, 0}
        },
 
        {
            {0, 0, 7, 0},
            {0, 7, 7, 7},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },
 
        {
            {0, 0, 7, 0},
            {0, 7, 7, 0},
            {0, 0, 7, 0},
            {0, 0, 0, 0}
        }
    }
};