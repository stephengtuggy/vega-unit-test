//
// Created by StephenTuggy on 8/15/2022.
//

#include "can_be_parent.hpp"

namespace VegaStrike {
    FgMemberCollection &CanBeParent::getChildren() {
        return children_;
    }
} // VegaStrike