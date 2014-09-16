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




