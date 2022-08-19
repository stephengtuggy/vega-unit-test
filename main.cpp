#include <iostream>
#include "boost/format.hpp"
#include <boost/smart_ptr/shared_ptr.hpp>
#include <utility>
#include "unit.hpp"
#include "universe.hpp"

using namespace boost;
using namespace boost::multi_index;
using namespace VegaStrike;

int main() {
    const int32_t kNumUnitsToCreate{10000};
    const int32_t kNumOfUnitToKill{5000};
    const std::string kFlightgroupName{"Shlimazel"};
    boost::shared_ptr<Unit> unit_to_kill{};

    std::cout << "Entering main()" << std::endl;

    std::cout << "Fetching universe for first time" << std::endl;
    Universe& universe = getUniverse();

    std::cout << (boost::format("Creating %1% units in flightgroup %2%") % kNumUnitsToCreate % kFlightgroupName) << std::endl;
    for (int32_t i = 0; i < kNumUnitsToCreate; ++i) {
        boost::shared_ptr<Unit> new_unit = universe.createUnit(kFlightgroupName, i);
        if (i == kNumOfUnitToKill) {
            unit_to_kill = new_unit;
        }
    }

    std::cout << "Copying all the Units to cout" << std::endl;
    FgMemberCollection const & live_units = universe.getAllLiveUnits();
    for (const auto& each_unit : live_units.get<FgMemberSequenced>()) {
        std::cout << each_unit << std::endl;
    }

    std::cout << (boost::format("Killing number %1% from flightgroup %2%") % kNumOfUnitToKill % kFlightgroupName) << std::endl;
    universe.killUnit(unit_to_kill);

    std::cout << "Copying all the remaining Units to cout" << std::endl;
    for (const auto& each_unit : live_units.get<FgMemberSequenced>()) {
        std::cout << each_unit << std::endl;
    }

    std::cout << "Killing all the remaining Units" << std::endl;
    universe.killAllUnits();

    std::cout << "Exiting main()" << std::endl;
    return 0;
}
