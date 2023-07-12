#include "pch.h"
#include<algorithm>
void  test(int a, int* b, int& c) {
    a = 10;
    *b = 20;
    c = 30;
}
enum LoaiTamGiac {
    TamGiacKhongTonTai,
    TamGiacDeu,
    TamGiacCan,
    TamGiacVuong,
    TamGiacThuong
};

LoaiTamGiac XacDinhLoaiTamGiac(double a, double b, double c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return TamGiacKhongTonTai;
    }

    if (a == b && b == c) {
        return TamGiacDeu;
    }

    if (a == b || b == c || c == a) {
        return TamGiacCan;
    }

    double maxSide = std::max(a, std::max(b, c));
    double sumSquares = a * a + b * b + c * c;

    if (2 * maxSide * maxSide == sumSquares) {
        return TamGiacVuong;
    }

    return TamGiacThuong;
}
/*TEST(testcasename, testname) {
    int a = 0; int b = 1; int c = 3;
    test(a, &b, c);
    EXPECT_EQ(a, 0);
    EXPECT_EQ(b, 20);
    EXPECT_EQ(c, 30);
}*/
TEST(XacDinhLoaiTamGiaccase, TamGiacKhongTonTai1) {
    double a = -1;
    double b = 1;
    double c = 1;
    LoaiTamGiac tamgiac = XacDinhLoaiTamGiac(a, b, c);
    EXPECT_EQ(tamgiac, TamGiacKhongTonTai);
}
TEST(XacDinhLoaiTamGiacCase, TamGiacKhongTonTai2) {
    double a = 1;
    double b = -1;
    double c = 1;
    LoaiTamGiac tamgiac = XacDinhLoaiTamGiac(a, b, c);
    EXPECT_EQ(tamgiac, TamGiacKhongTonTai);
}
TEST(XacDinhLoaiTamGiaccase, TamGiacKhongTonTai3) {
    double a = 1;
    double b = 1;
    double c = -1;
    LoaiTamGiac tamgiac = XacDinhLoaiTamGiac(a, b, c);
    EXPECT_EQ(tamgiac, TamGiacKhongTonTai);
}
TEST(XacDinhLoaiTamGiaccase, TamGiacDeuname) {
    double a = 1;
    double c = 1;
    double b = 1;
    LoaiTamGiac tamgiac = XacDinhLoaiTamGiac(a, b, c);
    EXPECT_EQ(tamgiac, TamGiacDeu);
}
TEST(XacDinhLoaiTamGiaccase, TamGiaccan1) {
    double a = 1;
    double b = 1;
    double c = 2;
    LoaiTamGiac tamgiac = XacDinhLoaiTamGiac(a, b, c);
    EXPECT_EQ(tamgiac, TamGiacCan);
}
TEST(XacDinhLoaiTamGiaccase, TamGiaccan2) {
    double a = 2;
    double b = 1;
    double c = 1;
    LoaiTamGiac tamgiac = XacDinhLoaiTamGiac(a, b, c);
    EXPECT_EQ(tamgiac, TamGiacCan);
}
TEST(XacDinhLoaiTamGiaccase, TamGiaccan3) {
    double a = 1;
    double b = 2;
    double c = 1;
    LoaiTamGiac tamgiac = XacDinhLoaiTamGiac(a, b, c);
    EXPECT_EQ(tamgiac, TamGiacCan);
}
TEST(XacDinhLoaiTamGiacCase, TamGiacVuongname) {
    double a = 6;
    double b = 8;
    double c = 10;
    LoaiTamGiac tamgiac = XacDinhLoaiTamGiac(a, b, c);
    EXPECT_EQ(tamgiac, TamGiacVuong);
}

TEST(XacDinhLoaiTamGiacCase, TamGiacThuongname) {
    double a = 1;
    double b = 2;
    double c = 3;
    LoaiTamGiac tamgiac = XacDinhLoaiTamGiac(a, b, c);
    EXPECT_EQ(tamgiac, TamGiacThuong);
}