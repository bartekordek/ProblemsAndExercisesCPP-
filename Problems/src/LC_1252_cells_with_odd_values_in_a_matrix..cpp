#include "LC_1252_cells_with_odd_values_in_a_matrix.hpp"

class Solution
{
public:
    int oddCells( int n, int m, vector<vector<int>>& indices )
    {
        auto result = 0;
        const int indicesSize = static_cast<int>( indices.size() );

        std::unordered_map<int, int> xTimes;
        std::unordered_map<int, int> yTimes;

        for( int i = 0; i < indicesSize; ++i )
        {
            ++xTimes[ indices[i][0] ];
            ++yTimes[ indices[ i ][ 1 ] ];
        }

        for( int row = 0; row < n; ++row )
        {
            for( int col = 0; col < m; ++col )
            {
                auto rowCount = 0;
                auto itR = xTimes.find( row );
                if( itR != xTimes.end() )
                {
                    rowCount = itR->second;
                }

                auto colCount = 0;
                auto itC = yTimes.find( col );
                if( itC != yTimes.end() )
                {
                    colCount = itC->second;
                }

                if( (rowCount + colCount) %2 != 0 )
                {
                    ++result;
                }
            }
        }

        return result;
    }
};

LC_1252_cells_with_odd_values_in_a_matrix::LC_1252_cells_with_odd_values_in_a_matrix()
{

}

LC_1252_cells_with_odd_values_in_a_matrix::~LC_1252_cells_with_odd_values_in_a_matrix()
{

}

void LC_1252_cells_with_odd_values_in_a_matrix::SetUp()
{

}

void LC_1252_cells_with_odd_values_in_a_matrix::TearDown()
{

}

void LC_1252_cells_with_odd_values_in_a_matrix::TestBody()
{

}

void LC_1252_cells_with_odd_values_in_a_matrix::SetUpTestCase()
{
    TestWithCUL::SetUpTestCase();
}

void LC_1252_cells_with_odd_values_in_a_matrix::TearDownTestCase()
{
    TestWithCUL::TearDownTestCase();
}

TEST_F( LC_1252_cells_with_odd_values_in_a_matrix, Test00 )
{
    Solution solution;
    std::vector < std::vector<int>> input = { { 0, 1 }, { 1, 1 } };
    auto res = solution.oddCells( 2, 3, input );
    GTEST_ASSERT_EQ( 6, res );
}