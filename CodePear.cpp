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





