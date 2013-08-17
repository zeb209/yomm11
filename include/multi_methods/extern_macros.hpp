// extern_macros.hpp
// Copyright (c) 2013 Jean-Louis Leroy
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#undef MM_CLASS

#define MM_CLASS(CLASS, BASES...)               \
  virtual void _mm_init_class_()

#undef MM_EXTERN_CLASS

#define MM_EXTERN_CLASS(CLASS)                                  \
  extern template class ::yorel::multi_methods::mm_class_of<CLASS>

#undef MULTI_METHOD

#define MULTI_METHOD(ID, RETURN_TYPE, ARGS...)                          \
  template<typename Sig> struct ID ## _method;                          \
  constexpr ::yorel::multi_methods::multi_method<ID ## _method, RETURN_TYPE(ARGS)> ID{}; \
  extern template class ::yorel::multi_methods::detail::multi_method_implementation<RETURN_TYPE, ARGS>