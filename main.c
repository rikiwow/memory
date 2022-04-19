
#include <stdio.h>
#include <stdlib.h>

#define debugprt printf

typedef struct pos
{
    long x;
    long y;
}pos_t;
pos_t vertex[200000]={{0,0}};

int main(int argc, char **argv)
{
    /* INPUT */

    int n=0;
    fscanf(stdin, "%d", &n);

    char *str = (char*)malloc(n+2);
    str[n+1] = '\0';
    fscanf(stdin, "%s", str);
#ifdef __DEBUG__ 
    debugprt( "input n: %d, moves: %s\n", n, str);
#endif

    char *newStr = (char*)malloc(n+2);
    newStr[0] = 'I'; 
    int lastIndex = 0;

    int i = 0;

    for ( i =0 ; i< n; i++ )
    {
#ifdef __DEBUG__ 
        debugprt("this move: %c, last move: %c\n", str[i], newStr[lastIndex]);
#endif

        if ( str[i] == 'S' )
        {
            if ( newStr[lastIndex] == 'N' )
            {
                newStr[lastIndex]='\0';
                lastIndex --;
                continue;
            }
          
        }

        if ( str[i] == 'N' )
        {
            if ( newStr[lastIndex] == 'S' )
            {
                newStr[lastIndex]='\0';
                lastIndex --;
                continue;
            }
        }

        if ( str[i] == 'E' )
        {
            if ( newStr[lastIndex] == 'W' )
            {
                newStr[lastIndex]='\0';
                lastIndex --;
                continue;
            }
        }

        if ( str[i] == 'W' )
        {
            if ( newStr[lastIndex] == 'E' )
            {
                newStr[lastIndex]='\0';
                lastIndex --;
                continue;
            }
        }

        lastIndex ++;
        newStr[lastIndex] = str[i];
        newStr[lastIndex+1]='\0';

#ifdef __DEBUG__ 
        debugprt("newstr: %s\n",  newStr);
#endif

    }

#ifdef __DEBUG__ 
    debugprt("###### start finding vertex: %s .lastIndex %d ######\n", (char*)newStr, lastIndex);
#endif
    vertex[0].x = 0;
    vertex[0].y = 0;
    int vertexNum = 1;

    vertex[1].x = 0;
    vertex[1].y = 0;

    for ( i=1; i<lastIndex; i++ )
    {
#ifdef __DEBUG__ 
        debugprt("this move: %c\n", newStr[i]);
#endif
        if ( newStr[i] == 'S' )
        {
            vertex[vertexNum].x = vertex[vertexNum-1].x;
            vertex[vertexNum].y --;
        }

        if ( newStr[i] == 'N' )
        {
            vertex[vertexNum].x = vertex[vertexNum-1].x;
            vertex[vertexNum].y ++;
        }

        if ( newStr[i] == 'E' )
        {
            vertex[vertexNum].x  ++ ;
            vertex[vertexNum].y = vertex[vertexNum-1].y;
        }

        if ( newStr[i] == 'W' )
        {
            vertex[vertexNum].x -- ;
            vertex[vertexNum].y = vertex[vertexNum-1].y;
        }

        if ( newStr[i] != newStr[i+1] )
        {
            vertexNum ++;
            vertex[vertexNum].x = vertex[vertexNum-1].x; 
            vertex[vertexNum].y = vertex[vertexNum-1].y;

#ifdef __DEBUG__ 
            debugprt("   Adding new vertex: %d, %d \n", vertex[vertexNum-1].x, vertex[vertexNum-1].y ); 
#endif
        }

        int j=0;
        for ( j=0; j< vertexNum; j++ )
        {
#ifdef __DEBUG__ 
            debugprt(" ###%d: %d, %d \n", j, vertex[j].x, vertex[j].y );
#endif
        }
    }


    vertex[vertexNum].x = vertex[0].x;
    vertex[vertexNum].y = vertex[0].y;
    vertexNum ++;

    long sum1 =0, sum2 = 0;
    int k = 0;
    long x1 =0, x2=0, y1=0, y2=0;
    for ( i = 0; i < vertexNum -1; i++ )
    {
        
        sum1 += vertex[i].x * vertex[i+1].y;
        sum2 += vertex[i].y * vertex[i+1].x;
    }

#ifdef __DEBUG__ 
    debugprt("sum1:%d, sum2:%d \n", sum1, sum2);
#endif

    int num = 0;
    num = ( sum1 -sum2 ) >> 1;

    printf ("%d\n", num);

    free(newStr);

    return 0;

}

