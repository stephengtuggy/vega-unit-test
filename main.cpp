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

    typedef multi_index_container<
            UnitSharedPtr,
            indexed_by<ordered_unique<identity<Unit>>
            >
    > UnitContainer;
    UnitContainer unit_container{};

    for (int32_t i = 0; i < 50; ++i) {
        UnitSharedPtr stillAnother = make_shared_from_intrusive(new Unit("Shlimazel", i));
        unit_container.get<0>().insert(stillAnother);
    }

    std::cout << "Exiting main()" << std::endl;
    return 0;
}
