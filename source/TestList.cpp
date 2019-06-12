#define CATCH_CONFIG_RUNNER
#include <catch2/catch.hpp>
#include <iostream>
#include "List.hpp"
#include "Circle.hpp"

TEST_CASE("List size")
{
    List<int> list;
    list.push_front(42);
    REQUIRE(list.empty() == false);
}

TEST_CASE("add an element with push_front", "[modifiers]")
{
    List<int> list;
    list.push_front(22);
    list.push_front(42);
    REQUIRE(42 == list.front());
    REQUIRE(22 == list.back());
}

TEST_CASE("add an element with push_back", "[modifiers]")
{
    List<int> list;
    list.push_back(23);
    list.push_back(26);
    REQUIRE(26 == list.back());
    REQUIRE(23 == list.front());
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
    Vec2 center;
    Color color;
    const Circle c_1(center, 5, color, "Herbert");
    circle_list.push_back(c_1);
    auto c_it = circle_list.begin();

    REQUIRE(c_it->getRadius() == 5);
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
    list.push_front(14);
    list.push_front(32);
    list.push_front(76);
    list.push_front(7);

    List<int> list2{list};

    REQUIRE(list2 == list);
    
    list.push_front(16);

    REQUIRE(list2 != list);
}

TEST_CASE("Inserting an Element")
{
    List<int> list;
    list.push_front(4);
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);

    ListIterator<int> itr = list.begin();
    ++itr;
    ++itr;

    ListIterator<int> newItr = list.insert(itr, 5);

    REQUIRE(newItr.node->next->value == 3);
    REQUIRE(newItr.node->prev->value == 2);
}

TEST_CASE("reversing a List")
{
    List<int> list;
    list.push_front(4);
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);

    List<int> list2;
    list2.push_front(1);
    list2.push_front(2);
    list2.push_front(3);
    list2.push_front(4);

    list.reverse();

    REQUIRE(list == list2);
}
 
TEST_CASE ("move constructor", "[constructor]")
{
List<int> list;
list.push_front(1);
list.push_front(2);
list.push_front(3);
list.push_front(4);
List<int> list2 = std::move(list);
REQUIRE (0 == list.size());
REQUIRE (list.empty());
REQUIRE (4 == list2.size());
}


int main(int argc, char * argv [])
{
    return Catch::Session().run(argc, argv);
}