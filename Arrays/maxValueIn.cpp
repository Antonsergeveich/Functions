template<typename T>
T maxValueIn(const T arr[], const int n)
{
	T max;
	max = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)max = arr[i];
	}
	return max;
}