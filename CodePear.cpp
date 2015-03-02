#ifndef ANDROID_HWUI_PATH_RENDER_H
#define ANDROID_HWUI_PATH_RENDER_H

#include <SkTArray.h>

#include "Vertex.h"

class SkMatrix;

namespace android
{
	namespace uirender
	{

		class VertexBuffer
		{
		public:
			VertexBuffer():
			mBuffer(0), 
			mSize(0), 
			mSize(0),
			mCleanupMethod(0)
			{}
			~VertexBuffer()
			{
				if(mCleanupMethod)
					mCleanupMethod(mBuffer);
			}
			
			template <class TYPE>
				TYPE* alloc(int size)
			{
				mSize = size;
				mBuffer = (void*)new TYPE[size];
				mCleanupMethod = &(cleanup<TYPE>);
				return (TYPE*)mBuffer;
			}
			private:
				template <class TYPE>
					static void cleanup(void* buffer)
			{
					delete[] (TYPE*)buffer;
			}
			
			void* mBuffer;
			unsigned int mSize;
			void (*mCleanupMethod)(void);
		}
		
		class PathRenderer
		{
		public:
			static SkRect computerPathBounds(const SkPath &path, const SkPaint *paint);
			
			static void ConvexPathVertices(const SkPath & path, const SkStrokeRect &stroke, bool isAA, const SkMatrix* transform, VertexBuffer* vertexBuffer);
			
			static void RecursiveQuadraticBezierVertices(float ax, float ay, float bx, float by, float cx, float fy, float sqrtInvScaleX, float sqrtInvScaleY, SkTArray<Vertex, true>* outputVertices);
			
			
		}
}
}



static void Circle(Mat& img, Point center, int radius, const void* color, int fill)
{
	Size size = img.size();
	size_t step = img.step;
	
	int pix_size = (int)img.elemSize();
	
	uchar* ptr = img.data;
	
	int err = 0, dx = radius, dy = 0, plus = 1, minus = (radius<<1)-1;
	
	int inside = center.x >= radius&& center.x  < size.width - radius && center.y >= radius && center.y < size.height - radius;
	
#define ICV_PUT_POINT(ptr, x)
	memcpy(ptr+(x)*pix_size, color, pix_size);
	
	while(dx >= dy)
	{
		int mask;
		int y11 = center.y - dy, y12 = center.y + dy, y21 = cneter.y - dx, y22 = center.y + dx;
		int x11 = center.x - dx, x12 = center.x + dx, x21 = center.x - dy, x22 = center.x + dy;
		
		if(inside)
		{
			uchar *tptr0 = ptr + y11*step;
			uchar *tptr1 = ptr + y12*step;
			
			if(fill)
			{
				ICV_HLINE(tptr0, x11, x12, color, pix_size);
				ICV_HLINE(tptt1, x11, x12, color, pix_size);
			}
			tptr0 = ptr + y21*step;
			tptr1 = ptr + y22*step;
			
			if(fill)
			{
				ICV_HLINE(tptr0, x21, x22, color, pix_size);
				ICV_HLINE(tptr0, x21, x22, color, pix_size);
			}
		}
		dy++;
		err += plus;
		plus += 2;
		mask = (err <= 0)-1;
		err -= minus &mask;
		dx += mask;
		minus -= mask&2;
	}
}

enum SkRotationDirection
{
	KCW_SkRotationDirection,
	KCCW_SkRorationDirection
};

enum Transforms
{
	KTranslate_Shift;
	KScale_Shift;
	KAffine_Shift;
	KPerspective_Shift;
	KRecStaysRect_Shift;
}

/* SkNoncopyable is the base class for objects that may do not want to be copied. It hides its copy-constructor and its assignment and operator.
	*/
class SK_API SkNoncopyable
{
public:
SkNoncopyable(){}

private:
	SkNoncopyable(const SkNoncopyable&);
	SkNoncopyable operator=(const SkNoncopyable&);
}

//在一个类中将父类定义为INHERITED，这样就更加清楚逻辑关系了


class SKI_API SkBaseDevice : public SkRefCnt
{
public:
	SK_DECLEAR_INST_COUNT(SkBaseDevice);
	
	SkBaseDevice();
	
	SkBaseDevice(const SkDeviceProperties &deviceProperties);
	
	virtual ~SkBaseDevice();
	
	SkBaseDevice* createCompatibleDevice(const SkImageInfo&);
	
	SkMetaData& getMetaData();
	
	virtual const SkDeviceProperties& getDeviceProperties()const
	{
		return fLeakyProperties;
	}
	
	virtual SkImageInfo imageInfo()const;
	
	
	int width() const
	{
		return this->imageInfo().width();
	}
	
	int height() const
	{
		return this->imageInof().height();
	}
	
	bool isOpaque() const
	{
		return this.ImageInof().isOpaque();
	}
	
	const SkBitmap& accessBitmap(bool changePixels);
	
	bool writePixels(const SkimageInfo& const void*, size_t rowBytes, int x, int y);
	
	void* accessPixels(SkImageInfo* info, size_t rowBytes);
	
	virtual void drawPaint(const SkDraw&, const SkPaint& paint) = 0;
	
	virtual void drawPoints(const SkDraw&, SkCanvas::PointMode, size_t count, const SkPoint[], const SkPaint& paint) = 0;
	
	virtual void drawRect(const SkDraw&, const SkRect& r, const SkPaint& paint) = 0;
	
	}
	
}

class SkDraw
{
public:
	SkDraw();
	SkDraw(const SkDraw& src);
	
	void drawPaint(const SkPaint&)const;
	void drawPoints(SkCanvas::PointMode, size_t count, const SkPaint&, bool forceUseDevice);
	
	void drawRect(cosnt SkRect&, const SkPaint&) const;
}



struct SkMask
{
	enum Format
	{
		kBW_Format,   // 1 bit per pixel mask(e.g. monochrome)
		kA8_Format,   // 8bits per pixel mask(e.g. anti-aliasing)
		k3D_Format,   // 3 8bits per pixel planes: alpha, mul, add
		
		kARGB32_Format,
		kLCD16_Format,
		kLCD32_Format
	}
	
	enum
	{
		kCoutMaskFormat = LCD32_Format + 1;
	}
	
	uint8_5* 	fImage;
	SkIRect		fBountds;
	uint32_t 	fRowBytes;
	Format 		fFormat;
}

class SkAutoMaskFreeImage
{
public:
	SkAutoMaskFreeImage(uint8_t* maskImage)
	{
		fImage = maskImage;
	}
	
	~SkAutoMaskFreeImage()
	{
		SkMask::FreeImage(fImage);
	}
	
	private:
	uint8_t* fImage;
}

void SkDraw::drawBitMap(const SkBitmap& bitmap, const Skmatrix& prematrix, const SkPaint& origPaint) const
{
	SkDEBUGCODE(this->validate());
	
	//nothing to draw
	if(fRC->isEmpty() || bitmap.width() == 0 || bitmap.height() == 0 || bitmap.colorType() == kUnknown_SkColorType) return;
	
	SkPaint paint(origPaint);
	paint.setStyle(SkPaint::kFille_Style);
	
	SkMatrix matrix;
	matrix.setConcat(*fMatrix, prematrix);
	
	if(clipped_out(matrix, *fRC, bitmap.width(), bitmap.height()) 
		return;
	
	if(bitmap.colorType() != kAlpha_8_SkColorType && just_translate(matrix, bitmap))
	{
		SkAutoLockPixels alp(bitmap);
		if (!bitmap.readyToDraw()) return;
	}
	
	SkDraw draw(*this);
	
	draw.fMatrix = &matrix;
	if(bitmap.colorType() == kAlpha_8_SkColorType)
	{
		draw.drawBitmapAsMask(bitmap, paint);
	}
	else
	{
		SkAutoBitmapShaderInstall install(bitmap, paint);
		SkRect r;
		r.set(0, 0, SkIntToScalar(bitmap.width()), SkIntoToScalar(bitmap.height());
		draw.drawRect(r, install.paintWithShader);
	}
}

// very similar with Netherlands national flag
template<typename T, typename C>
static T* SkTQSort_Partition(T* left, T*right, T*pivot, C lessThan)
{
	T pivotValue = *pivot;
	SkTSwap(*pivot, *right);
	T* newPivot = left;
	
	while(left < right)
	{
		if(lessThan(*left, pivotValue)
		{
			SkTSwap(*left, *newPivot);
			newPivot += 1;
		}
		left += 1;
	}
	
	SkTSwap(*right, *newPivot);
	
	return newPivot;
}


int count = 1;
char current = s[0];
for(int i = 0; i < s.Length; i++)
{
	if(current == s[i])
		count++;
	else
	{
		sb.AppendFormat("{0}{1}", count, current);
		count = 1;
		current = s[i];
	}	
}
sb.AppendFormat("{0}{1}", count, current);
return;



/**
	Gives method bitmap should be read to implement a shader. Also determines number and interpretation of extra parameter returned also as a Bitmap;
*/
enum BitmapType
{
	KNone_BitmapType, // shader is not represented as a bitmap;
	kDefault_BitmapType, // Acess bitmap using local coords transformed by matrix.
	kRadial_BitmapType,  // Acess bitmap by transforming local coordinates by the matrix and taking the distance of result from(0, 0)as bitmap column, Bitmap is 1 pixel tall.
	kSweeo_BitmapType
}


virtual BitmapType asABitmap(SkBitmap* outTexture, SkMatrix* out matixt, TileMode xy[2]]);


enum GradientType
{
	kNone_GradientType, 
	kColor_GradientType,
	kLinear_GradientType,
	kRadial_GradientType,
	kRadial2_GradientType,
	kSweep_GradientType,
	kConcial_GradientType,
	kLast_GradientType = kConical_GradientType
}

struct GradientInfo
{
	int fColorCount;
	
	SkColor* fColors;
	SkScalar* fColorOffsets;
	SkPoint fPoint[2];
	SkScalar fRadius[2];
	TileMode fTileMode;
	
	uint32_t fGradientFlags;
};

virtual GradientType asAGraident(GradientInfo* info) const;


/**
*   If the shader subclass is composed of the two shader,  return ture, and if rec is not null, fill it out with info about the shader.
*
*   These are bare pointer; the ownership and reference count are unchanged.

*/

struct ComposeRec
{
	const SkShader* fShaderA;
	const SkShader* fShaderB;
	const SkXfermode* fMode;
}

GLenum checkForError(char* loc)
{
	GLenum errCode;
	const GLubyte *errString;
	
	if((errCode == glGetError() != GL_NO_ERROR)
	{
		errString = glutErrorString(errCode);
		printf("OpenGL error: %s", errString);
		
		if(loc != NULL)
			printf("(%s)", loc);
		printf("\n");
	}
	
	return errCode;
}


#if defined WIN32 || defined WINCE
#include <windows.h>
#undef small
#undef min
#undef max
#undef abs
#endif

#ifdef _OPENMP
#define HAVE_OPENMP

#ifdef _APPLE_
#define HAVE_GCD

#if define _MSC_VER && _MSC_VER >= 1600
#define HAVA_CONCURRENCY




https://www.cs.duke.edu/courses/cps124/spring04/notes/13_npr/mit.pdf
	https://www.cs.duke.edu/courses/cps124/spring04/notes/13_npr/cmu.pdf
	
	
double getPSNR(const Mat& I1, const Mat& I2)
{
	Mat s1;
	absdiff(I1, I2, s1);
	
	s1.convertTo(s1, CV_32F);
	s1 = s1.mul(s1);
	
	Scalar s = sum(s1);
	
	double sse = s.val[0] + s.val[1] + s.val[2];
	
	if (sse <= le-10)
		return 0;
	else
	{
		double mse = sse / (double)(I1.channels() * I1.total());
		
		double psnr = 10.0*log10(255*255)/mse);
		return psnr;
	}
}



#ifndef DBZHANG_HELLO_
#define DBZHANG_HeLLO_

#if define _WIN32
	#if LIBHELLO_BUILD
		#define LIBHELLO_API __declspec(dllexport)
	#else 
		#define LIBHELLO_API __declspec(dllimport)
	#endif
#else
	#define LIBHELLO_API
#endif

LIBHELLO_API void hello(const char* name);
#endif



#ifdef FLANN_EXPORT
#undef FLANN_EXPORT
#endif

#ifdef WIN32
/* win32 dll export/import directives*/
#ifdef FLANN_EXPORTS
	#define FLANN_EXPORT __declspec(dllexport)
#elif defined(FLANN_STATIC)
	#define FLANN_EXPORT
#else
	#define FLANN_EXPORT __declspec(dllimport)
#endif

#else
/* unix needs nothing */
#define FLANN_EXPORT
#enfif

#ifdef FLANN_DEPECATED
#undef FLANN_DEPECATED
#endif

#if (defined _M_X64 && defined _MSC_VER && _MSC_VER > 1400)||
	__GNUC__ >= 4 && defined __x86_64__)
	#if defined WIN32
		#include <intrin.h>
	#endif 
	#if defined __SSE2__ || !defined __GNUC_
		#include <emmintrin.h>
	#endif
#endif

#if defined __BORLANDC__
	#include <fastmath.h>
#else 
	#include <math.h>
#endif

#ifdef HAVE_IPL
	#ifndef __IPL_H_
		#if defined WIN32 || defined _WIN32
			#include <ipl.h>
		#else
			#include <ipl/ipl.h>
		#endif
	#endif
#elif defined __IPL_H__
	#define HAVE_IPL
#endif

#if defined WIN32 || defined _WIN32
	#define CV_CDECL __cdecl
	#define CV_STDCALL __stdcall
#else
	#define CV_CDECL
	#define CV_STDCALL
#endif

#ifndef CV_EXTEN_C
#ifdef __cplusplus
	#define CV_EXTERN_C extern "C"
	#define CV_DEFAULT(val) = val
#else
	#define CV_EXTERN_C
	#define CV_DEFAULT(val)
#endif
#endif


#define CV_CARRAY(counter)
#define CV_CUSTOM_CARRAY(args)
#define CV_EXPORTS_W CV_EXPORTS
#define CV_IN_OUT
#define CV_OUT
#define CV_WRAP


/* CvArr* is used to pass arbitrary array-like data structures
* into functions where the particular array type is recognized at runtime*/

typedef void CvArr;

typedef union Cv32suf
{
	int i;
	unsigned u;
	float f;
}Cv32suf;

typedef union Cv64suf
{
	int64 i;
	uint64 u;
	double f;
}Cv64suf;


#define CV_SWAP(a, b, t) ((t) = (a), (a) = (b), (b)= (a))

/* min & max without jumps*/
#define CV_IMIN(a, b) ^^^^^^^^

通过异或的方法实现绝对值和取最值

typedef uint64 CvRNG;
#define CV_RNG_COEFF 4164903690U

CV_INLINE unsigned cvRandInt(int64 seed CV_DEFAULT(-1))
{}


typedef Algorithm* (*Constructor)(void)
typedef int (Algorithm::*Getter)()const;
typedef void (Algorithm::*Setter)(int);

static sorted_vector<string, Algorithm::Constructor>& alglist()
{
	static sorted_vector<string, Algorithm::Consturctor> alglist_var;
	return alglist_var;
}

Ptr<Algorithm> Algorithm::_create(const string& name)
{
	Algorithm::Contructor c = 0;
	if(!alglist().find(name, c))
		return Ptr<Algorithm>();
	return c();
}


******************************************************
// let iP represent the input vector and iip the output vector


std::vector<Point> *iP = NULL;
std::vector<Point> *iP = NULL;

if(tpsInter == FORWARD_WARP)
{
	iP = &iPIn;
	iiP = &iiPIn;
	
	FLAG_COEEFS_BACK_WARP_SET = true;
	FLAG_COEEFS_BACK_WARP_SET = false;
}else if (tpsInter == BACK_WARP)
{
	iP = &iiPIn;
	iiP = &iPIn;
	
	FLAG_COEFFS_BACK_WARP_SET = false;
	FLAG_COEFFS_FORWARD_WARP_SET = false;
}

******************************************************
// Gauss-Seidel iterative method

#include <stdio.h>
#include <conio.h>
#include <math.h>

define epsilon (0.001)

void main()
{
	int i, j, k, n;
	float a[10][10], x[10];
	
	float sum, temp, error, big;
	
	
	
	for(i = 1; i <= n; i++) x[i] = 0;
	
	do
	{
		big = 0;
		for(i = 1; i <= n; i++)
		{
			sum = 0;
			for(j = 1; j <= n; j++)
			{
				if(j!= i)
				{
					sum +=  a[i][j] * x[j];
				}
			}
			temp = (a[i][n+1]-sum)/ a[i][i]
			error = fabs(x[i]-temp);
			if(error > big) big = error;
			x[i] = temp;
			
		}
	}while(big >= e);
}

void CalculateGradientsD() //计算梯度， 查看一下OpenCV是怎么计算的


typedef struct CvConnectedComp
{
	double are;
	CvScalar value;
	CvRect rect;
	CvSeq* contour;
}CvConnectedComp;

/* sub-pixel interpolation methods */

enum
{
	CV_INTER_NN = 0,
	CV_INTER_LINEAR = 1,
	CV_INTER_CUBIC = 2,
	CV_INTER_AREA = 3,
	CV_INTER_LANCZOS = 4
};

// compute pseudo-inverse of A, equivalent to A.inv(DECOMP_SVD)

SVD svd(A);
Mat pinvA = svd.vt.t()*Mat::diag(1./svd.w)*svd.u.t();

// compute the new vector of parameters in the Levenberg-Marquardt algorithm;

x -= (A.t())*A + lambda*Mat::eye(A.cols, A.rows, A.types()).inv(DECOMP_CHOLESKY)*(A.t()*err);


/**********************************************
Qt efficient connection
***********************************************/

QList<QWidget *> widgets = this.findChildren<QWidget*>();
for(int i = 0; i < widgets.size(); i++)
{
	QWidget *w = widget.at(i);
	
	if(w->inherits("QAbstractSpinBox"))
	{
		this->connect(w, SIGNAL(activated(int)), SLOT(do_update());
	}
	if(w->inherits("QComboBox"))
	{
		this->connect(w, SIGNAL(activated(int)), SLOT(do_update()));
	}
}

/******************************************************
c plus plus variant length argument
******************************************************/

#include <stdarg.h>
void LOG::OutputSuccess(char* text, ...)
{
	va_list argList;
	va_start(argList, text);
	
	logFile = fopen(filename, "a+");
	
	if(!logFile)
		return;
		
	//write the text;
	fprintf(logFile, "<->");
	vfprintf(logFile, text, argList);
	
	putc('\n', logFile);
	
	//close the file
	fclose(logFile);
	logFile = NULL;
	va_end(argList);
}

void LOG::OutPutError(char *text, ...)
{
	//compile string to output
	va_list argList;
	va_start(argList, text);
	
	//Open file to append
	logFile=fopen(filename, "a+");
	if(!logFile) return;
	
	//Write the text
	fprintf(logFile, "<!>");
	vfprintf(logFile, text, argList);
	putc('\n', logFile);
	
	//close the file
	
	fclose(logFile);
	logFile=NULL;
	va_end(argList);
}


class BaseColumnFilter
{
	public:
	virtual ~BaseColumnFilter();
	// To be overriden by the user.
	//
	
	// runs a filtering operation on the set of row
	
	virtual void operator()(const uchar** src, uchar* dst, int dststep, int dstcount, int width) = 0;
	
	// resets the filter state(may be needed for IIR filters)
	
	int ksize; // the aperture size;
	int anchor; // position of the anchor point, normally not used during the processing
};

inline double gauss(double x, double mean, double sigma)
{
	double dist = x-mean;
	return exp(-dist*dist/2/sigma/sigma);
}

void MakeGuassianVector(double sigma, myvec& GAU)
{
	int i, j;
	double threshold = 0.001;// dynamic effective kernel size based on threshold.
	
	int halfWidth = ceilf(2*simga);
	
	GAU.init(halfWidth+1);
	GAU.zero();
	for(int i = 0; i <= halfWidth; i++)
	{
		GAU[i] = gauss((double)i, 0.0, sigma);
	}
	GAU.normalize();
}

void getDirectionalDoG(imatrix& image, ETF& e, mymatrix& dog, myvec& GAU1, myvec& GAU2, double tau)
{
	myvec vn(2);
	
	double x, y, d_x, d_y;
	double weight1, weight2, w_sum1, sum1, sum2, w_sum2;
	
	int s;
	int x1, y1;
	int dd;
	double val;
	
	int half_w1, half_w2;
	
	half_w1 = GAU1.getMax()-1;
	half_w2 = GAU2.getMax()-1;
	
	int image_x, image_y;
	image_x = image.getRow();
	image_y = image.getCol();
	
	for(i = 0; i < image_x; i++)
	{
		for(j = 0; j < image_y; j++)
		{
			sum1 = sum2 = 0.0;
			w_sum1 = w_sum2 = 0.0;
			
			weight1 = weight2 = 0.0;
			vn[0] = -e[i][j].ty;
			vn[1] = -e[i][j].tx;
		}
	}
}



//separable gaussian filter

void gaussian_filter_xy(Mat dst, float sigma, float precision_sigma)
{
	float twoSigma2 = 2.0f*sigma*sigma;
	int halfWidth = ceilf(precision*sigma);
	
	T sum = texSRC<T>(ix, iy);
	float norm = 1;
	for(int i = 1; i <= halfWidth; i++)
	{
		float kernel = expf(-i*i/twoSigma2);
		sum += kernel*(texSRC<T>(ix + dx*i, iy + dy*i) + texSRC<T>(ix + dx*i, iy+dy*i);
		norm += 2*kernel;
	}
	sum /= norm;
	dst(ix, iy) = sum;
}


#define CV_RGB((r), (g), (b)) Scalar((b), (g), (r))

#define CV_PI 3.1415926
#define Cv_LOG2 0.6931478055994

#define CV_SWAP(a, b, t)) ((t) = (a), (a) = (b), (b) = (t))

#ifndef MIN
#define MIN(a, b) ((a)>(b)?(b):(a))
#endif

#ifndef MAX
#define MAX(a, b) ((a)<(b)?(b):(a))


/* min & max without jumps*/

#define CV_IMIN(a, b) ((a) ^ (((a)^(b)) & (((a) < (b)) - 1)))

/* absolute value without jumps */
#ifndef __cplusplus
#define CV_IABS(a) (((a) ^ ((a) < 0 ? -1 : 0)) - ((a) < 0 ? -1 : 0))
#else
#define CV_IABS(a) abs(a)
#endif

#ifndef CV_INLINE
#if defined __cplusplus
	#define  CV_INLINE inline
#elif defined _MSC_VER
	#define CV_INLINE __inline
#else
#define CV_INLINE static
#endif
#endif /*CV_INLINE*/

#if (defined WIN32 || define _WIN32 || define WINCE)&& (defined CVAPI_EXPORTS)
#define CV_EXPORTS __declspec(dllexport)
#else
#define CV_EXPORTS
#endif

#ifndef CVAPI
#define CVAPI(rettype) CV_EXTERN_C CV_EXPORTS rettype CV_CDECL
#endif

/* special informative macros for wrapper generators */

#define CV_OUT
#define CV_IN
#define CV_IN_OUT

#define CV_PROP

/* CvArr* is used to pass arbitrary array-like data structures info functions where the particular array type is recognized at runtime */

typedef void CvArr;

typedef union Cv32suf
{
	int i;
	unsigned u;
	float f;
}
Cv32suf;

/* Line iterator state: */
typedef struct CvLineIterator
{
	/*Pointer to the current point: */
	uchar* ptr;
	
	/*Bresenham algorithm state: */
	
	int err;
	int plus_delta;
	int minus_delta;
	int plus_step;
	int minus_step;
}
CvLineIterator;

BilateralFilter_8u_Invoker

private:
	const Mat *temp;
	Mat *dest;
	int radius, maxk, *space_ofs;
	float *space_weight, *color_weight;
	

static void bilaterFiter_8u(const Mat& src, Mat& dst, int d, double simga_color, double sigma_space, int borderType)
{
	int cn = src.channels();
	int i, j, maxk, radius;
	Size size = src.size();
	
	double gauss_color_coeff = -0.5/(sigma_color*simga_color);
	double gauss_space_coeff = -0.5/(sigma_space*sigma_space);
	
	if(d <= 0)
		radius = cvRound(simga_space*1.5);
	else
		radius = d/2;
	radius = MAX(radius, 1);
	
	d = radius*2 + 1;
	
	Mat temp;
	copyMakeBorder(src, temp, radius, radius, radius, radius,borderType);
	
	vector<float> _color_weight(cn*256);
	vector<float> _space_weight(d*d)
	vector<int> _space_ofs(d*d);
	
	float* colorweight = &_colorweight[0];
	float* space_weight = &_space_weight[0];
	
	int *space_ofs = &_space_ofs[0];
	
	for(i = 0; i < 256*cn; i++)
	{
		color_weight[i] = (float)std::exp(i*i*gauss_color_coeff);
	}
}

_isnan(double x);
_finite(double x);

// assign a length which is slightly more than needed

len = (float)(maxValSrc-minValSrc)*cn;

kExpNumBins = kExpNumBinsPerChannel * cn;

vector<float> _expLUT(kExpNumBins +2);

float *expLUT = &_expLUT[0];

scale_index = kExpNumBins/len;

// initialize the exp LUT
for(i = 0; i < kExpNumBins + 2; i++)
{
	if(lastExpVal > 0.f)
	{
		double val = i/scale_index;
		expLUT[i] = (float)std::exp(val*val*gauss_color_coeff);
		lastExpVal = expLUT[i];
	}
	else
		expLUT[i] = 0.f;
}


void cv::bilaterFilter(InputArray _src, outputArray _dst, int d, double sigmaColor, double sigmaSpace, int borderType)
{
	Mat src = _src.getMat();
	_dst.create(src.size(), src.type());
	
	Mat dst = _dst.getMat();
	if(src.depth() == CV_8U)
	{
		bilaterFilter_8u(src, dst, sigmaColor, sigmaSpace, borderType);
	}
	else if(src.depth() == CV_32F)
	{
		bilateralFilter_32f(src,  dst, d, sigmaColor, sigmaSpace, borderType);
	}
	else
		CV_Error(CV_StsUnsupportedFormat, "Bilateral filtering is only implemented for 8u and 32f images.");
}


#if !defined(CV_IMPL)
#define CV_IMPL extern "C"
#endif // CV_IMPL


This structure defines information of image. We think an image as an offscreen.



//overload function

void operator()(src, dst, dststep, dstcount, width);

filterEngine->apply(src, dst);

这里filterEngine的设计理念
1.分离filter和image
2.抽象filter接口， 3种基本的抽象类
3.init中完成各个filter的初始化，及类型检查
4.在apply，start等函数中，完成filter过程。

The Guided filter is included in Wikipeida as a representative edge-preserving smoothing technique.
The guided filter is included in offical Matlab 2014



//Google test event 

class FooEnvironment: public testing::Environment
{
	public:
	virtual void SetUp()
	{
		std::cout << "Foo FooEnvironment Set Up" << std::endl;
	}
	virtual void TestDown()
	{
		std::cout << "Foo FooEnvironment TearDown" << std::endl;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	testing::AddGlobalTestEnvironment(new FooEnvironment);
	
	testing::initGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

class FooTest: public testing::Test
{
	protected:
	static void SetUpTestCase()
	{
		share_resource_ = new ...;
	}
	static void TearDownTestCase()
	{
		delete shared_resource_ ;
		shared_resource_= NULL;
	}
	
	static T* shared_resource_;
}

Test_F(FooTest, Test1){}  //F:   Fixture 
Test_F(FooTest, Test2){}


#define TESTCASE_NAME(testcase_name) \
	testcase_name##_TEST 

#define NANCY_TEST_(testcase_name) \
class TESTCASE_NAME(testcase_name) : public TestCase \
{\
	public: \
	TESTCASE_NAME(testcase_name)(const char* case_name):TestCase(case_name){};\
	virtual void Run();\
	
	
	private: \
	static TestCase *const testcase_; \
};\
\

TestCase *const TESTCASE_NAME(testcase_name) \
:: testcase_ = UnitTest::GetInstance()->RegisterTest(\ new TESTCASE_NAME(testcase_name)(#testcase_name));\

##(token-pasting)符号连接操作
#（stringizing)
void TESTCASE_NAME(testcase_name)::Run()
/* 注意Run()后面没有{}，之所以这么做是因为宏定义讲测试用例放入到Run方法主体中。
*/


NIESET(FooTest_PassDemo)
{
	EXPECT_EQ(3, Foo(1, 2));
	EXPeCT_EQ(3, Foo(1, 1));
}

#define NIEST(testcase_name) \
	NANCY_TEST_(testcase_name)
#define RUN_ALL_TEST() \
	UnitTest::GetInstance()->RunCases();
	
	
#ifdef FORDLLEXPORT
#define MCV_API __declspec(dllexport)
#else
#define MCV_API
#endif

AFF_AREAMASK affMaskFace = {0}, *paffMaskFace = &affMaskFace;
// bearguments check
MERR_INVALID_PARAM;

MHandle hMemMgr = NULL;
void *membuffer = malloc(1024*1024*40);

MLong size_of_buffer = 1024*1024*40;
hMemMgr = (MHandle)MMemMgrCreate(membuffer, size_of_buffer);
ret = AFF_Create(hMemMgr, MNULL, &hEngine);

if(MOK != ret)
	goto exit;

switch(lFaceOrient)
{
	case ASC_FOC_0:
	lFaceRoll = 0;
	break;
}


exit:
	if(hEngine)
		AFF_Release(hEngine);
	return MOK;

	
	
#define CV_IMPL extern "C"
#define CV_IMPL CV_EXTERN_C

#define Cv_INIT_ALGRITHM(classname, algname, memerinit)\
static ::cv::Algorithm* create##classname()\
{\
	return new classname;\
}\
static ::cv::AlgorithmInfo& class##_info()\
{\
	static ::cv::AlgorithmInfo classname##_info_var(algname, create##_name)\
	return classname##_infor_var;\
}\


#define CV_PASTE2(a, b) a##b
#define CV_PASTE(a, b) CV_PASTE(a, b)
#define CV_MAKE_STR(a) #a


//photoshop decolorization process

void _stdcall Desaturate(unsigned char *Src, int Width, int Height, int Stride)
{
	int X, Y, Max, Min, Value;
	unsigned char* Pointer;
	
	for(Y = 0; Y < Height; Y++)
	{
		Pointer = Src + Y*Stride;
		for(X = 0; X < Width; X++)
		{
			if(*Pointer >= *(Pointer+1))
			{
				Max = *Pointer;
				Min =  *(Pointer + 1);
			}
			else
			{
				Max = *(Pointer + 1);
				Min = *Pointer;
			}
			
			if(*(Pointer + 2) > Max) Max = *(Pointer + 2)
			else if (*(Pointer + 2) < Min)
			{
				Min = *(Pointer + 2);
			}
			
			Value = (Max + Min) >> 1;
			
			*Pointer++ = value;
			*Pointer++ = value;
			*Pointer++ = value;
		}
	}
}

//copy make border


for(Y = 0; Y < Height; Y++)
{
	*(CloneData + (Y+1) * CloneStride) = *(Scan0 + Y*Stride);
	
	CopyMemory(CloneData+CloneStride*(Y+1)+1, Scan0 + Y*Stride + Width - 1);
	
	*(CloneData + (Y+1)*CloneStride, CloneData + Width + 1) = *(Scan0 + Y*Stride + Width - 1);
}

CopyMemory(CloneData, CloneData + CloneStride, CloneStride);
CopyMemory(CloneData+(Height+1)*CloneStride, CloneData+Height*CloneStride, CloneStride);


//image process
GlobalFree(GloneData);



//integral image

for(int y = 0; y < image->height; y++, src+=image->width, sum += sum_width)
{
	int s = sum[-1] = 0;
	for(x = 0; x < image->width; x++)
	{
		s += src[x];
		sum[x] = sum[x-sum_width] + s;
	}
}
//opencv adaptive threshold
void cv::adaptiveThreshold(InputArray _src, OutputArray _dst, double maxValue, int method, int type, int blockSize, double delta)
{
	Mat src = _src.getMat();
	CV_Assert(src.type() == CV_8UC1);
	CV_Assert(blockSize % 2 == 1 && blockSize > 1);
	
	Size size = src.size();
	_dst.create(size, src.type());
	
	Mat dst = _dst.getMat();
	
	if(maxValue < 0)
	{
		dst = Scalar(0);
		return;
	}
	
	Mat mean;
	
	if(src.data != dst.data) mean = dst;
	
	if(src.data == ADAPTIVE_THRESH_MEAN_C)
		boxFilter(src, mean, src.type(), Size(blockSize, blockSize), Point(-1, -1), true, BORDER_REPLICATE);
	else if (method == ADAPTIVE_THRESH_GAUSSIAN_C)
		GaussianBlur(src, mean, Size(blockSize, blockSize), 0, 0, BORDER_REPELICATE);
	else
		CV_Error(CV_stsBadFlag, "Unknown/unsupported adaptive threshold method.");
		
		
	int i, j;
	uchar imaxval = saturate_cast<uchar>(maxValue);
	
	int idelta = type = THRESH_BINARY?cvCeil(delta):cvFloor(delta);
	
	uchar tab[768];
	
	//construct lookup table
	
	//do threshold
}

//Parallel Primitives

class CV_EXPORTS ParallelLoopBody
{
	public:
	virtual ~ParallelLoopBody();
	virtual void operator(const Range& range) const = 0;
}

CV_EXPORTS void parallel_for(const Range& range, const ParallelLoopBody &body)


// synchronization
class CV_EXPORTS Mutex
{
	public:
	Mutex();
	~Mutex();
	Mutex(const Mutex& m);
	
	Mutex& operator=(const Mutex &);
	
	void lock();
	bool trylock();
	void unlock();
	
	struct Impl;
	
	protected:
	Impl* impl;
};

class CV_EXPORTS AutoLock
{
	public:
	AutoLock(Mutex& m):mutex(&m){mutex->lock();}
	~AutoLock(){mutex->unlock();}
	
	protected:
	Mutex* mutex;
	
	private:
	AutoLock(const AutoLock &);
	AutoLock& operator= (const AutoLock&);
};





double myinf = std::numeric_limits<double>::infinity();



inline float qx_max_f3(float a, float b, float c)
{
	return max(max(a, b), c); // can unfold in case max function not inlin.
}

inline double qx_div(double x, double y)
{
	return (y != 0)?(x/y):0; // can be optimized again referenc opencv
}

inline void qx_image_dot_product(double *out, float *a, float *b, int len)
{
	*out++ = double(*a++) * double(*b++);
}

inline void qx_image_dot_product(double *out, float *a, unsigned char *b)
{
	*out++ = double(*a++)*double(*b++);
}

inline void image_zero(float **in, int h, int w, float zero = 0)
{
	memset(in[0], zero, sizeof(float)*h*w);
}

inline unsigned char rgb2gray(unsigned char *rgb)
{
	return (unsigned char(0.229*rgb[0] + 0.587*rgb[1] + 0.114*rgb[2] + 0.5));
}


//good naming and programming habit
float *tempLinePtr = temp.ptr<float>(j);

const float* srcLinePtr = temp.ptr<float>(j);

Mat plane[] = {temp, Mat::zeros(temp.size), CV_32F};

merge(planes, 2, complex);
dft(complex, complex, flag);

split(complex, planes);

void Cloning::solve(const Mat &img, Mat &mod_diff, Mat &result)
{
	const int w = img.cols;
	const int h = img.rows;
}

void Cloning::computeDerivatives(const Mat& destination, const Mat& patch, const Mat& binaryMask)
{
	initVariables(destination, binaryMask);
	
	computeGradientX(destination, destinationGradientX);
	
	computeGradientY(destination, destinationGradientY);
	
	computeGradientX(patch, patchDestinationGraidentX);
	computeGradeintY(patch, patcDestinationGradeintY);
	
	Mat Kernel(Size(3, 3), CV_8UC1);
	Kernel.setTo(Scalar(1));
	erode(binaryMask, binaryMask, Kernel, Point(-1, -1), 3);
	binaryMask.convertTo(binaryMaskFloat, CV_32FC1, 1.0/255.0;)
}

void Cloning::scalarProduct(Mat mat, float r, float g, float b)
{
	vector<Mat> channels;
	split(mat, channels);
	multiply(channels[2], r, channels[2]);
	multiply(channels[1], g, channels[1]);
	multiply(channels[0], b, channels[0]);
	merge(channels, mat);
}

//write program with clear blank line for good reading. just like composition with paragraph

void cv::edgePreservingFilter(InputArray _src, OutputArray _dst, int flags, float sigma_s, float sigma_r)
{
	Mat I = _src.getMat();
	_dst.create(I.size(), CV_8UC3);
	Mat dst = _dst.getMat();
	
	int h = I.size().hegiht;
	int w = I.size().width;
	
	Mat res = Mat(h, w, CV_32FC3);
	dst.convertTo(res, CV_32FC#, 1.0/255.0);
	
	Domain_Filter obj;
	
	Mat img = Mat(I.size(), CV_32FC3);
	I.convertTo(img, CV_32FC3, 1.0/255.0);
	
	obj.filter(image, res, sigma_s, simga_r, flags);
	
	convertScaleAbs(rest, dst, 255);
}

void cv::detailEnhance(InputArray _src, OutputArray _dst, float sigma_s, float simga_r)
{
	Mat I = _src.getMat();
	_dst.create(I.size(), CV_8UC3);
	Mat dst = _dst.getMat();
	
	int h = I.size().hegiht;
	int w = I.size().width;
	float factor = 3.0f;
	
	Mat img = Mat(I.size(), CV_32FC3);
	I.convertTo(img, CV_32FC3, 1.0/255.0);
	
	Mat res = Mat(h, w, CV_32FC1);
	dst.convertTo(res, CV_32FC3, 1.0/255);
	
	Mat result = Mat(img.size(), CV_32FC3);
	Mat lab = Mat(img.size(), CV_32FC3);
	
	vector<Mat> lab_channels;
	cvtColor(img, lab, COLOR_BGR2Lab);
	split(lab, lab_channels);
	
	Mat L = Mat(img.size(), CV_32FC1);
	
	lab_channel[0].convertTo(L, CV_32FC1, 1.0/255);
	
	Domian_Filter obj;
	
	obj.filter(L, res, sigma_s, sigma_r, 1);
	
	Mat detail = Mat(h, w, CV_32FC1);
	
	detail = L - res;
	multiply(detail, factor, detail);
	L = res + detail;
	
	L.convertTo(lab_channel[0], CV_32FC1, 255);
	
	merge(lab_channel, lab);
	cvtColor(lab, result, Color_Lab2BGR);
	result.convertTo(dst, CV_8UC3, 255);
}


typedef void (*LUTFunc)(const uchar* src, const uchar*dst, int len, int cn, int lutcn);

static LUTFunc lutTab[] = 
{
	(LUTFunC)LUT8_8u, (LUTFunc)....;
}

// simplest Image class

class Image
{
	CSize Size;
	T *Buffer;
	
	Image():Buffer(NULL){}
	
	~Image();
}


typedef double (*DotProdFunc)(const uchar* src1, const uchar* src2);

static DotProdFunc getDotProdFunc(int depth)
{
	static DotProdFunc dotProTab[] = 
	{
		(DotProdFunc)GET_OPTIMIZED(dotProd_8u), ....
	};
	
	return dotProdTab[depth];
}

double Mat::dot(InputArray _mat)const
{
	Mat mat = _mat.getMat();
	
	int cn = channels();
	DotProdFunc func = getDotProdFunc(depth());
	
	CV_Assert(mat.type() == type() && mat.size == size && func != 0)
	
	if(isContinous() && mat.isContinuous())
	{
		size_t len = total()*cn;
		if(len = (size_t)(int)len)
			return func(data, mat.data, (int)len);
	}
	
	const Mat *arrays[] = {this, &mat, 0};
	uchar* ptrs[2];
	
	NAryMatIterator it(arrays, ptrs);
	int len = (int)(it.size*cn);
	double r = 0;
	for(size_t i = 0; i < it.nplanes; i++, it++)
	{
		r += func(ptrs[0], ptr[1], len);
	}
	return r;
}



export LD_LIBRARY_PATH="../lib"
gcc main.c -I ../include -L ../lib -lhello -o main



#if (defined WIN32 || defined _WIN32 || defined WINCE || defined __CYGWIN__)
#define CV_EXPORTS __declspec(dllexport)
#elif defined __GNC__ && __GNC__ >= 4
#define CV_EXPORTS __attribute__((visibility("default")))
#else
#define CV_EXPORTS
#endif


#ifndef CV_INLINE
# if defined __cplusplus
#define CV_INLINE static inline
#elif defined __MSC_VER
#define CV_INLINE __inline
#else
#define CV_INLINE static
#endif
#endif

#ifndef CV_EXTERN_C
#ifdef __cplusplus
#define CV_EXTERN_C extern "C"
#else 
#define CV_EXTERN_C
#endif
#endif


#define CV_EXPORTS_W CV_EXPORTS
#define CV_EXPORTS_W_SIMPLE CV_EXPORTS
#define CV_IN_OUT
#define CV_OUT

#define CV_PI 3.1415926




#Photoshop image blending
#define ChannelBlend_Normal(A,B)     ((uint8)(A))
#define ChannelBlend_Lighten(A,B)    ((uint8)((B > A) ? B:A))
#define ChannelBlend_Darken(A,B)     ((uint8)((B > A) ? A:B))
#define ChannelBlend_Multiply(A,B)   ((uint8)((A * B) / 255))
#define ChannelBlend_Average(A,B)    ((uint8)((A + B) / 2))
#define ChannelBlend_Add(A,B)        ((uint8)(min(255, (A + B))))
#define ChannelBlend_Subtract(A,B)   ((uint8)((A + B < 255) ? 0:(A + B - 255)))
#define ChannelBlend_Difference(A,B) ((uint8)(abs(A - B)))
#define ChannelBlend_Negation(A,B)   ((uint8)(255 - abs(255 - A - B)))
#define ChannelBlend_Screen(A,B)     ((uint8)(255 - (((255 - A) * (255 - B)) >> 8)))
#define ChannelBlend_Exclusion(A,B)  ((uint8)(A + B - 2 * A * B / 255))
#define ChannelBlend_Overlay(A,B)    ((uint8)((B < 128) ? (2 * A * B / 255):(255 - 2 * (255 - A) * (255 - B) / 255)))
#define ChannelBlend_SoftLight(A,B)  ((uint8)((B < 128)?(2*((A>>1)+64))*((float)B/255):(255-(2*(255-((A>>1)+64))*(float)(255-B)/255))))
#define ChannelBlend_HardLight(A,B)  (ChannelBlend_Overlay(B,A))
#define ChannelBlend_ColorDodge(A,B) ((uint8)((B == 255) ? B:min(255, ((A << 8 ) / (255 - B)))))
#define ChannelBlend_ColorBurn(A,B)  ((uint8)((B == 0) ? B:max(0, (255 - ((255 - A) << 8 ) / B))))
#define ChannelBlend_LinearDodge(A,B)(ChannelBlend_Add(A,B))
#define ChannelBlend_LinearBurn(A,B) (ChannelBlend_Subtract(A,B))
#define ChannelBlend_LinearLight(A,B)((uint8)(B < 128)?ChannelBlend_LinearBurn(A,(2 * B)):ChannelBlend_LinearDodge(A,(2 * (B - 128))))
#define ChannelBlend_VividLight(A,B) ((uint8)(B < 128)?ChannelBlend_ColorBurn(A,(2 * B)):ChannelBlend_ColorDodge(A,(2 * (B - 128))))
#define ChannelBlend_PinLight(A,B)   ((uint8)(B < 128)?ChannelBlend_Darken(A,(2 * B)):ChannelBlend_Lighten(A,(2 * (B - 128))))
#define ChannelBlend_HardMix(A,B)    ((uint8)((ChannelBlend_VividLight(A,B) < 128) ? 0:255))
#define ChannelBlend_Reflect(A,B)    ((uint8)((B == 255) ? B:min(255, (A * A / (255 - B)))))
#define ChannelBlend_Glow(A,B)       (ChannelBlend_Reflect(B,A))
#define ChannelBlend_Phoenix(A,B)    ((uint8)(min(A,B) - max(A,B) + 255))
#define ChannelBlend_Alpha(A,B,O)    ((uint8)(O * A + (1 - O) * B))
#define ChannelBlend_AlphaF(A,B,F,O) (ChannelBlend_Alpha(F(A,B),A,O))



#############################################
//opencv mask operation

addWeighted : dst = src1 * alpha + (1-alpha) * src2 + gamma

bitwise_not / and / XOR  / OR


//opencv convenient opearation

// reverse the order of the row, column or both in matrix
CV_EXPORTS_W void flip(InputArray src, OutputArray dst, int filpCode);

// replicates the input matrix the specified numbers of times in horizontal or vertical  direction

CV_EXPORTS_W void repeat(InputArray src, int nx, int ny, OutputArray);

CV_EXPORTS_W void hconcat(const Mat* src, size_t nsrc, OutputArray dst);

CV_EXPORTS_W void vConcat(InputArrayofArray src, OutputArray dst);


// sorts independently each matrix row or each matrix column

enum 
{
	SORT_EVERY_ROW = 0,
	SORT_EVERY_COLUMN,
	SORT_ASCEDING = 0,
	SORT_DESCEDING = 16
}
CV_EXPORTS void sort(InputArray src, OutputArray dst, int flags);


//Forms a border around an image. The function copies the source image into the middle of the destination image. The areas to the left, to the right, above and below the copied source images will be filled with extrapolated pixels.
void copyMakeBorder(InputArray src, OutputArray dst, int top, int left, int bottom, int right...);


//Performs advanced morphological transformations
void morphologyEx(InputArray src, OutputArray, in op, InputArray kernel, Point anchor = Point(-1, -1), int iterations = 1, int borderType = BORDER_CONSTANT, const Scalar& borderValue = morphologyDefaultBorderValue());

开闭都是对亮的元素来说的。先腐蚀，去掉了高亮的细节部分，在膨胀，就相当于断开了。先膨胀再腐蚀，原来的空洞被填充。


// Any of the operations can be done in-place. In case of multi-channel images, each channel is processed independently.


// Calculates the integral of an image.

void integral(InputArray src, OutputArray sum, OutputArray titled, int sdepth = -1);

//Using these integral images, you can calculate sum, mean, and standard deviation over specific up-right or rotated rectangular region of the image in a constant time.

// It makes possible to do a fast blurring or fast block correlation with a variable window size, for example multi-channel images, sums for each channel are accumulated independently.



static const float sRGB2XYZ_D65[] = 
{
	
};