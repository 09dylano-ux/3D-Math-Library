
#ifndef MATRIX4_HPP
#define MATRIX4_HPP

#include "Vector3.hpp"
#include <array>
#include <cmath>
#include <cstring>

struct Matrix4 {
    // Row-major storage: m[row][col]
    float m[4][4]{{0.0f}};

    constexpr Matrix4() noexcept = default;

    static constexpr Matrix4 identity() noexcept {
        Matrix4 mat;
        mat.m[0][0] = 1.0f; mat.m[1][1] = 1.0f;
        mat.m[2][2] = 1.0f; mat.m[3][3] = 1.0f;
        return mat;
    }

    static Matrix4 translate(const Vector3& translation) noexcept {
        Matrix4 mat = identity();
        mat.m[0][3] = translation.x;
        mat.m[1][3] = translation.y;
        mat.m[2][3] = translation.z;
        return mat;
    }

    static Matrix4 scale(const Vector3& s) noexcept {
        Matrix4 mat = identity();
        mat.m[0][0] = s.x;
        mat.m[1][1] = s.y;
        mat.m[2][2] = s.z;
        return mat;
    }

    Matrix4 operator*(const Matrix4& rhs) const noexcept {
        Matrix4 result;
        for (int r = 0; r < 4; ++r) {
            for (int c = 0; c < 4; ++c) {
                result.m[r][c] = m[r][0] * rhs.m[0][c] +
                                 m[r][1] * rhs.m[1][c] +
                                 m[r][2] * rhs.m[2][c] +
                                 m[r][3] * rhs.m[3][c];
            }
        }
        return result;
    }

    [[nodiscard]] Vector3 transformPoint(const Vector3& p) const noexcept {
        return {
            m[0][0] * p.x + m[0][1] * p.y + m[0][2] * p.z + m[0][3],
            m[1][0] * p.x + m[1][1] * p.y + m[1][2] * p.z + m[1][3],
            m[2][0] * p.x + m[2][1] * p.y + m[2][2] * p.z + m[2][3]
        };
    }
};

#endif // MATRIX4_HPP
