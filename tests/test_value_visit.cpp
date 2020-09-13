#include "common.hpp"

TEMPLATE_TEST_CASE("value visit", "[value][visit]", Null, Boolean, Number, String, Array, Object) {
    SECTION("Json mutable") {
        Json j = TestType{};
        bool visited_good = false;
        bool visited_bad = false;
        j.visit([&]<typename V>(V&) {
            if constexpr (std::is_same_v<V, TestType>) {
                visited_good = true;
            } else {
                visited_bad = true;
            }
        });
        REQUIRE(visited_good);
        REQUIRE_FALSE(visited_bad);
    }
    SECTION("Json const") {
        Json const j = TestType{};
        bool visited_good = false;
        bool visited_bad = false;
        j.visit([&]<typename V>(V const&) {
            if constexpr (std::is_same_v<V, TestType>) {
                visited_good = true;
            } else {
                visited_bad = true;
            }
        });
        REQUIRE(visited_good);
        REQUIRE_FALSE(visited_bad);
    }
}
