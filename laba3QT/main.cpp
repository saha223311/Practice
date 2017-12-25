#include <string>
#include "algorithm.h"

#define TAP_COMPILE
#include "libtap\cpp_tap.h"

int main() {
    //
    algorithm alg;
    //
    plan_tests(7);
    //
    ok(alg.Execute("pasoib") == "p a s o i b", "Result of \"pasoib\" = \"p a s o i b\"");
    ok(alg.Execute("zzzqxx") == "zzz q xx", "Result of \"zzzqxx\" = \"zzz q xx\"");
    ok(alg.Execute("wasitacatisaw") == "wasitacatisaw", "Result of \"wasitacatisaw\" = \"wasitacatisaw\"");
    //
    ok(alg.Execute(std::string("a", 5000)) == "error1", "Result of std::string(\"a\", 5000) = error1");
    ok(alg.Execute("") == "error2", "Result of \"\" = error2");
    ok(alg.Execute("pasOib") == "error3", "Result of \"pasOib\" = error3");
    ok(alg.Execute("zzzqxx44") == "error3", "Result of \"zzzqxx44\" = error3");
    //
    return exit_status();
    return 0;
}


