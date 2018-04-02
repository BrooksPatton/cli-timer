void displaySymbols(int count);
int calculateNumberOfSymbolsToDisplay(int time, int secondsPerSymbol);
void displayEmptySpaces(int count);

int main(){
  int seconds = 60;
  int timeElapsed = 0;
  float totalSymbols = 80.0;
  float secondsPerSymbol = seconds / totalSymbols;

  while(timeElapsed <= seconds){
    int numberOfSymbolsToDisplay = (timeElapsed / secondsPerSymbol);

    printf("\rtime left: %02d [", seconds - timeElapsed);
    sleep(1);
    displaySymbols(numberOfSymbolsToDisplay);
    displayEmptySpaces(totalSymbols - numberOfSymbolsToDisplay);
    printf("]");
    timeElapsed++;
    fflush(stdout);
  }

  printf("\n");
  printf("and we are finished!");
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
