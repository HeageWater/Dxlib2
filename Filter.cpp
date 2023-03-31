#include "Filter.h"
#include <DxLib.h>

Filter::Filter()
{
	filterPos.x = 300;
	filterPos.x = 300;
	filterSize.x = { 128 };
	filterSize.y = { 64 };

}

Filter::~Filter()
{
}

void Filter::Inilialize()
{
	filterPos.x = 300;
	filterPos.x = 300;
	filterSize.x = { 128 };
	filterSize.y = { 64 };
}

void Filter::Update()
{
}

void Filter::Draw()
{
	//フィルター
	DrawBox(filterPos.x - filterSize.x,
		filterPos.y - filterSize.y,
		filterPos.x + filterSize.x,
		filterPos.y + filterSize.y,
		0xaaaaaa,
		false);
}
