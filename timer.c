void displaySymbols(int count);
int calculateNumberOfSymbolsToDisplay(int time, int secondsPerSymbol);
void displayEmptySpaces(int count);
void displayHelp();

int main(int argc, char **argv){
  char arguments;
  int timeInMinutes;
  char *message;
  int seconds;
  float secondsPerSymbol;
  int timeElapsed = 0;
  float totalSymbols = 20.0;


  while((arguments = getopt(argc, argv, "t:hm:")) != -1){
    if(arguments == 't') {
      timeInMinutes = atoi(optarg);
    }
    else if(arguments == 'm') {
      message = optarg;
    }
    else if(arguments == 'h') {
      displayHelp();
      return 0;
    }
  }

  seconds = timeInMinutes * 60;
  secondsPerSymbol = seconds / totalSymbols;

  while(timeElapsed <= seconds){
    int numberOfSymbolsToDisplay = (timeElapsed / secondsPerSymbol);

    printf("\r%s: %02d [", message, seconds - timeElapsed);
    sleep(1);
    displaySymbols(numberOfSymbolsToDisplay);
    displayEmptySpaces(totalSymbols - numberOfSymbolsToDisplay);
    printf("]");
    timeElapsed++;
    fflush(stdout);
  }

  printf("\n");
  return 0;
}

void displaySymbols(int count){
  for(int i = 0; i <= count; i++){
    printf("=");
  }
}

int calculateNumberOfSymbolsToDisplay(int time, int secondsPerSymbol){
  int total = 0;

  for(int i = 0; i <= time; i += secondsPerSymbol){
    if(i < time) total++;
  }

  return total;
}

void displayEmptySpaces(int count){
  for(int i = 1; i < count; i++){
    printf(" ");
  }
}

void displayHelp(){
  printf("\nUsage: timer -t (time) -m (message) [-h]\n");
  printf("example: timer -t 5 -m \"starting soon\"\n");
  printf("\noptions\n\n");
  printf("-t time in minutes to count down");
  printf("-m message to display next to counter");
  printf("-h this help message\n");
}
