#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void) {
  const int MAX_SECRET = 10;
  int secret;
  int guess = 0;
  int guess_count = 0;
  int input_trail_count;
  /* Seed - init the pseudo-random generator */
  srand(time(NULL));
  secret = rand() % MAX_SECRET + 1;
  do {
    printf("Guess my number between 1 and %d inclusive: ", MAX_SECRET);
    scanf("%d", &guess);
    /* Handle possible user string input by consuming
       and counting any remaining input characters */
    input_trail_count = 0;
    while ('\n' !=  getchar()) { ++input_trail_count; };
    if (0 == input_trail_count) {  /* no trailing chars after integer */
      if (guess > 0 && guess <= MAX_SECRET) { /* integer within range */
        if (guess < secret) {
          printf("Your guess [%d] is too low. Try again.\n", guess);
        } else if (guess > secret) {
          printf("Your guess [%d] is too high. Try again.\n", guess);
        }
        ++guess_count;
      } else { /* integer out of range */
        printf("Error: integer value [%d] is out of range (1-%d) !\n",
               guess, MAX_SECRET);
      }
    } else { /* detected non-integer input: string */
      printf("Error: detected non-integer input, only integers allowed!\n");
    }
  } while (guess != secret);
  printf("You guessed my number [%d] in [%d] tries!\n", secret, guess_count);
  return EXIT_SUCCESS;
}
/* eof */
