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


class SK_API SkNoncopyable
{
public:
SkNoncopyable(){}

private:
	SkNoncopyable(const SkNoncopyable&);
	SkNoncopyable operator=(const SkNoncopyable&);
}

//在一个类中将父类定义为INHERITED，这样就更加清楚逻辑关系了
