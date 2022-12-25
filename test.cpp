#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>
#include "Table.hpp"

TEST_CASE("Table test", "[Table]")
{
	const int ROW(2), COL(3), DATA(4);
	auto test = Table<int>(ROW, COL);
	
	CHECK(test.getSize() == ROW * COL);

	test[0][0] = DATA;
	CHECK(test[0][0] == DATA);
}

int main()
{
    return Catch::Session().run();
}
