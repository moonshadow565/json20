#include "common.hpp"

TEMPLATE_TEST_CASE("Destructor", "[semantics][destruct]", Null, Boolean, Number, String, Array, Object) {
    std::aligned_storage_t<sizeof(Json), alignof(Json)> storage;
    REQUIRE_NOTHROW(new (&storage) Json(TestType{}));
    REQUIRE_NOTHROW(std::launder(reinterpret_cast<Json*>(&storage))->~Json());
}
