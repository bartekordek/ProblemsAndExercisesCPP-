#include "LC_1351_count_negative_numbers_in_a_sorted_matrix.hpp"
#include "CUL/CULInterface.hpp"

using string = std::string;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int sum = 0;
        int columnCount = static_cast<int>( grid[0].size() );
        for( const auto& row: grid )
        {
            auto firstVal = binarySearch( row );
            if( firstVal != -1 )
            {
                sum += columnCount - firstVal;
            }
        }

        return sum;
    }
private:
    static int binarySearch( const vector<int>& vec )
    {
        size_t start = 0;
        size_t end = vec.size() - 1;
        size_t mid = 0;
        while( start < end )
        {
            mid = (start + end) / 2;
            if( vec[ mid ] >= 0 )
            {
                start = mid + 1;
            }
            else
            {
                end = mid;
            }
        }
        return vec[ end ] >= 0 ? -1 : (int)end;
    }
};

LC_1351_count_negative_numbers_in_a_sorted_matrix::LC_1351_count_negative_numbers_in_a_sorted_matrix()
{
}

void LC_1351_count_negative_numbers_in_a_sorted_matrix::SetUp()
{
}

void LC_1351_count_negative_numbers_in_a_sorted_matrix::TestBody()
{

}

void LC_1351_count_negative_numbers_in_a_sorted_matrix::SetUpTestCase()
{
    TestWithCUL::SetUpTestCase();
}

void LC_1351_count_negative_numbers_in_a_sorted_matrix::TearDownTestCase()
{
    TestWithCUL::TearDownTestCase();
}

TEST_F( LC_1351_count_negative_numbers_in_a_sorted_matrix, Test00 )
{
    Solution sol;
    vector<vector<int>> input = {
        {  4,  3,  2, -1},
        {  3,  2,  1, -1 },
        {  1,  1, -1, -2 },
        { -1, -1, -2, -3 }};
    auto res = sol.countNegatives( input );
    GTEST_ASSERT_EQ( 8, res );
}

TEST_F( LC_1351_count_negative_numbers_in_a_sorted_matrix, Test01 )
{
    Solution sol;
    vector<vector<int>> input = {
        {  3, 2 },
        {  1, 0 } };
    auto res = sol.countNegatives( input );
    GTEST_ASSERT_EQ( 0, res );
}

LC_1351_count_negative_numbers_in_a_sorted_matrix::~LC_1351_count_negative_numbers_in_a_sorted_matrix()
{

}

void LC_1351_count_negative_numbers_in_a_sorted_matrix::TearDown()
{

}