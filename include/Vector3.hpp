
#ifndef VECTOR3_HPP
#define VECTOR3_HPP

#include <cmath>
#include <iostream>

struct Vector3 {
    float x{0.0f};
    float y{0.0f};
    float z{0.0f};

    constexpr Vector3() noexcept = default;
    constexpr Vector3(float xVal, float yVal, float zVal) noexcept : x(xVal), y(yVal), z(zVal) {}

    constexpr Vector3 operator+(const Vector3& rhs) const noexcept {
        return {x + rhs.x, y + rhs.y, z + rhs.z};
    }

    constexpr Vector3 operator-(const Vector3& rhs) const noexcept {
        return {x - rhs.x, y - rhs.y, z - rhs.z};
    }

    constexpr Vector3 operator*(float scalar) const noexcept {
        return {x * scalar, y * scalar, z * scalar};
    }

    constexpr Vector3 operator/(float scalar) const noexcept {
        return {x / scalar, y / scalar, z / scalar};
    }

    [[nodiscard]] constexpr float dot(const Vector3& rhs) const noexcept {
        return x * rhs.x + y * rhs.y + z * rhs.z;
    }

    [[nodiscard]] constexpr Vector3 cross(const Vector3& rhs) const noexcept {
        return {
            y * rhs.z - z * rhs.y,
            z * rhs.x - x * rhs.z,
            x * rhs.y - y * rhs.x
        };
    }

    [[nodiscard]] float lengthSquared() const noexcept {
        return dot(*this);
    }

    [[nodiscard]] float length() const noexcept {
        return std::sqrt(lengthSquared());
    }

    [[nodiscard]] Vector3 normalized() const noexcept {
        float len = length();
        if (len > 0.00001f) {
            return *this / len;
        }
        return {0.0f, 0.0f, 0.0f};
    }
};

#endif // VECTOR3_HPP
