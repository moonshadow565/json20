#pragma once
#include "catch.hpp"
#include "json.hpp"

using namespace std::string_literals;
using namespace std::string_view_literals;
using Null = Json::Null;
using Boolean = Json::Boolean;
using Number = Json::Number;
using String = Json::String;
using StringView = Json::StringView;
using Array = Json::Array;
using Object = Json::Object;
constexpr auto Infinity = std::numeric_limits<Number>::infinity();
constexpr auto NaN = std::numeric_limits<Number>::quiet_NaN();

namespace Catch {
    template<>
    struct StringMaker<StringView> {
        static std::string convert(StringView const& value) {
            return std::string((char const*)value.data(), value.size());
        }
    };
    template<>
    struct StringMaker<String> {
        static std::string convert(String const& value) {
            return std::string((char const*)value.data(), value.size());
        }
    };
}

inline std::ostream& operator << (std::ostream& os, StringView value) {
    os.write((char const*)value.data(), value.size());
    return os;
}

inline std::ostream& operator << (std::ostream& os, String const& value) {
    os.write((char const*)value.data(), value.size());
    return os;
}
