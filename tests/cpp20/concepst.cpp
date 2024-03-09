#include "../catch.hpp"

#include <concepts>

template<typename T>
concept IsInteger = std::is_same_v<T, int>;

TEST_CASE("IsIntegerConcept")
{
    REQUIRE(IsInteger<int> == true);
    REQUIRE(IsInteger<char> == false);
    REQUIRE(IsInteger<float> == false);
}

template<typename T>
concept HasDoFunction = requires(T t)
{
    t.Do();
};

template<typename T>
    requires HasDoFunction<T>
void callDo1(T t)
{
    t.Do();
}

template<HasDoFunction T>
void callDo2(T t)
{
    t.Do();
}

struct A1
{
    void Do() {}
};

struct A2
{

};

TEST_CASE("HasDoConcept")
{
    callDo1(A1{});
    callDo2(A1{});
    //compilation error cause no Do in A2
    //callDo1(A2{}); 
    //callDo2(A2{});
}
