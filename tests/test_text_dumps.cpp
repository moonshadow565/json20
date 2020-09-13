#include "common.hpp"

static String dumps(Json value, int indent = 0) {
    auto result = value.dumps(indent);
    return result;
}

TEST_CASE("dumps json", "[text][dumps]") {
    SECTION("Null") { REQUIRE(dumps(Null{}) == u8"null"sv); }
    SECTION("Boolean") {
        REQUIRE(dumps(false) == u8"false"sv);
        REQUIRE(dumps(true) == u8"true"sv);
    }
    SECTION("Number") {
        REQUIRE(dumps(0.0) == u8"0"sv);
        REQUIRE(dumps(-1.0) == u8"-1"sv);
        REQUIRE(dumps(1.2) == u8"1.2"sv);
        REQUIRE(dumps(Infinity) == u8"Infinity"sv);
        REQUIRE(dumps(-Infinity) == u8"-Infinity"sv);
        REQUIRE(dumps(NaN) == u8"NaN"sv);
    }
    SECTION("Strings") {
        REQUIRE(dumps(u8"abc"sv) == u8R"("abc")"sv);
        REQUIRE(dumps(u8"ab'c"sv) == u8R"("ab'c")"sv);
    }
    SECTION("Strings with escape") {
        REQUIRE(dumps(u8R"(ab"c)"sv) == u8R"("ab\"c")"sv);
        REQUIRE(dumps(u8"\\\b\f\n\r\t\v\0\x0f"sv) == u8R"("\\\b\f\n\r\t\v\x00\x0F")"sv);
    }
    SECTION("Arrays") {
        REQUIRE(dumps(Array{}) == u8"[]"sv);
        REQUIRE(dumps(Array{1.0}) == u8"[1]"sv);
        REQUIRE(dumps(Array{1.0, 2.0}) == u8"[1,2]"sv);
        REQUIRE(dumps(Array{1.0, Array{2.0}}) == u8"[1,[2]]"sv);
    }
    SECTION("Objects") {
        REQUIRE(dumps(Object{}) == u8"{}"sv);
        REQUIRE(dumps(Object{{u8"a", 1}}) == u8R"({"a":1})"sv);
        REQUIRE(dumps(Object{{u8"", 0.0}}) == u8R"({"":0})"sv);
        REQUIRE(dumps(Object{{u8"a", Object{{u8"b", 2}}}}) == u8R"({"a":{"b":2}})"sv);
        REQUIRE(dumps(Object{{u8"a", 1}, {u8"b", 2}}) == u8R"({"a":1,"b":2})"sv);
    }
    SECTION("Objects with escaped property name") {
        REQUIRE(dumps(Object{{u8"\u03B1", 1}}) == u8R"({"\u03B1":1})"sv);
        REQUIRE(dumps(Object{{u8"\\\b\f\n\r\t\v\0\x01"s, 1}}) == u8R"({"\\\b\f\n\r\t\v\x00\x01":1})"sv);
    }
}
