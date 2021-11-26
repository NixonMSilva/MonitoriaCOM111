typedef struct complex
{
	// r - parte real
	// i - parte imaginaria
	double r;
	double i;
} complex_t;

complex_t* allocateComplex (double, double);

void freeComplex (complex_t* a);

void printComplex (complex_t* a);

complex_t* sumComplex (complex_t* a, complex_t* b);

complex_t* subtractComplex (complex_t* a, complex_t* b);

complex_t* multiplyComplex (complex_t* a, complex_t* b);

complex_t* divideComplex (complex_t* a, complex_t* b);