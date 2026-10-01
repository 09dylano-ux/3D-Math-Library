
#include "../include/Vector3.hpp"
#include "../include/Matrix4.hpp"
#include "../include/Quaternion.hpp"
#include <iostream>
#include <cassert>

int main() {
    std::cout << "=== Running Custom 3D Math Library Unit Tests ===\n\n";

    // Test 1: Vector Cross Product
    Vector3 right{1.0f, 0.0f, 0.0f};
    Vector3 up{0.0f, 1.0f, 0.0f};
    Vector3 forward = right.cross(up);

    assert(forward.z == 1.0f);
    std::cout << "[PASS] Vector3 Cross Product (Right x Up = Forward)\n";

    // Test 2: Matrix Transformation
    Vector3 point{1.0f, 0.0f, 0.0f};
    Matrix4 trans = Matrix4::translate(Vector3{0.0f, 5.0f, 10.0f});
    Matrix4 scale = Matrix4::scale(Vector3{2.0f, 2.0f, 2.0f});

    Matrix4 transformMatrix = trans * scale;
    Vector3 transformedPoint = transformMatrix.transformPoint(point);

    assert(transformedPoint.x == 2.0f);
    assert(transformedPoint.y == 5.0f);
    assert(transformedPoint.z == 10.0f);
    std::cout << "[PASS] Matrix4 Translation * Scale Transformation\n";

    // Test 3: Quaternion SLERP
    Quaternion q1 = Quaternion::angleAxis(0.0f, Vector3{0.0f, 1.0f, 0.0f});
    Quaternion q2 = Quaternion::angleAxis(1.5708f, Vector3{0.0f, 1.0f, 0.0f}); // 90 degrees
    Quaternion mid = Quaternion::slerp(q1, q2, 0.5f); // 45 degrees

    assert(mid.w > 0.0f);
    std::cout << "[PASS] Quaternion SLERP Interpolation\n";

    std::cout << "\nAll 3D Math Library Unit Tests Passed Successfully!\n";
    return 0;
}
