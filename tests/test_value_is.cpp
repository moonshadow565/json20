#include "common.hpp"

TEMPLATE_TEST_CASE(
    "is<Null> returns false for other json values", "[value][is][Null]", Boolean, Number, String, Array, Object) {
    Json const j = TestType{};
    REQUIRE_FALSE(j.is<Null>());
}
TEST_CASE("is<Null> returns true for Null{} json value", "[value][is][Null]") {
    Json const j = Null{};
    REQUIRE(j.is<Null>());
}

TEMPLATE_TEST_CASE(
    "is<Boolean> returns false for other json values", "[value][is][Boolean]", Null, Number, String, Array, Object) {
    Json const j = TestType{};
    REQUIRE_FALSE(j.is<Boolean>());
}
TEST_CASE("is<Boolean> returns true for Boolean{} json value", "[value][is][Boolean]") {
    Json const j = Boolean{};
    REQUIRE(j.is<Boolean>());
}

TEMPLATE_TEST_CASE(
    "is<Number> returns false for other json values", "[value][is][Number]", Null, Boolean, String, Array, Object) {
    Json const j = TestType{};
    REQUIRE_FALSE(j.is<Number>());
}
TEST_CASE("is<Number> returns true for Number{} json value", "[value][is][Number]") {
    Json const j = Number{};
    REQUIRE(j.is<Number>());
}

TEMPLATE_TEST_CASE(
    "is<String> returns false for other json values", "[value][is][String]", Null, Boolean, Number, Array, Object) {
    Json const j = TestType{};
    REQUIRE_FALSE(j.is<String>());
}
TEST_CASE("is<String> returns true for String{} json value", "[value][is][String]") {
    Json const j = String{};
    REQUIRE(j.is<String>());
}

TEMPLATE_TEST_CASE(
    "is<Array> returns false for other json values", "[value][is][Array]", Null, Boolean, Number, String, Object) {
    Json const j = TestType{};
    REQUIRE_FALSE(j.is<Array>());
}
TEST_CASE("is<Array> returns true for Array{} json value", "[value][is][Array]") {
    Json const j = Array{};
    REQUIRE(j.is<Array>());
}

TEMPLATE_TEST_CASE(
    "is<Object> returns false for other json values", "[value][is][Object]", Null, Boolean, Number, String, Array) {
    Json const j = TestType{};
    REQUIRE_FALSE(j.is<Object>());
}
TEST_CASE("is<Object> returns true for Object{} json value", "[value][is][Object]") {
    Json const j = Object{};
    REQUIRE(j.is<Object>());
}
