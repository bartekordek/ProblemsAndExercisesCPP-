#include "LC_1304_find_n_unique_integers_sum_up_to_zero.hpp"
#include "CUL/CULInterface.hpp"

using string = std::string;

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result( n, 0 );
        size_t middle = n / 2;
        int val = 0;
        for( auto i = 0; i < middle; ++i )
        {
            val = static_cast<int>( i - middle );
            result[i] = val;
            result[ n - i - 1 ] = -val;
        }

        return result;
    }
};

LC_1304_find_n_unique_integers_sum_up_to_zero::LC_1304_find_n_unique_integers_sum_up_to_zero()
{
}

void LC_1304_find_n_unique_integers_sum_up_to_zero::SetUp()
{
}

void LC_1304_find_n_unique_integers_sum_up_to_zero::TestBody()
{

}

void LC_1304_find_n_unique_integers_sum_up_to_zero::SetUpTestCase()
{
    TestWithCUL::SetUpTestCase();
}

void LC_1304_find_n_unique_integers_sum_up_to_zero::TearDownTestCase()
{
    TestWithCUL::TearDownTestCase();
}

TEST_F( LC_1304_find_n_unique_integers_sum_up_to_zero, Test00 )
{
    Solution solution;
    size_t size = 5;
    auto res = solution.sumZero( (int)size );
    auto sum = 0;
    for( const auto val: res )
    {
        sum += val;
    }
    GTEST_ASSERT_EQ( 0, sum );
}

TEST_F( LC_1304_find_n_unique_integers_sum_up_to_zero, Test01 )
{
    Solution solution;
    size_t size = 3;
    auto res = solution.sumZero( (int) size );
    auto sum = 0;
    for( const auto val : res )
    {
        sum += val;
    }
    GTEST_ASSERT_EQ( 0, sum );
}

TEST_F( LC_1304_find_n_unique_integers_sum_up_to_zero, Test03 )
{
    Solution solution;
    size_t size = 4;
    auto res = solution.sumZero( (int) size );
    auto sum = 0;
    for( const auto val : res )
    {
        sum += val;
    }
    GTEST_ASSERT_EQ( 0, sum );
}

LC_1304_find_n_unique_integers_sum_up_to_zero::~LC_1304_find_n_unique_integers_sum_up_to_zero()
{

}

void LC_1304_find_n_unique_integers_sum_up_to_zero::TearDown()
{

}