#include "LC_728_self_dividing_numbers.hpp"
#include "CUL/CULInterface.hpp"

using string = std::string;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for( int i = left; i <= right; ++i )
        {
            if( numberIsSeldDividing( i ) )
            {
                result.push_back( i );
            }
        }
        return result;
    }
private:
    bool numberIsSeldDividing( int number )
    {
        auto digits = extractDigits( number );

        for( const auto digit : digits )
        {
            if( digit == 0 || number % digit != 0 )
            {
                return false;
            }
        }

        return true;
    }

    std::vector<int> extractDigits( int number )
    {
        std::vector<int> digits;
        int a = 0;

        while( number > 0 )
        {
            a = number % 10;
            digits.push_back( a );
            number /= 10;
        }
        return digits;
    }
};

LC_728_self_dividing_numbers::LC_728_self_dividing_numbers()
{
}

void LC_728_self_dividing_numbers::SetUp()
{
}

void LC_728_self_dividing_numbers::TestBody()
{
}

void LC_728_self_dividing_numbers::SetUpTestCase()
{
    TestWithCUL::SetUpTestCase();
}

void LC_728_self_dividing_numbers::TearDownTestCase()
{
    TestWithCUL::TearDownTestCase();
}

TEST_F( LC_728_self_dividing_numbers, Test01 )
{
    Solution solution;
    auto result = solution.selfDividingNumbers( 1, 22 );
    for( int i = 1; i < 10; ++i )
    {
        GTEST_ASSERT_EQ( i, result[ i ] );
    }
}

LC_728_self_dividing_numbers::~LC_728_self_dividing_numbers()
{
}

void LC_728_self_dividing_numbers::TearDown()
{
}