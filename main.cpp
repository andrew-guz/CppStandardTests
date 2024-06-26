#include <iostream>

#include "aggregate_initialization.h"
#include "async.h"
#include "if_constexpr.h"
#include "if_init.h"
#include "mayby_unused.h"
// #include "nodiscard.h"
#include "array.h"
#include "lambda_capture_init.h"
#include "structure_binding.h"
#include "templates.h"
#include "use_threads.h"
#include "user_defined_literals.h"

int main(int argc, char** argv) {
    REGISTER_TEST(IfInit);
    REGISTER_TEST(IfConstexpr);
    REGISTER_TEST(Async);
    REGISTER_TEST(AggregateInitialization);
    REGISTER_TEST(MaybeUnused);
    // REGISTER_TEST(Nodiscard);
    REGISTER_TEST(UserDefinedLiterals);
    REGISTER_TEST(Array);
    REGISTER_TEST(Threads);
    REGISTER_TEST(LambdaCaptureInit);
    REGISTER_TEST(StructureBinding);
    REGISTER_TEST(Templates);

    if (argc > 1)
        Tests::instance().RunExact(argv[1]);
    else
        Tests::instance().RunAll();

    return 0;
}
