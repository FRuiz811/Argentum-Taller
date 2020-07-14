#include "NestContainer.h"
#include "../common/Exception.h"

#include <utility>
#include <algorithm>

NestContainer::NestContainer(std::vector<Nest> nests) : nests(std::move(nests)) {
    length = this->nests.size();
}

Nest& NestContainer::getNextNestAvailable() {
    std::sort_heap(nests.begin(), nests.end());
    for (auto &aNest : nests) {
        if (!aNest.isFull() ) {
            return aNest;
        }
    }
    throw Exception("There is not available nests to add creatures");
}
//    uint8_t counter = 0;
//    Nest& nest = nests.at(getNextIndex());
//    while (nest.isFull() && counter < length) {
//        nest = nests.at(getNextIndex());
//        counter++;
//    }
//    if (nest.isFull()) {
//
//    }
//    return nest;


std::vector<Nest> &NestContainer::getNests() {
    return nests;
}

Nest &NestContainer::getNest(uint nestId) {
    size_t index = 0;
    for (auto &aNest : nests) {
        if (nestId == aNest.getNestId()) {
            break;
        }
        index++;
    }
    return nests.at(index);
}

int NestContainer::getAmountCreatures() {
    int amountCreatures = 0;
    for (auto &aNest : nests) {
        amountCreatures += aNest.getAmountCreatures();
    }
    return amountCreatures;
}

uint8_t NestContainer::getNextIndex() {
    nestIndex++;
    nestIndex = nestIndex >= length ? 0 : nestIndex;
    return nestIndex;
}

NestContainer::NestContainer() = default;

NestContainer::~NestContainer() = default;
