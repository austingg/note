QRect dirtyRect = event->rect();
painter->drawImage(dirtyRect, image, dirtyRect);


update(QRect(lastPoint, endPoint).normalized().adjusted(-rad, -rad, rad, rad);
QPrinter printer(QPrinter::HighResolution);
QPrintDialog *printDialog = new QPrintDialog(&printer, this);


setCentralWidget(scribeArea);
setWindowTitle(tr("xxx"));

void MainWindow::closeEvent(QCloseEvent *event){
	if(maybeSave()){
		event->accept();
		}
	else event->ignore();
	}
	
QString filename = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::currentPath());
QColor color = QColorDialog::getColor();


bool ok;
int newWidth = QInputDialog::getInteger(this, tr("Scribble"), tr("Select pen width"),....., &ok)
if(ok){
	scribeArea->setPenWidth(newWidth);
	

connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));

menuBar()->addMenu(fileMenu);
statusBar()->showMessage();

QSplitter *splitter = new QSplitter;
splitter->addWidget(table);
splitter->addWidget(pieChart);
splitter->setStrethcFactor(0, 0);
splitter->setStretchFactor(1, 1);

setCentralWidget(splitter);

QStringList
QRubberBand   QRegion

QAbstractItemView::horizontalScrollBar()->setRange(0, 0);
verticalScrollBar()->setRange(0, 0);

Qt::DecorationRole    Qt::Dense4Pattern

painter.store();
painter.restore();


QDialogButtonBox
QGroupBox
QPushButton

QGroupBox *horizontalGroupBox = new QGroupBox(tr("Horizontal box"));
QHBoxLayout *layout = new QHBoxLayout;
for(int i = 0; i < NumButtons; ++i)
{
	button[i] = new QPushButton(tr("Button %1").arg(i + 1));
	layout->addWidget(button[i]);	
}
horizontalGroupBox->setLayout(layout);

setColumnStretch(1, 20);
layout->setColumnStretch(2, 20);


Project: animatedtiles

QTimer timer;
timer.start(125);
timer.setSingleShot(true)
trans = rootState->addTransition(&timer, SIGNAL(timeout()), ellipseState);
trans.addAnimation(group);

QTimer timer = new QTimer(this);
connect(timer, SIGNAL(timeout()), this, SLOT(update()));

timer->start(1000);

static const QPoint hourHand[3] = {
	QPoint(7, 8),
	QPoint(-7, 8), 
	QPoint(0, -40)
};

QColor hourColor(127, 0 , 127);
QColor minuteColor(0, 127, 127, 191);

QTime time = QTime::currentTime();


painter.save();
painter.rotate(30);
painter.drawConvexPolygon(hourHand, 3);
painter.restore();

for(int i = 0; i < 12; ++i){
	painter.drawLine(88, 0, 96, 0);
	painter.rotate(30.0);
	}
	
painter.setPen(Qt::NoPen);
painter.setBrush(minuteColor);
painter.save();
painter.rotate();
painter.restore();

for(int j = 0; j < 60; ++j){
	if((j % 5) != 0)
		painter.drawLine(92, 0, 96, 0);
	painter.rotate(6.0);
}


QPainterPath shape() const;
Chip(const QColor &color, int x, int y);

Q_UNUSED(widget);

QVarLengthArray<QLineF, 36> lines;



class View:: public QFrame
{
	Q_OBJECT
public:
	View(const QString &name, QWidget *parent = 0);
	
	QGraphicsView *view() const;
	
private solts:
	void resetView();
	void setResetButtonEnabled();
	void setupMatrix();
	void toggleOpenGL();
	void toggleAntialiasing();
	void print();
	
	void zoomIn();
	void zoomOut();
	void rotateLeft();
	void rotateRight();
	
private:
	QGraphicsView *graphcisView;
	QLabel *label;
	QToolButton *openGLButton;
	QToolButton *antialiasButton;
	QToolButton *printButton;
	QToolButton *resetButton;
	QSlider *zoomSlider;
	QSlider *rotateSlider;

};


setFrameStytle(SunKen | StyledPanel);
graphicsView = new GraphicsView;
graphicsView->setRenerHint(QPainter::Anialiasing, false);
graphicsView->setDragMode(QGraphicsView::RubberBandDrag);

setLayout(topLayout);

QMatrix matrix;
QVariant


emit signal

QColormap
QLine QLineF
QPainterPathStroker
QPalette
QPolygon QPolygon

fillable outlines for a give painter path.

setBackgroundRole(QPalette::Base);

The QPainterPath class provides a containter for painting operations, enabling graphical shapes to be constructed
and reused.
A painter path is an object composed of a number of graphical building blocks(such as rectangle, ellipse, lines, and curves). 
and can be used for filling, outlining, and clipping.

the main advantage of painter paths over normal drawing operations is that complex shapes only need to be created once, but they
can be drawn many times using only calls to QPainter::drawPath().


The transformation example shows how transformations influence the way that QPainter renders graphics primitives.

QPainter provides highly optimized funcions to do most of the darawing GUI programs require.It can draw everythin from simple graphical primitives(represented by the QPoint, QLine, QRect, QRegion and QPolygon classes.
to complex shapes like vector paths. In Qt vector paths are represented by the QPainterPath class. QPainterPath provides a container for  painting operations, enabling graphical shapes to be construted and reused.

To generate  fillable outlines for a given painter path, use the QPainterPathStroker class.
Lines and outlines are drawn using the QPen class. 
The pen's brush is a QBrush object used to fill stroks generated with the pen.
Shapes are filled using the QBrush class. A brush is defined by its color and its style(i.e. its fill pattern)
QColor also support alpha-blended outlining and filling(specifying the transparency effect);
The avaliable fill pattern are described by the Qt::BrushStyle enum. These include basic patterns spanning from 
uniform color to very sparse pattern, various line combinations, gradient fills and texture.Qt provides the QGradient class to define custom gradient fills,
while texture patterns are specified using the QPixmap class.





class Q_GUI_EXPORT QPainterPath
{
public:
	enum ElementType{
		MovetoElement,
		LineToElement,
		CurveToElement,
		CurveToDataElement
		};
	class Element{
	public:
		qreal x;
		qreal y;
		ElementType type;
		}
	bool isMoveTo() const {return type == MoveToElement;}
	bool isLineTo() const {return type == LineToElement;}
	
	operator QPointF() const{return QPointF(x, y);}
	bool operator == (const Element &e) const 
	inline bool operator != (const Element &e) const {return !operator == (e);}
	
	
	
	void setFillRule(Qt::FillRule fillRule);
	
	qreal slopeAtPercent(qreal t) const;
	QPointf pointAtPercent(qreal t) const;
	
	QPainterPath united(const QPainterPath &p) const;
	QPainterPath intersected(const QPainterPath &p) const;
	QPainterPath substracted(const QPainterPath &p) const;
	
	
	
}


You can convert the QPainterPath to QPolygonF with toFillPolygon() method, and calculate the area of the resulting polygon.

The coordinate system is controlled by the QPainter class. 
Together with the QPainteDevice and QPaintEngine classes, QPainter
form the basis of Qt's painting system. QPaitner is used to perform drawing
operations. QPaintDevice is an abstraction of a two dimensional space that canbe painted on using a QPainter.
and the QPaintEngine provides the interface that the painter uses to draw onto different types of devices.

the default coordiante system of a paint device has its origin at the top-left corner.
The QUndoStack class is a stack of QUndoCommand objects.


Qt's Undo Framework is an implementation of command pattern, for implementing undo/redo
functionality in applications.
The command pattern is based on the idae that all editing in an 
application is done by creating instances of command object.
Command objects apply changes to the document and are stored on 
a command stack. Furthermore, each command knows how to undo its changes
to bring the document back to it's previous state. it is also 
possible to redo a sequence of commans by traversing the stack upwards and calling
redo on each command.

QUndoCommand is the base class of all commands stored on an undo stack.
It can apply undo and redo a single change in the document.

QUndoStack is a list of QundoCommand objects, It contains all the commands executed on the 
document and can roll the document's state backwards or forwards by undoing or redoing them.

QUndoGroup is a group of undo stacks. It is useful when an application contains more than
one undostack, typically one for each opened documetn. QUndoGroup provides a
single pair of undo/redo slots for all the stacks in the group.

QUndoView is a widget which shows the contens of an undo stack, Clicking on a command in the 
view rolls the document's state backwords or forwards to that command.


Command compression: used to compress sequences of commands into single command.

QUndoStack provides convenient undo and redo QAction objects that can be inserted into 
a menu or a toolbar.

QGraphics View 体系结构
GraphicsView 提供的是一种类似于Qt model-view的编程。多个View可以监视同一个场景。
而场景包含多个具有多种几何外形的items。

场景
QGraphicsScene表示GraphicsView中的场景，它有以下职责：
为管理大量的items提供一个快速接口。
传播事件到每个item。
管理item的状态，例如选择，焦点处理等。
场景作为QGraphicsItem对象的容器。通过调用QGraphicsScene::addItem
把这些Item添加到场景中。可以使用items得到item.



stdint.h是c99中引进的一个标准C库头文件。
C99中，<stdint.h>定义了几种扩展的整数类型和宏。
<stdint.h>中的敞亮，定义以上各类型数的最大最小值。


class CV_EXPORTS LineIterator
{
	public: 
	LineIterator(const Mat& img, Point &pt1, Point &pt2, int connectivity, bool left_to_right)
	{
		uchar* operator*();
		LineIterator& operator++();
		LineIterator operator ++(int);
		
		Point pos() const;
		uchar* ptr();
		const uchar* ptr0;
		int step, elemSize;
		int err, count;
		int minusDelta, plusDelta;
		int minusStep, plusStep;
	}
}

CV_ExPORTS_W void fillPoly(Mat &img, const Point** pts,  const int* 
npts, int ncontours, const Scalar& color, int lineType = 8, inft shift = 0);
	

Load AA.dll failed-java.lang.UnsatisfiedLinkError: E:\AdNetwork.dll
可能存在依赖关系，注意加载顺序

void getMaxMin(float *arr, int size, float *max, float *min)
{
	float *p = arr, *endp = arr + size;
	
	if(size % 2 != 0)
	{
		*max = *min = *p++;
	}
	else
	{
		if(*p > *(p+1))
		{
			*max = *p;
			*min = *(p+1);
		}
		else
		{
			*max = *(p + 1);
			*min = *p;
		}
		p += 2;
	}
	while( p ! = endp)
	{
		if(*p > *(p + 1))
		{
			if(*p > *max) *max = *p;
			if(*(p+1) < *min) *min = *p;
		}
		else
		{
			if(*(p+1) > *max) *max = *(p + 1);
			if(*p < *min) *min = *p;
		}
		
		p += 2;
	}
}

private/qbezier_p.h

QT_MODULE(Gui)

class Q_AUTOTEST_EXPORT QPathClipper
{
	public:
	enum Operation
	{
		BoolAnd,
		BoolOr,
		BoolSub,
		Simplify
	};
	
	public:
	
	QPathClipper(const QPatinterPath &subject, 
	const, QPainterPath& clip);
	
	QPainterPath clip(Operation op = BoolAnd);
	
	bool intersect();
	bool contains();
	
	private:
	
	Q_DISABLE_COPY(QPathClipper)
	
	enum ClipperMode
	{
		ClipMode,
		CheckMode
	};
	
	struct QPathVertex
	{
	public: 
		QpathVertex(const QPointF& p = QPointF(), int e = -1);
		
		opeateor QPointF() const;
		
		int edge;
		
		qreal x;
		qreal y;
		
		class QPathEdge
		{
			public:
				enum Traversal
				{
					RightTraversal,
					LeftTraveersal
				};
				
				enum Direction
				{
					Forward, 
					Backward
				};
				
				enum Type
				{
					Line, 
					Curve
				};
				
				QPathEdage(int a = -1, int b = -1);
				
				mutable int flag;
				
		}
		
	}
}


void Polygon::translate(int dx, int dy)
{
	register QPoint *p = data();
	register int i = size();
	QPoint pt(dx, dy);
	while(i--)
	{
		*p += pt;
		p++;
	}
}


QPolygon QPolygon::united(const QPolygon &r) const
{
	QPainterPath subject;
	subject.addPolygon(*this);
	
	QPainterPath clip;
	clip.addPolygon(r);
	
	return subject.united(clip).toFillPoly().toPolygon;
}


class Q_GUI_EXPORT QRubberBand: public QWidget
{
	Q_OBJECT
	
	public:
	
	enum Shape{Line, Rectangle};
	
	explicit QRubberBand(Shape, QWidget * = 0);
	
	~QRubberBand();
	
	Shape shape()const;
}


qbitmap.h
qtimer.h


The QRubberBand class provides a rectangle or line that can indicate a selection or a boundary


Q_INIT_RESOURCE(basicdrawing);
QApplication app(argc, argv);
QApplication::addLibraryPath("./plugins");
QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));

Window window;
window.setWindowFlags(window.windowFlags()&~Qt::WindowMaimizeButtonHint);


class Q_GUI_EXPORT QPainterPath
{
	public:
		enum ElementType
		{
			MoveToElement,
			LineToElement,
			CurveToElement,
			CurveToDataElement
		};
		
		class Element
		{
			public:
				qreal x;
				qreal y;
				ElementType type;
				
				bool isMoveTo() const{return type == MoveToElement;}
				bool isLineTo() const {return type == LineToElement;}
				bool isCurveTo() const{ return type == CurveToElement;}
				
				operator QPointF() const {return QPointF(x, y);}
				
				bool operator== (const Element &e)const { return qFuzzyCompare(x, e.x)&& qFuzzyCompare(y, e.y);}
				
				inline operator != (const Element &e) const return !operator==(e);}
				
		}
		
		QPainterPath();
		
		explicit QPainterPath(const QPointF &startPoint);
		
		QPainterPath(const QPainterPath &other);
		
		QPainterPath &operator=(const QPainterPath &other);
		
		bool intersects(const QPainterPath &p) const;
		
		bool contains(const QPainterPath &p) const;
		
		QPainterPath united(const QPainterPath &r) const;
		
		QPainterPath intersected(const QPainterPath &r) const;
		
		QPainterPath substracted(const QPainterPath &r) const;
		QPainterPath substractedInversed(const QPainterPath &r) const;
		
}

template<typename _Tp> class Rect_
{
	public:
	typedef _Tp value_type;
	
	Rect_();
	Rect_(_Tp _x, _Tp _y, _Tp _width, _Tp _height);
	Rect_(const Rect_& r);
	Rect_(const Point_<_Tp>&org, const Size_<_Tp>& sz);
	Rect_(const Point_<_Tp>& pt1, const Point_<Tp>& pt2);
	
	Rect_& operator=(const Rect_& r);
	Point_<Tp> t1() const;
	Point_<Tp> br() const;
	
	_Tp area()const;
	
}

typedef Point_<int> Point2i;
typedef Point2i Point;
typedef Rect<int> Rect;
typedef Point_<float> Point2f;
typedef Point_<double> Point2d;
typedef Point3_<int> Point3i;
typedef Point3_<float> Point3f;
typedef Point3_<double> Point3d;

union
{
	struct{
		qreal x1, y1, x2, y2;
	}linear;
	
	struct{
		qreal cx, cy, fx, fy, radius;
		}radial;
	struct{
		qreal cx,cy, angle;
		}conical;
	void *dummy;
}


void View::print()
{
#ifndef QT_NO_PRINTER
	QPrinter printer;
	QPrinterdialog dialog(&printer, this);
	if(dialog.exec() == Dialog::Accepted)
	{
		QPainter painter(&printer);
		graphicsView->render(&painter);
	}
#endif
}

void View::toggleOpenGL()
{
#ifndef QT_NO_OPENGL
		graphicsView->setViewPort(openGlButton->isChecked()? new QGLWidget(QGLFormat(QGL::SampleBuffers): new QWdiget);
#endif
}


Cohen-Sutherland Line Clipping
Liang-Barsky Line Clipping : use parametric form to describe the line/ representation

Sutherland-Hodgman Polygon Clipping : convex polygon cliping
Weiler-Atherton Polygon Clipping : this algorithm provides a general polygon-clipping approach that canbe used to clip a fill area that is either a convex polygon or a concave polygon.


#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "glut32.lib");

float kernel[9] = {1.0, -2.0, 1.0, 4.0, -2.0, -1.-,};

CvMat km = cvMat(3, 3, CV_32FC1, k);

copyMakeBorder

The QBrush class defines the fill pattern of shapes drawn by QPainter
.

a brush has a style, a color, a gradient and a texture.

Pen style 设置线型

ui.comboBox.addItem(icon, "");

TileIndex tile_index = {tx, ty};


void process_tile(MyPaintTiledSurface *self, int tx, int ty)
{
	TitleIndex tile_index = {tx, ty};
	OperationDataDrawDab *op = operation_queue_pop(self->operation_queue, tile_index);
	if(!op)
	{
		return;
	}
	
	MyPaintTileRequest request_data;
	const int mipmap_level = 0;
	
	mypaint_tile_request_init(&request_data, mimmap_level, tx, ty, FALSE);
	
	mypaint_tile_surface_tile_request_start(self, &request_data);
	uint16_t *rgba_p = request_data.buffer;
	
	if(!rgba_p)
	{
		printf("Warning: Unable to get tile!\n");
		return;
	}
	
	uint16_t mask[MYPANIT_TILE_SIZE*MYPAINT_TILE_SIZE + 2*MYPAINT_TILE_SIZE];
	
	while(op)
	{
		process_op(rgba_p, mask, tile_index.x, tile_index.y, op);
		free(op);
		op = operation_queue_pop(self->operation_queue, tile_index);
	}
	
	mypaint_tiled_surface_tile_request_end(self, &request_data);
}// end of process tile.

gboolean draw_dab_internal(MyPaintTileSurface *self, float x, float y, 
							float radius, 
							float color_r, float color_g, float color_b,
							float opaque, float hardness,
							float color_a,
							float aspect_ratio, float angle,
							float lock_alpha,
							float colorize
							)
{
	OperationDataDrawDab op_struct;
	OperationDataDrawDab *op = &op_struct;
	op->x = x;
	op->y = y;
	
	op->radius = radius;
	op->aspect_ratio = aspect_ratio;
	op->angle = angle;
	op->opaque = CLAMP(opaque, 0.0f, 1.0f);
	op->hardness = CLAMP(hardness, 0.0f, 1.0f);
	op->lock_alpha = CLAMP(lock_alpha, 0.0f, 1.0f);
	op->colorize = CLAMP(colorize, 0.0f, 1.0f);
	
	if(op->raidus < 0.1f) return FALSE;
	if(op->hardness == 0.0f) return FALSE;
	if(op->opaque == 0.0f) return FALSE;
	
	float r_fringe = raidus + 1.0f;
	
	int tx1 = floor(floor(x - r_fringe)/MYPAINT_TILE_SIZE);
	int tx2 = floor(floor(x + r_fringe) / MYPAINT_TILE_SIZE);
	int ty1 = floor(floor(y - r_fringe) / MYPAINT_TILE_SIZE);
	int ty2 = floor(floor(y + r_fringe) / MYPAINT_TILE_SIZE);
	
	for (int ty = ty1; ty1 <= ty2; ty++)
	{
		for(int tx = tx1; tx <= tx2; tx++)
		{
			const TileIndex tile_index = {tx, ty};
			OperatonDataDrawDab *op_copy = (OperationDataDrawDab*)malloc(sizeof(OperationDataDrawDab));
			*op_copy = *op;
			operation_queue_add(self->operation_queue, tile_index, op_copy);
		}
	}
	
	update_dirty_bbxo(self, op);
}


typedef enum
{
	SurfaceTransactionPerStrokeTo,
	SurfaceTransactionPerSroke
}SurfaceTransaction;

typedef struct
{
	char *test_case_id;
	MyPaintTestsSurfaceFactory factory_function;
	gpointer factory_user_data;
	
	float brush_size;
	float scale;
	int iterations;
	const char* brush_file;
	SurfaceTransaction surface_transaction;
}SurfaceTestData;

int test_surface_drawing(void *user_data)
{
	SurfaceTestData *data = (SurfaceTestData *)user_data;
	char* event_data = read_file("events/painting20sec.dat");
	char* brush_data = read_file(data->brush_file);
	
	assert(event_data);
	assert(brush_data);
	
	MyPaintSurface *surface = data->factory_function(data->factory_user_data);
	MyPaintBrush *brush = mypaint_brush_new();
	myPaintUtilsStrokePlayer *player = mypaint_utils_stroke_player_new();
	
	mypaint_brush_from_string(brush, brush_data);
	mypaint_brush_set_base_value(brush, MYPAINT_BRUSH_SETTING_RADIUS_LOGARITHMIC, log(data->brush_size));
	
	mypaint_utils_stroke_player_set_brush(player, brush);
	mypaint_utils_stroke_player_set_surface(player, surface);
	mypaint_utils_stroke_player_set_source_data(play, data);
	mypaint_utils_stroke_player_set_scale(player, scale);
	
	if(data->surface_transaction == SurfaceTransationPerStroke)
	{
		
	}
	
}

typedef struct _MyPaintSurface MyPaintSurface;
struct _MyPaintSurface;

typedef void (*MyPaintSurfaceGetColorFunction)(struct _MyPaintSurface *self, float x, float y, float radius, float *color_r, float *color_g, float *color_b);

typedef int (*MyPaintSurfaceDrawDabFunction)(struct _MyPaintSurface *self, 
								float x, float y,
								float radius, 
								float color_r, float color_g, float color_b,
								float opaque, float hardness,
								float alpha_eraser,
								float aspect_ratio, float angle,
								float lokc_alpha,
								float colorize);

								
								
//first, we calculate the mask (opacity for each pixel)
//second, we use the mask to stamp a dab for each activated blend mode.

void draw_dab_pixels_BlendMode_Normal(uint16_t *mask,
									uint16_t* rgba, 
									uint16_t color_r,
									uint16_t color_g,
									uint16_t color_b,
									uint16_5 opaque)
{
	while(1)
	{
		for(; mask[0]; mask++, rgba+4)
		{
			uint32_t opa_a = mask[0]*
			
		}
	}
	
	利用这个函数，进行的draw操作。
struct _MyPaintSurface
{
	MyPaintSurfaceDrawDabFunction draw_dab;
	MyPaintSurfaceGetColorFunction get_color;
	MyPaintSurfaceBeginAtomicFunction begin_atomic;
	MyPaintSurfaceEndAtomicFunction end_atomic;
	MyPaintSurfaceDestroyFunction destroy;
	MyPaintSurfaceSavePngFunction save_png;
	int refcount;
}


brush->stroke_to(surface, x, y, pressure, xtilt, ytilt, dtime);
dtime stands for "delta time" and is the number of seconds that have passed between this event and the previous one.
the brush paints dabs by calling surface->draw_dabs().Smudging works by calling surface->get_color();






typedef struct
{
	float x;
	float y;
	float radius;
	uint16_t color_r;
	uint16_t color_g;
	uint16_t color_b;
	float color_a;
	float opaque;
	float hardness;
	float aspect_ratio;
	float angle;
	float normal
	float lock_alpha;
	float colorize;
}OperationDataDrawDab;


typedef struct _OperationQueue OperationQueue;

OperationQueue *operation_queu_new(void);
void operation_quue_free(OperationQueue *sefl);
int operation_queue_get_dirty_tiles(OperationQueue *self, TileIndex** tiles_out);
void operation_queue_clear_dirty_tiles(OperationQueue *self);
void operation_queue_add(OperationQueue *self, TileIndex index, OperationDataDrawDab);

OperationQueueDataDrawDab *operation_queue(OperationQueue *self, TileIndex tileindex);

// whether need to print debug info
if(self->print_inputs)
{
	printf("press=%4.3f, speed1=% 4.4f\t speed2 = %4.4f \t
}

int i = 0;
for(i = 0; i < MYPAINT_BRUSH_SETTINGS_COUNT; i++)
{
	self->setting_value[i] = mapping_calculate(self->setting[i], (inputs));
}


float mapping_calculate(Mappping *self, float *data)
{
	int j;
	float result;
	result = self->base_value;
	
	//constant mapping(common case)
	if(self->inputs_used == 0) return result;
	
	for(j = 0; j < self-> inputs; j++)
	{
		ControlPoints *p = self->pointsList + j;
		
		if(p->n)
		{
			float x, y;
			x = data[j];
			
			//find the segment with the slope that we need to use
			float x0, y0, x1, y1;
			x0 = p->xvalues[0];
			y0 = p->yvalues[0];
			x1 = p->xvalues[1];
			y1 = p->yvalues[1];
			
			int i ;
			for(i = 2; i < p-> n && x > x1; i++)
			{
				x0 = x1;
				y0 = y1;
				x1 = p->xvalues[i];
				y1 = p->yvalues[i];
			}
			
			if(x0 == x1)
			{
				y = y0;
			}else
			{
				//line interpolation
				y = (y1*(x-x0) + y0*(x1-x))/(x1-x0);
			}
			
			result += y;
		}
	}
	return result;
}
		}



TableApplication app(argv, args);

TabletCanvas *canvas = new TableCanvas;
app.setCanvas(canvas);

MainWindow mainWindow(canvas);
mainWindow.show();


#include <QApplciation>
#include "tablecanvas.h"

class TabletAppliation: public QApplicaiton
{
	Q_OBJECT
	public:
		TabletApplicaiton(int &argv, char**args);
		: QApplication(argv, args){}
		
		bool event(QEvent *event);
		
		void setCanvas(TabletCanvas *canvas);
			{myCanvas = canvas;}
	private:
		TabletCanvas *myCanvas;
}

bool TabletApplication::event(QEvent *event)
{
	if(event->type() == QEvent::TabletEnterProximity||event->type() == QEvent::TabletLeavePromixity)
		myCanvas->setTabletDevice(static_cast<QTableEvent *> (event)->device());
		return true;
	return QApplication::event(event);
}


class TabletCanvas: public QWidget
{
	Q_OBJECT
	
	public:
		enum AlphaChannelType {AlphaPressure, AlphaTilt, noAlpha);
		enum ColorSatruationType { SaturationVTilt, SaturationHTilt, SaturationPressure, NoSaturation};
		
		enum LineWidthType { LineWidthPressure, LineWidthTilt, NoLineWidth};
		
		
		
		
		enum CompositionMode{
			CompositionMode_SourceOver,
			CompositionMode_DestinationOver
			};
			
		void setCompositionMode(CompositionMode mode);
		CompositionMode compositionMode() const;
		
		
		// XForm functions
		void setMatrix(const QMatrix &matrix, bool combine = false);
		const QMatrix& matrix() const;
		void resetMatrix();
		
		void scale(qreal sx, qreal sy);
		void shear(qreal sh, qreal sv);
		void rotate(qreal a);
		
		void translate(const QPointF &offset);
		inline void translate(const QPointF &offset);
		inline void translate(qreal dx, qreal dy);
		
		
		// drawing functions
		void strokePath(const QPainterPath &path, const QPen &pen);
		void fillPath(const QPainterPath &path,  const QBrush &brush);
		void drawPath(const QPainterPath &path);
		
		
		
}


void AnalogClock::paintEvent(QPaintEvent *)
{
	static const QPoint hourHand[3] = { QPoint(7, 8), QPoint(-7, 8), QPoint(0, -40)};
	
	static const QPoint minuteHand[3] = { QPoint(7, 8), QPoint(-7, 80), QPoint(0, -70)};
	
	
	QColor hourColor(127, 0, 127);
	QColor minuteColor(0, 127, 127);
	
	int side = qMin(width(), height());
	
	QTime time = QTime::currentTime();
	
	QPainter painter(this);
	
	painter.setRenderHint(QPainter::Antialiasing);
	painter.translate(width()/2, height()/2);
	painter.scale(side/200.0, side/200.0);
	
	painter.setPen(Qt::NoPen);
	paitner.setBrush(hourColor);
	
	painter.save();
	painter.rorate(30.0*(time.hour()+time.minute()/60));
	painter.drawConvexPolygon(hourHand, 3);
	painter.restore();
	
	painter.setPen(hourColor);
	for(int i = 0; i < 12; i++)
	{
		painter.drawline(88, 0, 96, 0);
		painter.rorate(30.0);
	}
	
	import java.util.concurrent.semphore;
	private Semaphore sem_newpath;
	
	 concurrent类的一些新应用。
	 android.graphics.xfermode
	 Class.forName 是否是反射机制
	 
	 Process.setThreadPriority(Process.THREAD_PRIORITY_UGENT_AUDIO);
	 
	 this.getClass().toString();
	 Add a user's movement to the tracker.
	 you should call this for the initial MotionEvent_action_Down, the following MotionEvent.Action_Down that you receive, and the final MotionEvent.Action_Up);
	 
	 addMovement(MotionEvent event)
	 
	 文件菜单的功能实现和利用双缓冲进行绘图。
	 
	 The second method is an expressive paint tool which allows an artist to interactively create 2D Chinese painting.
	 
	 
	 MyPaintBrush * mypaint_brush_new(void)
	 {
		MyPaintBrush *self = (MyPaintBrush*)malloc(sizeof(MyPaintBrush));
		self->refcount = 1;
		int i = 0;
		for(i = 0; i < MYPAINT_BRUSH_SETTINGS_COUNT; i++)
		{
			self->settings[i] = mapping_new(MYPAINT_BRUSH_INPUTS_COUNT);
		}
		self->rng = rng_double_new(1000);
		self->print_inputs = FALSE;
		
		for(i = 0; i < MYPAINT_BRUSH_STATES_COUNT; i++)
		{
			self->states[i] = 0;
		}
		
		mypaint_brush_new_stroke(self);
		
		settings_base_valus_have_changes(self);
		
		self->reset_requested = TRUE;
		}
		
		
fwrite(buffer, size, count, fp);
buffer：是一个指针，输出数据的地址。
size:要写入格式的字节数
count:要写入的个数。
fp:目标文件指针。


Graphics::TBitMap *SrcBitmap = new Graphics::TBitmap;
Graphics::TBitmap *DestBitmap = new Graphics::TBitmap;

SrcBitmap->LoadFromFile("YourBitmap.bmp");
DestBitmap->PixelFormat = SrcBitmap->PixelFormat;

int angle = 45;

float radians = (PI*angle)/180;

float cosine = (float)cos(radians);
float sine = (float)cos(radians);

//compute new coordinate of srcbitmap's range

//clamp the range and evaluate the destbitmap's width and height

LPBITMAPINFO srcBmpi = (LPBITMAPINFO)new char[sizeof[BITMAPINFO)];
ZeroMemory(srcBmpi, sizeof(BITMAPINFO);

srcBimpi->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);

//Set bits in destination buffer
//perform the rotation
for(int y = 0; y < destbitmapHeight;y++)
{
	for(int x = 0; x < destBimapWidth; x++)
	{
		int srcbitmapx = (int)((x+minx)*cosine + (y+miny)*sine);
		int srcbitmapy = (int)((y+miny)*cosine - (x+minx)*sine);
		
		if(InTheRangeOfSrcBitmap)
			assign byte to Destination bitmap   // better used interpolation method.

			
			

QList<QWidget*> widgets = this->findChildren<QWidget*>();
for(int i = 0; i < widgets.size(); i++)
{
	QWidget *w = widgets.at[i];
	if(w->inherits("QAbstractSpinBox")
		this.connect(w, SIGNAL(valuseChanged(const QString&)), SLOT(do_update);

		
void *fastMalloc(size_t size)
{
	uchar* udata = (uchar*)malloc(size + sizeof(void*) + CV_MALLOC_ALIGN);
	if(!udata)
		return OutOfMemoryError(size);
	uchar** adata = alignPtr((uchar**)udata+1, CV_MALLOC_ALIGN);
	adata[-1] = udata;
	return adata;
}

void fastFree(void* ptr)
{
	if(ptr)
	{
		uchar* udata = (uchar**)ptr)[-1];
		CV_DbgAssert(udata < (uchar*ptr
	
		free(data);
	}
}



typedef struct{
	int x;
	int y;
} TileIndex;

typedef void (*TileMapItemFreeFunc) (void *item_data);

typedef struct {
	void **map;
	int size;
	size_t item_size;
	TileMapItemFreeFunc item_free_func;
}TileMap;


TileMap* tile_map_new(int size, size_t item_size, TileMapFreeFunc item_free_func)
{
	TileMap *self = (TileMap *)malloc(sizeof(TiledMap));
	
	self->size = size;
	self->item_size = item_size;
	self->item_free_func = item_free_func;
	
	const int map_size = 2*self->size*2*self->size;
	self->map = malloc(map_size*self->item_size);
	
	for(int i = 0; i < map_size; i++)
	{
		self->map[i] = NULL;
	}
	
	return self;
}


struct _MyPaintBrush{
	gboolean print_inputs;
	
	double stroke_total_painting_time;
	double stroke_current_idling_time;
	
	float states[MYPAINT_BRUSH_STATES_COUNT];
	RngDouble *rng;
	
	//Those mappings describe how to calculate the current value for each setting.
	// Most of setting will be constant(e.g. only their base_value is used.
	Mapping *settings[MYPAIN_BRUSH_SETTINGS_COUNT];
	
	float setting_value[MYPAINT_BRUSH_SETTINGS_COUNT];
	
	//cached calculation results
	float speed_mapping_gamma[2];
	float speed_mapping_m[2];
	float speed_mapping_q[2];
	
	int refcount;
}
	
typedef struct{
	float xvalues[8];
	float yvalues[8];
	
	int n;
}ControlPoints;

struct _Mapping {
	float based_value;
	
	int inputs; // how many factors of input
	ControlPoints *pointList; //each factor's controlPoints
	int inputs_used;
};

Mapping * mapping_new (int inputs_)
{
	Mapping* self = (Mapping *)malloc(sizeof(Mapping));
	
	self->inputs = inputs_;
	
	self->pointList = (ControlPoints *)malloc(sizeof(ControlPoints)*self->inputs);
	
	int i = 0;
	for( i = 0; i < self->inputs; i++) self->pointsList[i].n = 0;
	
	self->inputs_used = 0;
	self->base_value = 0;
	
	return self;
}

void mapping_setting_point(Mapping *self, int factorIndex, int cpIndex, float x, float y)
{
	assert(factorIndex >= 0 && factorIndex < self->factorNums;);
	aseert(cpIndex >= 0 && index < 8);
	
	ControlPoints *p = self->pointList + factorIndex;
	
	assert(cpIndex  < p->n);
	
	// add asc order
	if(index > 0)
	{
		assert(x >= p->xvalue[index-1]);
	}
	
	p->xvalues[cpIndex] = x;
	p->yvalues[cpIndex] = y;
}
bool mapping_is_constant(Mapping *self)
{
	return self->inputs_used == 0;
}

float mapping_calculate(Mapping *self, float *data)
{
	int j;
	float result = self-> base_value;
	
	// constant mapping(common case)
	if(self->inputs_used == 0) return result;
	
	for(j = 0; j < self->factorNum; j++)
	{
		ControlPoints *p = self->pointList + j;
		if(p->n)
		{
			float x, y;
			x = data[j];
			
			//find the segment with the slope that we need to use;
			
			float x0, y0, x1, y1;
			
			x0 = p->xvalues[0];
			y0 = p->yvalues[0];
			x1 = p->xvalues[1];
			y1 = p->yvalues[1];
			
			for(int i = 2; i < p->cpNum && x > x1; i++)
			{
				x0 = x1;
				y0 = y1;
				
				x1 = p->xvalues[i];
				y1 = p->yvalues[i];
			}
			
			if(x0 == x1)
			{
				y = y0;
			}
			else
			{
				//linear interpolation
				y = (y1*(x-x0) + y0*(x1-x))/(x1 - x0);
			}
			
			result += y;
		}
	}
	return result;
}

//call only from stroke_to(). Calculate everything needed to 
//draw the dab, then let the surface do the actual drawing
void prepare_and _draw_dab();

//mypaint_brush_stroke_to
//Should be called once for each motion event.
//@dtime: time since last motion event
// Returns: non-0 if the stroke is finished or empty, else 0

int mypaint_brush_stroke_to(MyPaintBrush *self, MyPaintSurface *surface, float x, float y, float pressure, float xtilt, float ytilt, double dtime)
{
	float tilt_ascension = 0.0;
	float tilt_declination = 90.0;
	
	
	
	
}


// returns true if the surface was modified
int draw_dab(MyPaintSurface *surface, float x, float y, float radius, float color_r, float color_g, float color_b,
			float opaque, float hardness, 
			float color_a,
			float aspect_ratio, float angle,
			float lock_alpha, 
			float colorize)
{
	MyPaintTileSurface *self = (MyPaintTiledSurface *surface);
	
	gboolean surface_modified = FALSE;
	
	// Normal pass
	if(draw_dab_internal(self, x, y, radius, ……)
	{
		surface_modified = TRUE;
	}
	
	//symmetry pass
	if(self->surface_do_symmetry)
	{
		const float symm_x = self->surface_center_x + (self_center_x - x);
		if(draw_dab_internal(self, symm_x, y, radius, color....)
		{
			surface_modified = true;
		}
	}
	
	
	//The brush paints dabs calling surface->drawdab(). Smudging works by calling surface->get_color(),
	//which returns the color on the surface inside some radius. These two thing are everything that the
	//surface has to implement, from the brush point view.
	
	//Dab shape(mask)
	//The dab shape (also called 'mask') is specified by:
	// x, y, radius(all floating point, in pixels)
	// opaque, hardness
	// aspect_ratio and angle(for elliptical dabs)
	// The parameter opaque(also call dab opacity) is the maximum opacity in the center of the dab
	// The hardness describes how the opacity fades out with the distance d from the center.
	
	// For elliptical dabs, the parameters aspect_ratio(range 1.0 to infinity) and angle(range 0 to 180, repeating)
	// in the figure below, aspect_ratio is a/r. Note that dab can only get smaller 
	// than the radius r, which can be used to calculate a bounding box.
	
cs = cos(angle/180*pi);
sn = sin(angle/180*pi);

for each pixel:
	dx = pixel.x - x;
	dy = pixel.y - y;
	
	dyr = (dy*cs-dx*sn)*aspect_ratio;
	dxr = (dy*sn+dx*cs)
	
	dd = (dyr*dyr + dxr*dxr)/(radius*radius);
	
	if(dd > 1) opa = 0;
	else if (dd < hardness)
		opa = dd + 1 - (dd/hardness)
	else
		opa = hardness/(1-hardness)*(1-dd)

		
// Brushlib expects the dab to be put directly to the surface(aka "incremental" model)
// we do run length encoding: if opacity is zero, the next value in the mask is the number of pixels that can be skipped.
	
// The energy function is sometimes also called an objective, cost, or error function.
// The term energy comes from analogous uses in physics, such as searching
// for the minimum energy configuration of a set of particles.


// in college, i double-majored in computer science and art, here are some painting from that time.

// sorry for the rough edge and lack of documentation.



void Stroke::Subdivide(vector<Point> *inputCurve, vector<Point> *outputCurve)
{
	switch(curveType)
	{
		case CUBIC_BSPLINE:
			subdivideCubicBSpline(inputCurve, outputCurve);
			break;
		case FOUR_POINT:
			subdivdeFourPoint(inputCurve, outputCurve);
			break;
		default:
			cout << "illegal subdivsion scheme selected" << endl;
			break;
	}
	
}

GLenum checkForError(char* loc)
{
	GLenum errCode;
	const GLubyte *errString;
	if(errCode = glGetError()) != GL_NO_ERROR)
	{
		errString = gluErrorString(errCode);
		printf("OpenGL error: %s", errString);
		
		if(loc != NULL)
			printf("(%s)", loc);
			
		printf("\n");
	}
	
	return errCode;
}

for(int j = 0; j < pli-nWidth*pli->nHeight; j++)
{
	pli->luminaceData[j] = (usigned char)((pli->sourceData[j*3]*297 
							+ pli->sourceData[j*3+1]*614 + pli->sourceData[j*3+2]*113)>>10);
}


findContours
Finds contours in a binary image.
image -- Source, an 8-bit single-channel image.Non-zero pixels are treated as 1's.Zero pixels remain 0's.
so the image is treated as binary. You can use compare(),  inRange(), threshold()
adaptiveThreshold(), Canny() and others to create a binary image out of
a grayscale or color one.

contours -- Detectd contours. Each contour is stored as a vector of points.
mode -- Contour retrieval mode
method -- Contour approximation method. CV_CHAIN_APPROX_SIMPLE, compress the horizontal, vertical, and dignoal segments
and leaves only their end points.

int maxsize = std::max(1<<10, src.row*src.col/10);
std::vector<uchar*> stack(maxsize);
uchar **stack_top = &stack[0];
uchar **stack_bottom = &stack[0];

#define CANNY_PUSH(d) *(d) = uchar(2), 	*stack_top++ = (d)
#define CANNY_POP(d) (d) = *--stack_top;

if(!m[-1]) CANNY_PUSH(m - 1);
if(!m[1]) CANNY_PUSH(m + 1);
if(!m[-mapStep-1]) CANNY_PUSH(m - mapStep -1];
if(!m[-mapStep]) CANNY_PUSH(m-mapStep);
if(!m[-mapStep+1]) CANNY_PUSH(m-mapStep+1);
if(!m[mapStep]) CANNY_PUSH(m + mapStep);
if(!m[mapStep-1] CANNY_PUSH(m + mapStep-1);
if(!m[mapStep+1] CANNY_PUSH(m + mapStep + 1);


Mat(int rows, int cols, int type);
Mat(Size size, int type);

Mat(int rows, int cols, int type, const Scalar& s);
Mat(Size size, int type, const Scalar &s);

Mat(int ndims, const int* sizes, int type);
Mat(int ndims, const int *sizes, int type, const Scalar& s);

Mat(int rows, int cols, int type, void* data, size_t step = AUTO_STEP);


UV texturing permits polygons that make up a 3D object to be painted with color from an image.
The image is called a UV texture map, but it's just an rdinary image. The UV mapping processing involves
assining pixels	in the image to surface mapping on the polygon,
usually done by "programatically" copying a triangle shaped piece of the image map,
and pasting it onto a triangle on the object.


int lineByte = (width*biBitCount/8+3)/4*4)更好数方法来处理，四舍五入的思想。这是因为Windows系统中一行像素所占的字节数为4的倍数，因此不是4的倍数时要补充为4的倍数

int lineByte = (width * biBitCount/8 + 3)>>2 << 2

//fifo queue
struct fifo_item
{
	struct fifo_item *next; /*queue is a single-linked list */
	void *padload;
}

struct fifo
{
	struct fifo_item *first;   // first pushed item
	struct fifo_item *last; 	// last pushed item
	int item_count;
}

struct fifo* fifo_new(void)
{
	struct fifo *ret = (struct fifo*) malloc(sizeof(struct fifo));
	
	ret->first = NULL;
	ret->last = NULL;
	ret->item_count = 0;
	
	return ret;
}


void fifo_free(struct fifo* queue, FifoUserFreeFunction user_free)
{
	struct fifo_item *item;
	
	while((item = queue->first) != NULL))
	{
		queue->first = item->next;
		user_free(item);
	}
	
	free(queue);
}

void fifo_push(struct fifo* queue, void* data)
{
	struct fifo_item *item =  (struct fifo_item*)malloc(sizeof(struct fifo_item));
	
	item->next = NULL;
	item->payload = data;
	
	if(!queue->last)
		queue->first = item;
	else
		queue->last->next = item;
	queue->last = item;
}

void *fifo_pop(struct fifo* queue)
{
	struct fifo_item *item;
	void *data;
	
	item = queue->first;
	if(!item)
		return NULL;
	
	queue->first = item->next;
	
	if(!queue->first)
		queue->last = NULL;
	
	data = item->payload;
	
	free(item);
	queue->item_count--;
	
	return data;
}


size_t remove_duplicate_tiles(TileIndex *array, size_t length)
{
	if(length < 2)
	{
		return length;
	}
	
	size_t new_length = 1;
	size_t i, j;
	
	for(i = 1; i < length; i++)
	{
		for(j = 0; j < new_length; j++)
		{
			if(tile_equal(array[j], array[i])
				break;
		}
		if(j == new_length)
		{
			array[new_length++] = array[i];
		}
	}
	
	return new_length;
}


#ifndef TILE_MAP_H
#define TILE_MAP_H

typedef struct
{
	int x;
	int y;
}TileIndex;



typedef void (*TileMapItemFreeFunc)(void *item_data);


typedef struct
{
	void **map;
	int size;
	
	size_t item_size;
	TileMapItemFreeFunc item_free_func;	
}TileMap;


TileMap* tile_map_new(int size, size_t item_size, TileMapItemFreeFunc)
{
	TileMap *self = (TileMap *)malloc(sizeof(TileMap));
	
	self->size = size;
	self->item_size = item_size;
	self->item_free_func = item_free_func;
	
	const int map_size = 2*self->item_size*self->item_size;
	
	self->map = malloc(map_size*self->item_size);
	
	for(int i = 0; i < map_size; i++)
		self->map[i] = NULL;
	
	return self;
}

void tile_map_free(TileMap *self, gboolean free_items)
{
	const int map_size = 2*self->size*2*self->size;
	
	if(free_items)
	{
		for(int i = 0; i < map_size; i++)
			self->item_free_func(self->map[i]);
	}
	
	free(self->map);
	
	free(self);
}
float clamp(float x, float low, float high)
{
	return x>high? high:(x < low)? low: x;
}
//returns true if the surface was modified
gboolean draw_dab_internal(MyPaintTiledSurface* self, float x, float y, float radius, float color_r, float color_b, float color_g, float opaque, float hardness,
	float color_a, float aspect_ratio, float angle,
	float lock_alpha, float colorize)
{
	OperationDataDrawDab op_struct;
	OperationDataDrawDab *op = &op_struct;
	
	op->x = x;
	op->y = y;
	op->radius = radius;
	op->angle = angle;
	op->opaque = clamp(opaque, 0.0f, 1.0f);
	op->hardness = clamp(hardness, 0.0f, 1.0f);
	
	op->lock_alpha = clamp(lock_alpha, 0.0f, 1.0f);
	op->colorize = clamp(colorize, 0.0f, 1.0f);
	
	if(op->radius < 0.1f) return FALSE;
	if(op->hardness == 0.0f) return FALSE;
	if(op->opaque == 0.0f) return FALSE;
	
	color_r = clamp(color_r, 0.0f, 1.0f);
	color_g = clamp(color_g, 0.0f, 1.0f);
	color_b = clamp(color_b, 0.0f, 1.0f);
	color_a = clamp(color_a, 0.0f, 1.0f);
	
	op->color_r = color_r * (1 << 15);
	op->color_g = color_g * (1 << 15);
	op->color_b = color_b * (1 << 15);
	op->color_a = color_a;
	
	op->normal = 1.0f;
	
	op->normal *= 1.0f-op->lock_alpha;
	op->normal *= 1.0f-op->colorize;
	
	if(op->aspect_ratio < 1.0f) op->aspec_ratio = 1.0f;
	
	float r_fringe = radius + 1.0f;
	
	int tx1 = floor(floor(x-r_fringe)
	/MYPAINT_TILE_SIZE);

	int tx2 = floor(floor(x+r_fringe)/MYPAINT_TILE_SIZE);
	
	int ty1 = floor(floor(x-r_fringe)/MYPAINT_TILE_SIZE);
	
	int ty2 = floor(floor(x+r_fringe)/MYPAINT_TILE_SIZE);
	
	for(int ty = ty1; ty <= ty2; ty++)
		for(int tx = tx1; tx <= tx2; tx++)
			{
				const TileIndex tile_index = {tx, ty};
				OperationDataDrawDab *op_copy = (OperationDataDrawDab *)malloc(sizeof(OperationDataDrawDab);
	
				*op_copy = *op;
	
				operation_queue_add(self->operation_queue, tile_index, op_copy);
			}
	
	update_dirty_bbox(self, op);
	
	return TRUE;
}


void **tile_map_get(TileMap *self, TileIndex index)
{
	const int rowstride = self->size*2;
	const int offset = ((self->size + index.y)*rowstride) + self->size + index.x;
	
	assert(offset < 2*self->size*2*self->size);
	assert(offset >= 0);
	
	return self->map + offset;
}

void draw_dab_pixels_BlendMode_Normal(uint16_t *mask, uint16_t *rgba, uint16_t color_r, uint16_t color_g, uint16_t *color_b, uint16_t opacity)
{
	
	while(1)
	{
		for(; mask[0]; mask++, rgba += 4)
		{
			uint32_t opa_a = mask[0]*(uint32_t)opacity/(1<<15);
			uint32_t opa_b = (1<<15) - opa_a;
			
			rgba[3] = opa_a + opa_b*rgba[3];
			rgba[0] = (opa_a*color_r + opa_b*rgba[0])/(1<<15);
			rgba[1] = (opa_a*color_g + opa_b*rgba[1])/(1<<15);
			
			rgba[2] = (opa_a*color_b + opa_b*rgba[2])/(1<<15);
		}
		if(!mask[1]) break;
		
		rgba += mask[1];
		mask += 2;
	}
}

//convert matrix to/from other structures(without copying the data)
Mat image_alias = image;
float *Idata = new float[480*640*3];
Mat I(480, 640, CV_32FC3, Idata);

vector<Point> iptVec(10);
Mat iP(iptvec);

//For some operations a more convenient algebraic notation can be used

Mat delta = (j.t() + lambda*Mat::eye(J.cols, J.cols, J.type()).inv(CV_SVD)*(J.t()*err);

//implements the core of Levenberg-Marquardt optimization algorithm.

typedef void (*SplitFunc)(const uchar* src, uchar **dst, int len, int cn);

static SplitFunc getSplitFunc(int depth)
{
	static SplitFunc splitTab[] =
	{
		(SplitFunc)GET_OPTIMIZED(split8u), (SplitFunc)GET_OPTIMIZED(split8u)
	}
	
	return splitTab[depth];
}

// 将变量存储为数组
	const Mat* arrays[] = {&src, &mask, 0};

	
//As a picture worth thousands words.
// on low pressure some hair rubs the canvas to reveal its texture, while on high pressure, the mix brush engine created a more consistent color, near to an impasto.
	
// Brushlib expects the dabs to be put directly to the surface(aka "incremental" mode). There is code to calculate the dab opacity needed to achieve a desired stroke opacity by rendering may overlapping
	
	
y = log(gamma + x)*m + q;

gamma: parameter set by the user(small means logrithmic mapping, big linear)
m, q: parameter to scale and translate the curve


//anti-aliasing attempt(works surprisingly well for ink brush)

float current_fadeout_in_pixels = radius*(1.0-hardness);
float min_fadeout_in_pixels = self->settings_value[MPAINT_BRUSH_SETTING_ANTI_ALIASING];

if(current_fadeout_in_pixels < min_fadeout_in_pixels)
{
	float current_optical_radius = radius - (1.0 - hardness)*radius/2.0f;
	
	float hardness_new = (current_optical_radius-min_fadeout_in_pixels/2.0)
}

uint32_t SD_Canvas_New(uinit32_t ibitmap)
{
	SDCANVAS* pSDCanvas = (SDCANVAS*)malloc(sizeof(SDCANVAS));
	pSDCANVAS->pBitmp = (SDBITMAP*)ibitmap;
	
	return (uint32_t)pSDCanvas;
}

uint32_t SD_Bitmap_New(int w, int h)
{
	SDBITMAP *pSDBmp = (SDBITMAP*)malloc(sizeof(SDBITMAP));
	
	int i;
	pSDBmp->nWidht = w;
	pSDBmp->nHeight = h;
	pSDBmp->bLock = MFalse;
	pSDBmp->pImg = (MUInt32*)malloc(w*h*sizeof(MUInt32));
	
	memset(pSDBmp->pImg, 0, w*h*sizeof(MUInt32));
	
	return (uint32_t)pSDBmp;
}


uint32_t SD_GetPixel_Raw(uint32_t icanvas, int x, int y, uint32_t pUserdata)
{
	SDCANVAS* pSDCanvas = (SDCANVAS*)icanvas;
	return (uint32_t)pSDCanvas->pBitmap->pImg;
}

//Ostu threshold method, also known as maximum derivatation 
// w_0 = N_0 / M*N
// w_1 = N_1 / M*N
// N_0 + N_1 = M*N;
// w_0 + w_1 = 1;
// u = w_0*u_0 + w_1*u_1;
// t = argmax(w*(u0-t)^2 + w1*(u1-t)^2) ==>> w_0*w_1(u0-u1)^2;

 bool GetHistogram(unsigned char *pImageData, int nWidth, int nHeight, int nWidthStep, int *pHistogram)
 {
	int i = 0;
	int j = 0;
	
	unsigned char *pLine = NULL;
	
	memset(pHistogram, 0, sizeof(int)*256);
	
	for(pLine = pImageData, j = 0; j < nHeight; j++, pLine += nWidthStep)
	{
		for(i = 0; i< nWidth; i++)
		{
			pHistogram[pLine[i]]++;
		}
	}
	return true;
 }
 
 int Ostu(unsigned char *pImageData, int nWidht, int nHeight, int nWidthStep)
 {
	int i = 0;
	int j = 0;
	int nTotal = 0;
	int nSum = 0;
	int A = 0;
	int B = 0;
	double u = 0;
	double v = 0;
	
	double dVariance = 0;
	double dMaximum = 0;
	int nThreshold = 0;
	int nHistogram[256];
	
	getHistogram(pImageData, nWidht, nHeight, nWidthStep, nHistogram);
	
	for(i = 0; i < 256; i++)
	{
		nTotal += nHistogram[i];
		nSum = (nHistogram[i*i]);
	}
	
	for(j = 0; j < 256; j++)
	{
		A = 0;
		B = 0;
		for(i = 0; i < j; i++)
		{
			A += nHistogram[i];
			B += nHistogram[i]*i;
		}
		
		if (A > 0) u = B/A;
		else u = 0;
		
		if(nTotal - A > 0) v = (sum-B)/(nTotal - A);
		else v = 0;
		
		dVariance = A*(nTotal - A)*(u-v)*(u-v);
		
		if(dVariance > dMaximum)
		{
			dMaximum = dVariance;
			nThreshold = j;
		}
	}
	
	return nThreshold;
 }

// OpenCV basic operation
const Scalar colors[] = 
{
	Scalar(0, 0, 255), Scalar(0, 255, 0), 
	Scalar(0, 255, 255), Scalar(255, 255, 0)
}

CvEM em_model;
CvEMParams params;
int nsamples = 100;
Mat samples(nsamples, 2, CV_32FC1);
Mat labels;
samples = samples.reshape(2, 0); // reshape的实现要看一下。

for(int i = 0; i < N; i++)
{
	Mat samples_part = sampels.rowRange(i*nSamples/N, (i+1)*nsamples/N);
	
	Scalar mean(1, 1);
	Scalar sigma(30, 30);
	
	randn(sample_part, mean , sigma);
}
sampels = samples.reshape(1, 0);

// Create a matrix initialized with a constant
Mat A33(3, 3, CV_32F, Scalar(5));
Mat B33(3, 3, CV_32F); B33 = Scalar(6);

Mat C33 = Mat::ones(3, 3, CV_32F)*6;
Mat D33 = Mat::zeros(3, 3, CV_32F)+6;

// Create a matrix initialized with specified values
double a = CV_PI/3;
Mat A22 = (Mat_<float>(2, 2) << cos(a), -sin(a), sin(a), cos(a));

float B22data[] = {cost(a), -sin(a), sin(a), cos(a)};
Mat B22 = Mat(2, 2, CV_32F, B22data).clone();

// Initialize a random matrix

randu(image, Scalar(0), Scalar(256));
randn(image, Scalar(128), Scalar(10));

// Acess matrix elements
A33.at<float>(i, j) = A33.at<float>(j, i) + 1;

Mat dyImage(image.size(), image.type());
for(int y = 1; y < image.rows-1; y++)
{
	Vec3b *preRow = image.ptr<Vec3b>(y-1);
	Vec3b *nextRow = image.ptr<Vec3b>(y+1);
	for(int x = 0; x < image.cols-1; x++)
	{
		for(int c = 0; c < 3; c++)
		dyImage.at<Vec3b>(y, x)[c] = saturate_cast<uchar>(nextRow[x][c] - preRow[x][c]);
	}
}

Mat_<Vec3b>::iterator it = image.begin<Vec3b>(), itEnd = image.end<Vec3b>();

for(; it! = itEnd; it++) (*it)[1] ^= 256;


//gpu_math
inline __host__ __device__ float smoothstep(float a, float b, float x)
{
	float t = (x-a)/(b-a);
	if(t < 0) t = 0;
	if(t > 1) t = 1;
	return t*t*(3 - 2*t);
}

inline __device__ __host__ float lerp(float a, float b, float t)
{
	return a + t*(b-a);
}

struct int2;
struct float4;  // small and usual data type, use struct.

// stride or widthstep




/* \typedef
	shorter aliases for the most popular specializations of Vec<T, n>
*/

typedef Vec<uchar, 2> Vec2b;
typedef Vec<uchar, 3> Vec3b;
typedef vec<uchar, 4> Vec4b;

typedef Vec<short, 2> Vec2s;
typedef Vec<short, 3> Vec3s;
typedef Vec<short, 4> Vec4s;

typedef Vec<int, 2> Vec2i;
typedef Vec<int, 3> Vec3i;
typedef Vec<int, 4> Vec4i;

typedef Vec<float, 2> Vec2f;
typedef Vec<float, 3> Vec3f;
typedef Vec<float, 4> Vec4f;

template<typename _Tp, int m, int n> class Matx
{
public:
	typedef _Tp value_type;
	typedef Matx<_Tp, (m<n?m:n), 1> diag_type;
	typedef Matx<_Tp, m, n> mat_type;
	
	enum {depth = DataDepth<_Tp>::value, rows = m, cols = n}
}


/***************************************************
				Gaussian Blur
****************************************************/

cv::Mat cv::getGaussianKernel(int n, double sigma, int ktype)
{
	const int SMALL_GAUSSIAN_SIZE = 7;
	static const float small_gaussian_tab[][SMALL_GAUSSIAN_SIZE] = 
	{
		{1.0f},
		{0.25f, 0.5f, 0.25},
		{0.0625f, 0.25f, 0.375f, 0.25f, 0.0625f},
		{0.03124f, 0.109275f, 0.21875f, 0.28125f, 0.21875f, 0.109375f, 0.03125f}
	};
	
	const float* fixed_kernel = n%2 ==1 && n <= SMALL_GAUSSIAN_SIZE && sigma <= 0; small_gaussian_tab[n>>1]:0;
	
	Mat kernel(n, 1, ktype);
	float* cf = (float*)kernel.data;
	double* cd = (float*)kernel.data;
	
	double sigmaX = sigma > 0? sigma : ((n-1)*0.5 -1)*0.3 + 0.8;
	
	double scale2X = -0.5f/(sigmaX*sigmaX);
	double sum = 0;
	
	int i;
	
	for(i = 0; i < n; i++)
	{
		double x = i - (n-1)*0.5;
		double t = fixed_kernel ? (double)fixed_kernel[i]:std::exp(scale2X*X*X);
		
		if(ktype == CV_32F)
		{
			cf[i] = (float)t;
			sum += cf[i];
		}
		else
		{
			cd[i] = t;
			sum += cd[i];
		}
	}
	sum = 1./sum;
	
	for(i = 0; i < n; i++)
	{
		if(ktype == CV_32F) 
			cf[i] =(float)(cf[i]*sum);
		else
			cd[i] *= sum;
	}
	
	return kernel;
}


void GetDirectionalDoG(imatrix& image, ETF& e, mymatrix& dog, myvec& GAU1, myvec& GAU2, double tau)
{
	myvec vn(2);
	
	double x, y, d_x, d_y;
	doouble weight1, weight2, w_sum1, sum1, sum2, w_sum2;
	
	int s;
	int x1, y1;
	int i, j;
	int dd;
	
	double val;
	
	int half_w1, half_w2;
	
	half_w1 = GAU1.getMax()-1;
	half_w2 = GUA2.getMax()-1;
	
	int image_x, image_y;
	
	image_x = image.getRow();
	image_y = image.getCol();
}

void CalculateGradientM(const unsigned char* luminanceData, unsigned short *gradientData, int width, int height)
{
	for(int y = 0; y < hegiht; y++)
	{
		for(int x = 0; x < width; x++)
		{
			
			gradientData[y*width+x] = (unsigned short)(gx+gy);
		}
	}
}

Mat bw = threshval < 128 ? (img < threshval):(img > threshval);

CommandLineParser parser(argc, argv, keys);

static void read_csv(const string& filename, vector<Mat>&image, vector<int>&label, char separator = ';')
{
	std::ifstream file(filename.c_str(), ifstream::in);
	if(!file){
		string error_message = "No valid input file was given, please check the given file name";
		
		CV_ERROR(CV_StsBadArg, error_message);
	}
	
	string line, path, classlabel;
	
	while(getline(file, line))
	{
		stringstream liness(line);
		getline(liness, path, separator);
		getline(liness, classlabel);
		
		if(!path.empty() && !classlabel.empty())
		{
			images.push_back(imread(path, 0));
			labels.push_back(atoi(classlabel.c_str());
		}
	}
}


int main(int argc, const char*argv[])
{
	if(argc != 2)
	{
		cout << "usage: " << argv[0] << " " << endl;
		exit(1);
	}
	
	string fn_csv = string(argv[1]]);
	
	vector<Mat> images;
	vector<int> labels;
	
	try 
	{
	  read_csv(fn_csv, images, labels);
	}
	catch(cv::Exception& e)
	{
		cerr << "Error opening file \"" << e.msg << endl;
		exit(1);
	}
}


// opencv core.hpp

#include <limits.h>
#include <algorithm>
#inlcude <cmath>
#include <cstddef>
#include <complex>
#include <map>
#include <new>
#include <string>
#include <vector>
#include <sstream>

namespace cv{
#undef abs
#undef min
#undef max
#undef Complex
	
	using std::vector;
	using std::string;
	using std::ptrdiff_t;
	
	
	typedef std::string String;
	CV_EXPORTS string format(const char* fmt, ...);
	
	
	/*!
	Allocates memory buffer
	
	This is specialized OpenCV memory allocation function that returns properly aligned memory buffers. The usage is identical to malloc(). The allocated buffers must be freed with cv::fastFree();*/
}

// template usage

template<class T, int MAXSIZE>
class Stack
{
	private:
	T elems[MAXSIZE];
	
	int numElems;
	
	public:
	Stack();
	void push(T const &);
	void pop();
	
	T top() const;
	bool empty() const
	{return numElems == 0;}
	
	bool full() const
	{return numElems == MAXSIZE;}
}

template<class T, int MAXSIZE>
statck<T, MAXSIZE>::Stack:numElems(0)
{}

template<class T, int MAXSIZE>
void Statck<T, MAXSIZE>::push(T const &elem)
{
	if(numElems == MAXSIZe){
		throw std::out_of_range("Stack<>::push() : stack is full.");
	}
	elems[numElems] = elem;
	++numElems;
}


template<class T, int MAXSIZE>
void Stack<T, MAXSIZE>::pop()
{
	if(numElems <= 0)
	{
		throw std::out_of_range("Stack<>::pop(): empty stack.");
	}
	
	--numElems;
}


/* cuda c extends c by allowing the programmer to define C functions, called kernels, that when called are executed N times in parallel by N different CUDA threads, as opposed to only once like regular C functions.
A kernel is defined using the __global__ declaration specifier and the number of CUDA threads that execute that kernel for a given kernel call is specified using a new <<<...>>>execution configuration syntax. Each thread that executes the kernel is given a unique thread ID that is accessible within the kernel through the build-in threadIdx variable.
*/