#include "common.hpp"

static Json loads(StringView txt, int max_depth = 4) {
    auto result = Json::loads(txt, max_depth);
    return result;
}

TEST_CASE("loads bad json", "[text][loads]") {
    SECTION("Empty") {
        REQUIRE_THROWS_WITH(loads(u8""sv), "Unexpected EOF in json! @ 0:0");
        REQUIRE_THROWS_WITH(loads(u8"//"sv), "Unexpected EOF in json! @ 0:2");
        REQUIRE_THROWS_WITH(loads(u8"/**/"sv), "Unexpected EOF in json! @ 0:4");
    }
    SECTION("Boolean") { REQUIRE_THROWS_WITH(loads(u8"tru"sv), "Bad character! @ 0:0"); }
    SECTION("Number") { REQUIRE_THROWS_WITH(loads(u8"1.2.1"sv), "Bad number! @ 0:3"); }
    SECTION("Array") { REQUIRE_THROWS_WITH(loads(u8"["sv), "Unexpected EOF in array! @ 0:1"); }
    SECTION("Object") { REQUIRE_THROWS_WITH(loads(u8"{"sv), "Unexpected EOF in object! @ 0:1"); }
}
