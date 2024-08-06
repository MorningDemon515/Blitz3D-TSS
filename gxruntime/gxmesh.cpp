#include "std.h"
#include "gxmesh.h"
#include "gxgraphics.h"

#include "gxruntime.h"

extern gxRuntime* gx_runtime;

gxMesh::gxMesh(gxGraphics* g, IDirect3DVertexBuffer9* vs, WORD* is, int max_vs, int max_ts) :
	graphics(g), locked_verts(0), vertex_buff(vs), tri_indices(is), max_verts(max_vs), max_tris(max_ts), mesh_dirty(false) {
}

gxMesh::~gxMesh() {
	unlock();

	vertex_buff->Release();

	delete[] tri_indices;
}

bool gxMesh::lock(bool all) {
	if(locked_verts) return true;

	//V1.1.06...
	int flags = DDLOCK_WAIT | DDLOCK_WRITEONLY;

	/*
	//XP or less?
	if(graphics->runtime->osinfo.dwMajorVersion < 6) {
		flags |= (all ? DDLOCK_DISCARDCONTENTS : DDLOCK_NOOVERWRITE);
	}*/

	if(vertex_buff->Lock(0,0,(void**)&locked_verts, flags) >= 0) {
		mesh_dirty = false;
		return true;
	}

	static dxVertex* err_verts = new dxVertex[32768];

	locked_verts = err_verts;
	return true;
}

void gxMesh::unlock() {
	if(locked_verts) {
		vertex_buff->Unlock();
		locked_verts = 0;
	}
}

void gxMesh::backup() {
	unlock();
}

void gxMesh::restore() {
	mesh_dirty = true;
}

void gxMesh::render(int first_vert, int vert_cnt, int first_tri, int tri_cnt) {
	unlock();
	graphics->dir3dDev->SetStreamSource(0, vertex_buff, 0, sizeof(graphics->D3DV));
	graphics->dir3dDev->DrawIndexedPrimitiveUP(
		D3DPT_TRIANGLELIST,
		0,                   // MinIndex
		max_verts,           // NumVertices
		tri_cnt,             // PrimitiveCount
		tri_indices + first_tri * 3,  // pIndexData
		D3DFMT_INDEX16,      // IndexDataFormat
		locked_verts,        // pVertexStreamZeroData
		sizeof(graphics->D3DV)    // VertexStreamZeroStride
	);
}