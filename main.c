#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sundial.h"

int main(int argc, char **argv) {
  double OFFSET; // EST TIME ZONE
  double LAT;
  double LONG;

  if (argc == 4) {
    LAT = strtod(argv[1], NULL);
    LONG = strtod(argv[2], NULL);
    OFFSET = strtod(argv[3], NULL)*60*60;
    printf("%2.3f, %2.3f\n",LAT,LONG);
    printf("Currenttime: %2.0f\n",getTime(time(NULL)));
    printf("Sunrise: %2.0f\n",sunrise(LAT,LONG,OFFSET,getTime(time(NULL)))); // long, lat for Durham, NC
    printf("Sunset: %2.0f\n",sunset(LAT,LONG,OFFSET,getTime(time(NULL))));
  } else {
    printf("usage: sundial LAT LONG TIMEZONE\n\nexample: sundial 35.994 -78.8986 -4    # Durham, NC\n");
  }
  return EXIT_SUCCESS;
}
