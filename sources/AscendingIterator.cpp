
#include "MagicalContainer.hpp"

namespace ariel {

    // Default constructor
    MagicalContainer::AscendingIterator::AscendingIterator(): container(MagicalContainer().getContainer()), currentIndex(0){

    }

    MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer &cont, int index  ) : container(
            cont), currentIndex(index) {

    }

    // Copy constructor
    MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer::AscendingIterator &other) : container(other.container),
                                                                                 currentIndex(
                                                                                         other.currentIndex) {}

    // Destructor
    MagicalContainer::AscendingIterator::~AscendingIterator(){

    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other){
        return *this;
    }

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const{
        return false;
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const{
        return false;
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const{
        return false;
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const{
        return false;
    }

    int MagicalContainer::AscendingIterator::operator*() const{
        return 0;
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++(){
        return *this;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const{
        return *this;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const{
        return *this;
    }
} // ariel