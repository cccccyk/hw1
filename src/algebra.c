#include "algebra.h"
#include <stdio.h>
#include <math.h>

Matrix create_matrix(int row, int col)
{
    Matrix m;
    m.rows = row;
    m.cols = col;
    return m;
}

Matrix add_matrix(Matrix a, Matrix b)
{

    if (a.rows != b.rows || a.cols != b.cols) {
        // 如果不相同，则打印错误消息并返回一个空矩阵
        printf("Error: Matrices dimensions do not match.\n");
        return create_matrix(0, 0); // 返回一个空的矩阵
    }

    Matrix result = create_matrix(a.rows, a.cols); // 创建一个新的矩阵来存储结果
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < a.cols; j++) {
            // 对应元素相加
            result.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }
    return result;
}

Matrix sub_matrix(Matrix a, Matrix b)
{
    if (a.rows != b.rows || a.cols != b.cols) {
        // 如果不相同，则打印错误消息并返回一个空矩阵
        printf("Error: Matrices dimensions do not match.\n");
        return create_matrix(0, 0); // 返回一个空的矩阵
    }

        Matrix result = create_matrix(a.rows, a.cols); // 创建一个新的矩阵来存储结果
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < a.cols; j++) {
            // 对应元素相加
            result.data[i][j] = a.data[i][j] - b.data[i][j];
        }
    }
    return result;
}

Matrix mul_matrix(Matrix a, Matrix b)
{
    // ToDo
    return create_matrix(0, 0);
}

Matrix scale_matrix(Matrix a, double k)
{
    // ToDo
    return create_matrix(0, 0);
}

Matrix transpose_matrix(Matrix a)
{
    // ToDo
    return create_matrix(0, 0);
}

double det_matrix(Matrix a)
{
    // ToDo
    return 0;
}

Matrix inv_matrix(Matrix a)
{
    // ToDo
    return create_matrix(0, 0);
}

int rank_matrix(Matrix a)
{
    // ToDo
    return 0;
}

double trace_matrix(Matrix a)
{
    // ToDo
    return 0;
}

void print_matrix(Matrix a)
{
    for (int i = 0; i < a.rows; i++)
    {
        for (int j = 0; j < a.cols; j++)
        {
            // 按行打印，每个元素占8个字符的宽度，小数点后保留2位，左对齐
            printf("%-8.2f", a.data[i][j]);
        }
        printf("\n");
    }
}