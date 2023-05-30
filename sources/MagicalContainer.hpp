//
// Created by moria on 5/29/23.
//

#pragma once

#include <vector>

namespace ariel {

    class MagicalContainer {
    private:
        std::vector<int> container;

    public:

        MagicalContainer();

        void addElement(int element);

        void removeElement(int element);

        int size() const;



//        AscendingIterator beginAscending() const;
//
//        SideCrossIterator beginSideCross() const;
//
//        PrimeIterator beginPrime() const;
//
//        AscendingIterator endAscending() const;
//
//        SideCrossIterator endSideCross() const;
//
//        PrimeIterator endPrime() const;

        class AscendingIterator {
        private:
            const MagicalContainer &container;
            int currentIndex;
        public:

            // Default constructor
            AscendingIterator();
            AscendingIterator(const MagicalContainer& cont, int index = 0);

            // Copy constructor
            AscendingIterator(const AscendingIterator& other);

            // Destructor
            ~AscendingIterator();


            AscendingIterator &operator=(const AscendingIterator &other);

            bool operator==(const AscendingIterator &other) const;

            bool operator!=(const AscendingIterator &other) const;

            bool operator>(const AscendingIterator &other) const;

            bool operator<(const AscendingIterator &other) const;

            int operator*() const;

            AscendingIterator &operator++();

            AscendingIterator begin() const;

            AscendingIterator end() const;
        };

        class SideCrossIterator {
        private:
            const MagicalContainer &container;
            int currentIndex;
        public:

            // Default constructor
            SideCrossIterator();

            SideCrossIterator(const MagicalContainer &cont, int index = 0);

            // Copy constructor
            SideCrossIterator(const SideCrossIterator &other);

            // Destructor
            ~SideCrossIterator();

            SideCrossIterator &operator=(const SideCrossIterator &other);

            bool operator==(const SideCrossIterator &other) const;

            bool operator!=(const SideCrossIterator &other) const;

            bool operator>(const SideCrossIterator &other) const;

            bool operator<(const SideCrossIterator &other) const;

            int operator*() const;

            SideCrossIterator &operator++();

            SideCrossIterator begin() const;

            SideCrossIterator end() const;
        };

        class PrimeIterator {
        private:
            const MagicalContainer &container;
            int currentIndex;
        public:

            // Default constructor
            PrimeIterator();

            PrimeIterator(const MagicalContainer &cont, int index = 0);

            // Copy constructor
            PrimeIterator(const PrimeIterator &other);

            // Destructor
            ~PrimeIterator();

            PrimeIterator &operator=(const PrimeIterator &other);

            bool operator==(const PrimeIterator &other) const;

            bool operator!=(const PrimeIterator &other) const;

            bool operator>(const PrimeIterator &other) const;

            bool operator<(const PrimeIterator &other) const;

            int operator*() const;

            PrimeIterator &operator++();

            PrimeIterator begin() const;

            PrimeIterator end() const;
        };

    };

} // ariel

