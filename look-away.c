#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void display_dialog() {
  char buffer[256];
  FILE *command = popen("osascript -e 'display dialog \"Take a break (Minutes)\" buttons {\"10\", \"20\", \"30\"} default button 1' -e 'set selectedTime to button returned of result' -e 'return selectedTime as string'", "r");
  if (fgets(buffer, sizeof(buffer), command) != NULL) {
    int break_time = atoi(buffer);
    sleep(break_time);
  }
  pclose(command);
}

void display_work_dialog() {
  char buffer[256];
  FILE *command = popen("osascript -e 'display dialog \"Start working\" buttons {\"OK\"} default button 1' -e 'return 60 as string'", "r");
  if (fgets(buffer, sizeof(buffer), command) != NULL) {
    int work_time = atoi(buffer);
    sleep(work_time);
  }
  pclose(command);
}

int main() {
  while (1) {
    display_work_dialog();
    display_dialog();
    display_work_dialog();
  }
  return 0;
}

