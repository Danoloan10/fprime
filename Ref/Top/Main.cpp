#include "./getopt.h"
#include <stdlib.h>
#include <ctype.h>

#include <Ref/Top/Components.hpp>

void print_usage(const char* app) {
    (void) printf("Usage: ./%s [options]\n-p\tport_number\n-a\thostname/IP address\n",app);
}

//#include <signal.h>
#include <stdio.h>

//volatile sig_atomic_t terminate = 0;

/*
static void sighandler(int signum) {
    exitTasks();
    terminate = 1;
}
*/

void run1cycle(void) {
    // call interrupt to emulate a clock
    blockDrv.callIsr();
    Os::Task::delay(1000); //10Hz
}

void runcycles(NATIVE_INT_TYPE cycles) {
    if (cycles == -1) {
        while (true) {
            run1cycle();
        }
    }

    for (NATIVE_INT_TYPE cycle = 0; cycle < cycles; cycle++) {
        run1cycle();
    }
}

//int main(int argc, char* argv[]) {
extern "C" void PartitionMain(void) {
    U32 port_number = 0; // Invalid port number forced
    char *hostname;
    hostname = NULL;
    bool dump = false;

	/*
    while ((option = getopt(argc, argv, "hdp:a:")) != -1){
        switch(option) {
            case 'h':
                print_usage(argv[0]);
                return 0;
                break;
            case 'p':
                port_number = atoi(optarg);
                break;
            case 'a':
                hostname = optarg;
                break;
            case '?':
                return 1;
            case 'd':
                dump = true;
                break;
            default:
                print_usage(argv[0]);
                return 1;
        }
    }
	*/

    (void) printf("Hit Ctrl-C to quit\n");

    bool quit = constructApp(dump, port_number, hostname);
    if (quit) {
        return;
    }

	/*
    // register signal handlers to exit program
    signal(SIGINT,sighandler);
    signal(SIGTERM,sighandler);
	*/

    int cycle = 0;

    while (1) { // TODO revisar
//        (void) printf("Cycle %d\n",cycle);
        runcycles(1);
        cycle++;
    }

    // Give time for threads to exit
    (void) printf("Waiting for threads...\n");
    Os::Task::delay(1000);

    (void) printf("Exiting...\n");

    return;
}
