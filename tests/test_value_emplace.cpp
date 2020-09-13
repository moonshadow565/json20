#include "common.hpp"

TEMPLATE_TEST_CASE("emplace<TestType> returns reference to new object",
                   "[value][emplace]",
                   Null,
                   Boolean,
                   Number,
                   String,
                   Array,
                   Object) {
    Json j = {};
    auto& ref = j.emplace<TestType>();
    REQUIRE(j.get_if<TestType>() == &ref);
}
