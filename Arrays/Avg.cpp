template<typename T>
double Avg(const T arr[], const int n)
{
	return  (double)Sum(arr, n) / n;
}