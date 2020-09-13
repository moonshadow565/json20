#include "common.hpp"

TEST_CASE("comparing Boolean values", "[value][compare][Boolean]") {
    SECTION("false to true") {
        Json const j = false;
        REQUIRE_FALSE(j == true);
    }
    SECTION("true to false") {
        Json const j = true;
        REQUIRE_FALSE(j == false);
    }
}

TEST_CASE("comparing Number values", "[value][compare][Number]") {
    SECTION("positive integers") {
        Json const j = 1;
        REQUIRE_FALSE(j == 2);
    }
    SECTION("negative integers") {
        Json const j = -2;
        REQUIRE_FALSE(j == -1);
    }
    SECTION("positive integers and infinity") {
        Json const j = 1;
        REQUIRE_FALSE(j == Infinity);
    }
    SECTION("positive integers and -infinity") {
        Json const j = 1;
        REQUIRE_FALSE(j == -Infinity);
    }
    SECTION("negative integers and infinity") {
        Json const j = -1;
        REQUIRE_FALSE(j == Infinity);
    }
    SECTION("negative integers and -infinity") {
        Json const j = -1;
        REQUIRE_FALSE(j == -Infinity);
    }
    SECTION("positive infinity and negative infinity") {
        Json const j = Infinity;
        REQUIRE_FALSE(j == -Infinity);
    }
    SECTION("two NaNs") {
        Json const j = NaN;
        REQUIRE_FALSE(j == NaN);
    }
}

TEST_CASE("comparing String values", "[value][compare][String]") {
    SECTION("same size string with completly different contents") {
        Json const j = u8"a"sv;
        REQUIRE_FALSE(j == u8"b"sv);
    }
    SECTION("differently sized strings with same starting contents") {
        Json const j = u8"b"sv;
        REQUIRE_FALSE(j == u8"ba"sv);
    }
    SECTION("differently sized strings with completly different contents") {
        Json const j = u8"b"sv;
        REQUIRE_FALSE(j == u8"aa"sv);
    }
}

TEST_CASE("comparing Array values", "[value][compare][Array]") {
    SECTION("same size array with completly different contents") {
        Json const j = Array{u8"a"sv};
        REQUIRE_FALSE(j == Array{u8"b"sv});
    }
    SECTION("differently sized array with same starting contents") {
        Json const j = Array{u8"b"sv};
        REQUIRE_FALSE(j == Array{u8"b"sv, u8"a"sv});
    }
    SECTION("differently sized array with completly different contents") {
        Json const j = Array{u8"b"sv};
        REQUIRE_FALSE(j == Array{u8"a"sv, u8"a"sv});
    }
    SECTION("same size arrays with starting contents and uncomparable contents") {
        Json const j = Array{u8"a"sv, NaN};
        REQUIRE_FALSE(j == Array{u8"a"sv, NaN});
    }
}

TEST_CASE("comparing Object values", "[value][compare][Object]") {
    SECTION("same size object with completly different contents") {
        Json const j = Object{{u8"a", 0}};
        REQUIRE_FALSE(j == Object{{u8"a", 1}});
    }
    SECTION("differently object array with same starting contents") {
        Json const j = Object{{u8"a", 1}};
        REQUIRE_FALSE(j == Object{{u8"a", 1}, {u8"b", 0}});
    }
    SECTION("differently object array with completly different contents") {
        Json const j = Object{{u8"a", 1}};
        REQUIRE_FALSE(j == Object{{u8"a", 0}});
    }
    SECTION("same size object with starting contents and uncomparable contents") {
        Json const j = Object{{u8"a", 0}, {u8"b", NaN}};
        REQUIRE_FALSE(j == Object{{u8"a", 0}, {u8"b", NaN}});
    }
}
