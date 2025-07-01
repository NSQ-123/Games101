#include<cmath>
#include<Eigen/Core>
#include<Eigen/Dense>
#include<iostream>
#include<Windows.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif



static int test(){

    // Basic Example of cpp
    std::cout << "Example of cpp \n";
    float a = 1.0, b = 2.0;
    std::cout << a << std::endl;
    std::cout << a/b << std::endl;
    std::cout << std::sqrt(b) << std::endl;
    std::cout << std::acos(-1) << std::endl;
    std::cout << std::sin(30.0/180.0*acos(-1)) << std::endl;

    // Example of vector
    std::cout << "Example of vector \n";
    // vector definition
    Eigen::Vector3f v(1.0f,2.0f,3.0f);
    Eigen::Vector3f w(1.0f,0.0f,0.0f);
    // vector output
    std::cout << "Example of output \n";
    std::cout << v << std::endl;
    // vector add
    std::cout << "Example of add \n";
    std::cout << v + w << std::endl;
    // vector scalar multiply
    std::cout << "Example of scalar multiply \n";
    std::cout << v * 3.0f << std::endl;
    std::cout << 2.0f * v << std::endl;

    // Example of matrix
    std::cout << "Example of matrix \n";
    // matrix definition
    Eigen::Matrix3f i,j;
    i << 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0;
    j << 2.0, 3.0, 1.0, 4.0, 6.0, 5.0, 9.0, 7.0, 8.0;
    // matrix output
    std::cout << "Example of output \n";
    std::cout << i << std::endl;
    // matrix add i + j
    // matrix scalar multiply i * 2.0
    // matrix multiply i * j
    // matrix multiply vector i * v

    return 0;
}



int main()
{
    // 设置控制台代码页为UTF-8
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    /*作业描述
    * 给定一个点 P=(2,1), 将该点绕原点先逆时针旋转 45◦，再平移 (1,2), 
    * 计算出变换后点的坐标（要求用齐次坐标进行计算）。
    */

    // 给定点P=(2,1)，转换为齐次坐标
    Eigen::Vector3f p(2.0f, 1.0f, 1.0f);
    std::cout << "原始点P(齐次坐标): \n" << p << std::endl << std::endl;
    
    // 创建旋转矩阵（逆时针旋转45度）
    float angle = 45.0f * M_PI / 180.0f; // 将角度转换为弧度
    Eigen::Matrix3f rotation;
    rotation << std::cos(angle), -std::sin(angle), 0,
                std::sin(angle),  std::cos(angle), 0,
                0,                0,               1;
    
    std::cout << "旋转矩阵（逆时针45度）: \n" << rotation << std::endl << std::endl;
    
    // 应用旋转变换
    Eigen::Vector3f p_rotated = rotation * p;
    std::cout << "旋转后的点: \n" << p_rotated << std::endl << std::endl;
    
    // 创建平移矩阵（平移(1,2)）
    Eigen::Matrix3f translation;
    translation << 1, 0, 1,
                   0, 1, 2,
                   0, 0, 1;
    
    std::cout << "平移矩阵（平移(1,2)）: \n" << translation << std::endl << std::endl;
    
    // 应用平移变换
    Eigen::Vector3f p_final = translation * p_rotated;
    std::cout << "最终变换后的点(齐次坐标): \n" << p_final << std::endl << std::endl;
    
    // 转换为笛卡尔坐标输出
    std::cout << "最终变换后的点(笛卡尔坐标): (" << p_final[0] << ", " << p_final[1] << ")" << std::endl << std::endl;
    
    // 也可以用复合变换矩阵一步完成
    std::cout << "=== 使用复合变换矩阵验证 ===" << std::endl;
    Eigen::Matrix3f composite_transform = translation * rotation;
    std::cout << "复合变换矩阵: \n" << composite_transform << std::endl << std::endl;
    
    Eigen::Vector3f p_final_check = composite_transform * p;
    std::cout << "复合变换结果: \n" << p_final_check << std::endl;
    std::cout << "复合变换结果(笛卡尔坐标): (" << p_final_check[0] << ", " << p_final_check[1] << ")" << std::endl;
    
    return 0;
}

