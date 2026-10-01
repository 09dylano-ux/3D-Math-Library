
#ifndef QUATERNION_HPP
#define QUATERNION_HPP

#include "Vector3.hpp"
#include <cmath>

struct Quaternion {
    float w{1.0f};
    float x{0.0f};
    float y{0.0f};
    float z{0.0f};

    constexpr Quaternion() noexcept = default;
    constexpr Quaternion(float wVal, float xVal, float yVal, float zVal) noexcept
        : w(wVal), x(xVal), y(yVal), z(zVal) {}

    static Quaternion angleAxis(float angleRadians, const Vector3& axis) noexcept {
        Vector3 normAxis = axis.normalized();
        float halfAngle = angleRadians * 0.5f;
        float sinHalf = std::sin(halfAngle);
        return {
            std::cos(halfAngle),
            normAxis.x * sinHalf,
            normAxis.y * sinHalf,
            normAxis.z * sinHalf
        };
    }

    Quaternion operator*(const Quaternion& rhs) const noexcept {
        return {
            w * rhs.w - x * rhs.x - y * rhs.y - z * rhs.z,
            w * rhs.x + x * rhs.w + y * rhs.z - z * rhs.y,
            w * rhs.y - x * rhs.z + y * rhs.w + z * rhs.x,
            w * rhs.z + x * rhs.y - y * rhs.x + z * rhs.w
        };
    }

    [[nodiscard]] float dot(const Quaternion& rhs) const noexcept {
        return w * rhs.w + x * rhs.x + y * rhs.y + z * rhs.z;
    }

    static Quaternion slerp(Quaternion q1, Quaternion q2, float t) noexcept {
        float cosTheta = q1.dot(q2);

        if (cosTheta < 0.0f) {
            q2 = Quaternion{-q2.w, -q2.x, -q2.y, -q2.z};
            cosTheta = -cosTheta;
        }

        if (cosTheta > 0.9995f) {
            // Linear interpolation for near-identical angles to prevent division by zero
            return Quaternion{
                q1.w + t * (q2.w - q1.w),
                q1.x + t * (q2.x - q1.x),
                q1.y + t * (q2.y - q1.y),
                q1.z + t * (q2.z - q1.z)
            };
        }

        float theta = std::acos(cosTheta);
        float sinTheta = std::sin(theta);

        float w1 = std::sin((1.0f - t) * theta) / sinTheta;
        float w2 = std::sin(t * theta) / sinTheta;

        return Quaternion{
            w1 * q1.w + w2 * q2.w,
            w1 * q1.x + w2 * q2.x,
            w1 * q1.y + w2 * q2.y,
            w1 * q1.z + w2 * q2.z
        };
    }
};

#endif // QUATERNION_HPP
