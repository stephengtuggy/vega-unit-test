#include <iostream>
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/sequenced_index.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/identity.hpp>
#include <boost/multi_index/mem_fun.hpp>
#include <boost/smart_ptr/intrusive_ref_counter.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>
#include "vega_intrusive_ptr.hpp"
#include "unit.hpp"

using namespace boost;
using namespace boost::multi_index;
using namespace VegaUnit;

int main() {
    std::cout << "Entering main()" << std::endl;
    UnitSharedPtr unitSharedPtr = make_shared_from_intrusive(new Unit());
    std::cout << "reference count: " << unitSharedPtr.use_count() << std::endl;
    UnitSharedPtr anotherPtr = unitSharedPtr; // NOLINT(performance-unnecessary-copy-initialization)
    std::cout << "reference count: " << unitSharedPtr.use_count() << std::endl;
    anotherPtr.reset();
    std::cout << "reference count: " << unitSharedPtr.use_count() << std::endl;

    std::cout << "Initializing multi_index_container" << std::endl;
    typedef multi_index_container<
            Unit,
            indexed_by<ordered_unique<identity<Unit>>
            >
    > UnitContainer;
    UnitContainer unit_container{};
    typedef UnitContainer::nth_index_iterator<0>::type UnitContainerIterator;
    typedef const UnitContainer::nth_index_const_iterator<0>::type UnitContainerConstIterator;

    UnitSharedPtr number_25{};
    for (int32_t i = 0; i < 50; ++i) {
        UnitSharedPtr stillAnother = make_shared_from_intrusive(new Unit("Shlimazel", i));
        unit_container.get<0>().emplace(*stillAnother);
        if (i == 25) {
            number_25 = stillAnother;
        }
    }

    std::cout << "Copying all the Units to cout" << std::endl;
    std::copy(unit_container.get<0>().cbegin(), unit_container.get<0>().cend(), std::ostream_iterator<const Unit &>(std::cout, "\n"));

    std::cout << "Erasing number 25" << std::endl;
    unit_container.get<0>().erase(*number_25);
    number_25->Kill();
    number_25.reset();

    std::cout << "Copying all the remaining Units to cout" << std::endl;
    std::copy(unit_container.get<0>().cbegin(), unit_container.get<0>().cend(), std::ostream_iterator<const Unit &>(std::cout, "\n"));

    std::for_each(unit_container.get<0>().begin(), unit_container.get<0>().end(), [](Unit unit) { unit.Kill(); } );

    std::cout << "Exiting main()" << std::endl;
    return 0;
}
