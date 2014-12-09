#define CATCH_CONFIG_RUNNER
#include "test.h"

int main(int argc, char** argv) {  
   ::testing::GTEST_FLAG(throw_on_failure) = true;
   ::testing::InitGoogleMock(&argc, argv);

   return Catch::Session().run( argc, argv );
}
