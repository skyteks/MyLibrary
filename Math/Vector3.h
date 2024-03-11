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
	#define Lenght() Magnitude()

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
	/// <param name="u"></param>
	/// <returns></returns>
	static Vector3 Normalized(const Vector3& u);

	/// <summary>
	/// The dot product of two vectors
	/// a • b = |a| * |b| * cos(θ)
	/// </summary>
	/// <param name="u"></param>
	/// <param name="v"></param>
	/// <returns></returns>
	static float Dot(const Vector3& u, const Vector3& v);

	/// <summary>
	/// The cross prodct of two vectors
	/// </summary>
	/// <param name="u"></param>
	/// <param name="v"></param>
	/// <returns></returns>
	static Vector3 Cross(const Vector3& u, const Vector3& v);

	/// <summary>
	/// The distance between the heads of two vectors
	/// </summary>
	/// <param name="u"></param>
	/// <param name="v"></param>
	/// <returns></returns>
	static float Distance(const Vector3& u, const Vector3& v);
	
	/// <summary>
	/// The squared distance between the heads of two vectors
	/// </summary>
	/// <param name="u"></param>
	/// <param name="v"></param>
	/// <returns></returns>
	static float SqrDistance(const Vector3& u, const Vector3& v);

	/// <summary>
	/// Projecting a vector onto another
	/// </summary>
	/// <param name="u"></param>
	/// <param name="v">the target vector to project u</param>
	/// <returns></returns>
	static Vector3 Project(const Vector3& u, const Vector3& v);

	/// <summary>
	/// Projecting a vector onto another and returning its magnitude
	/// </summary>
	/// <param name="u"></param>
	/// <param name="v"></param>
	/// <returns></returns>
	static float ProjectLenght(const Vector3& u, const Vector3& v);
	/// <summary>
	/// Projecting a vector onto a plane (like u shadow with sun angle of 90°)
	/// </summary>
	/// <param name="u"></param>
	/// <param name="v">the normal of u the fictional plane</param>
	/// <returns></returns>
	static Vector3 ProjectOnPlane(const Vector3& u, const Vector3& v);
	#define Reject(u, v) ProjectOnPlane(u, v)

	/// <summary>
	/// Reflect a vector using another as the mirror
	/// </summary>
	/// <param name="u"></param>
	/// <param name="v"></param>
	/// <returns></returns>
	static Vector3 Reflect(const Vector3& u, const Vector3& v);

	inline void operator=(const Vector3& v);

	inline void operator+=(const Vector3& v);

	inline void operator-=(const Vector3& v);

	inline void operator*=(const float a);

	inline void operator/=(const float a);
};

static inline Vector3 operator+(const Vector3& a, const Vector3& b);

static inline Vector3 operator-(const Vector3& a, const Vector3& b);

static inline Vector3 operator*(const Vector3& u, const float a);

static inline Vector3 operator*(const float a, const Vector3& u);

static inline Vector3 operator/(const Vector3& u, const float a);

static inline bool operator==(const Vector3& u, const Vector3& v);

static inline bool operator!=(const Vector3& u, const Vector3& v);