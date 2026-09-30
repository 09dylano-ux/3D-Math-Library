---

## 4. Custom 3D Math & Matrix Library (C++)

```markdown
# Custom 3D Game Math & Matrix Library

A lightweight, header-only C++ library for 3D game engine mathematics. Provides optimized implementations for vectors, $4\times 4$ matrices, quaternions, and spatial transformations without relying on external third-party math packages.

---

## The Problem It Solves

Relying entirely on high-level engine math wrappers hides what is happening at the hardware level. Game systems require custom transformation pipelines, fast inverse kinematics calculations, and precise camera projections optimized for SIMD registers.

## The Solution

This library implements 3D linear algebra fundamental operations from scratch, focusing on SIMD memory alignment, row-major storage conventions, and zero-allocation math operations.

---

## Key Features

- **Vector Math:** `Vector2`, `Vector3`, `Vector4` (Dot product, Cross product, Normalization, Reflection).
- **Matrix Transformation Operations:** $4\times 4$ Matrices handling Translation, Rotation, Scaling, Perspective Projection, and LookAt view transformations.
- **Quaternions:** Smooth spatial rotations avoiding Gimbal Lock, featuring Spherical Linear Interpolation (`SLERP`).
- **SIMD Layout Compatibility:** Memory-aligned structures ready for SSE instruction optimizations.

---

## Mathematical Foundations (The Metaphor)

Think of a $4\times 4$ Matrix as a **3D GPS coordinate transformer**:
* When an enemy model steps forward, turns left, and scales up in size, multiplying its local vector by a matrix applies all those spatial changes in a single calculation step.

---

## Example Usage

```cpp
#include "Math/Matrix4.hpp"
#include "Math/Vector3.hpp"

// Define a world transform
Vector3 position(0.0f, 5.0f, 10.0f);
Vector3 scale(2.0f, 2.0f, 2.0f);

Matrix4 translationMatrix = Matrix4::Translate(position);
Matrix4 scaleMatrix = Matrix4::Scale(scale);

// Combine transformations
Matrix4 worldMatrix = translationMatrix * scaleMatrix;

// Transform a local point into world space
Vector3 localPoint(1.0f, 0.0f, 0.0f);
Vector3 worldPoint = worldMatrix.TransformPoint(localPoint);
