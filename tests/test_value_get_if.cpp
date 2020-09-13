#include "common.hpp"

TEMPLATE_TEST_CASE("get_if<Null> returns nullptr for other json values",
                   "[value][get_if][Null]",
                   Boolean,
                   Number,
                   String,
                   Array,
                   Object) {
    SECTION("Json mutable") {
        Json j = TestType{};
        REQUIRE(j.get_if<Null>() == nullptr);
    }
    SECTION("Json const") {
        Json const j = TestType{};
        REQUIRE(j.get_if<Null>() == nullptr);
    }
}
TEST_CASE("get_if<Null> returns valid pointer for Null{} json value", "[value][get_if][Null]") {
    SECTION("Json mutable") {
        Json j = Null{};
        REQUIRE(j.get_if<Null>() != nullptr);
    }
    SECTION("Json const") {
        Json const j = Null{};
        REQUIRE(j.get_if<Null>() != nullptr);
    }
}

TEMPLATE_TEST_CASE("get_if<Boolean> returns nullptr for other json values",
                   "[value][get_if][Boolean]",
                   Null,
                   Number,
                   String,
                   Array,
                   Object) {
    SECTION("Json mutable") {
        Json j = TestType{};
        REQUIRE(j.get_if<Boolean>() == nullptr);
    }
    SECTION("Json const") {
        Json const j = TestType{};
        REQUIRE(j.get_if<Boolean>() == nullptr);
    }
}
TEST_CASE("get_if<Boolean> returns valid pointer for Boolean{} json value", "[value][get_if][Boolean]") {
    SECTION("Json mutable") {
        Json j = Boolean{};
        REQUIRE(j.get_if<Boolean>() != nullptr);
    }
    SECTION("Json const") {
        Json const j = Boolean{};
        REQUIRE(j.get_if<Boolean>() != nullptr);
    }
}

TEMPLATE_TEST_CASE("get_if<Number> returns nullptr for other json values",
                   "[value][get_if][Number]",
                   Null,
                   Boolean,
                   String,
                   Array,
                   Object) {
    SECTION("Json mutable") {
        Json j = TestType{};
        REQUIRE(j.get_if<Number>() == nullptr);
    }
    SECTION("Json const") {
        Json const j = TestType{};
        REQUIRE(j.get_if<Number>() == nullptr);
    }
}
TEST_CASE("get_if<Number> returns valid pointer for Number{} json value", "[value][get_if][Number]") {
    SECTION("Json mutable") {
        Json j = Number{};
        REQUIRE(j.get_if<Number>() != nullptr);
    }
    SECTION("Json const") {
        Json const j = Number{};
        REQUIRE(j.get_if<Number>() != nullptr);
    }
}

TEMPLATE_TEST_CASE("get_if<String> returns nullptr for other json values",
                   "[value][get_if][String]",
                   Null,
                   Boolean,
                   Number,
                   Array,
                   Object) {
    SECTION("Json mutable") {
        Json j = TestType{};
        REQUIRE(j.get_if<String>() == nullptr);
    }
    SECTION("Json const") {
        Json const j = TestType{};
        REQUIRE(j.get_if<String>() == nullptr);
    }
}
TEST_CASE("get_if<String> returns valid pointer for String{} json value", "[value][get_if][String]") {
    SECTION("Json mutable") {
        Json j = String{};
        REQUIRE(j.get_if<String>() != nullptr);
    }
    SECTION("Json const") {
        Json const j = String{};
        REQUIRE(j.get_if<String>() != nullptr);
    }
}

TEMPLATE_TEST_CASE("get_if<Array> returns nullptr for other json values",
                   "[value][get_if][Array]",
                   Null,
                   Boolean,
                   Number,
                   String,
                   Object) {
    SECTION("Json mutable") {
        Json j = TestType{};
        REQUIRE(j.get_if<Array>() == nullptr);
    }
    SECTION("Json const") {
        Json const j = TestType{};
        REQUIRE(j.get_if<Array>() == nullptr);
    }
}
TEST_CASE("get_if<Array> returns valid pointer for Array{} json value", "[value][get_if][Array]") {
    SECTION("Json mutable") {
        Json j = Array{};
        REQUIRE(j.get_if<Array>() != nullptr);
    }
    SECTION("Json const") {
        Json const j = Array{};
        REQUIRE(j.get_if<Array>() != nullptr);
    }
}

TEMPLATE_TEST_CASE("get_if<Object> returns nullptr for other json values",
                   "[value][get_if][Object]",
                   Null,
                   Boolean,
                   Number,
                   String,
                   Array) {
    SECTION("Json mutable") {
        Json j = TestType{};
        REQUIRE(j.get_if<Object>() == nullptr);
    }
    SECTION("Json const") {
        Json const j = TestType{};
        REQUIRE(j.get_if<Object>() == nullptr);
    }
}
TEST_CASE("get_if<Object> returns valid pointer for Object{} json value", "[value][get_if][Object]") {
    SECTION("Json mutable") {
        Json j = Object{};
        REQUIRE(j.get_if<Object>() != nullptr);
    }
    SECTION("Json const") {
        Json const j = Object{};
        REQUIRE(j.get_if<Object>() != nullptr);
    }
}
