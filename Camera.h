#ifndef CAMERA_H
#define CAMERA_H

#include "Vector3.h"

class Camera
{
	Vector3 m_Eye;
	Vector3 window[4];
	int pix_w, pix_h;
};


#endif