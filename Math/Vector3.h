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
	/// Normalises the vector
	/// </summary>
	void Normalize();

	/// <summary>
	/// The normalised Vector (magnitude of 1)
	/// </summary>
	/// <param name="v"></param>
	/// <returns></returns>
	static Vector3 Normalized(const Vector3& v);

	/// <summary>
	/// The dot product of two vectors
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns></returns>
	static float Dot(const Vector3& a, const Vector3& b);

	/// <summary>
	/// The cross prodct of two vectors
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns></returns>
	static Vector3 Cross(const Vector3& a, const Vector3& b);

	/// <summary>
	/// The distance between the heads of two vectors
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns></returns>
	static float Distance(const Vector3& a, const Vector3& b);
	
	/// <summary>
	/// The squared distance between the heads of two vectors
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns></returns>
	static float SqrDistance(const Vector3& a, const Vector3& b);

	/// <summary>
	/// Projecting a vector onto another
	/// </summary>
	/// <param name="v"></param>
	/// <param name="onto">the target vector to project onto</param>
	/// <returns></returns>
	static Vector3 Project(const Vector3& v, const Vector3& onto);

	/// <summary>
	/// Projecting a vector onto a plane (like a shadow with sun angle of 90°)
	/// </summary>
	/// <param name="v"></param>
	/// <param name="planeNormal">the normal of a the fictional plane</param>
	/// <returns></returns>
	static Vector3 ProjectOnPlane(const Vector3& v, const Vector3& n);

	inline void operator=(const Vector3& other);

	inline void operator+=(const Vector3& other);

	inline void operator-=(const Vector3& other);

	inline void operator*=(const float scalar);

	inline void operator/=(const float scalar);
};

static inline Vector3 operator+(const Vector3& a, const Vector3& b);

static inline Vector3 operator-(const Vector3& a, const Vector3& b);

static inline Vector3 operator*(const Vector3& v, const float scalar);

static inline Vector3 operator*(const float scalar, const Vector3& v);

static inline Vector3 operator/(const Vector3& v, const float scalar);

static inline bool operator==(const Vector3& a, const Vector3& b);

static inline bool operator!=(const Vector3& a, const Vector3& b);