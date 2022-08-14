#include <iostream>
#include <boost/smart_ptr/intrusive_ref_counter.hpp>
#include "vega_intrusive_ptr.hpp"
#include "unit.hpp"

int main() {
    std::cout << "Entering main()" << std::endl;
    UnitSharedPtr unitSharedPtr = make_shared_from_intrusive(new Unit());
    std::cout << "reference count: " << unitSharedPtr.use_count() << std::endl;
    UnitSharedPtr anotherPtr = unitSharedPtr; // NOLINT(performance-unnecessary-copy-initialization)
    std::cout << "reference count: " << unitSharedPtr.use_count() << std::endl;
    anotherPtr.reset();
    std::cout << "reference count: " << unitSharedPtr.use_count() << std::endl;
    UnitSharedPtr stillAnotherPtr = make_shared_from_intrusive(new Unit("Shlimazel", 1));
    std::cout << "Exiting main()" << std::endl;
    return 0;
}
