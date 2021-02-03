#pragma once

#include "Gtest.hpp"
#include "CUL/CULInterface.hpp"
#include "CUL/STL_IMPORTS/STD_vector.hpp"
#include "CUL/STL_IMPORTS/STD_unordered_map.hpp"
#include "CUL/STL_IMPORTS/STD_algorithm.hpp"
#include "CUL/STL_IMPORTS/STD_unordered_set.hpp"

template <typename Type>
using vector = std::vector<Type>;

class TestWithCUL:
    public ::testing::Test
{
public:
    CUL::CULInterface* getCUL();
protected:
    static void SetUpTestCase();
    static void TearDownTestCase();
private:
    static CUL::CULInterface* s_culInterface;
};

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():
        val( 0 ),
        left( nullptr ),
        right( nullptr )
    {

    }

    TreeNode( int x ):
            val( x ),
            left( nullptr ),
            right( nullptr )
    {

    }

    TreeNode( int x, TreeNode* left, TreeNode* right ):
        val( x ),
        left( left ),
        right( right )
    {

    }

    TreeNode* addLeft( int input )
    {
        left = new TreeNode( input );
        return left;
    }

    TreeNode* addRight( int input )
    {
        right = new TreeNode( input );
        return right;
    }

};