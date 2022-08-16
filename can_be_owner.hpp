//
// Created by StephenTuggy on 8/15/2022.
//

#ifndef VEGA_UNIT_TEST_CAN_BE_OWNER_HPP
#define VEGA_UNIT_TEST_CAN_BE_OWNER_HPP

#include "vega_unit_collection.hpp"

namespace VegaStrike {

    class CanBeOwner {
    protected:
        FgMemberCollection stuff_i_own_{};

    public:
        // Default constructor
        CanBeOwner() = default;
        // Copy constructor -- forbidden
        CanBeOwner(CanBeOwner const & rhs) = delete;
        // Move constructor
        CanBeOwner(CanBeOwner && rhs) = default;
        // Destructor
        virtual ~CanBeOwner() = default;
        CanBeOwner& operator=(CanBeOwner const & rhs) = delete;

        virtual FgMemberCollection& getOwned();
    };

} // VegaStrike

#endif //VEGA_UNIT_TEST_CAN_BE_OWNER_HPP
