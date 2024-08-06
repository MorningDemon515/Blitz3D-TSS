#ifndef GXLIGHT_H
#define GXLIGHT_H

class gxScene;

class gxLight {
public:
	gxLight(gxScene* scene, int type);
	~gxLight();

	D3DLIGHT9 d3d_light;

private:
	gxScene* scene;

	/***** GX INTERFACE *****/
public:
	enum {
		LIGHT_DISTANT = 1, LIGHT_POINT = 2, LIGHT_SPOT = 3
	};
	void setRange(float range);
	void setColor(const float rgb[3]) { memcpy(&d3d_light.Diffuse, rgb, 12); }
	void setPosition(const float pos[3]);
	void setDirection(const float dir[3]);
	void setConeAngles(float inner, float outer);

	void getColor(float rgb[3]) { memcpy(rgb, &d3d_light.Diffuse, 12); }
};

#endif