#ifndef mocha_static_assert_h_
#define mocha_static_assert_h_

template <bool> struct StaticAssert{
  enum{ StaticAssertionResult = 0 };
};
template <> struct StaticAssert<false> {
  enum{ StaticAssertionResult = -1 };
};

#define JOIN(a, b) JOIN_(a, b)
#define JOIN_(a, b) a##b
#define STATIC_ASSERT(expr)                                             \
  typedef char                                                          \
  JOIN(StaticAssertion_failed_in_, __LINE__)[StaticAssert<static_cast<bool>((expr))>::StaticAssertionResult]
      

#endif
