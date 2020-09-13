#include "common.hpp"

TEST_CASE("operator!() for Null values", "[value][negate][Null]") {
    SECTION("null value") {
        Json const j = Null{};
        REQUIRE(!j == true);
    }
}

TEST_CASE("operator!() for Boolean values", "[value][negate][Boolean]") {
    SECTION("boolean false value") {
        Json const j = false;
        REQUIRE(!j == true);
    }
    SECTION("boolean true value") {
        Json const j = true;
        REQUIRE(!j == false);
    }
}

TEST_CASE("operator!() for Number values", "[value][negate][Number]") {
    SECTION("NaN value") {
        Json const j = NaN;
        REQUIRE(!j == true);
    }
    SECTION("Infinity value") {
        Json const j = Infinity;
        REQUIRE(!j == false);
    }
    SECTION("-Infinity value") {
        Json const j = -Infinity;
        REQUIRE(!j == false);
    }
    SECTION("number 0 value") {
        Json const j = 0.0;
        REQUIRE(!j == true);
    }
    SECTION("number 1 value") {
        Json const j = 1.0;
        REQUIRE(!j == false);
    }
}

TEST_CASE("operator!() for String values", "[value][negate][String]") {
    SECTION("string empty value") {
        Json const j = u8""sv;
        REQUIRE(!j == true);
    }
    SECTION("string non-empty values") {
        SECTION("string values with some text") {
            Json const j = u8"text"sv;
            REQUIRE(!j == false);
        }
        SECTION("string values containing 'false'") {
            Json const j = u8"false"sv;
            REQUIRE(!j == false);
        }
        SECTION("string values containing string '0'") {
            Json const j = u8"0"sv;
            REQUIRE(!j == false);
        }
    }
}

TEST_CASE("operator!() for Array values", "[value][negate][Array]") {
    SECTION("array empty value") {
        Json const j = Array{};
        REQUIRE(!j == false);
    }
    SECTION("array non-empty values") {
        SECTION("array values with string") {
            Json const j = Array{u8"string"sv};
            REQUIRE(!j == false);
        }
        SECTION("array values with true bool") {
            Json const j = Array{true};
            REQUIRE(!j == false);
        }
        SECTION("array values with number '1'") {
            Json const j = Array{1.0};
            REQUIRE(!j == false);
        }
        SECTION("array values with nested array") {
            Json const j = Array{Array{1.0}};
            REQUIRE(!j == false);
        }
    }
}

TEST_CASE("operator!() for Object values", "[value][negate][Object]") {
    SECTION("empty object value") {
        Json const j = Object{};
        REQUIRE(!j == false);
    }
}
