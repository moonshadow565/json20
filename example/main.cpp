#include <iostream>
#include <string>
#include "json.hpp"

using namespace std::string_literals;
using namespace std::string_view_literals;

int main() {
    Json j = Json::Null{};
    auto x = j.into<std::optional<int>>();
    return 0;
}
