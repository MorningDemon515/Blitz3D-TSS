#include "std.h"

#include "bbblitz3d.h"
#include "bbgraphics.h"
#include "../MultiLang/MultiLang.h"


///////////////////////////
// GLOBAL WORLD COMMANDS //
///////////////////////////
void bbLoaderMatrix(BBStr* ext, float xx, float xy, float xz, float yx, float yy, float yz, float zx, float zy, float zz) {
	
}

int bbHWTexUnits() {
	return 0;
}

int bbGfxDriverCaps3D() {
	return 0;
}

void bbHWMultiTex(int enable) {
	
}

void bbWBuffer(int enable) {
	
}

void bbDither(int enable) {
	
}

void bbAntiAlias(int enable) {
	
}

void bbWireFrame(int enable) {
	
}

void bbAmbientLight(float r, float g, float b) {
	
}

void bbClearCollisions() {
	
}

void bbCollisions(int src_type, int dest_type, int method, int response) {
	
}

void bbUpdateWorld(float elapsed) {
	
}

void bbCaptureWorld() {
	
}

void bbRenderWorld(float tween) {
	
}

int bbTrisRendered() {
	return 0;
}

float bbStats3D(int n) {
	return 0.0;
}

int bbRunningUnderWine() {
	return 0;
}

////////////////
// MEMORYINFO //
////////////////
int bbMemoryLoad() {
	return 0;
}

int bbTotalPhys() {
	return 0;
}

int bbAvailPhys() {
	return 0;
}

int bbTotalVirtual() {
	return 0;
}

int bbAvailVirtual() {
	return 0;
}

//////////////////////
// TEXTURE COMMANDS //
//////////////////////

//Note: modify canvas->backup() to NOT release backup image!
int bbLoadTexture(BBStr* file, int flags) {
	return 0;
}

int bbLoadAnimTexture(BBStr* file, int flags, int w, int h, int first, int cnt) {
	return 0;
}

int bbCreateTexture(int w, int h, int flags, int frames) {
	return 0;
}

void bbFreeTexture(int t) {
	
}

void bbTextureBlend(int t, int blend) {
	
}

void bbTextureCoords(int t, int flags) {
	
}

void bbTextureBumpEnvMat(int t, int x, int y, float envmat) {
	
}

void bbTextureBumpEnvScale(int t, float envscale) {
	
}

void bbTextureBumpEnvOffset(int t, float envoffset) {
	
}

void bbScaleTexture(int t, float u_scale, float v_scale) {
	
}

void bbRotateTexture(int t, float angle) {
	
}

void bbPositionTexture(int t, float u_pos, float v_pos) {
	
}

void bbTextureLodBias(float bias) {
	
}

void bbTextureAnisotropic(int level) {
	
}

int bbTextureWidth(int t) {
	return 0;
}

int bbTextureHeight(int t) {
	return 0;
}

BBStr* bbTextureName(int t) {
	BBStr* h;
	return h;
}

void bbSetCubeFace(int t, int face) {
	
}

void bbSetCubeMode(int t, int mode) {
	
}

int bbTextureBuffer(int t, int frame) {
	
	return 0;
}

void  bbClearTextureFilters() {
	
}

void  bbTextureFilter(BBStr* t, int flags) {
	
}

////////////////////
// BRUSH COMMANDS //
////////////////////
int bbCreateBrush(float r, float g, float b) {
	return 0;
}

int bbLoadBrush(BBStr* file, int flags, float u_scale, float v_scale) {
	return 0;
}

void  bbFreeBrush(int b) {
	
}

void  bbBrushColor(int br, float r, float g, float b) {
	
}

void  bbBrushAlpha(int b, float alpha) {
	
}

void  bbBrushShininess(int b, float n) {
	
}

void  bbBrushTexture(int b, int t, int frame, int index) {
	
}

int bbGetBrushTexture(int b, int index) {
	return 0;
}

void  bbBrushBlend(int b, int blend) {
	
}

void  bbBrushFX(int b, int fx) {
	
}

///////////////////
// MESH COMMANDS //
///////////////////
int bbCreateMesh(int p) {
	return 0;
}

int bbLoadMesh(BBStr* f, int p) {
	return 0;
}

int bbLoadAnimMesh(BBStr* f, int p) {
	return 0;
}

int bbCreateCube(int p) {
	return 0;
}

int bbCreateSphere(int segs, int p) {
	return 0;
}

int  bbCreateCylinder(int segs, int solid, int  p) {
	return 0;
}

int  bbCreateCone(int segs, int solid, int  p) {
	return 0;
}

int  bbCopyMesh(int  m, int  p) {
	return 0;
}

void  bbScaleMesh(int  m, float x, float y, float z) {

}

void  bbRotateMesh(int  m, float x, float y, float z) {
	
}

void  bbPositionMesh(int  m, float x, float y, float z) {
	
}

void  bbFitMesh(int  m, float x, float y, float z, float w, float h, float d, int uniform) {
	
}

void  bbFlipMesh(int  m) {
	
}

void  bbPaintMesh(int  m, int b) {
	
}

void  bbAddMesh(int  src, int  dest) {
	
}

void  bbUpdateNormals(int  m) {
	
}

void  bbLightMesh(int  m, float r, float g, float b, float range, float x, float y, float z) {
	
}

float  bbMeshWidth(int  m) {
	return 0.0;
}

float  bbMeshHeight(int  m) {
	return 0.0;
}

float  bbMeshDepth(int  m) {
	return 0.0;
}

int  bbMeshesIntersect(int  a, int  b) {
	return 0;
}

int  bbCountSurfaces(int  m) {
	return 0;
}

int bbGetSurface(int  m, int index) {
	return 0;
}

void bbMeshCullBox(int  m, float x, float y, float z, float width, float height, float depth) {
	
}


//////////////////////
// SURFACE COMMANDS //
//////////////////////
int  bbFindSurface(int  m, int  b) {
	return 0;
}

int  bbCreateSurface(int  m, int  b) {
	return 0;
}

int  bbGetSurfaceBrush(int  s) {
	return 0;
}

int  bbGetEntityBrush(int  m) {
	return 0;
}

void  bbClearSurface(int  s, int verts, int tris) {
	
}

void  bbPaintSurface(int  s, int  b) {
	
}

int  bbAddVertex(int  s, float x, float y, float z, float tu, float tv, float tw) {
	return 0;
}

int  bbAddTriangle(int  s, int v0, int v1, int v2) {
	return 0;
}

void  bbVertexCoords(int  s, int n, float x, float y, float z) {
	
}

void  bbVertexNormal(int  s, int n, float x, float y, float z) {
	
}

void  bbVertexColor(int  s, int n, float r, float g, float b, float a) {
	
}

void  bbVertexTexCoords(int  s, int n, float u, float v, float w, int set) {
	
}

int  bbCountVertices(int  s) {
	return 0;
}

int  bbCountTriangles(int  s) {
	return 0;
}

float  bbVertexX(int  s, int n) {
	return 0.0;
}

float  bbVertexY(int  s, int n) {
	return 0.0;
}

float  bbVertexZ(int  s, int n) {
	return 0.0;
}

float  bbVertexNX(int  s, int n) {
	return 0.0;
}

float  bbVertexNY(int  s, int n) {
	return 0.0;
}

float  bbVertexNZ(int  s, int n) {
	return 0.0;
}

float  bbVertexRed(int  s, int n) {
	return 0.0;
}

float  bbVertexGreen(int  s, int n) {
	return 0.0;
}

float  bbVertexBlue(int  s, int n) {
	return 0.0;
}
float  bbVertexAlpha(int  s, int n) {
	return 0.0;
}
float  bbVertexU(int  s, int n, int t) {
	return 0.0;
}
float  bbVertexV(int  s, int n, int t) {
	return 0.0;
}
float  bbVertexW(int  s, int n, int t) {
	return 0.0;
}
int  bbTriangleVertex(int  s, int n, int v) {
	return 0;
}

/////////////////////
// CAMERA COMMANDS //
/////////////////////
int  bbCreateCamera(int  p) {
	return 0;
}

void  bbCameraZoom(int  c, float zoom) {

}

void  bbCameraRange(int  c, float nr, float fr) {
	
}

float bbGetCameraRangeNear(int  c) {
	return 0.0;
}

float bbGetCameraRangeFar(int  c) {
	return 0.0;
}

void  bbCameraClsColor(int  c, float r, float g, float b) {
}

void  bbCameraClsMode(int  c, int cls_color, int cls_zbuffer) {
	
}

void  bbCameraProjMode(int  c, int mode) {
	
}

void  bbCameraViewport(int  c, int x, int y, int w, int h) {
	
}

void  bbCameraFogRange(int  c, float nr, float fr) {
	
}

float bbGetCameraFogRangeNear(int  c) {
	return 0.0;
}

float bbGetCameraFogRangeFar(int  c) {
	return 0.0;
}

void  bbCameraFogDensity(int  c, float den) {
	
}

void  bbCameraFogColor(int  c, float r, float g, float b) {
	
}

void  bbCameraFogMode(int  c, int mode) {
	
}

int  bbCameraProject(int  c, float x, float y, float z) {
	
	return 0;
}

float  bbProjectedX() {
	return 0.0;
}

float  bbProjectedY() {
	return 0.0;
}

float  bbProjectedZ() {
	return 0.0;
}

int  bbCameraPick(int  c, float x, float y) {
	return 0;
}

int  bbLinePick(float x, float y, float z, float dx, float dy, float dz, float radius) {
	return 0;
}

int  bbEntityPick(int  src, float range) {
	return 0;
}

int  bbEntityVisible(int  src, int  dest) {
	return 0;
}

int  bbEntityInView(int  e, int  c) {
	return 0;
}

float  bbPickedX() {
	return 0.0;
}

float  bbPickedY() {
	return 0.0;
}

float  bbPickedZ() {
	return 0.0;
}

float  bbPickedNX() {
	return 0.0;
}

float  bbPickedNY() {
	return 0.0;
}

float  bbPickedNZ() {
	return 0.0;
}

float  bbPickedTime() {
	return 0.0;
}

int  bbPickedEntity() {
	return 0;
}

void* bbPickedSurface() {
	void* t;
	return t;
}

int  bbPickedTriangle() {
	return 0;
}

////////////////////
// LIGHT COMMANDS //
////////////////////
int  bbCreateLight(int type, int  p) {
	return 0;
}

void  bbLightColor(int  light, float r, float g, float b) {
	
}

void  bbLightRange(int  light, float range) {
	
}

void  bbLightConeAngles(int  light, float inner, float outer) {
	
}

////////////////////
// PIVOT COMMANDS //
////////////////////
int  bbCreatePivot(int  p) {
	return 0;
}

/////////////////////
// SPRITE COMMANDS //
/////////////////////
int  bbCreateSprite(int  p) {
	return 0;
}

int  bbLoadSprite(BBStr* file, int flags, int  p) {
	return 0;
}

void  bbRotateSprite(int  s, float angle) {
	
}

void  bbScaleSprite(int  s, float x, float y) {
	
}

void  bbHandleSprite(int  s, float x, float y) {
	
}

void  bbSpriteViewMode(int  s, int mode) {
	
}

/////////////////////
// MIRROR COMMANDS //
/////////////////////
int  bbCreateMirror(int  p) {
	return 0;
}

////////////////////
// PLANE COMMANDS //
////////////////////
int  bbCreatePlane(int segs, int  p) {
	return 0;
}

//////////////////
// MD2 COMMANDS //
//////////////////
int  bbLoadMD2(BBStr* file, int  p) {
	return 0;
}

void  bbAnimateMD2(int   m, int mode, float speed, int first, int last, float trans) {
	
}

float  bbMD2AnimTime(int   m) {
	return 0.0;
}

int  bbMD2AnimLength(int   m) {
	return 0;
}

int  bbMD2Animating(int   m) {
	return 0;
}

//////////////////
// BSP Commands //
//////////////////
int  bbLoadBSP(BBStr* file, float gam, int  p) {
	return 0;
}

void  bbBSPAmbientLight(int   t, float r, float g, float b) {
	
}

void  bbBSPLighting(int   t, int lmap) {
	
}

//////////////////////
// TERRAIN COMMANDS //
//////////////////////

int  bbCreateTerrain(int n, int  p) {
	return 0;
}

int  bbLoadTerrain(BBStr* file, int  p) {
	return 0;
}

void  bbTerrainDetail(int  t, int n, int m) {
	
}

void  bbTerrainShading(int  t, int enable) {
	
}

float  bbTerrainX(int  t, float x, float y, float z) {
	return 0.0;
}

float  bbTerrainY(int  t, float x, float y, float z) {
	return 0.0;
}

float  bbTerrainZ(int  t, float x, float y, float z) {
	return 0.0;
}

int  bbTerrainSize(int  t) {
	return 0;
}

float  bbTerrainHeight(int  t, int x, int z) {
	return 0.0;
}

void  bbModifyTerrain(int  t, int x, int z, float h, int realtime) {
	
}

////////////////////
// AUDIO COMMANDS //
////////////////////
int  bbCreateListener(int  p, float roll, float dopp, float dist) {
	return 0;
}

int bbEmitSound(int sound, int  o) {
	return 0;
}

/////////////////////
// ENTITY COMMANDS //
/////////////////////
int  bbCopyEntity(int  e, int  p) {
	return 0;
}

void  bbFreeEntity(int  e) {
	
}

void  bbHideEntity(int  e) {
	
}

void  bbShowEntity(int  e) {
	
}

int bbEntityHidden(int  e) {
	return 0;
}

void  bbEntityParent(int  e, int  p, int global) {
	
}

int  bbCountChildren(int  e) {
	return 0;
}

int  bbGetChild(int  e, int index) {
	return 0;
}

int  bbFindChild(int  e, BBStr* t) {
	return 0;
}

////////////////////////
// ANIMATION COMMANDS //
////////////////////////
int  bbLoadAnimSeq(int  o, BBStr* f) {
	return 0;
}

void  bbSetAnimTime(int  o, float time, int seq) {
	
}

void  bbAnimate(int  o, int mode, float speed, int seq, float trans) {
	
}

void  bbSetAnimKey(int  o, int frame, int pos_key, int rot_key, int scl_key) {
	
}

int  bbExtractAnimSeq(int  o, int first, int last, int seq) {
	return 0;
}

int  bbAddAnimSeq(int  o, int length) {
	return 0;
}

int  bbAnimSeq(int  o) {
	return 0;
}

float  bbAnimTime(int  o) {
	return 0.0;
}

int  bbAnimLength(int  o) {
	return 0;
}

int  bbAnimating(int  o) {
	return 0;
}

////////////////////////////////
// ENTITY SPECIAL FX COMMANDS //
////////////////////////////////
void  bbPaintEntity(int  m, int  b) {
	
}

void  bbEntityColor(int  m, float r, float g, float b) {
	
}

void  bbEntityAlpha(int  m, float alpha) {
	
}

void  bbEntityShininess(int  m, float shininess) {
	
}

void  bbEntityTexture(int  m, int t, int frame, int index) {
	
}

void  bbEntityBlend(int  m, int blend) {
	
}

void  bbEntityFX(int  m, int fx) {
	
}

void  bbEntityAutoFade(int  m, float nr, float fr) {
	
}

void  bbEntityOrder(int  o, int n) {
	
}

//////////////////////////////
// ENTITY PROPERTY COMMANDS //
//////////////////////////////
float  bbEntityX(int  e, int global) {
	return 0.0;
}

float  bbEntityY(int  e, int global) {
	return 0.0;
}

float  bbEntityZ(int  e, int global) {
	return 0.0;
}

float  bbEntityPitch(int  e, int global) {
	return 0.0;
}

float  bbEntityYaw(int  e, int global) {
	return 0.0;
}

float  bbEntityRoll(int  e, int global) {
	return 0.0;
}

float  bbEntityScaleX(int  e, int global) {
	return 0.0;
}

float  bbEntityScaleY(int  e, int global) {
	return 0.0;
}

float  bbEntityScaleZ(int  e, int global) {
	return 0.0;
}

float  bbGetMatElement(int  e, int row, int col) {
	return 0.0;
}

void  bbTFormPoint(float x, float y, float z, int  src, int  dest) {
	
}

void  bbTFormVector(float x, float y, float z, int  src, int  dest) {
}

void  bbTFormNormal(float x, float y, float z, int  src, int  dest) {
	
}

float  bbTFormedX() {
	return 0.0;
}

float  bbTFormedY() {
	return 0.0;
}

float  bbTFormedZ() {
	return 0.0;
}

float  bbVectorYaw(float x, float y, float z) {
	return 0.0;
}

float  bbVectorPitch(float x, float y, float z) {
	return 0.0;
}

float  bbDeltaYaw(int  src, int  dest) {
	return 0.0;
}

float  bbDeltaPitch(int  src, int  dest) {
	return 0.0;
}

///////////////////////////////
// ENTITY COLLISION COMMANDS //
///////////////////////////////
void  bbResetEntity(int  o) {
	
}

void  bbEntityType(int  o, int type, int recurs) {
	
}

void  bbEntityPickMode(int  o, int mode, int obs) {
	
}

int  bbGetParent(int  e) {
	return 0;
}

int  bbGetEntityType(int  o) {
	return 0;
}

void  bbEntityRadius(int  o, float x_radius, float y_radius) {
	
}

void  bbEntityBox(int  o, float x, float y, float z, float w, float h, float d) {
	
}

int  bbEntityCollided(int  o, int type) {
	
	return 0;
}

int  bbCountCollisions(int  o) {
	return 0;
}

float  bbCollisionX(int  o, int index) {
	return 0.0;
}

float  bbCollisionY(int  o, int index) {
	return 0.0;
}

float  bbCollisionZ(int  o, int index) {
	return 0.0;
}

float  bbCollisionNX(int  o, int index) {
	return 0.0;
}

float  bbCollisionNY(int  o, int index) {
	return 0.0;
}

float  bbCollisionNZ(int  o, int index) {
	return 0.0;
}

float  bbCollisionTime(int  o, int index) {
	return 0.0;
}

int  bbCollisionEntity(int  o, int index) {
	return 0;
}

void* bbCollisionSurface(int  o, int index) {
	return 0;
}

int  bbCollisionTriangle(int  o, int index) {
	return 0;
}

float  bbEntityDistance(int  src, int  dest) {
	return 0.0;
}

float  bbEntityDistanceSquared(int  src, int  dest) {
	return 0.0;
}

float  bbDistance(float x1, float x2, float y1, float y2, float z1, float z2) {
	return 0.0;
}
float  bbDistanceSquared(float x1, float x2, float y1, float y2, float z1, float z2) {
	return 0.0;
}


////////////////////////////////////
// ENTITY TRANSFORMATION COMMANDS //
////////////////////////////////////
void  bbMoveEntity(int  e, float x, float y, float z) {
	
}

void  bbTurnEntity(int  e, float p, float y, float r, int global) {
	
}

void  bbTranslateEntity(int  e, float x, float y, float z, int global) {
	
}

void  bbPositionEntity(int  e, float x, float y, float z, int global) {
	
}

void  bbScaleEntity(int  e, float x, float y, float z, int global) {
	
}

void  bbRotateEntity(int  e, float p, float y, float r, int global) {

}

void  bbPointEntity(int  e, int  t, float roll) {
	
}

void  bbAlignToVector(int  e, float nx, float ny, float nz, int axis, float rate) {
	
}

//////////////////////////
// ENTITY MISC COMMANDS //
//////////////////////////
void  bbNameEntity(int  e, BBStr* t) {
	
}

BBStr* bbEntityName(int  e) {
	BBStr* t;
	return t;
}

BBStr* bbEntityClass(int  e) {
	BBStr* t;
	return t;
}

void  bbClearWorld(int e, int b, int t) {
	
}

int  bbActiveTextures() {
	return 0;
}

void blitz3d_open() {
	
}

void blitz3d_close() {
	
}

bool blitz3d_create() {
	
	return true;
}

bool blitz3d_destroy() {
	
	return true;
}

void blitz3d_link(void (*rtSym)(const char* sym, void* pc)) {
	rtSym("LoaderMatrix$file_ext#xx#xy#xz#yx#yy#yz#zx#zy#zz", bbLoaderMatrix);
	rtSym("HWMultiTex%enable", bbHWMultiTex);
	rtSym("%HWTexUnits", bbHWTexUnits);
	rtSym("%GfxDriverCaps3D", bbGfxDriverCaps3D);
	rtSym("WBuffer%enable", bbWBuffer);
	rtSym("Dither%enable", bbDither);
	rtSym("AntiAlias%enable", bbAntiAlias);
	rtSym("WireFrame%enable", bbWireFrame);
	rtSym("AmbientLight#red#green#blue", bbAmbientLight);
	rtSym("ClearCollisions", bbClearCollisions);
	rtSym("Collisions%source_type%destination_type%method%response", bbCollisions);
	rtSym("UpdateWorld#elapsed_time=1", bbUpdateWorld);
	rtSym("CaptureWorld", bbCaptureWorld);
	rtSym("RenderWorld#tween=1", bbRenderWorld);
	rtSym("ClearWorld%entities=1%brushes=1%textures=1", bbClearWorld);
	rtSym("%ActiveTextures", bbActiveTextures);
	rtSym("%TrisRendered", bbTrisRendered);
	rtSym("#Stats3D%type", bbStats3D);

	rtSym("%CreateTexture%width%height%flags=0%frames=1", bbCreateTexture);
	rtSym("%LoadTexture$file%flags=1", bbLoadTexture);
	rtSym("%LoadAnimTexture$file%flags%width%height%first%count", bbLoadAnimTexture);
	rtSym("FreeTexture%texture", bbFreeTexture);
	rtSym("TextureBlend%texture%blend", bbTextureBlend);
	rtSym("TextureCoords%texture%coords", bbTextureCoords);
	rtSym("TextureBumpEnvMat%texture%x%y#envmat", bbTextureBumpEnvMat);
	rtSym("TextureBumpEnvScale%texture#envmat", bbTextureBumpEnvScale);
	rtSym("TextureBumpEnvOffset%texture#envoffset", bbTextureBumpEnvOffset);

	rtSym("ScaleTexture%texture#u_scale#v_scale", bbScaleTexture);
	rtSym("RotateTexture%texture#angle", bbRotateTexture);
	rtSym("PositionTexture%texture#u_offset#v_offset", bbPositionTexture);
	rtSym("TextureLodBias#bias", bbTextureLodBias);
	rtSym("TextureAnisotropic%level", bbTextureAnisotropic);

	rtSym("%TextureWidth%texture", bbTextureWidth);
	rtSym("%TextureHeight%texture", bbTextureHeight);
	rtSym("$TextureName%texture", bbTextureName);
	rtSym("SetCubeFace%texture%face", bbSetCubeFace);
	rtSym("SetCubeMode%texture%mode", bbSetCubeMode);
	rtSym("%TextureBuffer%texture%frame=0", bbTextureBuffer);
	rtSym("ClearTextureFilters", bbClearTextureFilters);
	rtSym("TextureFilter$match_text%texture_flags=0", bbTextureFilter);

	rtSym("%CreateBrush#red=255#green=255#blue=255", bbCreateBrush);
	rtSym("%LoadBrush$file%texture_flags=1#u_scale=1#v_scale=1", bbLoadBrush);
	rtSym("FreeBrush%brush", bbFreeBrush);
	rtSym("BrushColor%brush#red#green#blue", bbBrushColor);
	rtSym("BrushAlpha%brush#alpha", bbBrushAlpha);
	rtSym("BrushShininess%brush#shininess", bbBrushShininess);
	rtSym("BrushTexture%brush%texture%frame=0%index=0", bbBrushTexture);
	rtSym("%GetBrushTexture%brush%index=0", bbGetBrushTexture);
	rtSym("BrushBlend%brush%blend", bbBrushBlend);
	rtSym("BrushFX%brush%fx", bbBrushFX);

	rtSym("%LoadMesh$file%parent=0", bbLoadMesh);
	rtSym("%LoadAnimMesh$file%parent=0", bbLoadAnimMesh);
	rtSym("%LoadAnimSeq%entity$file", bbLoadAnimSeq);

	rtSym("%CreateMesh%parent=0", bbCreateMesh);
	rtSym("%CreateCube%parent=0", bbCreateCube);
	rtSym("%CreateSphere%segments=8%parent=0", bbCreateSphere);
	rtSym("%CreateCylinder%segments=8%solid=1%parent=0", bbCreateCylinder);
	rtSym("%CreateCone%segments=8%solid=1%parent=0", bbCreateCone);
	rtSym("%CopyMesh%mesh%parent=0", bbCopyMesh);
	rtSym("ScaleMesh%mesh#x_scale#y_scale#z_scale", bbScaleMesh);
	rtSym("RotateMesh%mesh#pitch#yaw#roll", bbRotateMesh);
	rtSym("PositionMesh%mesh#x#y#z", bbPositionMesh);
	rtSym("FitMesh%mesh#x#y#z#width#height#depth%uniform=0", bbFitMesh);
	rtSym("FlipMesh%mesh", bbFlipMesh);
	rtSym("PaintMesh%mesh%brush", bbPaintMesh);
	rtSym("AddMesh%source_mesh%dest_mesh", bbAddMesh);
	rtSym("UpdateNormals%mesh", bbUpdateNormals);
	rtSym("LightMesh%mesh#red#green#blue#range=0#x=0#y=0#z=0", bbLightMesh);
	rtSym("#MeshWidth%mesh", bbMeshWidth);
	rtSym("#MeshHeight%mesh", bbMeshHeight);
	rtSym("#MeshDepth%mesh", bbMeshDepth);
	rtSym("%MeshesIntersect%mesh_a%mesh_b", bbMeshesIntersect);
	rtSym("%CountSurfaces%mesh", bbCountSurfaces);
	rtSym("%GetSurface%mesh%surface_index", bbGetSurface);
	rtSym("MeshCullBox%mesh#x#y#z#width#height#depth", bbMeshCullBox);

	rtSym("%CreateSurface%mesh%brush=0", bbCreateSurface);
	rtSym("%GetSurfaceBrush%surface", bbGetSurfaceBrush);
	rtSym("%GetEntityBrush%entity", bbGetEntityBrush);
	rtSym("%FindSurface%mesh%brush", bbFindSurface);
	rtSym("ClearSurface%surface%clear_vertices=1%clear_triangles=1", bbClearSurface);
	rtSym("PaintSurface%surface%brush", bbPaintSurface);
	rtSym("%AddVertex%surface#x#y#z#u=0#v=0#w=1", bbAddVertex);
	rtSym("%AddTriangle%surface%v0%v1%v2", bbAddTriangle);
	rtSym("VertexCoords%surface%index#x#y#z", bbVertexCoords);
	rtSym("VertexNormal%surface%index#nx#ny#nz", bbVertexNormal);
	rtSym("VertexColor%surface%index#red#green#blue#alpha=1", bbVertexColor);
	rtSym("VertexTexCoords%surface%index#u#v#w=1%coord_set=0", bbVertexTexCoords);
	rtSym("%CountVertices%surface", bbCountVertices);
	rtSym("%CountTriangles%surface", bbCountTriangles);
	rtSym("#VertexX%surface%index", bbVertexX);
	rtSym("#VertexY%surface%index", bbVertexY);
	rtSym("#VertexZ%surface%index", bbVertexZ);
	rtSym("#VertexNX%surface%index", bbVertexNX);
	rtSym("#VertexNY%surface%index", bbVertexNY);
	rtSym("#VertexNZ%surface%index", bbVertexNZ);
	rtSym("#VertexRed%surface%index", bbVertexRed);
	rtSym("#VertexGreen%surface%index", bbVertexGreen);
	rtSym("#VertexBlue%surface%index", bbVertexBlue);
	rtSym("#VertexAlpha%surface%index", bbVertexAlpha);
	rtSym("#VertexU%surface%index%coord_set=0", bbVertexU);
	rtSym("#VertexV%surface%index%coord_set=0", bbVertexV);
	rtSym("#VertexW%surface%index%coord_set=0", bbVertexW);
	rtSym("%TriangleVertex%surface%index%vertex", bbTriangleVertex);

	rtSym("%CreateCamera%parent=0", bbCreateCamera);
	rtSym("CameraZoom%camera#zoom", bbCameraZoom);
	rtSym("CameraRange%camera#near#far", bbCameraRange);
	rtSym("#GetCameraRangeNear%camera", bbGetCameraRangeNear);
	rtSym("#GetCameraRangeFar%camera", bbGetCameraRangeFar);
	rtSym("CameraClsColor%camera#red#green#blue", bbCameraClsColor);
	rtSym("CameraClsMode%camera%cls_color%cls_zbuffer", bbCameraClsMode);
	rtSym("CameraProjMode%camera%mode", bbCameraProjMode);
	rtSym("CameraViewport%camera%x%y%width%height", bbCameraViewport);
	rtSym("CameraFogColor%camera#red#green#blue", bbCameraFogColor);
	rtSym("CameraFogRange%camera#near#far", bbCameraFogRange);
	rtSym("#GetCameraFogRangeNear%camera", bbGetCameraFogRangeNear);
	rtSym("#GetCameraFogRangeFar%camera", bbGetCameraFogRangeFar);
	rtSym("CameraFogDensity%camera#density", bbCameraFogDensity);
	rtSym("CameraFogMode%camera%mode", bbCameraFogMode);
	rtSym("CameraProject%camera#x#y#z", bbCameraProject);
	rtSym("#ProjectedX", bbProjectedX);
	rtSym("#ProjectedY", bbProjectedY);
	rtSym("#ProjectedZ", bbProjectedZ);

	rtSym("%EntityInView%entity%camera", bbEntityInView);
	rtSym("%EntityVisible%src_entity%dest_entity", bbEntityVisible);

	rtSym("%EntityPick%entity#range", bbEntityPick);
	rtSym("%LinePick#x#y#z#dx#dy#dz#radius=0", bbLinePick);
	rtSym("%CameraPick%camera#viewport_x#viewport_y", bbCameraPick);

	rtSym("#PickedX", bbPickedX);
	rtSym("#PickedY", bbPickedY);
	rtSym("#PickedZ", bbPickedZ);
	rtSym("#PickedNX", bbPickedNX);
	rtSym("#PickedNY", bbPickedNY);
	rtSym("#PickedNZ", bbPickedNZ);
	rtSym("#PickedTime", bbPickedTime);
	rtSym("%PickedEntity", bbPickedEntity);
	rtSym("%PickedSurface", bbPickedSurface);
	rtSym("%PickedTriangle", bbPickedTriangle);

	rtSym("%CreateLight%type=1%parent=0", bbCreateLight);
	rtSym("LightColor%light#red#green#blue", bbLightColor);
	rtSym("LightRange%light#range", bbLightRange);
	rtSym("LightConeAngles%light#inner_angle#outer_angle", bbLightConeAngles);

	rtSym("%CreatePivot%parent=0", bbCreatePivot);

	rtSym("%CreateSprite%parent=0", bbCreateSprite);
	rtSym("%LoadSprite$file%texture_flags=1%parent=0", bbLoadSprite);
	rtSym("RotateSprite%sprite#angle", bbRotateSprite);
	rtSym("ScaleSprite%sprite#x_scale#y_scale", bbScaleSprite);
	rtSym("HandleSprite%sprite#x_handle#y_handle", bbHandleSprite);
	rtSym("SpriteViewMode%sprite%view_mode", bbSpriteViewMode);

	rtSym("%LoadMD2$file%parent=0", bbLoadMD2);
	rtSym("AnimateMD2%md2%mode=1#speed=1%first_frame=0%last_frame=9999#transition=0", bbAnimateMD2);
	rtSym("#MD2AnimTime%md2", bbMD2AnimTime);
	rtSym("%MD2AnimLength%md2", bbMD2AnimLength);
	rtSym("%MD2Animating%md2", bbMD2Animating);

	rtSym("%LoadBSP$file#gamma_adj=0%parent=0", bbLoadBSP);
	rtSym("BSPLighting%bsp%use_lightmaps", bbBSPLighting);
	rtSym("BSPAmbientLight%bsp#red#green#blue", bbBSPAmbientLight);

	rtSym("%CreateMirror%parent=0", bbCreateMirror);

	rtSym("%CreatePlane%segments=1%parent=0", bbCreatePlane);

	rtSym("%CreateTerrain%grid_size%parent=0", bbCreateTerrain);
	rtSym("%LoadTerrain$heightmap_file%parent=0", bbLoadTerrain);
	rtSym("TerrainDetail%terrain%detail_level%morph=0", bbTerrainDetail);
	rtSym("TerrainShading%terrain%enable", bbTerrainShading);
	rtSym("#TerrainX%terrain#world_x#world_y#world_z", bbTerrainX);
	rtSym("#TerrainY%terrain#world_x#world_y#world_z", bbTerrainY);
	rtSym("#TerrainZ%terrain#world_x#world_y#world_z", bbTerrainZ);
	rtSym("%TerrainSize%terrain", bbTerrainSize);
	rtSym("#TerrainHeight%terrain%terrain_x%terrain_z", bbTerrainHeight);
	rtSym("ModifyTerrain%terrain%terrain_x%terrain_z#height%realtime=0", bbModifyTerrain);

	rtSym("%CreateListener%parent#rolloff_factor=1#doppler_scale=1#distance_scale=1", bbCreateListener);
	rtSym("%EmitSound%sound%entity", bbEmitSound);

	rtSym("%CopyEntity%entity%parent=0", bbCopyEntity);

	rtSym("#EntityX%entity%global=0", bbEntityX);
	rtSym("#EntityY%entity%global=0", bbEntityY);
	rtSym("#EntityZ%entity%global=0", bbEntityZ);
	rtSym("#EntityPitch%entity%global=0", bbEntityPitch);
	rtSym("#EntityYaw%entity%global=0", bbEntityYaw);
	rtSym("#EntityRoll%entity%global=0", bbEntityRoll);
	rtSym("#EntityScaleX%entity%global=0", bbEntityScaleX);
	rtSym("#EntityScaleY%entity%global=0", bbEntityScaleY);
	rtSym("#EntityScaleZ%entity%global=0", bbEntityScaleZ);
	rtSym("#GetMatElement%entity%row%column", bbGetMatElement);
	rtSym("TFormPoint#x#y#z%source_entity%dest_entity", bbTFormPoint);
	rtSym("TFormVector#x#y#z%source_entity%dest_entity", bbTFormVector);
	rtSym("TFormNormal#x#y#z%source_entity%dest_entity", bbTFormNormal);
	rtSym("#TFormedX", bbTFormedX);
	rtSym("#TFormedY", bbTFormedY);
	rtSym("#TFormedZ", bbTFormedZ);
	rtSym("#VectorYaw#x#y#z", bbVectorYaw);
	rtSym("#VectorPitch#x#y#z", bbVectorPitch);
	rtSym("#DeltaPitch%src_entity%dest_entity", bbDeltaPitch);
	rtSym("#DeltaYaw%src_entity%dest_entity", bbDeltaYaw);

	rtSym("ResetEntity%entity", bbResetEntity);
	rtSym("EntityType%entity%collision_type%recursive=0", bbEntityType);
	rtSym("EntityPickMode%entity%pick_geometry%obscurer=1", bbEntityPickMode);
	rtSym("%GetParent%entity", bbGetParent);
	rtSym("%GetEntityType%entity", bbGetEntityType);
	rtSym("EntityRadius%entity#x_radius#y_radius=0", bbEntityRadius);
	rtSym("EntityBox%entity#x#y#z#width#height#depth", bbEntityBox);
	rtSym("#EntityDistance%source_entity%destination_entity", bbEntityDistance);
	rtSym("#EntityDistanceSquared%source_entity%destination_entity", bbEntityDistanceSquared);
	rtSym("%EntityCollided%entity%type", bbEntityCollided);

	rtSym("%CountCollisions%entity", bbCountCollisions);
	rtSym("#CollisionX%entity%collision_index", bbCollisionX);
	rtSym("#CollisionY%entity%collision_index", bbCollisionY);
	rtSym("#CollisionZ%entity%collision_index", bbCollisionZ);
	rtSym("#CollisionNX%entity%collision_index", bbCollisionNX);
	rtSym("#CollisionNY%entity%collision_index", bbCollisionNY);
	rtSym("#CollisionNZ%entity%collision_index", bbCollisionNZ);
	rtSym("#CollisionTime%entity%collision_index", bbCollisionTime);
	rtSym("%CollisionEntity%entity%collision_index", bbCollisionEntity);
	rtSym("%CollisionSurface%entity%collision_index", bbCollisionSurface);
	rtSym("%CollisionTriangle%entity%collision_index", bbCollisionTriangle);

	rtSym("#Distance#x1#x2#y1#y2#z1=0#z2=0", bbDistance);
	rtSym("#DistanceSquared#x1#x2#y1#y2#z1=0#z2=0", bbDistanceSquared);

	rtSym("MoveEntity%entity#x#y#z", bbMoveEntity);
	rtSym("TurnEntity%entity#pitch#yaw#roll%global=0", bbTurnEntity);
	rtSym("TranslateEntity%entity#x#y#z%global=0", bbTranslateEntity);
	rtSym("PositionEntity%entity#x#y#z%global=0", bbPositionEntity);
	rtSym("ScaleEntity%entity#x_scale#y_scale#z_scale%global=0", bbScaleEntity);
	rtSym("RotateEntity%entity#pitch#yaw#roll%global=0", bbRotateEntity);
	rtSym("PointEntity%entity%target#roll=0", bbPointEntity);
	rtSym("AlignToVector%entity#vector_x#vector_y#vector_z%axis#rate=1", bbAlignToVector);
	rtSym("SetAnimTime%entity#time%anim_seq=0", bbSetAnimTime);
	rtSym("Animate%entity%mode=1#speed=1%sequence=0#transition=0", bbAnimate);
	rtSym("SetAnimKey%entity%frame%pos_key=1%rot_key=1%scale_key=1", bbSetAnimKey);
	rtSym("%AddAnimSeq%entity%length", bbAddAnimSeq);
	rtSym("%ExtractAnimSeq%entity%first_frame%last_frame%anim_seq=0", bbExtractAnimSeq);
	rtSym("%AnimSeq%entity", bbAnimSeq);
	rtSym("#AnimTime%entity", bbAnimTime);
	rtSym("%AnimLength%entity", bbAnimLength);
	rtSym("%Animating%entity", bbAnimating);

	rtSym("EntityParent%entity%parent%global=1", bbEntityParent);
	rtSym("%CountChildren%entity", bbCountChildren);
	rtSym("%GetChild%entity%index", bbGetChild);
	rtSym("%FindChild%entity$name", bbFindChild);

	rtSym("PaintEntity%entity%brush", bbPaintEntity);
	rtSym("EntityColor%entity#red#green#blue", bbEntityColor);
	rtSym("EntityAlpha%entity#alpha", bbEntityAlpha);
	rtSym("EntityShininess%entity#shininess", bbEntityShininess);
	rtSym("EntityTexture%entity%texture%frame=0%index=0", bbEntityTexture);
	rtSym("EntityBlend%entity%blend", bbEntityBlend);
	rtSym("EntityFX%entity%fx", bbEntityFX);
	rtSym("EntityAutoFade%entity#near#far", bbEntityAutoFade);
	rtSym("EntityOrder%entity%order", bbEntityOrder);
	rtSym("HideEntity%entity", bbHideEntity);
	rtSym("ShowEntity%entity", bbShowEntity);
	rtSym("%EntityHidden%entity", bbEntityHidden);
	rtSym("FreeEntity%entity", bbFreeEntity);

	rtSym("NameEntity%entity$name", bbNameEntity);
	rtSym("$EntityName%entity", bbEntityName);
	rtSym("$EntityClass%entity", bbEntityClass);

	rtSym("%MemoryLoad", bbMemoryLoad);
	rtSym("%TotalPhys", bbTotalPhys);
	rtSym("%AvailPhys", bbAvailPhys);
	rtSym("%TotalVirtual", bbTotalVirtual);
	rtSym("%AvailVirtual", bbAvailVirtual);

	rtSym("%RunningOnWine", bbRunningUnderWine);
}