#include "common.hpp"

TEST_CASE("at(size_t) indexes json array", "[value][at][Array]") {
    SECTION("Json mutable") {
        Json j = Array{1, 2, 3};
        SECTION("indexing should succeed and return the element") {
            REQUIRE_NOTHROW(j.at(1));
            REQUIRE(j.at(1) == 2);
        }
        SECTION("bad index will throw std::out_of_range") { REQUIRE_THROWS_AS(j.at(3), std::out_of_range); }
        SECTION("elements can be changed through returned reference") {
            j.at(1) = Json(20);
            REQUIRE(j.at(1) == 20);
        }
    }
    SECTION("Json const") {
        Json const j = Array{1, 2, 3};
        SECTION("indexing should succeed and return the element") {
            REQUIRE_NOTHROW(j.at(1));
            REQUIRE(j.at(1) == 2);
        }
        SECTION("bad index will throw std::out_of_range") { REQUIRE_THROWS_AS(j.at(3), std::out_of_range); }
    }
}
TEMPLATE_TEST_CASE("at(size_t) throws std::bad_cast when json doesn't contain array",
                   "[value][at][Array]",
                   Null,
                   Boolean,
                   Number,
                   String,
                   Object) {
    SECTION("Json mutable") {
        Json j = TestType{};
        REQUIRE_THROWS_AS(j.at(0), std::bad_cast);
    }
    SECTION("Json const") {
        Json const j = TestType{};
        REQUIRE_THROWS_AS(j.at(0), std::bad_cast);
    }
}

TEST_CASE("at(std::string) indexes json object", "[value][at][Object]") {
    SECTION("Json mutable") {
        Json j = Object{{u8"a", 1}, {u8"b", 2}, {u8"c", 3}};
        SECTION("indexing should succeed and return the element") {
            REQUIRE_NOTHROW(j.at(u8"b"));
            REQUIRE(j.at(u8"b") == 2);
        }
        SECTION("bad index will throw std::out_of_range") { REQUIRE_THROWS_AS(j.at(u8"d"), std::out_of_range); }
        SECTION("elements can be changed through returned reference") {
            j.at(u8"b") = Json(20);
            REQUIRE(j.at(u8"b") == 20);
        }
    }
    SECTION("Json const") {
        Json j = Object{{u8"a", 1}, {u8"b", 2}, {u8"c", 3}};
        SECTION("indexing should succeed and return the element") {
            REQUIRE_NOTHROW(j.at(u8"b"));
            REQUIRE(j.at(u8"b") == 2);
        }
        SECTION("bad index will throw std::out_of_range") { REQUIRE_THROWS_AS(j.at(u8"d"), std::out_of_range); }
    }
}
TEMPLATE_TEST_CASE("at(std::string) throws std::bad_cast when json doesn't contain object",
                   "[value][at][Object]",
                   Null,
                   Boolean,
                   Number,
                   String,
                   Array) {
    SECTION("Json mutable") {
        Json j = TestType{};
        REQUIRE_THROWS_AS(j.at(u8"a"), std::bad_cast);
    }
    SECTION("Json const") {
        Json const j = TestType{};
        REQUIRE_THROWS_AS(j.at(u8"a"), std::bad_cast);
    }
}
