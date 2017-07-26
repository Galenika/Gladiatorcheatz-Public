#pragma once

#define SEQUENCE_DEFAULT_DRAW 0
#define SEQUENCE_DEFAULT_IDLE1 1
#define SEQUENCE_DEFAULT_IDLE2 2
#define SEQUENCE_DEFAULT_LIGHT_MISS1 3
#define SEQUENCE_DEFAULT_LIGHT_MISS2 4
#define SEQUENCE_DEFAULT_HEAVY_MISS1 9
#define SEQUENCE_DEFAULT_HEAVY_HIT1 10
#define SEQUENCE_DEFAULT_HEAVY_BACKSTAB 11
#define SEQUENCE_DEFAULT_LOOKAT01 12

#define SEQUENCE_BUTTERFLY_DRAW 0
#define SEQUENCE_BUTTERFLY_DRAW2 1
#define SEQUENCE_BUTTERFLY_LOOKAT01 13
#define SEQUENCE_BUTTERFLY_LOOKAT03 15

#define SEQUENCE_FALCHION_IDLE1 1
#define SEQUENCE_FALCHION_HEAVY_MISS1 8
#define SEQUENCE_FALCHION_HEAVY_MISS1_NOFLIP 9
#define SEQUENCE_FALCHION_LOOKAT01 12
#define SEQUENCE_FALCHION_LOOKAT02 13

#define SEQUENCE_DAGGERS_IDLE1 1
#define SEQUENCE_DAGGERS_LIGHT_MISS1 2
#define SEQUENCE_DAGGERS_LIGHT_MISS5 6
#define SEQUENCE_DAGGERS_HEAVY_MISS2 11
#define SEQUENCE_DAGGERS_HEAVY_MISS1 12

#define SEQUENCE_BOWIE_IDLE1 1

#define RandomInt(nMin, nMax) (rand() % (nMax - nMin + 1) + nMin)

struct Skin
{
	int pk;
	int itemDI;
	int s;
	float w;
	int st;
	std::string custName;
	std::string model;

	Skin(int pk, int itemDI, int s, float w, int st, std::string custName, std::string model)
	{
		this->pk = pk;
		this->s = s;
		this->itemDI = itemDI;
		this->w = w;
		this->st = st;
		this->custName = custName;
		this->model = model;
	}

	Skin() { };
};

extern std::unordered_map<int, Skin> skins;

class Skinchanger
{
public:

	void change(ClientFrameStage_en stage);
	void fireEventOnClientSide(GameEvent *gEvent);

private:

	const char *getModelByItemDI(int idx);
	const char *knifeToString(int idx);
};

extern bool bForceFullUpdate;

extern std::unique_ptr<Skinchanger> skinchanger;