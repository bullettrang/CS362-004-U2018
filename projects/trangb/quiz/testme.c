#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define WHITESPACE 32
#define RIGHTBRACKET 125
#define LOWERE 101
#define LOWERT 116
char inputChar()
{
	char output;
	int rando;
	
	// 32(whitespace) to 125 ( } ) 
	rando = (rand() % (RIGHTBRACKET - WHITESPACE + 1)) + WHITESPACE;
	output = (char)rando;
  
    return output;
}

char *inputString()
{
	char outputStr[6];

	int i;
	int num;
	char c;
	char * finalStr;
	for (i = 0; i < 5; i++) {
		//grab random int between 101 -116
		num = (rand() % (LOWERT - LOWERE + 1)) + LOWERE;
		c = (char)num;
		outputStr[i] = c;
	}
    //append '\0'
	outputStr[5] = '\0';
	finalStr = outputStr;
    return finalStr;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
