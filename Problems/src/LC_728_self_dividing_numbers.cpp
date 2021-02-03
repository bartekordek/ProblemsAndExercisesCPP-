#include "LC_728_self_dividing_numbers.hpp"
#include "CUL/CULInterface.hpp"

using string = std::string;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for( int i = left; i <= right; ++i )
        {
            if( i % 10 != 0 )
            {
                if( numberIsSeldDividing( i ) )
                {
                    result.push_back( i );
                }
            }
        }
        return result;
    }
private:
    bool numberIsSeldDividing( int number )
    {
        extractDigits( number );

        for( const auto digit : m_digits )
        {
            if( digit == 0 )
            {
                return false;
            }

            if( number % digit != 0 )
            {
                return false;
            }
        }

        return true;
    }

    void extractDigits( int number )
    {
        m_digits.clear();
        int a = 0;
        while( number > 0 )
        {
            a = number % 10;
            m_digits.push_back( a );
            number /= 10;
        }
    }

    std::vector<int> m_digits;
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

TEST_F( LC_728_self_dividing_numbers, Test00 )
{
    Solution solution;
    auto result = solution.selfDividingNumbers( 1, 22 );
    for( int i = 0; i < 9; ++i )
    {
        std::cout << "i + 1 = " << i + 1 << ", val = " << result[ i ] << "\n";
        GTEST_ASSERT_EQ( i + 1, result[ i ] );
    }
}

TEST_F( LC_728_self_dividing_numbers, Test01 )
{
    Solution solution;
    solution.selfDividingNumbers( 66, 708 );
}

LC_728_self_dividing_numbers::~LC_728_self_dividing_numbers()
{
}

void LC_728_self_dividing_numbers::TearDown()
{
}