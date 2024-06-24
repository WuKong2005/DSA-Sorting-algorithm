#include "experiment.h"

int main(int argc, char** argv) {
    srand(time(NULL));

    experiment Test;
    Test.readCommand(argc, argv);
    Test.startExperiment();
    Test.printResult();
    return 0;
}