#include "../catch.hpp"

#include <iostream>
#include <string>
#include <utility>

struct A {
    void f1() {}

    int f2(int i) { return i; }
};

struct B {
    void f1() {}

    std::string f2(const std::string& str) const { return str; }
};

template<typename T, typename Fp, typename... Args>
auto call(T& t, Fp fp, Args&&... args) {
    return (t.*fp)(std::forward<Args>(args)...);
}

TEST_CASE("Caller variadic template") {
    A a;

    call(a, &A::f1);
    REQUIRE(call(a, &A::f2, 3) == 3);

    B b;

    call(b, &B::f1);
    REQUIRE(call(b, &B::f2, "Hello") == "Hello");
}
