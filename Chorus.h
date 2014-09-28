#ifndef CHORUS_H
#define CHORUS_H

#include "math.h"
#include "FxBase.h"
#include "ModuleBase.h"

#define	MAXBUFFERSIZE 8192		// must be about 1/5 of a second at given sample rate
#define ROUND(n)		((int)((double)(n)+0.5))

#define	MODF(n,i,f) ((i) = (int)(n), (f) = (n) - (double)(i))
//	modf - vaguely related to the library routine modf(), this macro breaks a double into
//	integer and fractional components i and f respectively.
//	n - input number, a double
//	i - integer portion, an integer (the input number integer portion should fit)
//	f - fractional portion, a double


#define	NUM_MIX_MODES	7
#define	NUM_DELAYS	11

namespace CHORUS{
enum t
{
	// Parameters Tags
	kRate = 0,
	kWidth,
	kDelay,
	kWetLevel,

	kNumParams
};
};

class Chorus : public ModuleBase
{
public:
	Chorus();
	~Chorus();
	
	void resetBuffer();
	void resetCoeffs();
	
	void setParameter(int index, float value);
	void setSampleRate (float sampleRate);
	
	void setRate ();
	void setWidth ();
	void setDelay ();
	void setWetLevel ();
	void setSweep();
	
	void process(float &in);
	void process(float &inL, float &inR);
	void process(double &in);
	void process(double &inL, double &inR);

private :
	float *parameter_;
	float paramSweepRate;
	float paramWidth;
	float paramDelay;
	float paramWetLevel;	
	
	double _minSweepSamples;	// lower bound of calculated sweep range, calc'd by setSweep from rate, width, delay
	double _maxSweepSamples;	// upper bound, ditto
	
	double _sweepRate;			// actual calculated sweep rate
	int		_sweepSamples;			// sweep width in # of samples
	int	   _delaySamples;		// number of samples to run behind filling pointer

	double *_bufferL;		// stored sound
	double *_bufferR;
	int	   writeIndex;					// fill/write pointer
	double _step;				// amount to step the sweep each sample
	double _sweep;
};

#endif
