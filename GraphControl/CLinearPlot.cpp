#include "CLinearPlot.h"

CLinearPlot::CLinearPlot()
{
}

CLinearPlot::CLinearPlot(CRect rc)
{
	//CWnd::Create(NULL, NULL, WS_CHILD | WS_VISIBLE, rc, pParent, nID);
	rcPlot = rc;
}

CLinearPlot::~CLinearPlot()
{

	if (bitmap)
	{
		bitmap.reset();
		//Gdiplus::Bitmap* bmp = bitmap.release();
		//delete bmp;
	}
	if (graphics)
	{
		graphics.reset();
		//Gdiplus::Graphics* grp = graphics.release();
		//delete grp;
	}
}

CLinearPlot::CLinearPlot(CLinearPlot&&)
{
}


void CLinearPlot::setColor(Gdiplus::Color _color)
{
	color = _color;
}

void CLinearPlot::setValue(Gdiplus::REAL _startAngle, Gdiplus::REAL _sweepAngle)
{
	//CRect rc;
	//GetClientRect(rc);

	bitmap.reset(new Gdiplus::Bitmap(rcPlot.Width(), rcPlot.Height(), PixelFormat32bppARGB));
	graphics.reset(Gdiplus::Graphics::FromImage(bitmap.get()));

	Gdiplus::RectF ellipseRect(rcPlot.left + 1.0f, rcPlot.top + 1.0f, rcPlot.Width() - 2.0f, rcPlot.Height() - 2.0f);

	Gdiplus::SolidBrush brush(color);

	startAngle = _startAngle;
	sweepAngle = _sweepAngle;
	graphics->SetSmoothingMode(Gdiplus::SmoothingMode::SmoothingModeAntiAlias);

	graphics->FillPie(&brush, ellipseRect, startAngle, sweepAngle);

}

Gdiplus::Bitmap* CLinearPlot::getBitmap()
{
	return bitmap.get();
}

void CLinearPlot::setPlotColor(Gdiplus::Color _color)
{
	color = _color;
}