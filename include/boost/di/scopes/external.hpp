//
// Copyright (c) 2012 Krzysztof Jusiak (krzysztof at jusiak dot net)
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#if !BOOST_PP_IS_ITERATING

    #ifndef BOOST_DI_SCOPES_EXTERNAL_HPP
    #define BOOST_DI_SCOPES_EXTERNAL_HPP

    #include <boost/preprocessor/iteration/iterate.hpp>

    #include "boost/di/convertibles/convertible_any.hpp"
    #include "boost/di/config.hpp"

    #define BOOST_PP_ITERATION_PARAMS_1 (   \
        BOOST_DI_ITERATION_PARAMS(          \
            1                               \
          , BOOST_DI_LIMIT_SIZE             \
          , "boost/di/scopes/external.hpp"  \
        )                                   \
    )

    namespace boost {
    namespace di {
    namespace scopes {

    class external
    {
    public:
        template<
            typename TExpected
          , typename = TExpected
        >
        class scope : public convertibles::convertible_any<TExpected>
        {
        public:
            typedef scope result_type;

            template<typename T>
            explicit scope(const T& value)
                : convertibles::convertible_any<TExpected>(value)
            { }

            result_type& create() {
                return *this;
            }

            #include BOOST_PP_ITERATE()
        };
    };

    } // namespace scopes
    } // namespace di
    } // namespace boost

    #endif

#else

    template<BOOST_DI_TYPES(Args)>
    result_type& create(BOOST_DI_ARGS_NOT_USED(Args)) {
        return *this;
    }

#endif

