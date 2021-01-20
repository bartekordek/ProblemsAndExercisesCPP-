#include "LC_1588_sum_of_all_odd_length_subarrays.hpp"

#include "CUL/STL_IMPORTS/STD_thread.hpp"
#include "CUL/STL_IMPORTS/STD_iostream.hpp"
#include "CUL/STL_IMPORTS/STD_vector.hpp"
#include "CUL/STL_IMPORTS/STD_unordered_map.hpp"
#include "CUL/STL_IMPORTS/STD_map.hpp"
#include "CUL/STL_IMPORTS/STD_set.hpp"
#include "CUL/STL_IMPORTS/STD_array.hpp"
#include "CUL/STL_IMPORTS/STD_algorithm.hpp"
#include "CUL/STL_IMPORTS/STD_stack.hpp"
#include "CUL/STL_IMPORTS/STD_queue.hpp"
#include "CUL/STL_IMPORTS/STD_functional.hpp"
#include "CUL/STL_IMPORTS/STD_numeric.hpp"

template <typename Type>
using vector = std::vector<Type>;

template <typename Type>
using map = std::map<Type,Type>;

template <typename Type>
using set = std::set<Type>;

using string = std::string;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

std::string toString( const vector<int>& array )
{
    CUL::String result;
    const auto size = array.size();
    for( size_t i = 0; i < size; ++i )
    {
        result += CUL::String( array[i] ) + " ";
    }
    return result.string();
}

LC_1588_sum_of_all_odd_length_subarrays::LC_1588_sum_of_all_odd_length_subarrays()
{

}

LC_1588_sum_of_all_odd_length_subarrays::~LC_1588_sum_of_all_odd_length_subarrays()
{

}

void LC_1588_sum_of_all_odd_length_subarrays::SetUp()
{

}

void LC_1588_sum_of_all_odd_length_subarrays::TearDown()
{

}

void LC_1588_sum_of_all_odd_length_subarrays::TestBody()
{

}

class Solution
{
public:
    int sumOddLengthSubarrays( vector<int>& arr )
    {
        int sum = 0;
        for( int x = 1; x <= arr.size(); x = x + 2 )
        {
            for( int i = 0; i + x <= arr.size(); i++ )
            {
                sum = std::accumulate( arr.begin() + i, arr.begin() + i + x, sum );
            }
        }
        return sum;
    }
    
    int sumOddLengthSubarrays2( vector<int>& arr )
    {
        auto sum = 0;
        const auto arrSize = (int) arr.size();

        vector<int> coefVec;
        coefVec.resize( arrSize );

        if( arr.size() == 1 )
        {
            return arr[ 0 ];
        }

        auto calcCoef = [] ( int arrSize, int coefMax, vector<int>& coefOut )
        {
            auto maxVal = 0;
            for( int i = 0; i < arrSize / 2; ++i )
            {
                maxVal = coefOut[ i ] = std::min( i + 1, coefMax );
                coefOut[ arrSize - i - 1 ] = std::min( i + 1, coefMax );
            }

            if( arrSize % 2 != 0 )
            {
                coefOut[ arrSize / 2 ] = std::min( coefMax, ++maxVal );
            }
        };

        auto sumForSize = [&arr, &calcCoef, &coefVec] ( int sampleSize, int wholeSize )
        {
            sampleSize = sampleSize == wholeSize ? 1 : sampleSize;
            auto sum = 0;
            auto tresholdCoefVal = sampleSize;
            if( tresholdCoefVal == wholeSize )
            {
                tresholdCoefVal = 1;
            }

            auto maxVal = std::min( wholeSize - sampleSize + 1, sampleSize );
            calcCoef( wholeSize, maxVal, coefVec );

            for( int j = 0; j < wholeSize; ++j )
            {
                sum += coefVec[ j ] * arr[ j ];
            }
            return sum;
        };

        for( int currentSize = 1; currentSize <= arrSize; currentSize += 2 )
        {
            auto sumForSizeValue = sumForSize( currentSize, arrSize );
            sum += sumForSizeValue;
        }

        return sum;
    }
};

void LC_1588_sum_of_all_odd_length_subarrays::SetUpTestCase()
{
    TestWithCUL::SetUpTestCase();
}

void LC_1588_sum_of_all_odd_length_subarrays::TearDownTestCase()
{
    TestWithCUL::TearDownTestCase();
}

TEST_F( LC_1588_sum_of_all_odd_length_subarrays, result3 )
{
    Solution solution;
    std::vector<int> input = { 1, 2 };
    auto res = solution.sumOddLengthSubarrays( input );
    GTEST_ASSERT_EQ( 3, res );
}

TEST_F( LC_1588_sum_of_all_odd_length_subarrays, result_58 )
{
    Solution solution;
    std::vector<int> input = { 1,4,2,5,3 };
    auto res = solution.sumOddLengthSubarrays( input );
    GTEST_ASSERT_EQ( 58, res );
}

TEST_F( LC_1588_sum_of_all_odd_length_subarrays, result_66 )
{
    Solution solution;
    std::vector<int> input = { 10,11,12 };
    auto res = solution.sumOddLengthSubarrays( input );
    GTEST_ASSERT_EQ( 66, res );
}

TEST_F( LC_1588_sum_of_all_odd_length_subarrays, result_1 )
{
    Solution solution;
    std::vector<int> input = { 1 };
    auto res = solution.sumOddLengthSubarrays( input );
    GTEST_ASSERT_EQ( 1, res );
}

TEST_F( LC_1588_sum_of_all_odd_length_subarrays, result_68 )
{
    Solution solution;
    std::vector<int> input = { 7,6,8,6 };
    auto res = solution.sumOddLengthSubarrays( input );
    GTEST_ASSERT_EQ( 68, res );
}

TEST_F( LC_1588_sum_of_all_odd_length_subarrays, result_878 )
{
    Solution solution;
    std::vector<int> input = { 6,9,14,5,3,8,7,12,13,1 };
    auto res = solution.sumOddLengthSubarrays( input );
    GTEST_ASSERT_EQ( 878, res );
}