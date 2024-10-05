#include "std.h"
#include "bbgraphics.h"
#include "bbinput.h"
#include "bbutf8.h"
#include "../MultiLang/MultiLang.h"

void bbFreeImage(bbImage* i);

#define RED(_X_) ( ((_X_)>>16) & 0xff )
#define GRN(_X_) ( ((_X_)>>8) & 0xff )
#define BLU(_X_) ( (_X_) & 0xff )

struct vec2 { float x, y; };

static vec2 vrot(float m[2][2], const vec2& v)
{
    vec2 t; t.x = m[0][0] * v.x + m[0][1] * v.y; t.y = m[1][0] * v.x + m[1][1] * v.y;
    return t;
}

static float vmin(float a, float b, float c, float d)
{
    float t = a; if (b < t) t = b; if (c < t) t = c; if (d < t) t = d; return t;
}

static float vmax(float a, float b, float c, float d)
{
    float t = a; if (b > t) t = b; if (c > t) t = c; if (d > t) t = d; return t;
}

int bbCountGfxDrivers()
{
    return 0;
}

BBStr* bbGfxDriverName(int n)
{
    BBStr* t ;
    return t;
}

void  bbSetGfxDriver(int n)
{
   
}

int  bbCountGfxModes()
{
    
    return 0;
}

int  bbGfxModeWidth(int n)
{
    
    return 0;
}

int  bbGfxModeHeight(int n)
{
    
    return 0;
}

int  bbGfxModeDepth(int n)
{
    
    return 0;
}

int  bbGfxModeExists(int w, int h, int d)
{
    return 0;
}

int  bbGfxDriver3D(int n)
{
    return 0;
}

int  bbCountGfxModes3D()
{
    return 0;
}

int  bbGfxMode3DExists(int w, int h, int d)
{
    return 0;
}

int  bbGfxMode3D(int n)
{
    return 0;
}

int  bbWindowed3D()
{
    return 0;
}

float bbDPIScaleX() {
    
    return 0.0;
}

float bbDPIScaleY() {
    return 0.0;
}

int  bbTotalVidMem()
{
    return 0;
}

int  bbAvailVidMem()
{
    return 0;
}

void bbSetBuffer(int buff)
{
    
}

int bbGraphicsBuffer()
{
    return 0;
}

int bbLoadBuffer(int c, BBStr* str)
{
    return 0;
}

int bbSaveBuffer(int c, BBStr* str)
{
    return 0;
}

void bbBufferDirty(int c)
{
   
}

void bbGraphics(int w, int h, int d, int mode)
{
    
}

void bbGraphics3D(int w, int h, int d, int mode)
{
   
}

void bbEndGraphics()
{
    
}

int bbGraphicsLost()
{
    return 0;
}

int bbInFocus()
{
    return 0;
}

int bbDesktopWidth()
{
    return 0;
}

int bbDesktopHeight()
{
    return 0;
}

void  bbSetGamma(int r, int g, int b, float dr, float dg, float db)
{
   
}

void  bbUpdateGamma(int calibrate)
{
    
}

float  bbGammaRed(int n)
{
    
    return 0.0;
}

float  bbGammaGreen(int n)
{
    return 0.0;
}

float  bbGammaBlue(int n)
{
    return 0.0;
}

int bbFrontBuffer()
{
    return 0;
}

int bbBackBuffer()
{
    return 0;
}

void bbLockBuffer(int buff)
{
    
}

void bbUnlockBuffer(int buff)
{
    
}

int bbReadPixel(int x, int y, int buff)
{
    return 0;
}

void bbWritePixel(int x, int y, int argb, int buff)
{
    
}

int bbReadPixelFast(int x, int y, int buff)
{
    return 0;
}

void bbWritePixelFast(int x, int y, int argb, int buff)
{
    
}

void bbCopyPixel(int src_x, int src_y, int src, int dest_x, int dest_y, int buff)
{
    
}

void bbCopyPixelFast(int src_x, int src_y, int src, int dest_x, int dest_y, int buff)
{
    
}

int bbScanLine()
{
    return 0;
}

void bbVWait(int n)
{
    
}

void bbFlip(int vwait)
{
    
}

int bbGraphicsWidth()
{
    return 0;
}

int bbGraphicsHeight()
{
    return 0;
}

int bbGraphicsDepth()
{
    return 0;
}

void bbOrigin(int x, int y)
{
    
}

void bbViewport(int x, int y, int w, int h)
{
    
}

void bbColor(int r, int g, int b)
{
    
}

void bbGetColor(int x, int y)
{
    
}

int bbColorRed()
{
    return 0;
}

int bbColorGreen()
{
    return 0;
}

int bbColorBlue()
{
    return 0;
}

void bbClsColor(int r, int g, int b)
{
    
}

void bbSetFont(int f)
{
    
}

void bbCls()
{
}

void bbPlot(int x, int y)
{
   
}

void bbLine(int x1, int y1, int x2, int y2)
{
    
}

void bbRect(int x, int y, int w, int h, int solid)
{
    
}

void bbOval(int x, int y, int w, int h, int solid)
{
   
}

/*
* xPos: 0 = align left, 1 = align center, 2 = align right
* yPos: 0 = align top, 1 = align middle, 2 = align bottom
*/
void bbText(int x, int y, BBStr* str, int xPos, int yPos)
{
   
}

BBStr* bbConvertToANSI(BBStr* str)
{
    BBStr* ret = new BBStr(UTF8::convertToAnsi(str->c_str()));
    delete str;
    return ret;
}

BBStr* bbConvertToUTF8(BBStr* str)
{
    BBStr* ret = new BBStr(UTF8::convertToUtf8(str->c_str()));
    delete str;
    return ret;
}

void bbCopyRect(int sx, int sy, int w, int h, int dx, int dy, int src, int dest)
{
    
}

void bbCopyRectStretch(int sx, int sy, int w, int h, int dx, int dy, int dw, int dh, int src, int dest)
{
    
}


int bbLoadFont(BBStr* name, int height) {
    return 0;
}

void bbFreeFont(int f)
{
   
}

int bbFontWidth()
{
    return 0;
}

int bbFontHeight()
{
    return 0;
}

int bbGetFont() {
    return 0;
}

int bbStringWidth(BBStr* str)
{
    return 0;
}

int bbStringHeight(BBStr* str)
{
    return 0;
}

BBStr* bbFontPath(BBStr* facename) {
    BBStr* t;

    return  t;
}

int bbOpenMovie(BBStr* s)
{
    return 0;
}

int bbDrawMovie(int movie, int x, int y, int w, int h)
{
    return 0;
}

int bbMovieWidth(int movie)
{
    return 0;
}

int bbMovieHeight(int movie)
{
    return 0;
}

int bbMoviePlaying(int movie)
{
    return 0;
}

void bbCloseMovie(int movie)
{
 
}

bbImage* bbLoadImage(BBStr* s)
{

    bbImage* i;
    return i;
}

bbImage* bbLoadAnimImage(BBStr* s, int w, int h, int first, int cnt)
{
    bbImage* i;
    return i;
}

bbImage* bbCopyImage(bbImage* i)
{
    
    bbImage* t;
    return t;
}

bbImage* bbCreateImage(int w, int h, int n)
{
    bbImage* i;
    return i;
}

void bbFreeImage(bbImage* i)
{
   
}

int bbSaveImage(bbImage* i, BBStr* str, int n)
{
    return 0;
}

void bbGrabImage(bbImage* i, int x, int y, int n)
{
   
}

int bbImageBuffer(bbImage* i, int n)
{
    return 0;
}

void bbDrawImage(bbImage* i, int x, int y, int frame)
{
    
}

void bbDrawBlock(bbImage* i, int x, int y, int frame)
{
    
}

void bbTileImage(bbImage* i, int x, int y, int frame)
{
    
}

void bbTileBlock(bbImage* i, int x, int y, int frame)
{
    
}

void bbDrawImageRect(bbImage* i, int x, int y, int r_x, int r_y, int r_w, int r_h, int frame)
{
    
}

void bbDrawBlockRect(bbImage* i, int x, int y, int r_x, int r_y, int r_w, int r_h, int frame)
{
    
}

void bbMaskImage(bbImage* i, int r, int g, int b)
{
   
}

void bbHandleImage(bbImage* i, int x, int y)
{
    
}

void bbMidHandle(bbImage* i)
{
  
}

void bbAutoMidHandle(int enable)
{
    
}

int bbImageWidth(bbImage* i)
{
    return 0;
}

int bbImageHeight(bbImage* i)
{
    return 0;
}

int bbImageXHandle(bbImage* i)
{
    return 0;
}

int bbImageYHandle(bbImage* i)
{
    return 0;
}

int bbImagesOverlap(bbImage* i1, int x1, int y1, bbImage* i2, int x2, int y2)
{
    return 0;
}

int bbImagesCollide(bbImage* i1, int x1, int y1, int f1, bbImage* i2, int x2, int y2, int f2)
{
    return 0;
}

int bbRectsOverlap(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2)
{
    return 0;
}

int bbImageRectOverlap(bbImage* i, int x, int y, int x2, int y2, int w2, int h2)
{
    return 0;
}

int bbImageRectCollide(bbImage* i, int x, int y, int f, int x2, int y2, int w2, int h2)
{
    return 0;
}

void bbTFormImage(bbImage* i, float a, float b, float c, float d)
{
    
}

void bbScaleImage(bbImage* i, float w, float h)
{
    
}

void bbResizeImage(bbImage* i, float w, float h)
{
    
}

void bbRotateImage(bbImage* i, float d)
{
   
}

void bbTFormFilter(int enable)
{
   
}

static int p_ox, p_oy, p_hx, p_hy, p_vpx, p_vpy, p_vpw, p_vph;

void bbWrite(BBStr* str)
{
    
}

void bbPrint(BBStr* str)
{
   
}

BBStr* bbInput(BBStr* prompt)
{
  BBStr* t;
  return t;
}

void bbLocate(int x, int y)
{
   
}

void bbShowPointer()
{
    
}

void bbHidePointer()
{
   
}

bool graphics_create()
{
    
    return false;
}

bool graphics_destroy()
{
    
    return true;
}

void graphics_link(void (*rtSym)(const char* sym, void* pc))
{

    //gfx driver info
    rtSym("%CountGfxDrivers", bbCountGfxDrivers);
    rtSym("$GfxDriverName%driver", bbGfxDriverName);
    rtSym("SetGfxDriver%driver", bbSetGfxDriver);

    //gfx mode info
    rtSym("%CountGfxModes", bbCountGfxModes);
    rtSym("%GfxModeExists%width%height%depth", bbGfxModeExists);

    rtSym("%GfxModeWidth%mode", bbGfxModeWidth);
    rtSym("%GfxModeHeight%mode", bbGfxModeHeight);
    rtSym("%GfxModeDepth%mode", bbGfxModeDepth);
    rtSym("%AvailVidMem", bbAvailVidMem);
    rtSym("%TotalVidMem", bbTotalVidMem);

    rtSym("#DPIScaleX", bbDPIScaleX);
    rtSym("#DPIScaleY", bbDPIScaleY);

    rtSym("%GfxDriver3D%driver", bbGfxDriver3D);
    rtSym("%CountGfxModes3D", bbCountGfxModes3D);
    rtSym("%GfxMode3DExists%width%height%depth", bbGfxMode3DExists);
    rtSym("%GfxMode3D%mode", bbGfxMode3D);
    rtSym("%Windowed3D", bbWindowed3D);

    //display mode
    rtSym("Graphics%width%height%depth=0%mode=0", bbGraphics);
    rtSym("Graphics3D%width%height%depth=0%mode=0", bbGraphics3D);
    rtSym("EndGraphics", bbEndGraphics);
    rtSym("%GraphicsLost", bbGraphicsLost);
    rtSym("%InFocus", bbInFocus);

    rtSym("SetGamma%src_red%src_green%src_blue#dest_red#dest_green#dest_blue", bbSetGamma);
    rtSym("UpdateGamma%calibrate=0", bbUpdateGamma);
    rtSym("#GammaRed%red", bbGammaRed);
    rtSym("#GammaGreen%green", bbGammaGreen);
    rtSym("#GammaBlue%blue", bbGammaBlue);

    rtSym("%FrontBuffer", bbFrontBuffer);
    rtSym("%BackBuffer", bbBackBuffer);
    rtSym("%ScanLine", bbScanLine);
    rtSym("VWait%frames=1", bbVWait);
    rtSym("Flip%vwait=1", bbFlip);
    rtSym("%GraphicsWidth", bbGraphicsWidth);
    rtSym("%GraphicsHeight", bbGraphicsHeight);
    rtSym("%GraphicsDepth", bbGraphicsDepth);

    //buffer management
    rtSym("SetBuffer%buffer", bbSetBuffer);
    rtSym("%GraphicsBuffer", bbGraphicsBuffer);
    rtSym("%LoadBuffer%buffer$bmpfile", bbLoadBuffer);
    rtSym("%SaveBuffer%buffer$bmpfile", bbSaveBuffer);
    rtSym("BufferDirty%buffer", bbBufferDirty);

    //fast pixel reads/write
    rtSym("LockBuffer%buffer=0", bbLockBuffer);
    rtSym("UnlockBuffer%buffer=0", bbUnlockBuffer);
    rtSym("%ReadPixel%x%y%buffer=0", bbReadPixel);
    rtSym("WritePixel%x%y%argb%buffer=0", bbWritePixel);
    rtSym("%ReadPixelFast%x%y%buffer=0", bbReadPixelFast);
    rtSym("WritePixelFast%x%y%argb%buffer=0", bbWritePixelFast);
    rtSym("CopyPixel%src_x%src_y%src_buffer%dest_x%dest_y%dest_buffer=0", bbCopyPixel);
    rtSym("CopyPixelFast%src_x%src_y%src_buffer%dest_x%dest_y%dest_buffer=0", bbCopyPixelFast);

    //rendering
    rtSym("Origin%x%y", bbOrigin);
    rtSym("Viewport%x%y%width%height", bbViewport);
    rtSym("Color%red%green%blue", bbColor);
    rtSym("GetColor%x%y", bbGetColor);
    rtSym("%ColorRed", bbColorRed);
    rtSym("%ColorGreen", bbColorGreen);
    rtSym("%ColorBlue", bbColorBlue);
    rtSym("ClsColor%red%green%blue", bbClsColor);
    rtSym("SetFont%font", bbSetFont);
    rtSym("Cls", bbCls);
    rtSym("Plot%x%y", bbPlot);
    rtSym("Rect%x%y%width%height%solid=1", bbRect);
    rtSym("Oval%x%y%width%height%solid=1", bbOval);
    rtSym("Line%x1%y1%x2%y2", bbLine);
    rtSym("Text%x%y$text%xPos=0%yPos=0", bbText);
    rtSym("$ConvertToANSI$str", bbConvertToANSI);
    rtSym("$ConvertToUTF8$str", bbConvertToUTF8);
    rtSym("CopyRect%source_x%source_y%width%height%dest_x%dest_y%src_buffer=0%dest_buffer=0", bbCopyRect);
    rtSym("CopyRectStretch%source_x%source_y%width%height%dest_x%dest_y%dest_w%dest_h%src_buffer=0%dest_buffer=0", bbCopyRectStretch);


    //fonts
    rtSym("%LoadFont$fontname%height=12", bbLoadFont);
    rtSym("%CurrentFont", bbGetFont);
    rtSym("FreeFont%font", bbFreeFont);
    rtSym("%FontWidth", bbFontWidth);
    rtSym("%FontHeight", bbFontHeight);
    rtSym("%StringWidth$string", bbStringWidth);
    rtSym("%StringHeight$string", bbStringHeight);
    rtSym("$FontPath$facename", bbFontPath);

    //movies
    rtSym("%OpenMovie$file", bbOpenMovie);
    rtSym("%DrawMovie%movie%x=0%y=0%w=-1%h=-1", bbDrawMovie);
    rtSym("%MovieWidth%movie", bbMovieWidth);
    rtSym("%MovieHeight%movie", bbMovieHeight);
    rtSym("%MoviePlaying%movie", bbMoviePlaying);
    rtSym("CloseMovie%movie", bbCloseMovie);

    rtSym("%LoadImage$bmpfile", bbLoadImage);
    rtSym("%LoadAnimImage$bmpfile%cellwidth%cellheight%first%count", bbLoadAnimImage);
    rtSym("%CopyImage%image", bbCopyImage);
    rtSym("%CreateImage%width%height%frames=1", bbCreateImage);
    rtSym("FreeImage%image", bbFreeImage);
    rtSym("%SaveImage%image$bmpfile%frame=0", bbSaveImage);

    rtSym("GrabImage%image%x%y%frame=0", bbGrabImage);
    rtSym("%ImageBuffer%image%frame=0", bbImageBuffer);
    rtSym("DrawImage%image%x%y%frame=0", bbDrawImage);
    rtSym("DrawBlock%image%x%y%frame=0", bbDrawBlock);
    rtSym("TileImage%image%x=0%y=0%frame=0", bbTileImage);
    rtSym("TileBlock%image%x=0%y=0%frame=0", bbTileBlock);
    rtSym("DrawImageRect%image%x%y%rect_x%rect_y%rect_width%rect_height%frame=0", bbDrawImageRect);
    rtSym("DrawBlockRect%image%x%y%rect_x%rect_y%rect_width%rect_height%frame=0", bbDrawBlockRect);
    rtSym("MaskImage%image%red%green%blue", bbMaskImage);
    rtSym("HandleImage%image%x%y", bbHandleImage);
    rtSym("MidHandle%image", bbMidHandle);
    rtSym("AutoMidHandle%enable", bbAutoMidHandle);
    rtSym("%ImageWidth%image", bbImageWidth);
    rtSym("%ImageHeight%image", bbImageHeight);
    rtSym("%ImageXHandle%image", bbImageXHandle);
    rtSym("%ImageYHandle%image", bbImageYHandle);

    rtSym("ScaleImage%image#xscale#yscale", bbScaleImage);
    rtSym("ResizeImage%image#width#height", bbResizeImage);
    rtSym("RotateImage%image#angle", bbRotateImage);
    rtSym("TFormImage%image#a#b#c#d", bbTFormImage);
    rtSym("TFormFilter%enable", bbTFormFilter);

    rtSym("%ImagesOverlap%image1%x1%y1%image2%x2%y2", bbImagesOverlap);
    rtSym("%ImagesCollide%image1%x1%y1%frame1%image2%x2%y2%frame2", bbImagesCollide);
    rtSym("%RectsOverlap%x1%y1%width1%height1%x2%y2%width2%height2", bbRectsOverlap);
    rtSym("%ImageRectOverlap%image%x%y%rect_x%rect_y%rect_width%rect_height", bbImageRectOverlap);
    rtSym("%ImageRectCollide%image%x%y%frame%rect_x%rect_y%rect_width%rect_height", bbImageRectCollide);

    rtSym("Write$string", bbWrite);
    rtSym("Print$string=\"\"", bbPrint);
    rtSym("$Input$prompt=\"\"", bbInput);
    rtSym("Locate%x%y", bbLocate);

    rtSym("ShowPointer", bbShowPointer);
    rtSym("HidePointer", bbHidePointer);

    rtSym("%DesktopWidth", bbDesktopWidth);
    rtSym("%DesktopHeight", bbDesktopHeight);
}

extern "C" {
    _declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;
    _declspec(dllexport) DWORD AmdPowerXpressRequestHighPerformance = 0x00000001;
}