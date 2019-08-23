//This program is to test signal receive
//The program will keep running untile receive two signals:
// Ctrl+c or time > 5sec, then program will quit.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

int score=0;

void endGame(int sig){
	printf("\nFinal score: %i /n", score);
	exit(0);
}

//custom signal handler. Default signal handler is to stop program.
//So we need custom handler.
int catch_signal(int sig, void(*handler)(int)){
	struct sigaction action;
	action.sa_handler = handler;//set default handler to custom handler.
	sigemptyset(*action.sa_mask);
	action.sa_flag=0;
	return sigaction(sig, &action, NULL);
}

//custom signal handler.
//after receive alarm, raise SIGINT and call endGame to exit.
void times_up(int sig){
    puts("\nTimes UP!");
    raise(SIGINT);
}

void error(char *msg){
    fprintf(stderr, "%s, %s\n", msg, strerror(errno));
    exit(1);
}



int main(){
    catch_signal(SIGALRM, times_up);
    catch_signal(SIGINT, endGame);

    //set time(0) as seed of random
    srandom(time(0));

    while(1){
        //set two random ints
        int a = random()%11;
        int b = random()%11;

        char txt[4];
        //set alarm delay 5 sec
        alarm(5);
        printf("\nWhat's %i times %i ? ", a, b);
        fgets(txt, 4, stdin);
        int answer = atoi(txt);
        if (answer == a*b){
            score++;
            printf("\n Correct answer! Current score: %i \n", score);
        }
        else{
            printf("\n Wrong answer! Current score: %i \n", score);
        }
    }
    return(0);

}



