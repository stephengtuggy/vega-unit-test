//
// Created by StephenTuggy on 8/15/2022.
//

#include "can_be_owner.hpp"

namespace VegaStrike {
    FgMemberCollection &CanBeOwner::getOwned() {
        return stuff_i_own_;
    }
} // VegaStrike