
struct Vector3
{
	float x, y, z;

	Vector3();

	Vector3(float _x, float _y, float _z = 0.0f);

	/// <summary>
	/// The lenght of the vector
	/// </summary>
	/// <returns></returns>
	float Magnitude() const;

	/// <summary>
	/// The squared lenght of the vector
	/// </summary>
	/// <returns></returns>
	float SqrMagnitude() const;

	/// <summary>
	/// The dot product of two vectors
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns></returns>
	static float Dot(Vector3& a, Vector3& b);

	/// <summary>
	/// Adding two vectors
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	Vector3 operator+(Vector3& other);

	/// <summary>
	/// Subtracting a vector from another
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	Vector3 operator-(Vector3& other);

	/// <summary>
	/// Scaling a vector
	/// </summary>
	/// <param name="scalar"></param>
	/// <returns></returns>
	Vector3 operator*(float scalar);

};
