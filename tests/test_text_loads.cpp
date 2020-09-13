#include "common.hpp"

static Json loads(StringView txt, int max_depth = 4) {
    auto result = Json::loads(txt, max_depth);
    return result;
}

TEST_CASE("loads good json", "[text][loads]") {
    SECTION("depth limit") {
        REQUIRE(loads(u8"[[true]]", 2) == Array{{Array{{true}}}});
        REQUIRE_THROWS_AS(loads(u8"[[true]]", 1), Json::ReadError);
    }
    SECTION("Null") { REQUIRE(loads(u8"null"sv) == Null{}); }
    SECTION("Boolean") {
        REQUIRE(loads(u8"true"sv) == true);
        REQUIRE(loads(u8"false"sv) == false);
    }
    SECTION("Number") {
        REQUIRE(loads(u8"1"sv) == 1.0);
        REQUIRE(loads(u8"0x1"sv) == 1.0);
        REQUIRE(loads(u8"1.2"sv) == 1.2);
        REQUIRE(loads(u8"+1.23e100"sv) == +1.23e100);
        REQUIRE(loads(u8"123"sv) == 123);
        REQUIRE(loads(u8"-1"sv) == -1.0);
        REQUIRE(loads(u8"+1"sv) == +1.0);
        REQUIRE(loads(u8"1."sv) == 1.);
        REQUIRE(loads(u8".1"sv) == .1);
        REQUIRE(loads(u8"0010"sv) == 10.0);
        REQUIRE(loads(u8"1e1"sv) == 10);
        REQUIRE(loads(u8"1e-1"sv) == 0.1);
        REQUIRE(loads(u8"1e+1"sv) == 10);
        REQUIRE(loads(u8"0x10"sv) == 16);
        REQUIRE(loads(u8"-0x10"sv) == -16);
        REQUIRE(loads(u8"+0x10"sv) == +16);
        REQUIRE(loads(u8"Infinity"sv) == Infinity);
        REQUIRE(loads(u8"-Infinity"sv) == -Infinity);
        REQUIRE(std::isnan(loads(u8"NaN"sv).get<Number>()));
        REQUIRE(std::isnan(loads(u8"-NaN"sv).get<Number>()));
    }
    SECTION("String") {
        REQUIRE(loads(u8R"("abc")"sv) == u8"abc"sv);
        REQUIRE(loads(u8"'abc'"sv) == u8"abc"sv);
        REQUIRE(loads(u8R"('"')"sv) == u8R"(")"sv);
        REQUIRE(loads(u8R"("'")"sv) == u8"'"sv);
        REQUIRE(loads(u8"'\u2028\u2029'"sv) == u8"\u2028\u2029"sv);
    }
    SECTION("String escapes") {
        REQUIRE(loads(u8R"("\"")"sv) == u8R"(")"sv);
        REQUIRE(loads(u8R"('\'')"sv) == u8"'"sv);
        REQUIRE(loads(u8R"('\b\f\n\r\t\v\0\x0f\a')"sv) == u8"\b\f\n\r\t\v\0\x0f\a"sv);
        REQUIRE(loads(u8"'\\\n\\\r\n\\\r'") == u8""sv);
        REQUIRE(loads(u8"'\\\xE2\x80\xA8\\\xE2\x80\xA9'") == u8""sv);
        REQUIRE(loads(u8"'\\u01fF'") == u8"\xC7\xBF"sv);
    }
    SECTION("Array") {
        REQUIRE(loads(u8"[]"sv) == Array{});
        REQUIRE(loads(u8"[1]"sv) == Array{1});
        REQUIRE(loads(u8"[1,2]"sv) == Array{1, 2});
        REQUIRE(loads(u8"[1,]"sv) == Array{1});
        REQUIRE(loads(u8"[1,[2,3]]"sv) == Array{1, Array{2, 3}});
    }
    SECTION("Object") {
        REQUIRE(loads(u8"{}"sv) == Object{});
        REQUIRE(loads(u8R"({"a":1})"sv) == Object{{u8"a", 1}});
        REQUIRE(loads(u8"{'a':1}"sv) == Object{{u8"a", 1}});
        REQUIRE(loads(u8"{a:1}"sv) == Object{{u8"a", 1}});
        REQUIRE(loads(u8"{a:1,}"sv) == Object{{u8"a", 1}});
        REQUIRE(loads(u8"{a:{b:2}}"sv) == Object{
                                              {u8"a", Object{{u8"b", 2}}},
                                          });
        REQUIRE(loads(u8"{a: 1, b: 2}"sv) == Object{
                                                 {u8"a", 1},
                                                 {u8"b", 2},
                                             });
        REQUIRE(loads(u8"{$a$:1}"sv) == Object{{
                                            u8"$a$",
                                            1,
                                        }});
        REQUIRE(loads(u8"{_a_:1}"sv) == Object{{
                                            u8"_a_",
                                            1,
                                        }});
    }
    SECTION("Object with unicode property names") {
        REQUIRE(loads(u8"{\u03B1:1}"sv) == Object{{u8"\u03B1"s, 1}});
        REQUIRE(loads(u8"{a\u200D:1}"sv) == Object{{u8"a\u200D"s, 1}});
    }
    SECTION("Object with escaped property names") { REQUIRE(loads(u8"{\\u0061\\u0062:1}"sv) == Object{{u8"ab"s, 1}}); }
    SECTION("Comments") {
        REQUIRE(loads(u8"[//comment\n]"sv) == Array{});
        REQUIRE(loads(u8"[/*\ncomment\n**/]"sv) == Array{});
        REQUIRE(loads(u8"[/*/*comment*/*/]"sv) == Array{});
        REQUIRE(loads(u8"[]//comment"sv) == Array{});
    }
    SECTION("Whitespace") {
        REQUIRE(loads(u8"[\t \v \f \n \r]"sv) == Array{});
        REQUIRE(loads(u8"[\u00A0\u2003\u2028\u2029\uFEFF]"sv) == Array{});
    }
}
