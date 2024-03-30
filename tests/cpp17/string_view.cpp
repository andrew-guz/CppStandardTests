#include "../catch.hpp"

#include <string>
#include <string_view>

std::size_t length(const std::string_view str) { return str.size(); }

TEST_CASE("Length") { REQUIRE(length("Hello from big string not optimized by length") == 45); }

TEST_CASE("Constexpr") {
    constexpr std::string_view str{"Another big string"};
    constexpr std::size_t position = str.find("big");
    REQUIRE(position == 8);
}
