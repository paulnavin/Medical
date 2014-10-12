#include <Logging/Assertion.h>

#ifdef WIN32
  #pragma warning(push)
  #pragma warning(disable: 4365)
#endif

#include <assert.h>
void REQUIRE(bool statement)
{
  assert(statement);
}

void ENSURE(bool statement)
{
  assert(statement);
}

void ASSERT(bool statement)
{
  assert(statement);
}

#ifdef WIN32
  #pragma warning(pop)
#endif
