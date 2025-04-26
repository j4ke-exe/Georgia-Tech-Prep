#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Structures Section
struct Race
{
   int numberOfLaps;
   int currentLap;
   char firstPlaceDriverName[50];
   char firstPlaceRaceCarColor[50];
};

struct RaceCar
{
   char driverName[50];
   char raceCarColor[50];
   int totalLapTime;
};

// Print Functions Section
void printIntro()
{
   printf("Welcome to our main event digital race fans!\n"
          "I hope everybody has their snacks because we are about to begin!\n");
   fflush(stdout);
}

void printCountDown()
{
   printf("Racers Ready! In...\n");
   for (int i = 5; i > 0; i--)
   {
      printf("%d\n", i);
      fflush(stdout);
   }
   printf("Race!\n");
   fflush(stdout);
}

void printFirstPlaceAfterLap(struct Race race)
{
   printf("First Place Is: %s in the %s race car!\n", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
   fflush(stdout);
}

void printCongratulations(struct Race race)
{
   printf("Let's all congratulate %s in the %s race car for an amazing performance.\n"
          "It truly was a great race and everybody have a goodnight!\n",
          race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
   fflush(stdout);
}

// Logic Functions Section
int calculateTimeToCompleteLap()
{
   int speed = (rand() % 3) + 1;
   int acceleration = (rand() % 3) + 1;
   int nerves = (rand() % 3) + 1;
   int sum = speed + acceleration + nerves;

   return sum;
}

void updateRaceCar(struct RaceCar *raceCar)
{
   raceCar->totalLapTime += calculateTimeToCompleteLap();
}

void updateFirstPlace(struct Race *race, struct RaceCar *raceCar1, struct RaceCar *raceCar2)
{
   if (raceCar1->totalLapTime <= raceCar2->totalLapTime)
   {
      strcpy(race->firstPlaceDriverName, raceCar1->driverName);
      strcpy(race->firstPlaceRaceCarColor, raceCar1->raceCarColor);
   }
   else
   {
      strcpy(race->firstPlaceDriverName, raceCar2->driverName);
      strcpy(race->firstPlaceRaceCarColor, raceCar2->raceCarColor);
   }
}

void startRace(struct RaceCar *raceCar1, struct RaceCar *raceCar2)
{
   struct Race race;
   race.numberOfLaps = 5;
   race.currentLap = 1;
   strcpy(race.firstPlaceDriverName, "");
   strcpy(race.firstPlaceRaceCarColor, "");

   for (int i = 0; i < race.numberOfLaps; i++)
   {
      updateRaceCar(raceCar1);
      updateRaceCar(raceCar2);
      updateFirstPlace(&race, raceCar1, raceCar2);
      printFirstPlaceAfterLap(race);
      race.currentLap++;
   }

   printCongratulations(race);
}

// Main Section
int main()
{
   srand(time(0));

   struct RaceCar raceCar1;
   strcpy(raceCar1.driverName, "Bob");
   strcpy(raceCar1.raceCarColor, "Blue");
   raceCar1.totalLapTime = 0;

   struct RaceCar raceCar2;
   strcpy(raceCar2.driverName, "Dave");
   strcpy(raceCar2.raceCarColor, "Red");
   raceCar2.totalLapTime = 0;

   printIntro();
   printCountDown();
   startRace(&raceCar1, &raceCar2);

   return 0;
}
