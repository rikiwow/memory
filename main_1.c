#include <stdio.h>
char str[100001];
int main(int argc, char** argv) {
	unsigned int n = 0;
	scanf("%u", &n);
	scanf("%s", &str);
	long currentX = 0;
	long result = 0;
	for (unsigned int i = 0; i < n; i++) {
		switch (str[i]) {
		case 'S':
			result -= currentX;
			break;
		case 'N':
			result += currentX;
			break;
		case 'W':
			currentX--;
			break;
		case 'E':
			currentX++;
		}
	}
	printf("%ld", result);
	return 0;
}

#include <stdio.h>
int main()
{
    int c;  //the input num int
    int i;  //the for loop item
    int x = 0, y = 0;   //track the pos
    char s; //for every read step
    unsigned int total = 0; //times of 0.5
    scanf("%d", &c);
    //printf("%d\n", c);
    for (i = 0; i < c; ++i)
    {
        //scanf(&s);
        s = fgetc(stdin);
        switch (s)
        {
        case 'N':
            total += x;
            ++y;
            break;
        case 'E':
            total -= y;
            ++x;
            break;
        case 'S':
            total -= x;
            --y;
            break;
        case 'W':
            total += y;
            --x;
            break;
        }
        //printf("T: %c, %d, %d, %d\n", s, x, y, total);
    }
    printf("%d", total / 2);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define MaxNum  100000
char input[MaxNum+100];

int main(int argc, char* argv[] )
{
    fgets(input,sizeof(input),stdin);
    int k=atoi(input);
    fgets(input,sizeof(input),stdin);

    int x=0, y=0,s=0;
    for (int i=0; i<k; ++i) {
      switch (input[i]) {
        case 'E': ++x; s-=y; break;
        case 'W': --x; s+=y; break;
        case 'N': ++y; break;
        case 'S': --y; break;
      }
    }
    printf("%d\n", s );
}