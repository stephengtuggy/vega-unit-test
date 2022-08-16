#include <iostream>
#include "boost/format.hpp"
#include <boost/smart_ptr/shared_ptr.hpp>
#include "unit.hpp"
#include "universe.hpp"

using namespace boost;
using namespace boost::multi_index;
using namespace VegaStrike;

int main() {
    const int32_t kNumUnitsToCreate{10000};
    const int32_t kNumOfUnitToKill{5000};
    const std::string kFlightgroupName{"Shlimazel"};

    std::cout << "Entering main()" << std::endl;

    std::cout << "Fetching universe for first time" << std::endl;
    Universe& universe = getUniverse();

    for (int32_t i = 0; i < kNumUnitsToCreate; ++i) {
        Unit & new_unit = universe.createUnit(kFlightgroupName, i);
    }

    std::cout << "Copying all the Units to cout" << std::endl;
    FgMemberCollection const & live_units = universe.getAllLiveUnits();
//    std::copy(live_units.get<FgMemberSequenced>().cbegin(), live_units.get<FgMemberSequenced>().cend(), std::ostream_iterator<const Unit &>(std::cout, "\n"));
//
//    std::cout << (boost::format("Killing number %1% from flightgroup %2%") % kNumOfUnitToKill % kFlightgroupName) << std::endl;
//    UnitSequencedIterator unit_to_kill = live_units.get<0>().find(std::make_tuple(kFlightgroupName, kNumOfUnitToKill), new CompareByFlightgroup());
//    universe.killUnit(const_cast<Unit &>(*unit_to_kill));
//
//    std::cout << "Copying all the remaining Units to cout" << std::endl;
//    std::copy(live_units.get<0>().cbegin(), live_units.get<0>().cend(), std::ostream_iterator<const Unit &>(std::cout, "\n"));
//
//    std::cout << "Killing all the remaining Units" << std::endl;
//    std::for_each(live_units.get<0>().begin(), live_units.get<0>().end(), [](Unit unit) { unit.kill(); } );

    std::cout << "Exiting main()" << std::endl;
    return 0;
}
