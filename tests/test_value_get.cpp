#include "common.hpp"

TEMPLATE_TEST_CASE("get<Null> throws std::bad_cast for other json values",
                   "[value][get][Null]",
                   Boolean,
                   Number,
                   String,
                   Array,
                   Object) {
    SECTION("Json mutable") {
        Json j = TestType{};
        REQUIRE_THROWS_AS(j.get<Null>(), std::bad_cast);
    }
    SECTION("Json const") {
        Json const j = TestType{};
        REQUIRE_THROWS_AS(j.get<Null>(), std::bad_cast);
    }
}
TEST_CASE("get<Null> returns valid reference for Null{} json value", "[value][get][Null]") {
    SECTION("Json mutable") {
        Json j = Null{};
        REQUIRE_NOTHROW(j.get<Null>());
    }
    SECTION("Json const") {
        Json const j = Null{};
        REQUIRE_NOTHROW(j.get<Null>());
    }
}

TEMPLATE_TEST_CASE("get<Boolean> throws std::bad_cast for other json values",
                   "[value][get][Boolean]",
                   Null,
                   Number,
                   String,
                   Array,
                   Object) {
    SECTION("Json mutable") {
        Json j = TestType{};
        REQUIRE_THROWS_AS(j.get<Boolean>(), std::bad_cast);
    }
    SECTION("Json const") {
        Json const j = TestType{};
        REQUIRE_THROWS_AS(j.get<Boolean>(), std::bad_cast);
    }
}
TEST_CASE("get<Boolean> returns valid reference for Boolean{} json value", "[value][get][Boolean]") {
    SECTION("Json mutable") {
        Json j = Boolean{};
        REQUIRE_NOTHROW(j.get<Boolean>());
    }
    SECTION("Json const") {
        Json const j = Boolean{};
        REQUIRE_NOTHROW(j.get<Boolean>());
    }
}

TEMPLATE_TEST_CASE("get<Number> throws std::bad_cast for other json values",
                   "[value][get][Number]",
                   Null,
                   Boolean,
                   String,
                   Array,
                   Object) {
    SECTION("Json mutable") {
        Json j = TestType{};
        REQUIRE_THROWS_AS(j.get<Number>(), std::bad_cast);
    }
    SECTION("Json const") {
        Json const j = TestType{};
        REQUIRE_THROWS_AS(j.get<Number>(), std::bad_cast);
    }
}
TEST_CASE("get<Number> returns valid reference for Number{} json value", "[value][get][Number]") {
    SECTION("Json mutable") {
        Json j = Number{};
        REQUIRE_NOTHROW(j.get<Number>());
    }
    SECTION("Json const") {
        Json const j = Number{};
        REQUIRE_NOTHROW(j.get<Number>());
    }
}

TEMPLATE_TEST_CASE("get<String> throws std::bad_cast for other json values",
                   "[value][get][String]",
                   Null,
                   Boolean,
                   Number,
                   Array,
                   Object) {
    SECTION("Json mutable") {
        Json j = TestType{};
        REQUIRE_THROWS_AS(j.get<String>(), std::bad_cast);
    }
    SECTION("Json const") {
        Json const j = TestType{};
        REQUIRE_THROWS_AS(j.get<String>(), std::bad_cast);
    }
}
TEST_CASE("get<String> returns valid reference for String{} json value", "[value][get][String]") {
    SECTION("Json mutable") {
        Json j = String{};
        REQUIRE_NOTHROW(j.get<String>());
    }
    SECTION("Json const") {
        Json const j = String{};
        REQUIRE_NOTHROW(j.get<String>());
    }
}

TEMPLATE_TEST_CASE("get<Array> throws std::bad_cast for other json values",
                   "[value][get][Array]",
                   Null,
                   Boolean,
                   Number,
                   String,
                   Object) {
    SECTION("Json mutable") {
        Json j = TestType{};
        REQUIRE_THROWS_AS(j.get<Array>(), std::bad_cast);
    }
    SECTION("Json const") {
        Json const j = TestType{};
        REQUIRE_THROWS_AS(j.get<Array>(), std::bad_cast);
    }
}
TEST_CASE("get<Array> returns valid reference for Array{} json value", "[value][get][Array]") {
    SECTION("Json mutable") {
        Json j = Array{};
        REQUIRE_NOTHROW(j.get<Array>());
    }
    SECTION("Json const") {
        Json const j = Array{};
        REQUIRE_NOTHROW(j.get<Array>());
    }
}

TEMPLATE_TEST_CASE("get<Object> throws std::bad_cast for other json values",
                   "[value][get][Object]",
                   Null,
                   Boolean,
                   Number,
                   String,
                   Array) {
    SECTION("Json mutable") {
        Json j = TestType{};
        REQUIRE_THROWS_AS(j.get<Object>(), std::bad_cast);
    }
    SECTION("Json const") {
        Json const j = TestType{};
        REQUIRE_THROWS_AS(j.get<Object>(), std::bad_cast);
    }
}
TEST_CASE("get<Object> returns valid reference for Object{} json value", "[value][get][Object]") {
    SECTION("Json mutable") {
        Json j = Object{};
        REQUIRE_NOTHROW(j.get<Object>());
    }
    SECTION("Json const") {
        Json const j = Object{};
        REQUIRE_NOTHROW(j.get<Object>());
    }
}
