#include "doctest.h"

using namespace std;

#include "sources/MagicalContainer.hpp" //no need for other includes

using namespace ariel;

TEST_CASE("Create MagicalContainer and check container size") {
    MagicalContainer container;
    SUBCASE("Test addElement() and size()") {

        container.addElement(17);
        container.addElement(2);
        container.addElement(25);
        container.addElement(9);
        container.addElement(3);
        CHECK(container.size() == 5);
    }
    SUBCASE("Test removeElement()") {

        CHECK_NOTHROW(container.removeElement(2));

        CHECK_THROWS(container.removeElement(2));
        CHECK(container.size() == 4);

        CHECK_NOTHROW(container.removeElement(3));
        CHECK(container.size() == 3);
    }
}

TEST_CASE("Test AscendingIterator class - begin") {
    MagicalContainer container;
    MagicalContainer container1;
    container.addElement(5);
    container.addElement(2);
    container.addElement(8);
    container1.addElement(9);
    container1.addElement(3);
    MagicalContainer::AscendingIterator ascIter(container);

    auto first_asc_iterator = ascIter.begin();
    auto second_asc_iterator = ascIter.begin();


    SUBCASE("Test dereference operator") {
        CHECK(*first_asc_iterator == 2);
        CHECK(*second_asc_iterator == 2);
    }

    SUBCASE("Test pre-increment operator and comparison operators") {
        ++first_asc_iterator;
        CHECK(*first_asc_iterator == 5);

        CHECK(first_asc_iterator > second_asc_iterator);
        CHECK(first_asc_iterator != second_asc_iterator);
        CHECK_FALSE(first_asc_iterator == second_asc_iterator);

        ++second_asc_iterator;
        CHECK(first_asc_iterator == second_asc_iterator);

        ++second_asc_iterator;
        CHECK(*second_asc_iterator == 8);

        CHECK(first_asc_iterator < second_asc_iterator);

        ++first_asc_iterator;
        CHECK(*first_asc_iterator == 8);
        CHECK(first_asc_iterator == second_asc_iterator);

    }
}

TEST_CASE("Test SideCrossIterator class - begin") {
    MagicalContainer container;
    container.addElement(5);
    container.addElement(2);
    container.addElement(11);
    container.addElement(20);
    container.addElement(8);
    // We should run it like this: 5 8 2 20 11
    MagicalContainer::SideCrossIterator crossIter(container);
    auto first_cross_iterator = crossIter.begin();
    auto second_cross_iterator = crossIter.begin();

    SUBCASE("Test dereference operator") {
        CHECK(*first_cross_iterator == 5);
        CHECK(*second_cross_iterator == 5);
    }

    SUBCASE("Test pre-increment operator and comparison operators") {
        ++first_cross_iterator;
        CHECK(*first_cross_iterator == 8);

        CHECK(first_cross_iterator > second_cross_iterator);
        CHECK(first_cross_iterator != second_cross_iterator);
        CHECK_FALSE(first_cross_iterator == second_cross_iterator);

        ++second_cross_iterator;
        CHECK(first_cross_iterator == second_cross_iterator);

        ++second_cross_iterator;
        CHECK(*second_cross_iterator == 2);

        CHECK_FALSE(first_cross_iterator < second_cross_iterator);

        ++first_cross_iterator;
        CHECK(*first_cross_iterator == 2);
        CHECK(first_cross_iterator == second_cross_iterator);

        ++first_cross_iterator;
        CHECK(*first_cross_iterator == 20);
        CHECK(first_cross_iterator > second_cross_iterator);

        ++first_cross_iterator;
        CHECK(*first_cross_iterator == 11);
        CHECK(first_cross_iterator > second_cross_iterator);

    }
}

TEST_CASE("Test PrimeIterator class") {
    MagicalContainer container;
    container.addElement(5);
    container.addElement(7);
    container.addElement(8);
    container.addElement(2);
    container.addElement(9);
    MagicalContainer::PrimeIterator ascIter(container);
    auto first_asc_iterator = ascIter.begin();
    auto second_asc_iterator = ascIter.begin();

    SUBCASE("Test dereference operator") {
        CHECK(*first_asc_iterator == 5);
        CHECK(*second_asc_iterator == 5);
    }

    SUBCASE("Test pre-increment operator and comparison operators") {
        ++first_asc_iterator;
        CHECK(*first_asc_iterator == 7);

        CHECK(first_asc_iterator > second_asc_iterator);
        CHECK(first_asc_iterator != second_asc_iterator);
        CHECK_FALSE(first_asc_iterator == second_asc_iterator);

        ++second_asc_iterator;
        CHECK(first_asc_iterator == second_asc_iterator);

        ++second_asc_iterator;
        CHECK(*second_asc_iterator == 2);

        CHECK(first_asc_iterator > second_asc_iterator);

    }
    SUBCASE("Test end equals to iterators"){
        auto first_asc_iterator_end = ascIter.end();
        CHECK(first_asc_iterator_end == ++second_asc_iterator);
    }
}
