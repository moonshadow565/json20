#include "common.hpp"

TEST_CASE("Convert Null asign", "[semantics][asign][Null]") {
    Json j = 0;
    SECTION("nullptr literal") {
        j = nullptr;
        REQUIRE(j == Null{});
    }
    SECTION("copy") {
        Null const other = {};
        j = other;
        REQUIRE(j == Null{});
    }
    SECTION("move") {
        Null other = {};
        j = std::move(other);
        REQUIRE(j == Null{});
    }
}

TEST_CASE("Convert Boolean asign", "[semantics][asign][Boolean]") {
    Json j = 0;
    SECTION("false literal") {
        j = false;
        REQUIRE(j == false);
    }
    SECTION("true literal") {
        j = true;
        REQUIRE(j == true);
    }
    SECTION("copy") {
        Boolean const other = true;
        j = other;
        REQUIRE(j == true);
    }
    SECTION("move") {
        Boolean other = true;
        j = std::move(other);
        REQUIRE(j == true);
    }
}

TEST_CASE("Convert Number asign", "[semantics][asign][Number]") {
    Json j;
    SECTION("0 literal") {
        j = 0;
        REQUIRE(j == 0.0);
    }
    SECTION("char") {
        SECTION("copy char") {
            char const other = 1;
            j = other;
            REQUIRE(j == 1);
        }
        SECTION("move char") {
            char other = 1;
            j = std::move(other);
            REQUIRE(j == 1);
        }
        SECTION("copy signed char") {
            signed char const other = 1;
            j = other;
            REQUIRE(j == 1);
        }
        SECTION("move signed char") {
            signed char other = 1;
            j = std::move(other);
            REQUIRE(j == 1);
        }
        SECTION("copy unsigned char") {
            unsigned char const other = 1;
            j = other;
            REQUIRE(j == 1);
        }
        SECTION("move unsigned char") {
            unsigned char other = 1;
            j = std::move(other);
            REQUIRE(j == 1);
        }
    }
    SECTION("short") {
        SECTION("copy short") {
            short const other = 1;
            j = other;
            REQUIRE(j == 1);
        }
        SECTION("move short") {
            short other = 1;
            j = std::move(other);
            REQUIRE(j == 1);
        }
        SECTION("copy unsigned short") {
            unsigned short const other = 1;
            j = other;
            REQUIRE(j == 1);
        }
        SECTION("move unsigned short") {
            unsigned short other = 1;
            j = std::move(other);
            REQUIRE(j == 1);
        }
    }
    SECTION("int") {
        SECTION("copy int") {
            int const other = 1;
            j = other;
            REQUIRE(j == 1);
        }
        SECTION("move int") {
            int other = 1;
            j = std::move(other);
            REQUIRE(j == 1);
        }
        SECTION("copy unsigned int") {
            unsigned int const other = 1;
            j = other;
            REQUIRE(j == 1);
        }
        SECTION("move unsigned int") {
            unsigned int other = 1;
            j = std::move(other);
            REQUIRE(j == 1);
        }
    }
    SECTION("long") {
        SECTION("copy long") {
            long const other = 1;
            j = other;
            REQUIRE(j == 1);
        }
        SECTION("move long") {
            long other = 1;
            j = std::move(other);
            REQUIRE(j == 1);
        }
        SECTION("copy unsigned long") {
            unsigned long const other = 1;
            j = other;
            REQUIRE(j == 1);
        }
        SECTION("move unsigned long") {
            unsigned long other = 1;
            j = std::move(other);
            REQUIRE(j == 1);
        }
    }
    SECTION("long long") {
        SECTION("copy long long") {
            long long const other = 1;
            j = other;
            REQUIRE(j == 1);
        }
        SECTION("move long long") {
            long long other = 1;
            j = std::move(other);
            REQUIRE(j == 1);
        }
        SECTION("copy unsigned long long") {
            unsigned long long const other = 1;
            j = other;
            REQUIRE(j == 1);
        }
        SECTION("move unsigned long long") {
            unsigned long long other = 1;
            j = std::move(other);
            REQUIRE(j == 1);
        }
    }
    SECTION("floating point") {
        SECTION("copy float") {
            float const other = 1;
            j = other;
            REQUIRE(j == 1);
        }
        SECTION("move float") {
            float other = 1;
            j = std::move(other);
            REQUIRE(j == 1);
        }
        SECTION("copy double") {
            double const other = 1;
            j = other;
            REQUIRE(j == 1);
        }
        SECTION("move double") {
            double other = 1;
            j = std::move(other);
            REQUIRE(j == 1);
        }
        SECTION("copy long double") {
            long double const other = 1;
            j = other;
            REQUIRE(j == 1);
        }
        SECTION("move long double") {
            long double other = 1;
            j = std::move(other);
            REQUIRE(j == 1);
        }
    }
}

TEST_CASE("Convert String asign", "[semantics][asign][String]") {
    Json j;
    SECTION("from string_view") {
        j = u8"string_view"sv;
        REQUIRE(j == u8"string_view"sv);
    }
    SECTION("copy other") {
        String const other = u8"other";
        j = other;
        REQUIRE(j == u8"other"sv);
    }
    SECTION("move other") {
        String other = u8"other";
        j = std::move(other);
        REQUIRE(j == u8"other"sv);
    }
}

TEST_CASE("Convert Array asign", "[semantics][asign][Array]") {
    Json j;
    SECTION("copy other") {
        Array const other = {1, 2, 3};
        j = other;
        REQUIRE(j == Array{1, 2, 3});
    }
    SECTION("move other") {
        Array other = {1, 2, 3};
        j = std::move(other);
        REQUIRE(j == Array{1, 2, 3});
    }
}

TEST_CASE("Convert Object asign", "[semantics][asign][Object]") {
    Json j;
    SECTION("copy other") {
        Object const other = {{u8"a", 1}, {u8"b", 2}};
        j = other;
        REQUIRE(j == Object{{u8"a", 1}, {u8"b", 2}});
    }
    SECTION("move other") {
        Object other = {{u8"a", 1}, {u8"b", 2}};
        j = std::move(other);
        REQUIRE(j == Object{{u8"a", 1}, {u8"b", 2}});
    }
}

TEST_CASE("Copy Json asign", "[semantics][asign][copy]") {
    Json j;
    SECTION("Null") {
        Json const other = Null{};
        j = other;
        REQUIRE(j == Null{});
    }
    SECTION("Boolean") {
        Json const other = true;
        j = other;
        REQUIRE(j == true);
    }
    SECTION("Number") {
        Json const other = 1.2;
        j = other;
        REQUIRE(j == 1.2);
    }
    SECTION("String") {
        Json const other = u8"string"sv;
        j = other;
        REQUIRE(j == u8"string"sv);
    }
    SECTION("Array") {
        Json const other = Array{1, 2, 3};
        j = other;
        REQUIRE(j == Array{1, 2, 3});
    }
    SECTION("Object") {
        Json const other = Object{{u8"a", 1}, {u8"b", 2}};
        j = other;
        REQUIRE(j == Object{{u8"a", 1}, {u8"b", 2}});
    }
}

TEST_CASE("Move Json asign", "[semantics][asign][move]") {
    Json j;
    SECTION("Null") {
        Json other = Null{};
        j = std::move(other);
        REQUIRE(j == Null{});
        REQUIRE(other == Null{});
    }
    SECTION("Boolean") {
        Json other = true;
        j = std::move(other);
        REQUIRE(j == true);
        REQUIRE(other == Null{});
    }
    SECTION("Number") {
        Json other = 1.2;
        j = std::move(other);
        REQUIRE(j == 1.2);
        REQUIRE(other == Null{});
    }
    SECTION("String") {
        Json other = u8"string"sv;
        j = std::move(other);
        REQUIRE(j == u8"string"sv);
        REQUIRE(other == Null{});
    }
    SECTION("Array") {
        Json other = Array{1, 2, 3};
        j = std::move(other);
        REQUIRE(j == Array{1, 2, 3});
        REQUIRE(other == Null{});
    }
    SECTION("Object") {
        Json other = Object{{u8"a", 1}, {u8"b", 2}};
        j = std::move(other);
        REQUIRE(j == Object{{u8"a", 1}, {u8"b", 2}});
        REQUIRE(other == Null{});
    }
}

TEST_CASE("Copy Json asign to self", "[semantics][asign][copy]") {
    SECTION("Null") {
        Json j = Null{};
        j = (Json const&)j;
        REQUIRE(j == Null{});
    }
    SECTION("Boolean") {
        Json j = true;
        j = (Json const&)j;
        REQUIRE(j == true);
    }
    SECTION("Number") {
        Json j = 1.2;
        j = (Json const&)j;
        REQUIRE(j == 1.2);
    }
    SECTION("String") {
        Json j = u8"string"sv;
        j = (Json const&)j;
        REQUIRE(j == u8"string"sv);
    }
    SECTION("Array") {
        Json j = Array{1, 2, 3};
        j = (Json const&)j;
        REQUIRE(j == Array{1, 2, 3});
    }
    SECTION("Object") {
        Json j = Object{{u8"a", 1}, {u8"b", 2}};
        j = (Json const&)j;
        REQUIRE(j == Object{{u8"a", 1}, {u8"b", 2}});
    }
}

TEST_CASE("Move Json asign to self", "[semantics][asign][move]") {
    SECTION("Null") {
        Json j = Null{};
        j = std::move((Json&)j);
        REQUIRE(j == Null{});
    }
    SECTION("Boolean") {
        Json j = true;
        j = std::move((Json&)j);
        REQUIRE(j == true);
    }
    SECTION("Number") {
        Json j = 1.2;
        j = std::move((Json&)j);
        REQUIRE(j == 1.2);
    }
    SECTION("String") {
        Json j = u8"string"sv;
        j = std::move((Json&)j);
        REQUIRE(j == u8"string"sv);
    }
    SECTION("Array") {
        Json j = Array{1, 2, 3};
        j = std::move((Json&)j);
        REQUIRE(j == Array{1, 2, 3});
    }
    SECTION("Object") {
        Json j = Object{{u8"a", 1}, {u8"b", 2}};
        j = std::move((Json&)j);
        REQUIRE(j == Object{{u8"a", 1}, {u8"b", 2}});
    }
}

TEST_CASE("Copy Json asign to parent", "[semantics][asign][copy]") {
    SECTION("array child to array parent ") {
        Json j = Array{{Array{{1, 2, 3}}}};
        auto const& ref = j.at(0);
        j = ref;
        REQUIRE(j == Array{{1, 2, 3}});
    }
    SECTION("object child to array parent") {
        Json j = Array{{Object{{u8"b", 2}}}};
        REQUIRE_NOTHROW(j = j.at(0));
        REQUIRE(j == Object{{u8"b", 2}});
    }
    SECTION("array child to object parent") {
        Json j = Object{{u8"a", Array{{1, 2, 3}}}};
        REQUIRE_NOTHROW(j = j.at(u8"a"));
        REQUIRE(j == Array{{1, 2, 3}});
    }
    SECTION("object child to object parent") {
        Json j = Object{{u8"a", Object{{u8"b", 2}}}};
        REQUIRE_NOTHROW(j = j.at(u8"a"));
        REQUIRE(j == Object{{u8"b", 2}});
    }
}

TEST_CASE("Move Json asign to parent", "[semantics][asign][move]") {
    SECTION("array child to array parent") {
        Json j = Array{{Array{{1, 2, 3}}}};
        REQUIRE_NOTHROW(j = std::move(j.at(0)));
        REQUIRE(j == Array{{1, 2, 3}});
    }
    SECTION("object child to array parent") {
        Json j = Array{{Object{{u8"b", 2}}}};
        REQUIRE_NOTHROW(j = std::move(j.at(0)));
        REQUIRE(j == Object{{u8"b", 2}});
    }
    SECTION("array child to object parent") {
        Json j = Object{{u8"a", Array{{1, 2, 3}}}};
        REQUIRE_NOTHROW(j = std::move(j.at(u8"a")));
        REQUIRE(j == Array{{1, 2, 3}});
    }
    SECTION("object child to object parent") {
        Json j = Object{{u8"a", Object{{u8"b", 2}}}};
        REQUIRE_NOTHROW(j = std::move(j.at(u8"a")));
        REQUIRE(j == Object{{u8"b", 2}});
    }
}

TEST_CASE("Copy Json asign to child", "[semantics][asign][copy]") {
    SECTION("array parent to array child") {
        Json j = Array{{Array{{1, 2, 3}}}};
        REQUIRE_NOTHROW(j.at(0) = j);
        REQUIRE(j == Array{{Array{{Array{{1, 2, 3}}}}}});
    }
    SECTION("array parent to object child") {
        Json j = Array{{Object{{u8"b", 2}}}};
        REQUIRE_NOTHROW(j.at(0) = j);
        REQUIRE(j == Array{{Array{{Object{{u8"b", 2}}}}}});
    }
    SECTION("object parent to array child") {
        Json j = Object{{u8"a", Array{{1, 2, 3}}}};
        REQUIRE_NOTHROW(j.at(u8"a") = j);
        REQUIRE(j == Object{{u8"a", Object{{u8"a", Array{{1, 2, 3}}}}}});
    }
    SECTION("object parent to object child") {
        Json j = Object{{u8"a", Object{{u8"b", 2}}}};
        REQUIRE_NOTHROW(j.at(u8"a") = j);
        REQUIRE(j == Object{{u8"a", Object{{u8"a", Object{{u8"b", 2}}}}}});
    }
}

TEST_CASE("Move Json asign to child", "[semantics][asign][move]") {
    SECTION("array parent to array child") {
        Json j = Array{{Array{{1, 2, 3}}}};
        REQUIRE_NOTHROW(j.at(0) = std::move(j));
        REQUIRE(j == Null{});
    }
    SECTION("array parent to object child") {
        Json j = Array{{Object{{u8"b", 2}}}};
        REQUIRE_NOTHROW(j.at(0) = std::move(j));
        REQUIRE(j == Null{});
    }
    SECTION("object parent to array child") {
        Json j = Object{{u8"a", Array{{1, 2, 3}}}};
        REQUIRE_NOTHROW(j.at(u8"a") = std::move(j));
        REQUIRE(j == Null{});
    }
    SECTION("object parent to object child") {
        Json j = Object{{u8"a", Object{{u8"b", 2}}}};
        REQUIRE_NOTHROW(j.at(u8"a") = std::move(j));
        REQUIRE(j == Null{});
    }
}
