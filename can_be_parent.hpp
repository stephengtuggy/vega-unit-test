//
// Created by StephenTuggy on 8/15/2022.
//

#ifndef VEGA_UNIT_TEST_CAN_BE_PARENT_HPP
#define VEGA_UNIT_TEST_CAN_BE_PARENT_HPP

#include "vega_unit_collection.hpp"

namespace VegaStrike {

    class CanBeParent {
    protected:
        FgMemberCollection children_{};

    public:
        // Default constructor
        CanBeParent() = default;
        // Copy constructor -- forbidden
        CanBeParent(CanBeParent const & rhs) = delete;
        // Move constructor
        CanBeParent(CanBeParent && rhs) = default;
        // Destructor
        virtual ~CanBeParent() = default;
        CanBeParent& operator=(CanBeParent const & rhs) = delete;

        virtual FgMemberCollection &getChildren();
    };

} // VegaStrike

#endif //VEGA_UNIT_TEST_CAN_BE_PARENT_HPP
