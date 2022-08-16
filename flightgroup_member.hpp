//
// Created by StephenTuggy on 8/15/2022.
//

#ifndef VEGA_UNIT_TEST_FLIGHTGROUP_MEMBER_HPP
#define VEGA_UNIT_TEST_FLIGHTGROUP_MEMBER_HPP

#include <string>
#include <cstdint>
#include <utility>

namespace VegaStrike {

    class FlightgroupMember {
    protected:
        std::string flightgroup_name_{};
        int32_t flightgroup_sub_number_{};
    public:
        // Default constructor -- forbidden
        inline FlightgroupMember() = default;
        // Copy constructor -- forbidden
        FlightgroupMember(FlightgroupMember const & rhs) = delete; //: flightgroup_name_(rhs.flightgroup_name_), flightgroup_sub_number_(rhs.flightgroup_sub_number_) {}
        // Move constructor
        FlightgroupMember(FlightgroupMember&& rhs) = default;
        // Main constructor
        inline FlightgroupMember(std::string flightgroup_name, int32_t flightgroup_sub_number) : flightgroup_name_(std::move(flightgroup_name)), flightgroup_sub_number_(flightgroup_sub_number) {}
        virtual ~FlightgroupMember() = default;

        FlightgroupMember& operator=(FlightgroupMember& initializer) = delete;
        virtual bool operator<(FlightgroupMember& other);

        virtual std::string getFlightgroupName() const;
        virtual int32_t getFlightgroupSubNumber() const;
    };

} // VegaStrike

#endif //VEGA_UNIT_TEST_FLIGHTGROUP_MEMBER_HPP
