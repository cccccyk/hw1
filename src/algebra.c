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
        printf("Error: Matrix a and b must have the same rows and cols.\n");
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
        printf("Error: Matrix a and b must have the same rows and cols.\n");
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
    // 检查是否满足矩阵乘法的条件：a的列数等于b的行数
    if (a.cols != b.rows) {
        printf("Error: The number of cols of matrix a must be equal to the number of rows of matrix b.\n");
        return create_matrix(0, 0); // 返回一个空矩阵
    }

    Matrix result = create_matrix(a.rows, b.cols); // 创建结果矩阵
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < b.cols; j++) {
            // 计算结果矩阵的每个元素
            result.data[i][j] = 0; // 初始化
            for (int k = 0; k < a.cols; k++) {
                result.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return result;
}

Matrix scale_matrix(Matrix a, double k)
{
    Matrix result = create_matrix(a.rows, a.cols); // 创建结果矩阵
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < a.cols; j++) {
            // 每个元素乘以k
            result.data[i][j] = a.data[i][j] * k;
        }
    }
    return result;
}

Matrix transpose_matrix(Matrix a)
{
    Matrix result = create_matrix(a.cols, a.rows); // 创建转置矩阵，行列数互换
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < a.cols; j++) {
            result.data[j][i] = a.data[i][j]; // 互换行和列的值
        }
    }
    return result;
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