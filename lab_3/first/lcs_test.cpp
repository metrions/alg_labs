#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#define CATCH_CONFIG_MAIN

#include "lcs.h"


TEST_CASE( "Both strings are empty" ) {
    CHECK( lcs("", "") == "" );
}

TEST_CASE( "One string is empty" ) {
    CHECK( lcs("", "abcd") == "" );
    CHECK( lcs("abcd", "") == "" );
}

TEST_CASE( "Equal strings" ) {
    CHECK( lcs("abcd", "abcd") == "abcd" );
}

TEST_CASE( "Substring" ) {
    CHECK( lcs("abab", "ab") == "ab" );
}

TEST_CASE( "Substring in the middle" ) {
    CHECK( lcs("xyaban", "abarab") == "aba" );
}

TEST_CASE( "Subsequences" ) {
    CHECK( lcs("nahybser", "iunkayxbis") == "naybs" );
    CHECK( lcs("z1artunx", "yz21rx") == "z1rx" );
    CHECK( lcs("z1arxzyx1a", "yz21rx") == "z1rx" );
    CHECK( lcs("yillnum", "numyjiljil") == "yill" );
}

TEST_CASE( "Reverse subsequence" ) {
    auto result = lcs("xablar", "ralbax");
    CHECK( (result == "aba" || result == "ala") ); 
}

TEST_CASE( "Both strings are" ) {
    CHECK( lcs_slow("", "") == "" );
}

TEST_CASE( "One string " ) {
    CHECK( lcs_slow("", "abcd") == "" );
    CHECK( lcs_slow("abcd", "") == "" );
}

TEST_CASE( "Equal" ) {
    CHECK( lcs_slow("abcd", "abcd") == "abcd" );
}

TEST_CASE( "Substr" ) {
    CHECK( lcs_slow("abab", "ab") == "ab" );
}

TEST_CASE( "Substring in the" ) {
    CHECK( lcs_slow("xyaban", "abarab") == "aba" );
}

TEST_CASE( "Subsequs" ) {
    CHECK( lcs_slow("nahybser", "iunkayxbis") == "naybs" );
    CHECK( lcs_slow("z1artunx", "yz21rx") == "z1rx" );
    CHECK( lcs_slow("z1arxzyx1a", "yz21rx") == "z1rx" );
    CHECK( lcs_slow("yillnum", "numyjiljil") == "yill" );
}

TEST_CASE( "Reverse subseq" ) {
    auto result = lcs_slow("xablar", "ralbax");
    CHECK( (result == "aba" || result == "ala") ); 
}
