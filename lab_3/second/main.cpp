#define CATCH_CONFIG_RUNNER



#include "activities.h"

int main() {
    int result = Catch::Session().run(argc, argv);
    return result;
}
