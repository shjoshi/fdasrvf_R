
#include "Oblique.h"

Oblique::Oblique(integer n, integer num) : ProductManifold(1, new Sphere(n), num)
{
	name.assign("Oblique");
	delete EMPTYEXTR;
	delete EMPTYINTR;
	EMPTYEXTR = new ObliqueVector(n, num);
	EMPTYINTR = new ObliqueVector(n - 1, num);
};

Oblique::~Oblique(void)
{
	for (integer i = 0; i < numofmani; i++)
	{
		delete manifolds[i];
	}
};

void Oblique::ChooseObliqueParamsSet1(void)
{
	Sphere *S = dynamic_cast<Sphere *> (manifolds[0]);
	S->ChooseStieParamsSet1();
};

void Oblique::ChooseObliqueParamsSet2(void)
{
	Sphere *S = dynamic_cast<Sphere *> (manifolds[0]);
	S->ChooseSphereParamsSet1();
};

void Oblique::ChooseObliqueParamsSet3(void)
{
	Sphere *S = dynamic_cast<Sphere *> (manifolds[0]);
	S->ChooseSphereParamsSet2();
};

void Oblique::ChooseObliqueParamsSet4(void)
{
	Sphere *S = dynamic_cast<Sphere *> (manifolds[0]);
	S->ChooseSphereParamsSet3();
};

void Oblique::SetParams(PARAMSMAP params)
{
	Manifold::SetParams(params);
	PARAMSMAP::iterator iter;
	for (iter = params.begin(); iter != params.end(); iter++)
	{
		if (iter->first == static_cast<std::string> ("ParamSet"))
		{
			switch (static_cast<integer> (iter->second))
			{
			case 1:
				ChooseObliqueParamsSet1();
				break;
			case 2:
				ChooseObliqueParamsSet2();
				break;
			case 3:
				ChooseObliqueParamsSet3();
				break;
			case 4:
				ChooseObliqueParamsSet4();
				break;
			default:
				break;
			}
		}
	}
};
