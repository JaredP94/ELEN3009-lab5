#include "date.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Copy of Date object shares no state with original Date object")
{
	Date christmas{25, Month::December, 2017};
	Date christmas_copy{christmas};
	CHECK(christmas==christmas_copy);
	
	christmas_copy.incrementDay();
	CHECK_FALSE(christmas==christmas_copy);
}