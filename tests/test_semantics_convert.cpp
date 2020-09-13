#include "common.hpp"

TEST_CASE("Convert into optional", "[semantics][convert][optional]") {
    REQUIRE(Json(Null{}).into<std::optional<int>>() == std::nullopt);
    REQUIRE(Json(5).into<std::optional<int>>() == 5);
}

TEST_CASE("Convert into shared_ptr", "[semantics][convert][shared_ptr]") {
    REQUIRE(Json(Null{}).into<std::shared_ptr<int>>() == nullptr);
    REQUIRE(*Json(5).into<std::shared_ptr<int>>() == 5);
}

TEST_CASE("Convert into unique_ptr", "[semantics][convert][unique_ptr]") {
    REQUIRE(Json(Null{}).into<std::unique_ptr<int>>() == nullptr);
    REQUIRE(*Json(5).into<std::unique_ptr<int>>() == 5);
}
