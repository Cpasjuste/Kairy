/******************************************************************************
*
* Copyright (C) 2015 Nanni
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*
*****************************************************************************/

#include <Kairy/Actions/ScaleTo.h>
#include <Kairy/Graphics/Node.h>

NS_KAIRY_BEGIN

//=============================================================================

ScaleTo::ScaleTo(float duration, float scale)
	: FiniteTimeAction(duration)
{
	_startScaleX = 0.0f;
	_startScaleY = 0.0f;
	_endScaleX = scale;
	_endScaleY = scale;
}

//=============================================================================

std::shared_ptr<ScaleTo> ScaleTo::create(float duration, float scale)
{
	return std::make_shared<ScaleTo>(duration, scale);
}

//======================================================================

std::shared_ptr<ScaleTo> ScaleTo::create(float duration, float scaleX, float scaleY)
{
	return std::make_shared<ScaleTo>(duration, scaleX, scaleY);
}

//======================================================================

ScaleTo::ScaleTo(float duration, float scaleX, float scaleY)
	: FiniteTimeAction(duration)
{
	_startScaleX = 0.0f;
	_startScaleY = 0.0f;
	_endScaleX = scaleX;
	_endScaleY = scaleY;
}

//=============================================================================

void ScaleTo::start(Node* target)
{
	_startScaleX = target->getScaleX();
	_startScaleY = target->getScaleY();

	FiniteTimeAction::start(target);
}

//=============================================================================

void ScaleTo::step(float dt)
{
	_target->setScaleX(_startScaleX + (_endScaleX - _startScaleX) * dt);
	_target->setScaleY(_startScaleY + (_endScaleY - _startScaleY) * dt);
}

//=============================================================================

NS_KAIRY_END
