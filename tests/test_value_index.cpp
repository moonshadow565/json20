#include "common.hpp"

TEST_CASE("operator[size_t] indexes json array", "[value][at][Array]") {
    Json j = Array{1, 2, 3};
    SECTION("indexing should succeed and return the element") {
        REQUIRE_NOTHROW(j[1]);
        REQUIRE(j[1] == 2);
    }
    SECTION("bad index will insert elements up to index") {
        REQUIRE(j.get<Array>().size() == 3);
        REQUIRE_NOTHROW(j[3]);
        REQUIRE(j.get<Array>().size() == 4);
    }
    SECTION("elements can be changed through returned reference") {
        j[1] = 20.0;
        REQUIRE(j[1] == 20.0);
    }
}
TEMPLATE_TEST_CASE("operator[size_t] throws std::bad_cast when json doesn't contain array",
                   "[value][at][Array]",
                   Null,
                   Boolean,
                   Number,
                   String,
                   Object) {
    Json j = TestType{};
    REQUIRE_THROWS_AS(j[0], std::bad_cast);
}

TEST_CASE("operator[std::string] indexes json object", "[value][at][Object]") {
    SECTION("Json mutable") {
        Json j = Object{{u8"a", 1}, {u8"b", 2}, {u8"c", 3}};
        SECTION("indexing should succeed and return the element") {
            REQUIRE_NOTHROW(j[u8"b"]);
            REQUIRE(j[u8"b"] == 2);
        }
        SECTION("bad key will insert new key/value pair") {
            REQUIRE(j.get<Object>().size() == 3);
            REQUIRE_NOTHROW(j[u8"d"]);
            REQUIRE(j.get<Object>().size() == 4);
        }
        SECTION("elements can be changed through returned reference") {
            j[u8"b"] = 20.0;
            REQUIRE(j[u8"b"] == 20.0);
        }
    }
}
TEMPLATE_TEST_CASE("operator[std::string] throws std::bad_cast when json doesn't contain object",
                   "[value][at][Object]",
                   Null,
                   Boolean,
                   Number,
                   String,
                   Array) {
    Json j = TestType{};
    REQUIRE_THROWS_AS(j[u8"a"], std::bad_cast);
}
