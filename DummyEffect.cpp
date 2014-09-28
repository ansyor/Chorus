#include "DummyEffect.h"

using namespace CHORUS;

DummyEffect::DummyEffect()
{
	name_ = "Dummy Effect";

	parameter_ = new float[kNumParams];

	for(int i = 0; i < kNumParams; ++i)
	{
		parameter_[i] = 0;
	}
    
	reset();
	calc();
}

DummyEffect::~DummyEffect()
{
	if(parameter_)
		delete[] parameter_;
	parameter_ = 0;
}

void DummyEffect::resetBuffer()
{
	chorus_.resetBuffer();
}

void DummyEffect::resetCoeffs()
{
	chorus_.resetCoeffs();
}

void DummyEffect::calc()
{	
	chorus_.calc();
}

void DummyEffect::setSampleRate(float sampleRate)
{
	sampleRate_ = sampleRate;
	chorus_.setSampleRate(sampleRate_);
}

void DummyEffect::setParameter(int index, float value)
{
	parameter_[index] = value;
	chorus_.setParameter(index, value);
}

 void DummyEffect::process(float *in, int sampleFrames)
 {
	 double _in;
	
	 for(int i = 0; i < sampleFrames; i++)
	 {
		 _in = in[i];
		 
		 chorus_.process(_in);

		 in[i] = (float)_in; 
	 }
 }
 void DummyEffect::process(float *inL, float *inR, int sampleFrames)
 {
	 double _inL, _inR;
	 for(int i = 0; i < sampleFrames; i++)
	 {
		 //LR
		 _inL = inL[i];
		 _inR = inR[i];

		 chorus_.process(_inL,_inR);


		 inL[i] = (float)_inL;
		 inR[i] = (float)_inR;
	 }
 }

 void DummyEffect::process(double *in, int sampleFrames)
{
	double _in;
	
	for(int i = 0; i < sampleFrames; i++)
	{
		_in = in[i];
		
		chorus_.process(_in);
		
		in[i] = (float)_in; 
	}
 }

 void DummyEffect::process(double *inL, double *inR, int sampleFrames)
 {
	 double _inL, _inR;
	 for(int i = 0; i < sampleFrames; i++)
	 {
		 //LR
		 _inL = inL[i];
		 _inR = inR[i];
		 
		 chorus_.process(_inL,_inR);
		 
		 
		 inL[i] = (float)_inL;
		 inR[i] = (float)_inR;
	 }
 }