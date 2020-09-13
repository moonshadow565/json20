#include "common.hpp"

TEST_CASE("Convert Null construct", "[semantics][construct][Null]") {
    SECTION("default construct") {
        Json const j;
        REQUIRE(j == Null{});
    }
    SECTION("empty brace construct") {
        Json const j{};
        REQUIRE(j == Null{});
    }
    SECTION("nullptr literal") {
        Json const j = nullptr;
        REQUIRE(j == Null{});
    }
    SECTION("copy") {
        Null const other = {};
        Json const j = other;
        REQUIRE(j == Null{});
    }
    SECTION("move") {
        Null other = {};
        Json const j = std::move(other);
        REQUIRE(j == Null{});
    }
}

TEST_CASE("Convert Boolean construct", "[semantics][construct][Boolean]") {
    SECTION("false literal") {
        Json const j = false;
        REQUIRE(j == false);
    }
    SECTION("true literal") {
        Json const j = true;
        REQUIRE(j == true);
    }
    SECTION("copy") {
        Boolean const other = true;
        Json const j = other;
        REQUIRE(j == true);
    }
    SECTION("move") {
        Boolean other = true;
        Json const j = std::move(other);
        REQUIRE(j == true);
    }
}

TEST_CASE("Convert Number construct", "[semantics][construct][Number]") {
    SECTION("0 literal") {
        Json const j = 0;
        REQUIRE(j == 0.0);
    }
    SECTION("char") {
        SECTION("copy char") {
            char const other = 1;
            Json const j = other;
            REQUIRE(j == 1);
        }
        SECTION("move char") {
            char other = 1;
            Json const j = std::move(other);
            REQUIRE(j == 1);
        }
        SECTION("copy signed char") {
            signed char const other = 1;
            Json const j = other;
            REQUIRE(j == 1);
        }
        SECTION("move signed char") {
            signed char other = 1;
            Json const j = std::move(other);
            REQUIRE(j == 1);
        }
        SECTION("copy unsigned char") {
            unsigned char const other = 1;
            Json const j = other;
            REQUIRE(j == 1);
        }
        SECTION("move unsigned char") {
            unsigned char other = 1;
            Json const j = std::move(other);
            REQUIRE(j == 1);
        }
    }
    SECTION("short") {
        SECTION("copy short") {
            short const other = 1;
            Json const j = other;
            REQUIRE(j == 1);
        }
        SECTION("move short") {
            short other = 1;
            Json const j = std::move(other);
            REQUIRE(j == 1);
        }
        SECTION("copy unsigned short") {
            unsigned short const other = 1;
            Json const j = other;
            REQUIRE(j == 1);
        }
        SECTION("move unsigned short") {
            unsigned short other = 1;
            Json const j = std::move(other);
            REQUIRE(j == 1);
        }
    }
    SECTION("int") {
        SECTION("copy int") {
            int const other = 1;
            Json const j = other;
            REQUIRE(j == 1);
        }
        SECTION("move int") {
            int other = 1;
            Json const j = std::move(other);
            REQUIRE(j == 1);
        }
        SECTION("copy unsigned int") {
            unsigned int const other = 1;
            Json const j = other;
            REQUIRE(j == 1);
        }
        SECTION("move unsigned int") {
            unsigned int other = 1;
            Json const j = std::move(other);
            REQUIRE(j == 1);
        }
    }
    SECTION("long") {
        SECTION("copy long") {
            long const other = 1;
            Json const j = other;
            REQUIRE(j == 1);
        }
        SECTION("move long") {
            long other = 1;
            Json const j = std::move(other);
            REQUIRE(j == 1);
        }
        SECTION("copy unsigned long") {
            unsigned long const other = 1;
            Json const j = other;
            REQUIRE(j == 1);
        }
        SECTION("move unsigned long") {
            unsigned long other = 1;
            Json const j = std::move(other);
            REQUIRE(j == 1);
        }
    }
    SECTION("long long") {
        SECTION("copy long long") {
            long long const other = 1;
            Json const j = other;
            REQUIRE(j == 1);
        }
        SECTION("move long long") {
            long long other = 1;
            Json const j = std::move(other);
            REQUIRE(j == 1);
        }
        SECTION("copy unsigned long long") {
            unsigned long long const other = 1;
            Json const j = other;
            REQUIRE(j == 1);
        }
        SECTION("move unsigned long long") {
            unsigned long long other = 1;
            Json const j = std::move(other);
            REQUIRE(j == 1);
        }
    }
    SECTION("floating point") {
        SECTION("copy float") {
            float const other = 1;
            Json const j = other;
            REQUIRE(j == 1);
        }
        SECTION("move float") {
            float other = 1;
            Json const j = std::move(other);
            REQUIRE(j == 1);
        }
        SECTION("copy double") {
            double const other = 1;
            Json const j = other;
            REQUIRE(j == 1);
        }
        SECTION("move double") {
            double other = 1;
            Json const j = std::move(other);
            REQUIRE(j == 1);
        }
        SECTION("copy long double") {
            long double const other = 1;
            Json const j = other;
            REQUIRE(j == 1);
        }
        SECTION("move long double") {
            long double other = 1;
            Json const j = std::move(other);
            REQUIRE(j == 1);
        }
    }
}

TEST_CASE("Convert String construct", "[semantics][construct][String]") {
    SECTION("from string_view") {
        Json const j = u8"string_view"sv;
        REQUIRE(j == u8"string_view"sv);
    }
    SECTION("copy other") {
        String const other = u8"other";
        Json const j = other;
        REQUIRE(j == u8"other"sv);
    }
    SECTION("move other") {
        String other = u8"other";
        Json const j = std::move(other);
        REQUIRE(j == u8"other"sv);
    }
}

TEST_CASE("Convert Array construct", "[semantics][construct][Array]") {
    SECTION("copy other") {
        Array const other = {1, 2, 3};
        Json const j = other;
        REQUIRE(j == Array{1, 2, 3});
    }
    SECTION("move other") {
        Array other = {1, 2, 3};
        Json const j = std::move(other);
        REQUIRE(j == Array{1, 2, 3});
    }
}

TEST_CASE("Convert Object construct", "[semantics][construct][Object]") {
    SECTION("copy other") {
        Object const other = {{u8"a", 1}, {u8"b", 2}};
        Json const j = other;
        REQUIRE(j == Object{{u8"a", 1}, {u8"b", 2}});
    }
    SECTION("move other") {
        Object other = {{u8"a", 1}, {u8"b", 2}};
        Json const j = std::move(other);
        REQUIRE(j == Object{{u8"a", 1}, {u8"b", 2}});
    }
}

TEST_CASE("Copy Json construct", "[semantics][construct][copy]") {
    SECTION("Null") {
        Json const other = Null{};
        Json const j = other;
        REQUIRE(j == Null{});
    }
    SECTION("Boolean") {
        Json const other = true;
        Json const j = other;
        REQUIRE(j == true);
    }
    SECTION("Number") {
        Json const other = 1.2;
        Json const j = other;
        REQUIRE(j == 1.2);
    }
    SECTION("String") {
        Json const other = u8"string"sv;
        Json const j = other;
        REQUIRE(j == u8"string"sv);
    }
    SECTION("Array") {
        Json const other = Array{1, 2, 3};
        Json const j = other;
        REQUIRE(j == Array{1, 2, 3});
    }
    SECTION("Object") {
        Json const other = Object{{u8"a", 1}, {u8"b", 2}};
        Json const j = other;
        REQUIRE(j == Object{{u8"a", 1}, {u8"b", 2}});
    }
}

TEST_CASE("Move Json construct", "[semantics][construct][move]") {
    SECTION("Null") {
        Json other = Null{};
        Json const j = std::move(other);
        REQUIRE(j == Null{});
        REQUIRE(other == Null{});
    }
    SECTION("Boolean") {
        Json other = true;
        Json const j = std::move(other);
        REQUIRE(j == true);
        REQUIRE(other == Null{});
    }
    SECTION("Number") {
        Json other = 1.2;
        Json const j = std::move(other);
        REQUIRE(j == 1.2);
        REQUIRE(other == Null{});
    }
    SECTION("String") {
        Json other = u8"string"sv;
        Json const j = std::move(other);
        REQUIRE(j == u8"string"sv);
        REQUIRE(other == Null{});
    }
    SECTION("Array") {
        Json other = Array{1, 2, 3};
        Json const j = std::move(other);
        REQUIRE(j == Array{1, 2, 3});
        REQUIRE(other == Null{});
    }
    SECTION("Object") {
        Json other = Object{{u8"a", 1}, {u8"b", 2}};
        Json const j = std::move(other);
        REQUIRE(j == Object{{u8"a", 1}, {u8"b", 2}});
        REQUIRE(other == Null{});
    }
}
