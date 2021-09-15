// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.h"
#include "Matrix_test_helpers.h"
#include "unit_test_framework.h"

using namespace std;


// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Fills a 3x5 Matrix with a value and checks
// that Matrix_at returns that value for each element.
TEST(test_fill_basic) {
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  const int value = 42;
  Matrix_init(mat, 3, 5);
  Matrix_fill(mat, value);

  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
    }
  }

  delete mat; // delete the Matrix
}

//Test Init
TEST(test_init) {
    Matrix* mat = new Matrix; // create a Matrix in dynamic memory
    Matrix_init(mat, 4, 6);
    ASSERT_EQUAL(Matrix_width(mat), 4);
    ASSERT_EQUAL(Matrix_height(mat), 6);
    delete mat;
}

//Test width and height
TEST(test_width_and_height) {
    Matrix* mat = new Matrix; // create a Matrix in dynamic memory
    Matrix_init(mat, 6, 7);
    ASSERT_EQUAL(Matrix_width(mat), 6);
    ASSERT_EQUAL(Matrix_height(mat), 7);
    delete mat;
}



//Test row and column
TEST(test_row_and_column) {
    Matrix* mat = new Matrix; // create a Matrix in dynamic memory
    Matrix_init(mat, 6, 7);
    Matrix_fill(mat, 0);

    int* ptr = Matrix_at(mat, 2, 3);
    ASSERT_EQUAL(Matrix_row(mat, ptr), 2);
    ASSERT_EQUAL(Matrix_column(mat, ptr), 3);

    int* ptr1 = Matrix_at(mat, 4, 5);
    ASSERT_EQUAL(Matrix_row(mat, ptr1), 4);
    ASSERT_EQUAL(Matrix_column(mat, ptr1), 5);

    delete mat;
}

//Test at
TEST(test_at) {
    Matrix* mat = new Matrix; // create a Matrix in dynamic memory
    Matrix_init(mat, 6, 7);
    Matrix_fill(mat, 1);
    //border case
    ASSERT_EQUAL(*Matrix_at(mat, 0, 0), 1);
    ASSERT_EQUAL(*Matrix_at(mat, 6, 5), 1);

    //border case
    *Matrix_at(mat, 6, 5) = 7;
    ASSERT_EQUAL(*Matrix_at(mat, 6, 5), 7);

    //border case
    *Matrix_at(mat, 0, 0) = 8;
    ASSERT_EQUAL(*Matrix_at(mat, 0, 0), 8);
    delete mat;
}

//Test fill border
TEST(test_fill_border) {
    Matrix* mat = new Matrix; // create a Matrix in dynamic memory
    Matrix_init(mat, 5, 8);
    Matrix_fill(mat, 0);
    Matrix_fill_border(mat, 10);

    for (int i = 0; i < 5; i++) {
        ASSERT_EQUAL(*Matrix_at(mat, 0, i), 10);
        ASSERT_EQUAL(*Matrix_at(mat, 7, i), 10);
    }
    for (int i = 0; i < 8; i++) {
        ASSERT_EQUAL(*Matrix_at(mat, i, 0), 10);
        ASSERT_EQUAL(*Matrix_at(mat, i, 4), 10);
    }
    delete mat;
}

//Test max 
TEST(test_max) {
    Matrix* mat = new Matrix; // create a Matrix in dynamic memory
    Matrix_init(mat, 5, 8);
    Matrix_fill(mat, 0);
    ASSERT_EQUAL(Matrix_max(mat), 0);

    *Matrix_at(mat, 0, 0) = 10;
    ASSERT_EQUAL(Matrix_max(mat), 10);

    *Matrix_at(mat, 7, 4) = 11;
    ASSERT_EQUAL(Matrix_max(mat), 11);

    delete mat;
}

//Test min column and min value
TEST(test_min_col_val) {
    Matrix* mat = new Matrix; // create a Matrix in dynamic memory

    //basic
    Matrix_init(mat, 5, 8);
    Matrix_fill(mat, 1);
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 0, 0, 5), 0);

    //border
    *Matrix_at(mat, 0, 4) = 0;
    *Matrix_at(mat, 0, 1) = 0;
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 0, 2, 4), 2);
    ASSERT_EQUAL(Matrix_min_value_in_row(mat, 0, 2, 4), 1);
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 0, 2, 5), 4);
    ASSERT_EQUAL(Matrix_min_value_in_row(mat, 0, 2, 5), 0);
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 0, 1, 4), 1);
    ASSERT_EQUAL(Matrix_min_value_in_row(mat, 0, 1, 4), 0);

    delete mat;
}

//Test print
TEST(test_print) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 2, 3);
    Matrix_fill(mat, 0);

   //border case
    *Matrix_at(mat, 0, 0) = 3;
    *Matrix_at(mat, 1, 1) = 3;
    *Matrix_at(mat, 2, 1) = 3;
    ostringstream expected;
    expected << "2 3\n"
        << "3 0 \n"
        << "0 3 \n"
        << "0 3 \n";
    ostringstream actual;
    Matrix_print(mat, actual);
    ASSERT_EQUAL(expected.str(), actual.str());
    delete mat;
}
// ADD YOUR TESTS HERE
// You are encouraged to use any functions from Matrix_test_helpers.h as needed.


// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here
