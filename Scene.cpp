#include "Scene.h"
#include "CSphere.h"
#include "Polygon.h"
#include "CDirectionalLight.h"
#include "CRay.h"
#include "test.h"
#include <gl/glut.h>
#include <iostream>
#include <fstream>
using namespace std;

int GCount = 0;
Scene::Scene()
{
	initScene();
}

Scene::~Scene()
{
	if (!m_Object.empty())
	{
		CGObject *tmp = m_Object.back();
		m_Object.pop_back();
		delete tmp;
	}

	if (!m_LightSource.empty())
	{
		CLightSource *tmp = m_LightSource.back();
		m_LightSource.pop_back();
		delete tmp;
	}
}


void Scene::initScene()
{
	printf("initScene begin\n");
	m_Object.push_back(new CSphere(Vector3(6, 6, 15), 15, Vector3(0.3, 0.7, 0.3), Vector3(0.3, 0.7, 0.3), Vector3(1, 1, 1), Vector3(0.3), 100, 0.7, false, false));
	m_Object.push_back(new CSphere(Vector3(-6, 6, 15), 15, Vector3(0.7, 0.3, 03), Vector3(0.3, 0.7, 0.3), Vector3(1, 1, 1), Vector3(0.3), 100, 0.7, false, false));
	
	Vector3 box[7];
	int vIndex[2][4] = {
		{ 0, 1, 2, 3 },
		{ 1, 4, 5, 2 }
	};
	
	box[0].set(-100, 100, 0);
	box[1].set(-100, 0, 0);
	box[2].set(100, 0, 0);
	box[3].set(100, 100, 0);
	box[4].set(-100, 0, 100);
	box[5].set(100, 0, 100);


	for (int i = 0; i<2; i++)
	{
		m_Object.push_back(new Polygon(box, vIndex[i], 4, Vector3(0.3, 0.3, 0.3), Vector3(0.2, 0.6, 0.6), Vector3(1, 1, 1), Vector3(0.3), 8, 1, false, true));
	}

	//m_Object.push_back(new Polygon(box, vIndex[0], 4, Vector3(0, 0, 0.7), Vector3(1, 0, 0.0), Vector3(1, 1, 1), 8, 1, false));


	//设置光源
	m_LightSource.push_back(new CDirectionalLight(Vector3(0, 40, 20), Vector3(0.2, 0.2, 0.2), Vector3(0.8,0.8,0.8), Vector3(1,1,1), Vector3(0, -2, -1)));
	//m_LightSource.push_back(new CDirectionalLight(Vector3(0, 20, 40), Vector3(0.2, 0.2, 0.2), Vector3(0.8, 0.8, 0.8), Vector3(1, 1, 1), Vector3(0, -1, -2)));
	//m_LightSource.push_back(new CDirectionalLight(Vector3(0, 20, 40), Vector3(0.2, 0.2, 0.2), Vector3(0.8, 0.8, 0.8), Vector3(1, 1, 1), Vector3(0, -1, -2)));

	//m_LightSource.push_back(new CDirectionalLight(Vector3(10, 5, 0), Vector3(0.3, 0.3, 0.3), Vector3(0.5, 0.5, 0.5), Vector3(0), Vector3(-1, -1, 0)));


	//设置相机
	m_Eye.set(0, 20, 30);
	m_Direction.set(0, -2, -3);
	distance = 10;
	win_Width = 15;
	win_Height = 15;

	computeWindow();

	pix_Width = 400;
	pix_Height = 400;
	buffer.resize(pix_Width*pix_Height);

	TotalTraceDepth = 2;

	isSceneChanged = true;
	printf("initScene end\n");
}

void Scene::computeWindow()
{
	Vector3 up = Vector3(0, 1, 0);
	if (m_Direction.z == 0 && m_Direction.y == 0){
		up = m_Direction.cross(Vector3(0, 0, 1)).norm();
	}
	else{
		up = m_Direction.cross(Vector3(1, 0, 0)).norm();
	}
	Vector3 h_offest = (up - m_Direction.norm().dot(up)).norm()*(win_Height / 2);
	Vector3 right = m_Direction.cross(Vector3(0, 1, 0)).norm();
	Vector3 w_offest = (right - m_Direction.norm().dot(right)).norm()*(win_Width / 2);

	Vector3 center = m_Eye + m_Direction.norm() * distance;
	window[0] = center + h_offest - w_offest;
	window[1] = center + h_offest + w_offest;
	window[2] = center - h_offest + w_offest;
	window[3] = center - h_offest - w_offest;
}

void Scene::test()
{

	Vector3 intersection, color(0, 0, 0);
	CRay ray(Vector3(10, 0, 0), Vector3(-1, 0, 0));
	int objIndex = findNearestObject(ray, intersection, -2);
	printf("%d\n", objIndex);
	intersection.show();

	if (objIndex != -1)
	{
		Vector3 p = intersection;
		Vector3 N = m_Object[objIndex]->getNormal(p);
		N.normalize();
		printf("p.show\n");
		p.show();
		for (int i = 0; i < m_LightSource.size(); i++)
		{
			Vector3 ambient = m_LightSource[i]->EvalAmbient(m_Object[objIndex]->material.m_Ka);
			Vector3 L = m_LightSource[i]->m_Postion - p;
			L.normalize();
			Vector3 diffuse = m_LightSource[i]->EvalDiffuse(m_Object[objIndex]->material.m_Kd, N, L);
			Vector3 V = m_Eye - p;
			V.normalize();
			Vector3 specular = m_LightSource[i]->EvalSpecular(m_Object[objIndex]->material.m_Ks, m_Object[objIndex]->material.m_Shininess, N, L, V);
			printf("ambient\n");
			ambient.show();
			printf("diffuse\n");
			diffuse.show();
			printf("specular\n");
			specular.show();
			printf("\n");
			color += ambient + diffuse + specular;
		}
	}

	color.show();
}

int Scene::findNearestObject(const CRay& ray, Vector3 &Intersection, int sourceObj)
{
	int objects_numbers = m_Object.size();
	float distance = 1000000; // 初始化无限大距离
	int objIndex = -1;
	//Vector3 Intersection;     // 交点
	for (int i = 0; i<objects_numbers; i++)  // 遍历场景中每一个物体
	{
		CGObject *obj = m_Object[i];
		if (obj->isIntersected(ray, distance) != MISS && i != sourceObj) // 判断是否有交点
		{
			Intersection = ray.getPoint(distance); //如果相交，求出交点保存到Intersection
			objIndex = i;
		}
	}
	return objIndex;
}


void Scene::writeFrameBuffer()
{
	int point = 0;

	Vector3 xRate = (window[1] - window[0]) / pix_Width;
	Vector3 yRate = (window[3] - window[0]) / pix_Height;
	//xRate.show();
	//yRate.show();
	//((window[0] + xRate * 0) + (yRate * 0)).show();
	//((window[0] + xRate * (pix_Width - 1)) + (yRate * (pix_Height-1))).show();

	for (int y = 0; y < pix_Height; y++)
	{
		for (int x = 0; x < pix_Width; x++)
		{
			//printf("x:%d, y:%d\n", x, y);
			Vector3 pos = window[0] + xRate * x + yRate * y;
			//pos.show();
			Vector3 direction = pos - m_Eye;
			//direction.show();
			
			CRay ray(m_Eye, direction);
			//printf("5\n");
			Vector3 color = RayTracing(ray, 0, -2);
			//printf("9\n");
			buffer[point++] = color;
			//buffer.push_back(color);


			if (x == 0 && y == 0 || x == pix_Width - 1 && y == pix_Height - 1){
				pos.show();
				direction.show();
				color.show();
			}

			if (x == pix_Width / 2 && y == pix_Height / 2)
			{
				printf("middle\n");
				pos.show();
				direction.show();
				color.show();
			}

			//printf("10\n");
			//printf("%d/n",point);
			//printf("%f,%f,%f\n", color.x, color.y, color.z);
		}
	}	
	printf("count:%d\n", GCount);
}

void Scene::writePic()
{
	char filename[] = "pic.txt"; // 此处写入文件名 
	ofstream fout(filename);
	for (int y = 0; y < pix_Height; y++)
	{
		for (int x = 0; x < pix_Width; x++){
			if (buffer[y*pix_Width + x].x != 1.0){
				fout << 0;
			}
			else{
				fout << 1;
			}
		}
		fout << endl;
	}
	fout.close();
}

Vector3 Scene::RayTracing(const CRay& ray, int depth, int sourceObj)
{
	//printf("6\n");

	if (TotalTraceDepth == depth){
		return Vector3(0, 0, 0);
	}

	Vector3 intersection, color(0,0,0);
	int objIndex = findNearestObject(ray, intersection, sourceObj);
	//printf("7\n");
	//printf("objIndex = %d\n", objIndex);
	if (objIndex != -1)
	{
		//printf("8\n");

		Material Mat = m_Object[objIndex]->getMaterial(intersection);
		Vector3 p = intersection;
		Vector3 N = m_Object[objIndex]->getNormal(p);
		N.normalize();

		for (int i = 0; i < m_LightSource.size(); i++)
		{
			Vector3 p;
			findNearestObject(CRay(m_LightSource[i]->m_Postion, intersection - m_LightSource[i]->m_Postion), p, -2);
			
			Vector3 ambient = m_LightSource[i]->EvalAmbient(Mat.m_Ka);
			
			color += ambient;
			if (intersection.near(p))//算起来误差挺大的
			{
				Vector3 L = m_LightSource[i]->m_Postion - p;
				L.normalize();
				Vector3 diffuse = m_LightSource[i]->EvalDiffuse(Mat.m_Kd, N, L);
				Vector3 V = m_Eye - p;
				V.normalize();
				Vector3 specular = m_LightSource[i]->EvalSpecular(Mat.m_Ks, Mat.m_Shininess, N, L, V);
				color += diffuse + specular;
			}
		}

		//RayTracing()
		//CRay mray;
		//Vector3 Ir;

		if (objIndex == 0 && intersection.y < 20 && intersection.x > -5 && intersection.x < 5){
			int a = 1;
		}

		CRay mray(intersection, ray.m_Direction - N * (ray.m_Direction).dot(N) * 2);

		Vector3 Ir = RayTracing(mray, depth + 1, objIndex);
		color.isAColor();
		color = Vector3(Ir.x * Mat.m_Kr.x,
			Ir.y * Mat.m_Kr.y,
			Ir.z * Mat.m_Kr.z)* 0.25 + color * 0.75;
	}

	return color;
}


void Scene::displayScene()
{
	if (isSceneChanged)
	{
		writeFrameBuffer();
		isSceneChanged = false;
		printf("change\n");
	}
	glRasterPos2f(-1, -1);
	glDrawPixels(pix_Width, pix_Height, GL_RGB, GL_FLOAT, (const GLvoid*)&buffer[0]);
}