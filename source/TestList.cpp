#define CATCH_CONFIG_RUNNER
#include <catch2/catch.hpp>
#include "List.hpp"

TEST_CASE("List size")
{
    List<int> list;
    list.push_front(42);
    REQUIRE(list.empty() == false);
}

TEST_CASE("add an element with push_front", "[modifiers]")
{
    List<int> list;
    list.push_front(42);
    REQUIRE(42 == list.front());
}

TEST_CASE("add an element with push_back", "[modifiers]")
{
    List<int> list;
    list.push_back(26);
    REQUIRE(26 == list.back());
}

TEST_CASE("delete an element with pop_front", "[modifiers]")
{
    List<int> list;
    list.push_front(26);
    list.push_front(32);
    list.pop_front();
    REQUIRE(26 == list.front());
}

TEST_CASE("delete an element with pop_back", "[modifiers]")
{
    List<int> list;
    list.push_back(26);
    list.push_back(32);
    list.pop_back();
    REQUIRE(26 == list.back());
}

TEST_CASE("should be empty after clearing", "[modifiers]")
{
    List<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    list.clear();

    REQUIRE(list.empty());
}

TEST_CASE("ListIterator Operatoren")
{
    List<int> list;
    list.push_front(34);
    list.push_front(18);
    list.push_front(21);
    ListIterator<int> itr = list.begin();
    ListIterator<int> itr2 = list.end();

    REQUIRE(*itr == 21);
    REQUIRE(*itr2 == 34);

    ++itr;
    REQUIRE(*itr == 18);

    itr2++;
    REQUIRE(*itr2 == 34);

    List<Circle> circle_list;
    circle_list.push_back(...);
    auto c_it = circle_list.begin();
    std::cout<< "Der Radius des 1. Circles in der Liste ist : "
    << c_it->get_radius() << std::endl;
}

TEST_CASE("ListIterator gleich/ungleich")
{
    List<int> list;
    list.push_front(34);
    list.push_front(18);
    list.push_front(21);
    ListIterator<int> itr = list.begin();
    ListIterator<int> itr2 = list.end();

    REQUIRE(itr != itr2);
    REQUIRE(itr == itr);
}

TEST_CASE("should be an empty range after default construction", "[iterators]")
{
    List<int> list;
    auto b = list.begin();
    auto e = list.end();
    REQUIRE(b == e);
}

TEST_CASE("provide access to the first element with begin", "[iterators]")
{
    List<int> list;
    list.push_front(42);
    REQUIRE(42 == * list.begin());
}

TEST_CASE("Vergleiche zwei Listen")
{
    List<int> list;
    List<int> list2;
    list.push_front(42);
    list.push_front(23);
    list2.push_front(42);
    list2.push_front(23);

    REQUIRE(list == list2);

    list2.push_front(45);

    REQUIRE(list != list2);
}

TEST_CASE("copy constructor", "[constructor]")
{
List<int> list;
list.push_front(1);
list.push_front(2);
list.push_front(3);
list.push_front(4);

List<int> list2{list};
REQUIRE(list == list2);
}

int main(int argc, char * argv [])
{
    return Catch::Session().run(argc, argv);
}