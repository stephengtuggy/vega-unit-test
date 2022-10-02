// Copyright (c) 2022 Stephen G. Tuggy
//
// This file is part of Vega Test.
//
// Vega Test is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Vega Test is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Vega Test. If not, see <https://www.gnu.org/licenses/>.

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
