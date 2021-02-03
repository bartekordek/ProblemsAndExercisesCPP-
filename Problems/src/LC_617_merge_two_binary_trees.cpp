#include "LC_617_merge_two_binary_trees.hpp"
#include "CUL/CULInterface.hpp"

using string = std::string;

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2)
    {
        if( t1 == nullptr )
        {
            return t2;
        }

        if( t2 == nullptr )
        {
            return t1;
        }

        t1->val += t2->val;

        if( t1->left )
        {
            if( t2->left )
            {
                mergeTrees( t1->left, t2->left );
            }
        }
        else
        {
            if( t2->left )
            {
                t1->left = t2->left;
            }
        }

        if( t1->right )
        {
            if( t2->right )
            {
                mergeTrees( t1->right, t2->right );
            }
        }
        else
        {
            if( t2->right )
            {
                t1->right = t2->right;
            }
        }

        return t1;
    }
};

LC_617_merge_two_binary_trees::LC_617_merge_two_binary_trees()
{
}

void LC_617_merge_two_binary_trees::SetUp()
{
}

void LC_617_merge_two_binary_trees::TestBody()
{
}

void LC_617_merge_two_binary_trees::SetUpTestCase()
{
    TestWithCUL::SetUpTestCase();
}

void LC_617_merge_two_binary_trees::TearDownTestCase()
{
    TestWithCUL::TearDownTestCase();
}

TEST_F( LC_617_merge_two_binary_trees, Test00 )
{
    TreeNode rootLeft( 1 );
    rootLeft.addLeft( 3 )->addLeft( 5 );
    rootLeft.addRight( 2 );

    TreeNode rootRight( 2 );
    rootRight.addLeft( 1 )->addRight( 4 );
    rootRight.addRight( 3 )->addRight( 7 );

    Solution solution;
    solution.mergeTrees( &rootLeft, &rootRight );
}

TEST_F( LC_617_merge_two_binary_trees, Test01 )
{
    TreeNode rootLeft( 1 );
    rootLeft.addLeft( 3 )->addLeft( 5 );
    rootLeft.addRight( 2 );

    TreeNode rootRight( 2 );
    rootRight.addLeft( 1 )->addRight( 4 );
    rootRight.addRight( 3 )->addRight( 7 )->addLeft( 18 );

    Solution solution;
    auto res = solution.mergeTrees( &rootLeft, &rootRight );
    GTEST_ASSERT_EQ( 18, res->right->right->left->val );
}

LC_617_merge_two_binary_trees::~LC_617_merge_two_binary_trees()
{
}

void LC_617_merge_two_binary_trees::TearDown()
{
}