#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include "catch.hpp"

TEST_CASE("Catch operability", "[simple]"){
    REQUIRE(1+1 == 2);
}

#include "funcs.h"

TEST_CASE("test 1, file", "[simple]"){
    std::ofstream inputPrepare;
    inputPrepare.open ("input.txt", std::ofstream::trunc);
    inputPrepare<<"2\n"
                  "1 3 0 3\n"
                  "2 4 1.5 4.5";
    inputPrepare.close();

    std::ifstream input( "input.txt", std::ofstream::in);
    std::ofstream output("output.txt", std::ofstream::trunc);
    parseFile(input,output);
    input.close();
    output.close();
    
    std::ifstream outputCheck("output.txt", std::ofstream::in);
    std::stringstream buffer;
    buffer<<outputCheck.rdbuf();
    outputCheck.close();
    REQUIRE(buffer.str() == "3.7500000000\n");
}

TEST_CASE("test 2", ""){
    std::stringstream input, output;
    input<<"2\n"
           "1 2 0 3\n"
           "1 2 2 1";
    parseFile(input,output);
    REQUIRE(output.str() == "3.0000000000\n");
}

TEST_CASE("segment crossing 0", ""){
    std::stringstream input, output;
    input<<"1\n"
           "0 1 2 1";
    parseFile(input,output);
    double S;
    output >> S;
    REQUIRE(S == Approx((2*M_PI - (2-1))/2).epsilon(1e-6) );
}

