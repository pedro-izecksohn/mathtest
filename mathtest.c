#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Question
{
  short int a, b;
} Question;

Question generateQuestion ()
{
  Question ret;
  ret.a = (rand()%200)-100;
  ret.b = (rand()%200)-100;
  return ret;
}

int main ()
{
  short int maxscore=10, score=0, qi=0, temp;
  time_t begin = time(NULL);
  srand (begin);
  for (;qi<maxscore;qi++)
  {
    Question q = generateQuestion();
    printf ("%hd%+hd=", q.a, q.b);
    scanf ("%hd", &temp);
    getchar();
    if (temp==(q.a+q.b))
    {
      score++;
    }
  }
  time_t end = time(NULL);
  printf ("You gave the right answer for %hd of %hd questions.\n", score, maxscore);
  time_t seconds = end-begin;
  double timed_score = ((((double)score)/((double)maxscore))/(double)seconds)*60.0;
  printf ("Your timed score is %lf .\nPress ENTER to exit.", timed_score);
  getchar();
  return 0;
}
