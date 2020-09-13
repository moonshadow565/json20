#include "common.hpp"

TEMPLATE_TEST_CASE(
    "Null can not be equal to other json values", "[value][equal][Null]", Boolean, Number, String, Array, Object) {
    Json const j = TestType{};
    REQUIRE_FALSE(j == Null{});
    REQUIRE_FALSE(Null{} == j);
    REQUIRE(j != Null{});
    REQUIRE(Null{} != j);
}
TEST_CASE("is equal Null{} to Null{}", "[value][equal][Null]") {
    Json const j = Null{};
    REQUIRE(j == Null{});
    REQUIRE(Null{} == j);
}

TEMPLATE_TEST_CASE(
    "Boolean can not be equal to other json values", "[value][equal][Boolean]", Null, Number, String, Array, Object) {
    Json const j = TestType{};
    REQUIRE_FALSE(j == Boolean{});
    REQUIRE_FALSE(Boolean{} == j);
}
TEST_CASE("is equal Boolean{} to Boolean{}", "[value][equal][Boolean]") {
    Json const j = Boolean{};
    REQUIRE(j == Boolean{});
    REQUIRE(Boolean{} == j);
}

TEMPLATE_TEST_CASE(
    "Number can not be equal to other json values", "[value][equal][Number]", Null, Boolean, String, Array, Object) {
    Json const j = TestType{};
    REQUIRE_FALSE(j == Number{});
    REQUIRE_FALSE(Number{} == j);
}
TEST_CASE("is equal Number{} to Number{}", "[value][equal][Number]") {
    Json const j = Number{};
    REQUIRE(j == Number{});
    REQUIRE(Number{} == j);
}

TEMPLATE_TEST_CASE(
    "String can not be equal to other json values", "[value][equal][String]", Null, Boolean, Number, Array, Object) {
    Json const j = TestType{};
    REQUIRE_FALSE(j == String{});
    REQUIRE_FALSE(String{} == j);
}
TEST_CASE("is equal String{} to String{}", "[value][equal][String]") {
    Json const j = String{};
    REQUIRE(j == String{});
    REQUIRE(String{} == j);
}

TEMPLATE_TEST_CASE(
    "Array can not be equal to other json values", "[value][equal][Array]", Null, Boolean, Number, String, Object) {
    Json const j = TestType{};
    REQUIRE_FALSE(j == Array{});
    REQUIRE_FALSE(Array{} == j);
}
TEST_CASE("is equal Array{} to Array{}", "[value][equal][Array]") {
    Json const j = Array{};
    REQUIRE(j == Array{});
    REQUIRE(Array{} == j);
}

TEMPLATE_TEST_CASE(
    "Object can not be equal to other json values", "[value][equal][Object]", Null, Boolean, Number, String, Array) {
    Json const j = TestType{};
    REQUIRE_FALSE(j == Object{});
    REQUIRE_FALSE(Object{} == j);
}
TEST_CASE("is equal Object{} to Object{}", "[value][equal][Object]") {
    Json const j = Object{};
    REQUIRE(j == Object{});
    REQUIRE(Object{} == j);
}
