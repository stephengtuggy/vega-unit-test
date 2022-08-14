//
// Created by StephenTuggy on 8/14/2022.
//

#ifndef VEGA_UNIT_TEST_VEGA_INTRUSIVE_PTR_HPP
#define VEGA_UNIT_TEST_VEGA_INTRUSIVE_PTR_HPP

#include <boost/intrusive_ptr.hpp>
#include <boost/shared_ptr.hpp>

struct null_deleter
{
    void operator()(void const *) const
    {
    }
};

template<class T>
struct intrusive_deleter {
    void operator()(T *p) {
        if (p) {
            intrusive_ptr_release(p);
        }
    }

    void operator()(boost::intrusive_ptr<T> p) {
        if (p) {
            intrusive_ptr_release(p);
        }
    }
};

template<class T>
boost::shared_ptr<T> make_shared_from_intrusive(T *p) {
    if (p) {
        intrusive_ptr_add_ref(p);
    }
    boost::shared_ptr<T> px(p, intrusive_deleter<T>());
    return px;
}

template<class T>
boost::shared_ptr<T> make_shared_from_intrusive(boost::intrusive_ptr<T> p) {
    if (p) {
        intrusive_ptr_add_ref(p);
    }
    boost::shared_ptr<T> px(p, intrusive_deleter<T>());
    return px;
}

#endif //VEGA_UNIT_TEST_VEGA_INTRUSIVE_PTR_HPP
