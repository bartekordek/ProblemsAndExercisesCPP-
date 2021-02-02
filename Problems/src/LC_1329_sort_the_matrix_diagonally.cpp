#include "LC_1329_sort_the_matrix_diagonally.hpp"
#include "CUL/CULInterface.hpp"

CUL::LOG::ILogger* g_logger = nullptr;

class Solution {
public:
    struct Cell
    {
        size_t row = 0;
        size_t col = 0;
    };

    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        vector<vector<int>> result;

        const auto rowSize = mat.size();
        const auto colSize = mat[0].size();
        const auto diagonalCount = rowSize + colSize - 1;
        const auto maxDiagonal = std::sqrt( rowSize * rowSize + colSize * colSize );

        std::vector<Cell> diagPositions;
        diagPositions.reserve( maxDiagonal );

        std::vector<int> values;
        values.reserve( maxDiagonal );

        size_t rowTemp = 0;
        for( size_t row = 0; row < rowSize; ++row )
        {
            rowTemp = row;
            for( size_t col = 0; col < colSize && rowTemp < rowSize; ++col, ++rowTemp )
            {
                Cell cell;
                cell.row = rowTemp;
                cell.col = col;

                values.push_back( mat[rowTemp][col] );
                diagPositions.push_back( cell );
            }
            if( diagPositions.size() > 1 )
            {
                std::sort( values.begin(), values.end() );
                for( size_t cellId = 0; cellId < values.size(); ++ cellId )
                {
                    mat[ diagPositions[cellId].row ][ diagPositions[ cellId ].col ] = values[cellId];
                }
            }
            diagPositions.clear();
            values.clear();
        }

        size_t colTemp = 0;
        for( size_t col = 1; col < colSize; ++col )
        {
            colTemp = col;
            for( size_t row = 0; row < rowSize && colTemp < colSize; ++row, ++colTemp )
            {
                Cell cell;
                cell.row = row;
                cell.col = colTemp;
                values.push_back( mat[ row ][ colTemp ] );
                diagPositions.push_back( cell );
            }
            if( diagPositions.size()>1 )
            {
                std::sort( values.begin(), values.end() );
                for( size_t cellId = 0; cellId < values.size(); ++cellId )
                {
                    mat[ diagPositions[ cellId ].row ][ diagPositions[ cellId ].col ] = values[ cellId ];
                }
            }
            diagPositions.clear();
            values.clear();
        }
        return mat;
    }
};

LC_1329_sort_the_matrix_diagonally::LC_1329_sort_the_matrix_diagonally()
{
}

void LC_1329_sort_the_matrix_diagonally::SetUp()
{
    g_logger = getCUL()->getLogger();
}

void LC_1329_sort_the_matrix_diagonally::TestBody()
{

}

void LC_1329_sort_the_matrix_diagonally::SetUpTestCase()
{
    TestWithCUL::SetUpTestCase();
}

void LC_1329_sort_the_matrix_diagonally::TearDownTestCase()
{
    TestWithCUL::TearDownTestCase();
}

TEST_F( LC_1329_sort_the_matrix_diagonally, Test00 )
{
    Solution solution;
    std::vector < std::vector<int>> input = {
        {3,3,1,1},
        {2,2,1,2},
        {1,1,1,2} };
    auto res = solution.diagonalSort( input );
    GTEST_ASSERT_EQ( 1, res[ 0 ][ 0 ] );
    GTEST_ASSERT_EQ( 1, res[ 0 ][ 1 ] );
    GTEST_ASSERT_EQ( 1, res[ 0 ][ 2 ] );
    GTEST_ASSERT_EQ( 1, res[ 0 ][ 3 ] );
}


LC_1329_sort_the_matrix_diagonally::~LC_1329_sort_the_matrix_diagonally()
{

}

void LC_1329_sort_the_matrix_diagonally::TearDown()
{

}